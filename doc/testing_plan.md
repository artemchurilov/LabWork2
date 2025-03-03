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
