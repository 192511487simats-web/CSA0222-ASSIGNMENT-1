# TASK 6 – FORMATTED INPUT/OUTPUT AND INPUT VALIDATION

## 1. Standard C Format Specifiers Reference Table

| Data Type | Format Specifier | Technical Application |
| :--- | :--- | :--- |
| `int` | `%d` | Signed base-10 integer numbers |
| `unsigned int` | `%u` | Unsigned base-10 integer numbers |
| `long` | `%ld` | Signed long integer (used for intermediate billing paise) |
| `long long` | `%lld` | Signed widest integer format (used for district totals) |
| `float` | `%f` | Single-precision floating point number |
| `double` | `%lf` | Double-precision floating point number |
| `char` | `%c` | Single text character symbol |
| `char[]` (String) | `%s` | Character array continuous text blocks |

### Format Specifier Mismatch Consequences
If a mismatched format specifier is paired with an alternate data type size (such as using `%d` to print a 64-bit `long`), the compiler extracts an incorrect width of bytes from the program stack layout. This results in binary parsing shifts, memory misalignments, or printing random garbage values.

### Robust Input Verification Via `scanf` Return Checks
`scanf()` evaluates and returns an integer corresponding directly to the number of data fields it successfully captured, converted, and stored. If a program expects a numeric digit (`%d`) but the user types characters like `"invalid"`, `scanf` fails to match the field and returns `0`. By verifying if `scanf(...) != 1`, the program can immediately catch garbage data, abort gracefully, and protect against infinite parsing loop corruptions.

---

## 2. Alternative Concept & Complexity Analysis

### Alternative Approach
Reading raw console strings using `fgets()` into a buffer array first, then processing the string inputs downstream via standard runtime parsers like `sscanf()` or `strtol()`.

### Complexity Metrics Grid
* **Time Complexity:** **$\mathcal{O}(L)$** where $L$ represents the length of the incoming line character string array. The system passes over each index to copy it into a stream buffer before converting characters to integers.
* **Space Complexity:** Requires a static local stack allocation footprint (e.g., a buffer configuration array requiring a flat **256 bytes** of stack storage).

### Error Recovery Comparison
`fgets()` is highly superior to raw `scanf()` for live user input. When a user enters alphanumeric mistakes or presses Enter unexpectedly, raw `scanf()` can leave the unparsed text sitting in the stdin buffer indefinitely, causing infinite loops if called inside a program loop. `fgets()` completely drains the line out of the input buffer in a single transaction, leaving the terminal clean for successive user prompts.
