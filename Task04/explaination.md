TASK 04 – USE MACROS SAFELY

Aim

To implement C macros for repeated calculations, examine their expansion using the preprocessor, identify common macro pitfalls, and compare macros with static inline functions.

Algorithm

Define a macro to convert rupees into paise.

Define a square macro with parentheses around its parameter and the complete expression.

Define a macro to find the maximum of two values.

Define equivalent static inline functions for square and maximum calculations.

Execute the program and observe the results.

Preprocess the program using gcc -E and inspect the expanded expressions.

Explain the limitations of macros and compare their time and space costs with inline functions.

Input

The program uses the following test values:

Rupees: 50

First integer: 5

Second integer: 8

Increment test value: 3

Expected Output

Rupees to paise: 5000 Square of a + 1: 36 Maximum of a and b: 8 Square using inline function: 36 Maximum using inline function: 8 

The output involving MAX(i++, b) is not guaranteed because the macro can modify i without a defined evaluation order. Its actual result must not be relied upon.

Macro Expansion

The C preprocessor replaces macro invocations with their replacement text before compilation.

For example:

#define RUPEES_TO_PAISE(rupees) ((rupees) * 100) 

The invocation:

RUPEES_TO_PAISE(50) 

expands to:

((50) * 100) 

The command gcc -E main.c -o preprocessed.txt generates the preprocessed source for inspection.

Why Parentheses Are Necessary

An unsafe square macro is:

#define SQUARE(x) x*x 

For SQUARE(a + 1), the replacement is a + 1*a + 1. If a is 5, this evaluates to 11 rather than 36.

The safer macro is:

#define SQUARE(x) ((x) * (x)) 

This correctly groups the argument and the multiplication.

Repeated Evaluation in MAX

The macro:

#define MAX(a, b) (((a) > (b)) ? (a) : (b)) 

may evaluate one argument twice. Passing i++ can modify the variable more than once. In this example, the macro invocation can cause undefined behavior because the same variable is modified without a defined sequencing order.

Therefore, macro arguments should not contain side effects. A function is generally safer when arguments may be evaluated or modified.

When to Use a Function

A function is preferable when type checking, predictable argument evaluation, debugging, or avoiding repeated evaluation is important.

A static inline function provides a function-like interface and allows the compiler to inline the calculation when appropriate. However, the C language does not guarantee that the compiler will inline every call.

Alternative Concept and Complexity Analysis

Static Inline Functions

The macros can be replaced with:

static inline int square_function(int x) { return x * x; } static inline int max_function(int a, int b) { return (a > b) ? a : b; } 

These functions evaluate each argument expression once when called, before entering the function. They avoid the repeated-evaluation problem demonstrated by MAX(i++, b).

Time Complexity

Macro calculation: O(1) for these fixed arithmetic expressions.

Inline-function calculation: O(1) for these fixed arithmetic expressions.

A function call may have call overhead if the compiler does not inline it. The compiler may remove that overhead when it optimizes the code.

Space Complexity

If a macro is used k times, its replacement code is expanded at every use, which can increase the size of the compiled program.

A function provides one function definition that can be called from multiple locations. If the compiler inlines it, the generated code may also be duplicated. Actual executable size depends on compiler optimization.

Result

The macros and corresponding inline functions were implemented. The square macro demonstrates why parentheses are required, while the maximum macro demonstrates the risk of repeated evaluation. Preprocessor output was generated for inspection using gcc -E.

