#include "gtest/gtest.h"
#include "../include/Cell.h"
#include "../include/GameMap.h"
#include "../include/Shop.h"

#include "../include/Tree.h"
#include "../include/Stone.h"
#include "../include/Mob.h"
#include "../include/Campfire.h"
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(CellTest, WaterTerrainBlocksMovement)
{
    Cell cell;
    cell.setTerrain(TerrainType::WATER);
    EXPECT_FALSE(cell.isPassable());
    EXPECT_EQ(cell.getSymbol(), '~');
}


class GameMapTest : public ::testing::Test
{
protected:
    GameMap map{5, 5};
};

TEST(GameStateTest, InitialValues) {
    GameState state;
    EXPECT_EQ(state.inventory.hp, 100);
    EXPECT_EQ(state.inventory.energy, 50);
    EXPECT_EQ(state.day, 1);
}

TEST(GameObjectTest, TreeInteraction) {
    GameState state;
    Tree().interact(state);
    EXPECT_EQ(state.inventory.energy, 40);
    EXPECT_EQ(state.inventory.wood, 1);
}

TEST(GameObjectTest, StoneInteraction) {
    GameState state;
    Stone().interact(state);
    EXPECT_EQ(state.inventory.energy, 35);
    EXPECT_EQ(state.inventory.stone, 1);
}

TEST(GameObjectTest, CampfireInteraction) {
    GameState state;
    state.inventory.hp = 50;
    state.inventory.energy = 20;
    Campfire().interact(state);
    EXPECT_EQ(state.inventory.hp, 100);
    EXPECT_EQ(state.inventory.energy, 50);
    EXPECT_EQ(state.day, 2);
}



TEST(CellTest, ObjectInteraction) {
    Cell cell;
    cell.setObject(std::make_shared<Tree>());
    GameState state;
    cell.interact(state);
    EXPECT_EQ(state.inventory.wood, 1);
}

TEST(CellTest, PassabilityCheck) {
    Cell cell;
    cell.setObject(std::make_shared<Tree>());
    EXPECT_FALSE(cell.isPassable());
}


TEST(GameStateTest, DeathResetsResources) {
    GameState state;
    state.inventory = {0, 0, 100, 5, 3, 2, 3};
    Mob('D', 100, 0).interact(state);
    
    EXPECT_EQ(state.inventory.hp, 100);
    EXPECT_EQ(state.inventory.gold, 0);
    EXPECT_EQ(state.inventory.wood, 0);
    EXPECT_EQ(state.inventory.stone, 0);
    EXPECT_EQ(state.inventory.sword_level, 2);
    EXPECT_EQ(state.inventory.shield_level, 3);
    EXPECT_EQ(state.day, 2);
}

TEST(MobTest, DamageCalculation) {
    GameState state;
    state.inventory.shield_level = 3;
    Mob('M', 25, 10).interact(state);
    
    // 25 - (3*5) = 10 damage
    EXPECT_EQ(state.inventory.hp, 84);
    EXPECT_EQ(state.inventory.gold, 10);
    EXPECT_EQ(state.last_message, "Fought M! Lost 16 HP. Got 10 gold.");
}


#include "../include/CardPlayer.h"
TEST(CardPlayerTest, Initialization) {
    CardPlayer player;
    EXPECT_EQ(player.getHealth(), 50);
    EXPECT_EQ(player.getEnergy(), 3);
}

TEST(CardPlayerTest, DamageCalculation) {
    CardPlayer player;
    
    player.addBlock(5);
    player.takeDamage(3);
    EXPECT_EQ(player.getBlock(), 2);
    EXPECT_EQ(player.getHealth(), 50);
    player.takeDamage(10);
    EXPECT_EQ(player.getBlock(), 0);
    EXPECT_EQ(player.getHealth(), 42);
}



TEST(EnemyAITest, CardPrioritization) {
    Enemy enemy;
    CardPlayer player;
    
    
    player.takeDamage(30); 
    enemy.executeTurn(player);
    
    EXPECT_LT(player.getHealth(), 20);
}


#include "../include/AttackCard.h"

TEST(AttackCardTest, ConstructorAndGetters) {
    AttackCard card(3,"Fireball", 10);
    
    EXPECT_EQ(card.getName(), "Fireball");
    EXPECT_EQ(card.getEnergyCost(), 3);
}

TEST(AttackCardTest, PlayAffectsEnemyHealthAndUserEnergy) {
    AttackCard card(3,"Strike", 8);
    Enemy enemy;
    CardPlayer player;

    enemy.setHealth(100);  
    player.setEnergy(5);   

    card.play(player, enemy);

    EXPECT_EQ(enemy.getHealth(), 100 - 8);
    EXPECT_EQ(player.getEnergy(), 5 - 3);
}

#include "../include/BasicAttack.h"

TEST(BasicAttackTest, ConstructorInitializesEnergyCost) {
    BasicAttack attack;
    EXPECT_EQ(attack.getPriority(), 1); 
}

TEST(BasicAttackTest, GetNameReturnsCorrectValue) {
    BasicAttack attack;
    EXPECT_EQ(attack.getName(), "Basic Attack");
}


TEST(BasicAttackTest, CanUseAlwaysTrue) {
    BasicAttack attack;
    
    CardPlayer player;
    Enemy enemy;
    player.setHealth(100);
    enemy.setHealth(50);
    EXPECT_TRUE(attack.canUse(player, enemy));

    player.setHealth(0);
    EXPECT_TRUE(attack.canUse(player, enemy));

    player.setHealth(100);
    enemy.setHealth(0);
    EXPECT_TRUE(attack.canUse(player, enemy));
}

TEST(BasicAttackTest, ExecuteDamagesTarget) {
    BasicAttack attack;
    Enemy user;       
    CardPlayer target;

    target.setHealth(20);
    user.setHealth(100);

    attack.execute(user, target);

    EXPECT_EQ(target.getHealth(), 12);

    EXPECT_TRUE(user.isAlive());
}

#include "../include/BossMob.h"

TEST(BossMobTest, BasicProperties) {
    BossMob boss;
    
    EXPECT_EQ(boss.getSymbol(), 'B');
    EXPECT_FALSE(boss.isPassable());
}

TEST(BossMobTest, InteractWithoutSwordLevel3) {
    BossMob boss;
    GameState state;
    state.inventory.sword_level = 2;
    
    boss.interact(state);
    
    EXPECT_EQ(state.last_message, "You need sword level 3 to fight boss!");
    EXPECT_EQ(state.inventory.gold, 0);
    EXPECT_NE(state.inventory.hp, 0);   
}

#include "../include/Campfire.h"

TEST(CampfireTest, SymbolIsC) {
    Campfire campfire;
    EXPECT_EQ(campfire.getSymbol(), 'C');
}

TEST(CampfireTest, RestoresHealthAndEnergy) {
    Campfire campfire;
    GameState state;

    state.inventory.hp = 50;
    state.inventory.energy = 20;
    state.day = 3;

    campfire.interact(state);

    EXPECT_EQ(state.inventory.hp, 100);
    EXPECT_EQ(state.inventory.energy, 50);
    EXPECT_EQ(state.day, 4);
    EXPECT_EQ(state.last_message, "Restored health and energy! New day: 4");
}

TEST(CampfireTest, RestoresOnlyHealth) {
    Campfire campfire;
    GameState state;
    
    state.inventory.hp = 80;
    state.inventory.energy = 50;
    state.day = 5;

    campfire.interact(state);

    EXPECT_EQ(state.inventory.hp, 100);
    EXPECT_EQ(state.inventory.energy, 50);
    EXPECT_EQ(state.day, 6);
    EXPECT_EQ(state.last_message, "Restored health and energy! New day: 6");
}

TEST(CampfireTest, RestoresOnlyEnergy) {
    Campfire campfire;
    GameState state;
    
    state.inventory.hp = 100;
    state.inventory.energy = 30;
    state.day = 2;

    campfire.interact(state);

    EXPECT_EQ(state.inventory.hp, 100);
    EXPECT_EQ(state.inventory.energy, 50);
    EXPECT_EQ(state.day, 3);
    EXPECT_EQ(state.last_message, "Restored health and energy! New day: 3");
}

TEST(CampfireTest, AlreadyFullyRested) {
    Campfire campfire;
    GameState state;
    
    state.inventory.hp = 100;
    state.inventory.energy = 50;
    state.day = 7;

    campfire.interact(state);

    EXPECT_EQ(state.inventory.hp, 100);
    EXPECT_EQ(state.inventory.energy, 50);
    EXPECT_EQ(state.day, 7);
    EXPECT_EQ(state.last_message, "Already fully rested!");
}

#include "../include/CardShop.h"

TEST(CardShopTest, BasicProperties) {
    CardShop shop;
    EXPECT_EQ(shop.getSymbol(), 'K');
    EXPECT_FALSE(shop.isPassable());
}

