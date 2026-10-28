# TASK 1 – UNDERSTAND THE PROBLEM AND IDENTIFY THE DATA

## 1. Aim

To analyse the electricity billing problem and identify the inputs, outputs, constants, variables, validation rules and assumptions required to develop a reliable billing program in C.

## 2. Problem Analysis

Grama Jyothi Rural Electricity Co-operative bills approximately 4,000 households every month. The program uses the previous and current electricity meter readings to calculate units consumed. It then calculates the energy charge according to the consumption slabs and adds a fixed charge to determine the total bill.

The program must prevent incorrect bills, handle meter rollover correctly, and calculate monetary values accurately. It should also support expansion from a village to a taluk or district.

## 3. Input Data

| Input                  | Description                              | Reason                                           |
| ---------------------- | ---------------------------------------- | ------------------------------------------------ |
| Previous meter reading | Reading from the previous billing period | Required to calculate consumption                |
| Current meter reading  | Reading from the current billing period  | Required to calculate consumption                |
| Household number       | Identifies the household                 | Ensures the bill belongs to the correct consumer |
| Consumer category      | Category of the household                | Can support category-specific rules if required  |

The tariff values are predefined for the original billing program.

## 4. Output Data

| Output         | Description                                    |
| -------------- | ---------------------------------------------- |
| Units consumed | Electricity consumed during the billing period |
| Energy charge  | Charge calculated using the consumption slabs  |
| Fixed charge   | Fixed amount added to the bill                 |
| Total bill     | Sum of the energy charge and fixed charge      |

**Total Bill = Energy Charge + Fixed Charge**

## 5. Constants and Variables

### Constants

| Constant             | Value | Purpose                              |
| -------------------- | ----: | ------------------------------------ |
| `SLAB1_UNITS`        |   100 | Limit of the first consumption slab  |
| `SLAB2_UNITS`        |   200 | Limit of the second consumption slab |
| `RATE1_PAISE`        |     0 | Rate per unit for the first slab     |
| `RATE2_PAISE`        |   225 | Rate per unit for the second slab    |
| `RATE3_PAISE`        |   450 | Rate per unit above 200 units        |
| `FIXED_CHARGE_PAISE` |  5000 | Fixed charge of ₹50                  |

These values should be defined in one place so that tariff revisions can be applied consistently.

### Variables

The previous reading, current reading, units consumed, energy charge and total bill are variables because their values depend on the household and its electricity consumption.

The household number and consumer category are also variable inputs.

## 6. Negative, Fractional and Large Values

**Negative values:** Meter readings and electricity consumption must not be negative. Invalid negative readings must be rejected. The total bill must never be negative.

**Fractional values:** Electricity charges may contain paise. Monetary values should be stored as integer paise to avoid floating-point representation errors.

**Large values:** The total amount accumulated across hundreds of thousands of households can be large. A sufficiently wide integer type, such as `long long`, should be considered for accumulated totals.

**Meter rollover:** The meter is a 16-bit counter with a maximum reading of 65535. After reaching this value, it rolls over to 0. The program must calculate consumption correctly when this occurs.

## 7. Rules for a Correct Bill

1. Meter readings must be within the range 0 to 65535.
2. Consumption must be calculated correctly, including meter rollover.
3. The first 100 units are free.
4. Units from 101 to 200 cost ₹2.25 per unit.
5. Units above 200 cost ₹4.50 per unit.
6. A fixed charge of ₹50 must be added.
7. The total bill must equal the energy charge plus the fixed charge.
8. The bill must never be negative.
9. Monetary calculations should use integer paise.
10. Invalid input must be detected and handled appropriately.

## 8. Assumptions

1. Each household has a valid identification number.
2. The meter uses a 16-bit register with a maximum reading of 65535.
3. The billing period is monthly.
4. The first 100 units are free, the next 100 units cost ₹2.25 per unit, and units above 200 cost ₹4.50 per unit.
5. The fixed charge is ₹50 per household.
6. Tariff values remain unchanged during a program run.
7. Bills are calculated for individual households, while totals may be accumulated for many households.
8. No category-specific discount is assumed because the assignment does not specify one.

## 9. Alternative Concept: Store Meter Readings as Text

Meter readings could be stored as character strings instead of integers. For example, the reading 1530 could be stored as `"01530"`.

When readings are stored as fixed-width integers, comparison and arithmetic generally take O(1) time. Each reading also occupies a fixed amount of memory.

When readings are stored as text, the program must convert the strings into numbers before performing arithmetic. If a reading contains `d` digits, conversion and comparison may require O(d) time. Each text reading requires O(d) space, including the terminating null character.

| Feature                      | Integer representation        | Text representation           |
| ---------------------------- | ----------------------------- | ----------------------------- |
| Example                      | `1530`                        | `"01530"`                     |
| Conversion before arithmetic | Not required                  | Required                      |
| Comparison time              | O(1) for fixed-width integers | Up to O(d)                    |
| Storage per reading          | Fixed size                    | Proportional to string length |
| Leading zeros                | Not preserved                 | Preserved                     |
| Arithmetic                   | Direct                        | Requires conversion           |

Integer representation is more suitable for electricity billing because it supports direct arithmetic, efficient comparison and straightforward meter rollover calculations. Text representation is useful when preserving the original formatting, including leading zeros, is important.

## 10. Result

The problem analysis identifies the data needed for reliable electricity billing. Suitable constants, appropriate data types, input validation and integer-paise calculations help prevent incorrect bills and support future expansion of the billing system.
