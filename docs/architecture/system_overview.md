# System Overview  

## Purpose  
The system is a **turn-based console RPG** focused on strategic resource management and boss battles. The player must optimize their actions (movement, combat, resting) to defeat bosses in the fewest in-game days possible. The game emphasizes minimalistic design, tactical decision-making, and a risk-reward balance between exploration and progression.

## Key Features  
1. **Energy-Driven Gameplay**:  
   - Each action (fight, interact) costs 1 energy.  
   - Restore energy by sleeping at campfires (consumes 5 wood, increments day counter).  
2. **Static Enemies & Boss AI**:  
   - Regular enemies (mobs) attack only when the player is adjacent.  
   - Bosses actively chase the player within a 5-tile radius and have unique abilities.  
3. **Resource-Based Progression**:  
   - Collect wood (from trees), stone (from mines), and gold (from mobs).  
   - Spend resources at shops to upgrade gear (sword damage, armor defense).  
4. **Boss Teleportation**:  
   - Teleportation penalty: +1 day on failure.  
5. **Day Counter**:  
   - Track total days spent. The goal is to complete the game in the fewest days.  

## Technologies  
- **Language**: C++17 (STL only, no external libraries).  
- **Build System**: Makefile.  
- **Testing**: Google Test.  

## Constraints  
- **No GUI**: All interactions are console-based (text output).  
- **Single-player**: No multiplayer or networking.  
- **Performance**: Smooth operation on maps up to 20x20.  

## Architecture Highlights  
- **Entity-Component-System (ECS)**:  
  - **Components**: `Position`, `Health`, `Energy`, `BossAI`, `Resources`.  
  - **Systems**: `MovementSystem`, `CombatSystem`, `EnergySystem`, `ShopSystem`.  
- **Modular Design**:  
  - Isolated modules for map management, combat logic, and UI rendering.  
  - Hardcoded map for simplicity (no file I/O in initial version).      