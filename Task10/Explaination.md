# TASK 10 – COMPARE EXPECTATIONS WITH EXECUTION

## 1. Observed Precision Discrepancy Analysis

### 4,000 Bills (Village Scale)
* **Behavior:** The `long long` paise accumulator and the `double` accumulator match perfectly. The standard 32-bit `float` tracker exhibits tiny fractional tracking drift due to initial rounding limits at the lower significant decimal bounds.

### 60,000 Bills (Taluk Scale)
* **Behavior:** The single-precision `float` begins shedding precision visibly. Because a 32-bit float only carries 24 bits of mantissa precision (roughly 7 total digits), as the whole number segment expands, it drops trailing decimal precision, creating noticeable revenue leakage.

### 800,000 Bills (District Scale)
* **Behavior:** The tracking failure compounds severely. At 800,000 bills, the total reaches hundreds of millions of rupees. Because the total is so large, adding a single small bill (like ₹162.50) to the running `float` total fails entirely because the float cannot track such a vast scale difference, completely ignoring the new bill.

---

## 2. Integer Range and Standard Compliances
* **`int` and `long` Scales:** On modern standard 64-bit systems, a 32-bit `int` limits tracking capacity to ₹21,474,836.47 (stored as paise), which can risk overflow during cross-district tally sweeps. Utilizing a 64-bit `long long` provides a virtually infinite threshold ($2^{63}-1$), ensuring absolute security at any scale.
* **Standard Minimums:** The C standard guarantees that a `long` must be at least 4 bytes and a `long long` must be at least 8 bytes. Our system matches these requirements perfectly, validating long-term cross-platform deployment safety.

---

## 3. Alternative Concept & Complexity Analysis

### Alternative Approach
Accumulating large district totals within a 64-bit `double` variable instead of an integer-based `long long paise` array.

### Precision Loss and Performance Scaling Analysis
* **Time Complexity:** **$\mathcal{O}(1)$** hardware execution step for both datatypes. Standard CPU floating-point logic handles double registers rapidly in single cycles.
* **Space Complexity:** Consumes exactly **8 bytes** of storage space for both `double` and `long long` data primitives.
* **Accuracy Breakdown:** A `double` provides roughly 15 to 17 digits of significant decimal alignment precision. While it scales far better than a standard `float` without losing values at 800,000 entries, it still uses binary fractions to approximate base-10 decimals ($0.1_{10} \approx 0.000110011..._2$). Over millions or billions of transactional sweeps, this tiny binary fractional mismatch will still introduce rounding issues. Storing financial information in a `long long` structure keeps tracking mathematically flawless.
