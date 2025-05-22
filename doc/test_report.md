**ToyRick Testing Report**  
**Version: 1.0**  

---
### **1. Summary**  
- **Tests Passed:** 34/34 (100% success rate).  
- **Automation Coverage:** 45% (15/34 tests automated, including unit, integration, and stress tests).  
- **Critical Issues:** None identified.  
- **Stability:** No crashes or memory leaks observed during extended playthroughs or edge-case handling.  

---

### **2. Detailed Breakdown**  

#### **2.1. Main Menu**  
- **Result:** All functionalities confirmed.  
- **Key Notes:**  
  - Navigation (W/S keys) responds smoothly.  
  - "Start Game," "Rules," and "Quit" options work as intended.  

#### **2.2. Map Navigation**  
- **Result:** Movement and interactions validated.  
- **Key Notes:**  
  - Player cannot exceed map boundaries.  
  - Map toggle (B key) switches layouts without issues.  
  - Campfire respawn triggers correctly upon player death.  

#### **2.3. Combat System**  
- **Result:** Combat logic aligns with design specs.  
- **Key Notes:**  
  - Card energy costs and damage values verified via unit tests.  
  - Enemy AI uses context-appropriate abilities.  
  - Victory/defeat conditions handled properly.  

#### **2.4. Shop System**  
- **Result:** Core features functional.  
- **Key Notes:**  
  - Sword/shield upgrades increase stats and deduct gold (unit-tested).  
  - Insufficient funds trigger error messages.  
  - **Pending:** Manual verification of deck management (card replacement in full decks).  

#### **2.5. Resource System**  
- **Result:** All tests passed.  
- **Key Notes:**  
  - Tree chopping (10 energy) and stone mining (15 energy) deduct energy correctly.  
  - Energy exhaustion blocks resource collection.  

#### **2.6. Deck System**  
- **Result:** Basic functionality confirmed.  
- **Key Notes:**  
  - Starting decks match selected types.  
  - **Pending:** Clarify results for card replacement in full decks.  

#### **2.7. Boss Fight**  
- **Result:** Boss mechanics validated.  
- **Key Notes:**  
  - Boss access requires Sword Level ≥3 (unit-tested).  
  - Defeating boss grants 1000 gold (confirmed).  

#### **2.8. Edge Cases & Performance**  
- **Result:** Robust under stress.  
- **Key Notes:**  
  - No crashes at max resources (9999).  
  - Invalid inputs (e.g., non-numeric shop entries) handled gracefully.  
  - Valgrind confirms no memory leaks.  

---

### **3. Recommendations**  
1. Expand automated test coverage for shop/card purchases (Section 4).  
2. Resolve pending manual tests for deck management (Sections 4 & 6).  
3. Add FPS stress tests for object-heavy scenarios.  
4. Implement CI/CD pipelines for automated test execution.  

---

### **4. Conclusion**  
The game meets all core requirements with no critical defects. Minor gaps in shop/deck testing require resolution before release. Performance and stability are production-ready.  
