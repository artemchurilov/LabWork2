<<<<<<< HEAD
# System Requirements and Use Cases

## Functional Requirements

### 1. Player Movement
- **FR1**: The player can move on a grid-based map using `W/A/S/D` keys.
  - Collision detection with obstacles (walls `#` and water `~`).
  - Movement is turn-based (one action per key press).

### 2. Static Enemies and Boss AI
- **FR2**: Enemy behavior:
  - **FR2.1**: Regular enemies (mobs) are static and attack only when the player is adjacent.
  - **FR2.2**: Bosses have simple chase AI (move toward the player if within 5 tiles).

### 3. Resource System
- **FR3**: Resource collection and display:
  - Press `R` to show resources: wood (from trees `T`), stone (from mines `M`), gold (from defeating mobs).
  - Resources are automatically added to the player's stats (no inventory slots).

### 4. Combat System
- **FR4**: Turn-based combat mechanics:
  - **FR4.1**: Damage formula: `(Player Attack * Level) - Enemy Defense`.
  - **FR4.2**: Defeating mobs grants gold and XP. Bosses drop unique items but no gold.
  - **FR4.3**: On player defeat, return to the Forest with no penalty except +1 day counter.

### 5. Energy and Day Counter
- **FR5**: Action energy system:
  - Each action (combat, interaction) consumes 1 energy.
  - Maximum energy: 10. Restore energy by sleeping at campfires (cost: 5 wood, +1 day).
  - Goal: Complete the game in the fewest days possible.

### 6. Boss Teleportation
- **FR6**: Teleport to boss arenas:
  - Press `B` to attempt teleport to the Ruby Meadow (current boss).
  - On defeat: Return to the Forest, some resource loss, +1 day.

### 7. Shop and Upgrades
- **FR7**: Shop interactions:
  - Access shops (`S` on the map) by pressing `E` nearby.
  - Spend resources to upgrade gear:
    - Sword: `5 gold + 2 stone` → +10% damage.
    - Armor: `3 wood + 5 gold` → +5 defense.

### 8. Map System
- **FR8**: Hardcoded map:
  - Predefined 20x20 grid with static objects (trees, mines, campfires, bosses).
---

## Non-Functional Requirements

### 1. Performance
- **NFR1**: The game must render at ≥30 FPS on a 20x20 map (console output).

### 2. Compatibility
- **NFR2**: Compatible with g++ on Ubuntu. Zero external dependencies.

### 3. Code Quality
- **NFR3**: Adherence to C++17 standards and modular design (ECS pattern encouraged).

---

## Use Case Examples

### Use Case 1: Farming Mobs
1. Player moves adjacent to a mob (`M`).
2. Combat starts automatically:
   - Player deals damage using `Attack`.
   - If mob health ≤0: Player gains `10 gold` and `5 XP`.
3. Player presses `R` to check gold count.

### Use Case 2: Boss Fight
1. Player presses `B` to teleport.
2. Boss chases the player:
   - Player attacks until boss is defeated or flees.
3. On defeat: Boss drops "Ruby Sword" (unique item), player returns to next Forest location.

### Use Case 3: Campfire Rest
1. Player moves to a campfire (`C`).
2. Presses `E` to sleep (cost: 5 wood).
3. Energy is restored, day counter increases by 1.

---

## Notes
- All UI interactions are console-based (no GUI libraries).
- Map symbols: `P` (player), `T` (tree), `M` (mob), `B` (boss), `C` (campfire), `S` (shop).
=======
System Requirements & Use Cases

Functional Requirements:

    Resource Gathering:
        Interact with Tree to gain wood (cost: 10 energy).
        Interact with Stone to gain stone (cost: 15 energy).

    Upgrades:
        Visit Shop to upgrade sword/shield levels (cost: 50 gold).

    Card Management:
        Purchase card packs at CardShop (cost: resources).
        Build and modify a deck.

    Combat:
        Engage in turn-based battles using cards (CombatSystem).
        Defeat bosses (BossMob) to win the game.

Use Case Examples:
    Fighting a Boss:
        Player interacts with BossMob.
        CombatSystem initializes a battle.
        Player uses cards (Strike, Defend) to defeat the boss.
        Victory rewards 1000 gold; defeat resets progress.

    Buying a Card Pack:
        Player interacts with CardShop.
        Selects a pack (e.g., "Arms Action" for 100 gold and 10 wood).
        Card is added to the deck or collection.

Compiler and Libraries Requirements
    Compiler: requires g++ (GCC for C++) with support for the C++17 standard. 
    Standard Libraries: standard C++ library, mathematical library libm. 
    Google Test: Libraries: libgtest and libgtest_main.
    Multithreading 
    System Utilities: ar utility 
>>>>>>> docs
