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
