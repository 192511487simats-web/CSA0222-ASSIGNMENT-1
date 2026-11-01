# TASK 5 – STRUCTURAL MODULARIZATION AND COMPILATION BLOCKS

## 1. Structural C Program Layout Analysis
* **Header Files (`.h`):** Function as the interface declarations. They advertise prototypes, data structures, and macros without exposing execution implementations, hiding concrete logic from modules that include them.
* **Include Guards:** Blocks written using `#ifndef BILLING_H` prevent double-inclusion syntax anomalies. If a downstream target imports multiple headers that cross-reference each other, the guard halts symbol replication definitions.
* **Angle Brackets vs. Quotes:** `<file.h>` directs compilation toolchains straight to core standard system lookup paths (like `/usr/include`). `"file.h"` forces alternative lookup loops targeting your direct local workspace folders first.

## 2. Conditional Compilation Runtime Verification
By injecting `#ifdef DEBUG` checks, diagnostic tracing output print paths remain isolated. They trigger only if explicit macro switches are passed down through parameters during environmental tool steps (`-DDEBUG`).

## 3. Alternative Concept & Complexity Analysis
* **Alternative:** Managing tracing loops with runtime variable parameters (`if (debug_enabled) { ... }`).
* **Time Complexity:** 
  * `#ifdef DEBUG`: **$\mathcal{O}(0)$ runtime cost**. Production compilation runs strip trace operations completely before code reaches processing pools.
  * Runtime variable: **$\mathcal{O}(1)$ execution overhead**. The hardware pipeline evaluates conditional conditional evaluations continuously on active branches.
* **Space Complexity (Executable Binary Size):** Preprocessor guards isolate diagnostic text assets, yielding lightweight final footprints. Local programmatic conditional variables leave unused string arrays permanently locked into the code layout, creating bloat.
