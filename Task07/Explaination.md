# TASK 7 – CONTROL TYPE CONVERSION AND PRECISION

## 1. Core Conversion Definitions
* **Implicit Conversion:** Automatic type conversions executed silently by the compiler when evaluating expressions containing mixed types. This follows rules for integer promotion (e.g., promoting a `short` to an `int`) and usual arithmetic conversions (matching the lower type to the higher, wider type like `int` to `double`).
* **Integer Division:** When dividing two integers, C drops all fractional decimal parts entirely. It does not round to the nearest whole number; it truncates towards zero.
* **Explicit Casting:** Explicitly forcing a variable conversion by prefixing it with a type parenthetical label (e.g., `(double)x`). 

---

## 2. Explanation of Demonstrated Surprises

### Surprise 1: Truncation in `units / 100`
* **Why it happens:** Because both `units` and `100` are integers, the expression evaluates to an integer value (`1`). Only *after* the truncation occurs is the value upgraded to a `double` configuration for assignment, hiding the `.50` permanently.
* **Resolution:** Explicitly casting the numerator via `(double)units / 100` converts the first operator to a double floating point context, forcing C to use floating point division rules.

### Surprise 2: Unsigned Arithmetic Wrapping
* **Why it happens:** Unsigned types cannot express negative numbers. When computing `100 - 200`, the math rolls backward past zero, wrapping directly to the absolute highest limit of a 32-bit integer ($2^{32} - 100 = 4,294,967,196$).

### Surprise 3: Large Type Demotion
* **Why it happens:** A standard 32-bit signed `int` can only scale up to a maximum value of `2,147,483,647`. Attempting to jam a `long long` holding 5 Billion down into an integer container drops the upper high-order bytes entirely, leaving behind corrupted, truncated junk data.

---

## 3. Alternative Concept & Complexity Analysis

### Alternative Approach
Performing all calculations entirely within `float` representations, and rounding the final grand total only once at the very end of processing.

### Complexity Metrics & Scaling Evaluation
* **Time Complexity:** **$\mathcal{O}(1)$** for additions in both approaches. However, floating-point units (FPUs) inside CPUs execute addition operations with slightly higher cycle latencies than standard hardware integer execution modules.
* **Space Complexity:** Both layouts consume fixed variables (4 bytes for standard single `float` vs 4 bytes for standard signed integer `long`).
* **Error Growth Analysis:** Storing intermediate states as `float` variables forces an error growth profile that scales directly with the number of bills $n$. Because a `float` maintains flat precision across roughly 7 decimal digits, accumulating 800,000 bills sequentially results in catastrophic precision dropping. Small individual house additions will get ignored by the running total. Relying on whole-integer paise completely isolates precision bugs out of the architecture across any processing volume.
