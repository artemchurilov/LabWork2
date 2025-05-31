<<<<<<< HEAD
# Testing Plan  

## Testing Scope  

### 1. Unit Testing  
- **Objective:** Validate individual classes and methods.  
- **Tools:** Google Test (if allowed) or manual testing.  
- **Test Examples:**  
  - **`Player` Class:**  
    - `Move()`: Player cannot move outside map boundaries.  
    - `RestoreEnergy()`: Energy resets to maximum value.  
  - **`CombatSystem` Class:**  
    - `CalculateDamage()`: Damage is calculated correctly (attack * level - defense).  
  - **`ResourceSystem` Class:**  
    - `AddGold(10)`: Player’s gold increases by 10.  


### 2. Integration Testing  
- **Objective:** Validate interactions between components.  
- **Test Examples:**  
  - **Resource Collection:**  
    - Player interacts with a tree (`E`) → `wood` increases by 1.  
  - **Shop Interaction:**  
    - Attempting to upgrade a sword without resources → "Not enough gold!" message.  
  - **Boss Battle:**  
    - Defeating a boss grants a unique item.  


### 3. System Testing  
- **Objective:** Validate end-to-end gameplay flow.  
- **Scenarios:**  
  1. Game start → movement → resource farming → mob combat → boss teleportation → victory.  
  2. Player death → respawn at starting point +1 day.  

## Test Cases  

### Movement & Collision  
 **Test**                          **Expected Result**           
 Player moves into a wall (`#`)     Position remains unchanged.  
 Player moves out of map bounds     Position stays within map.     

### Combat System  
 **Test**                                     **Expected Result**         
 Player level 2, attack 15 → mob defense 5     Damage = (15 * 2) - 5 = 25.  
 Player health ≤0                              Respawn at starting point.     

### Resources & Shop  
 **Test**                          **Expected Result**           
 Collect 5 wood at a campfire       `wood` = 5, sleep restores energy.   
 Attempt upgrade without resources  Upgrade fails, resources unchanged.   

### Energy & Day Counter  
 **Test**                           **Expected Result**           
 10 actions → energy = 0            Combat blocked.     
 Sleep at campfire                  Energy = 10, day counter +1. 


## Performance Testing  
- **Objective:** Ensure smooth operation.  
- **Tests:**  
  - Rendering a 20x20 map: ≤50 ms per frame.  
  - Handling 10 enemies simultaneously: no lag.  

## Manual Testing  
- **UI/UX Checks:**  
  - Map symbols/colors render correctly.  
  - Error messages are clear (e.g., "Not enough energy!").  

## Tools  
1. **Google Test:** Automate unit tests.  
2. **Makefile:** Build test binaries.  
3. **Logging:** Output test results to console.  


## Traceability Matrix  
 **Requirement** (FR/NFR)  **Test Cases**          

 FR1 (Movement)            Collision, boundary checks.   
 FR4 (Combat)              Damage calculation, respawn.  
 FR7 (Shop)                Upgrade logic, resource checks.   
 NFR1 (Performance)        Rendering and latency tests.  
=======
### 1. Main Menu Testing

|**Test Case**|**Steps**|**Expected Result**|**Automation**|
|---|---|---|---|
|Main Menu Navigation|1. Launch game  <br>2. Use W/S keys|Highlighted selection moves properly|Manual|
|Start Game Functionality|Select "Start Game"|Game initializes correctly|Manual|
|Rules Screen Display|Select "Rules"|Game rules displayed properly|Manual|
|Quit Game Functionality|Select "Quit"|Game exits cleanly|Manual|

### 2. Map Navigation Testing

|**Test Case**|**Steps**|**Expected Result**|**Automation**|
|---|---|---|---|
|Movement Boundaries|Try to move beyond map edges|Player stays within bounds|Manual|
|Object Interaction|Move into objects (T, S, M, $)|Appropriate interactions trigger|Manual|
|Map Toggle (B key)|Press B during gameplay|Map alternates layout|Manual|
|Campfire Respawn|Die and check respawn|Player respawns at campfire|Manual|

### 3. Combat System Testing

|**Test Case**|**Steps**|**Expected Result**|**Automation**|
|---|---|---|---|
|Card Play Mechanics|Play different cards in combat|Correct energy cost/damage applied|Unit Tests|
|Enemy AI Behavior|Observe enemy turns|Enemies use appropriate abilities|Manual|
|Health Calculations|Take damage with/without block|Health updates correctly|Unit Tests|
|Victory/Defeat Conditions|Win/lose combat scenarios|Proper outcome handling|Integration|

### 4. Shop System Testing

|**Test Case**|**Steps**|**Expected Result**|**Automation**|
|---|---|---|---|
|Sword/Shield Upgrades|Purchase upgrades with sufficient gold|Stats increase, gold deducted|Unit Tests|
|Insufficient Funds|Attempt purchases without enough gold|Error message displayed|Unit Tests|
|Card Shop Purchases|Buy card packs|Cards added to collection/deck|Integration|
|Deck Management|Try to exceed 15-card deck|Card replacement prompt appears|Manual|

### 5. Resource System Testing

|**Test Case**|**Steps**|**Expected Result**|**Automation**|
|---|---|---|---|
|Tree Chopping|Interact with T with >=10 energy|Wood +1, energy -10|Unit Tests|
|Stone Mining|Interact with S with >=15 energy|Stone +1, energy -15|Unit Tests|
|Energy Exhaustion|Try gathering without enough energy|Error message displayed|Unit Tests|

### 6. Deck System Testing

|**Test Case**|**Steps**|**Expected Result**|**Automation**|
|---|---|---|---|
|Initial Deck Selection|Choose different deck types|Correct cards in starting deck|Manual|
|Card Replacement|Try adding card to full deck|Replacement interface works|Manual|
|Card Details View|Select cards in deck view|Proper descriptions displayed|Manual|

### 7. Boss Fight Testing

|**Test Case**|**Steps**|**Expected Result**|**Automation**|
|---|---|---|---|
|Boss Access Requirements|Try fighting boss with sword <3|Access denied message|Unit Tests|
|Boss Combat Mechanics|Fight boss with proper gear|Special combat mechanics active|Manual|
|Victory Rewards|Defeat boss|1000 gold awarded|Unit Tests|

### 8. Edge Case Testing

|**Test Case**|**Steps**|**Expected Result**|**Automation**|
|---|---|---|---|
|Max Resource Limits|Collect maximum resources|No overflow/crashes|Stress Test|
|Invalid Input Handling|Enter non-numeric shop inputs|Proper error handling|Unit Tests|
|Consecutive Actions|Rapid key presses|No input queue overflow|Stress Test|

### 9. Performance Testing

| **Test Case**       | **Steps**                    | **Expected Result**        | **Automation** |
| ------------------- | ---------------------------- | -------------------------- | -------------- |
| Memory Usage        | Long gameplay session        | No memory leaks (valgrind) | Automated      |
>>>>>>> docs
