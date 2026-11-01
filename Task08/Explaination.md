# TASK 8 – TRACE THE COMPILATION PROCESS

## 1. Compilation Stage Output Taxonomy
* **Preprocessing (`gcc -E` $\rightarrow$ `main.i`):** The preprocessor handles direct text modifications. It fully expands macros (swapping `TEST_UNITS` with literal text values), evaluates conditional directives (`#ifdef`), and copies the full contents of header definitions (`<stdio.h>`) into the stream while stripping white-space and code comments.
* **Compilation (`gcc -S` $\rightarrow$ `main.s`):** The compiler takes the preprocessed `.i` text file, performs syntactic checking, and translates the high-level C structural statements down into architecture-specific Assembly code.
* **Assembly (`gcc -c` $\rightarrow$ `main.o`):** The assembler converts human-readable assembly instructions into unlinked binary Machine Code (Object files). These files contain instruction opcodes and raw tables but cannot be executed by the operating system yet because standard library reference paths remain unresolved.
* **Linking (`gcc` $\rightarrow$ `main.exe`):** The linker stitches individual `.o` object files together along with external system library binaries (like standard I/O runtime code), configures the memory map segments, and generates a valid standalone executable file.

---

## 2. Compilation Error Classifications

| Error Category | Diagnostic Phase | Core Definition | Concrete Project Example |
| :--- | :--- | :--- | :--- |
| **Compile-Time Error** | Preprocessor / Compiler | Syntax violations, typo anomalies, or structural misuse that breaks formal syntax layout rules. | Forgetting a terminating semicolon `;` at the end of a variable assignment expression. |
| **Link-Time Error** | Linker | Triggered when functions or objects are declared but the structural definition symbols are missing. | Calling `compute_bill(100)` when `billing.c` was left out of the list of files passed to `gcc`. |
| **Run-Time Error** | OS Runtime Execution | Code passes layout validations cleanly but triggers critical hardware or system state violations during live operation. | Executing a division operation where the denominator evaluates to zero, causing a mathematical crash. |

### GCC Warning Mitigations (`-Wall -Wextra`)
Enabling `-Wall -Wextra` flags forces the compiler to report subtle style issues or logic flaws (such as uninitialized variables or data type signed-width comparisons). Fixing all warnings ensures code safety and long-term maintainability.

---

## 3. Alternative Concept & Complexity Analysis

### Alternative Approach
Splitting the billing system into separate multiple translation units (`input.c`, `tariff.c`, `report.c`) linked via a common internal header file, rather than managing everything inside one codebase file.

### Compilation Performance Scaling Analysis
* **Full Recompilation Cost:** If everything sits inside a single source file, any code change requires compiling the entire file from scratch. The compile time scales linearly with the total line volume.
* **Incremental Separate Compilation Strategy:** Splitting modules allows the system to utilize incremental builds via build scripts or Makefiles. If a developer edits a rule inside `tariff.c`, *only* `tariff.c` needs to be recompiled into an object file (`tariff.o`). The remaining modules are skipped, and the linker stiches the existing object files together instantly. This drastically reduces developer iteration delays, optimizing development speed down from $O(N)$ total lines to $O(1)$ local change blocks.
