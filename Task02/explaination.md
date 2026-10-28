# TASK 2 – CHOOSE THE DATA TYPES

## 1. Aim

To select appropriate C data types for meter readings and monetary calculations and to implement unsigned arithmetic to handle meter rollover correctly.

## 2. Algorithm

1. Start the program.
2. Define `meter_t` as `unsigned short`.
3. Create the `consumption()` function to calculate the difference between two meter readings.
4. Display the size and maximum value of the meter data type.
5. Calculate consumption for normal meter readings.
6. Calculate consumption for a meter rollover.
7. Display the results.
8. Stop the program.

## 3. Input

The program uses predefined test values.

| Previous Reading | Current Reading | Condition      |
| ---------------: | --------------: | -------------- |
|             1200 |            1530 | Normal reading |
|            65400 |             120 | Meter rollover |

## 4. Expected Output

```text
sizeof(meter_t) = 2 bytes, maximum reading = 65535
Consumption: 330 units
Consumption: 256 units
```

This is the expected output specified in the assignment. It assumes that `unsigned short` occupies 2 bytes on the target system.

## 5. Data-Type Analysis

| Data item                           | Suggested data type          | Reason                                                 |
| ----------------------------------- | ---------------------------- | ------------------------------------------------------ |
| Previous reading                    | `meter_t` (`unsigned short`) | Represents the 16-bit meter register                   |
| Current reading                     | `meter_t` (`unsigned short`) | Stores a reading from 0 to 65535                       |
| Units consumed                      | `unsigned int`               | Stores non-negative consumption                        |
| Household number                    | Suitable integer type        | Identifies a household                                 |
| Energy charge                       | `long long`                  | Stores monetary amounts in paise                       |
| Fixed charge                        | `long long`                  | Stores the fixed charge in paise                       |
| Total bill                          | `long long`                  | Supports larger accumulated totals                     |
| Floating-point experiment           | `float`                      | Used to demonstrate rounding errors                    |
| Alternative monetary representation | `double`                     | Provides greater floating-point precision than `float` |

The actual sizes and ranges of the types should be verified using `sizeof`, `<limits.h>` and `<float.h>` on the compiler used.

## 6. Why Money Should Be Stored as Integer Paise

Floating-point types cannot represent every decimal fraction exactly. Consequently, repeated monetary calculations may introduce small rounding errors.

Instead, store money as integer paise. For example:

₹162.50 = 16250 paise.

Integer-paise arithmetic avoids floating-point representation errors for monetary amounts expressed in whole paise.

## 7. Explanation of Meter Rollover

For the first test:

Previous reading = 1200
Current reading = 1530

Consumption = 1530 − 1200 = 330 units.

For the second test, the meter rolls over after reaching 65535.

Previous reading = 65400
Current reading = 120

Consumption = (65535 − 65400) + 1 + 120

Consumption = 135 + 1 + 120

Consumption = 256 units.

The unsigned 16-bit result wraps around modulo 65536, producing 256 rather than a negative number.

## 8. Alternative Concept: Double Rupees

An alternative is to store monetary values as `double` rupees rather than integer paise. The program would calculate charges in rupees and round to two decimal places when producing the bill.

However, floating-point values may introduce representation and rounding errors. When many bills are added, these errors can accumulate. Integer paise avoids these representation errors for values expressed in whole paise.

Both approaches perform an individual addition in O(1) time and use a fixed amount of memory per value. The exact storage size depends on the implementation.

## 9. Result

The program calculates normal consumption as 330 units and rollover consumption as 256 units. The results demonstrate the use of unsigned arithmetic for handling a 16-bit meter register rollover.
