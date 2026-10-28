# TASK 3 – DEFINE THE CONSTANTS

## 1. Aim

To define electricity tariff values as constants using preprocessor macros and implement a billing function that calculates the energy charge slab by slab.

## 2. Algorithm

1. Start the program.
2. Define the slab limits, rates and fixed charge using `#define`.
3. Initialise the bill with the fixed charge.
4. Calculate the energy charge according to the number of units consumed.
5. Add the energy charge to the fixed charge.
6. Return the total bill in paise.
7. Convert the amount into rupees and paise for display.
8. Stop the program.

## 3. Input

The program uses the following predefined test values.

| Test | Units consumed |
| ---- | -------------: |
| 1    |              0 |
| 2    |            100 |
| 3    |            150 |
| 4    |            200 |
| 5    |            350 |

## 4. Expected Output

```text
  0 units -> Rs 50.00
100 units -> Rs 50.00
150 units -> Rs 162.50
200 units -> Rs 275.00
350 units -> Rs 950.00
```

## 5. Explanation

The program defines all tariff values at the beginning using `#define`. The function `compute_bill()` begins with the fixed charge of 5000 paise, equivalent to ₹50.

The first 100 units are charged at 0 paise per unit. Units from 101 to 200 are charged at 225 paise per unit. Units above 200 are charged at 450 paise per unit.

For 150 units:

Energy charge = (150 − 100) × 225 = 11250 paise.

Total bill = 5000 + 11250 = 16250 paise = ₹162.50.

For 350 units:

Energy charge = (100 × 225) + (150 × 450) = 90000 paise.

Total bill = 5000 + 90000 = 95000 paise = ₹950.00.

## 6. Difference Between `#define`, `const` and `enum`

### `#define`

A preprocessor macro replaces its name with the specified value before compilation. It does not have a C data type and does not itself allocate storage.

### `const`

A `const` object has a type and cannot be modified through that identifier. It is checked by the compiler and can be easier to inspect during debugging.

### `enum`

An enumeration defines named integer constants. It is suitable for representing a limited set of named options, such as consumer categories.

## 7. Naming Conventions

Constant names are written in uppercase letters with underscores between words. Examples include `RATE2_PAISE`, `SLAB1_UNITS` and `FIXED_CHARGE_PAISE`.

These names make the purpose of each tariff value clear.

## 8. Alternative Concept and Complexity Analysis

The tariff values could instead be represented by `const` variables. This would provide type information and compiler checking. An `enum` could be used for named integer options, but it is not the most appropriate choice for fractional monetary rates.

Using `#define` avoids repeated tariff values throughout the program and allows a revision to be made in one place. Using `const` can improve type checking and debugging.

The choice between macros and constants generally does not change the billing function's asymptotic running time. The billing function uses a fixed number of calculations, so its time complexity is O(1), and its auxiliary space complexity is O(1).

## 9. Result

The program calculates electricity bills using centrally defined tariff macros. The expected results confirm that the fixed charge and slab-wise energy charges are combined correctly for the five test cases.
