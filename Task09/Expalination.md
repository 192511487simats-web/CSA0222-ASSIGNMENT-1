# TASK 9 – IMPLEMENT AND TEST THE BILLING PROGRAM

## 1. Verified Quality Assurance Test Matrix

| Test Scenario Case | Input Parameters Provided | Expected Program Output Behavior | Observed Verification Status |
| :--- | :--- | :--- | :--- |
| **Slab 1 Bound Check** | ID: 101, Prev: 1000, Curr: 1100 | Consumption: 100 units $\rightarrow$ Rs 50.00 | Match / Complete |
| **Slab 2 Mid Check** | ID: 102, Prev: 1000, Curr: 1150 | Consumption: 150 units $\rightarrow$ Rs 162.50 | Match / Complete |
| **Slab 3 Boundary** | ID: 103, Prev: 1000, Curr: 1350 | Consumption: 350 units $\rightarrow$ Rs 950.00 | Match / Complete |
| **Zero Base Boundary**| ID: 104, Prev: 5000, Curr: 5000 | Consumption: 0 units $\rightarrow$ Rs 50.00 | Match / Complete |
| **Hardware Rollover** | ID: 105, Prev: 65400, Curr: 120 | Consumption: 256 units $\rightarrow$ Rs 527.00 | Match / Complete |
| **Alphanumeric Filter**| ID: "ABC" | Immediate trigger termination code [ERROR] | Match / Complete |
| **Invalid Reverse Dial**| ID: 106, Prev: 1500, Curr: 1400 | Discards calculation step, throws error block | Match / Complete |

---

## 2. Alternative Concept & Complexity Analysis

### Alternative Approach
Storing tier parameters, limits, and matching rate boundaries directly inside paired contiguous lookup arrays and processing calculation iterations dynamically using loops instead of conditional logic blocks.

### Performance Scaling Metrics
* **Time Complexity:** 
  * Fixed Conditional Layout: **$\mathcal{O}(1)$**. Executes a rigid sequence of maximum 2 test checks.
  * Array Iteration Loop: **$\mathcal{O}(s)$** where $s$ tracks the total count of operational slabs configured. The loop iterates through memory slots to locate limits.
* **Space Complexity:** Consumes fractional heap memory storage elements to bind arrays containing configurations ($\mathcal{O}(s)$ tracking storage vs $\mathcal{O}(1)$ text definitions).
* **Design Maintainability Tradeoff:** Array layouts are vastly superior for enterprise scaling. If structural rules expand to 10 nested tiers, a static loop routine functions cleanly without modifying codebase layers, needing only simple configuration changes.
