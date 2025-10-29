# CSI2372 — Week 8 Lab Handout

**Topic:** Exception Safety • RAII • Templates • Concepts • File I/O • Resource Management  
**Course:** Advanced Programming Concepts with C++ (Fall 2025, uOttawa)

---

## 1. Overview

In this lab, you will integrate your understanding of C++ exception safety, RAII, templates, and compile-time type analysis.  
You will implement multiple modular components that demonstrate resource management, template-based abstractions, and concept-driven constraints.

The lab consists of four tasks:

- **Result<T, E>** – header-only generic result type; you will implement the methods using TODO hints.    
- **Expression Evaluator Library** — simple parsing and computation
- **Statistics Library** — static library structure with encapsulation and debug flags 
- **Text Utility Library** — header/source separation with preprocessor-controlled logging 

All work is autograded via CI/CTest.  
When the GitHub Actions build is green, you earn full marks.

---

## 2. Learning Objectives

By the end of this lab, you should be able to:
 
- Use C++ templates and concepts to write type-safe generic code.  
- Apply **header/source separation** and respect the *One Definition Rule (ODR)*.  
- Use **namespaces** to organize code logically and prevent symbol conflicts.  
- Employ **conditional compilation** (`#ifdef`, `#define`) to toggle debug or logging features.  
- Design **static library–style** code that exposes a small, stable API and hides implementation details.  
- Utilize **structs, enums, and classes** effectively to build clear, testable components.  
- Implement safe, minimal, and modular C++ code that supports automated testing.


---

## 3. Task A — Result<T, E>

### Description
You are given a **header-only template class** `Result<T, E>` similar to Rust’s Result. **No `.cpp` file is used; all implementations must be written in `Result.hpp`.**

### Required Behavior
- Represents either a success (`T`) or an error (`E`).  
- The header file `Result.hpp` contains **TODO comments** explaining what to implement.  
- Implement all methods yourself:
  - `static Result<T, E> Ok(const T& value);` — create a success result.  
  - `static Result<T, E> Err(const E& error);` — create an error result.  
  - `bool is_ok() const noexcept;` — check if the result is success.  
  - `bool is_err() const noexcept;` — check if the result is an error.  
  - `T unwrap() const;` — return success value; throw `std::runtime_error` if this is an error.  
  - `E unwrap_err() const;` — return error value; throw `std::runtime_error` if this is a success.  
- Internally, use `std::variant<T, E>` to store the value.  
- Ensure exception safety when accessing variants.

### Concepts Covered
Class templates, std::variant, error modeling, safe value access, exception propagation.

---

## 4. Task B — Expression Evaluator Library

### Description
You will implement a small C++ library that parses and evaluates arithmetic expressions given as strings.  
The program must tokenize input, perform sequential evaluation, and summarize the result.

### Required Behavior
- Implement the following functions inside namespace `csi::expr`:
  - `Operator parse_operator(const std::string&)`  
    → Convert `"+"`, `"-"`, `"*"`, `"/"` to the corresponding enum; otherwise return `Unknown`.  
  - `Expression parse_expression(const std::string&)`  
    → Tokenize numeric and operator elements into an `Expression` object.  
  - `double evaluate(const Expression&)`  
    → Apply operations **left to right** (ignore operator precedence).  
    → On division by zero, return `0`.  
  - `std::string summarize(const Expression&)`  
    → Return a formatted report:  
      `"Expression with N operations, final result = X"`

### Concepts Covered
- Header/source separation  
- Enums and structs  
- String parsing and tokenization  
- Namespace encapsulation  
- Safe arithmetic evaluation  

---

## 5. Task C — Statistics Library (Static Library Style)

### Description
In this task, you will create a **small statistics utility library** designed for static linking.  
You will combine helper functions and a class into a cleanly separated `.hpp`/`.cpp` pair.  
The library should support debug output via **conditional compilation**.


### Required Behavior
Implement inside namespace `mathlib::stats`:

- `double mean(const std::vector<double>& nums);`  
  → Return the average; `0.0` if empty.  

- `double variance(const std::vector<double>& nums);`  
  → Compute average of squared differences using `mean()`. Return `0.0` if fewer than 2 elements.  

- `std::optional<double> find_max(const std::vector<double>& nums);`  
  → Return `std::nullopt` if empty; otherwise the largest value.  

- **Class `Stats`**
  - Constructor: `Stats(const std::vector<double>& data);`
  - Method: `std::string summary();`  
    → Return `"mean=..., variance=..., max=..."`  
    → When `DEBUG_MODE` is defined, also print:  
      ```
      [DEBUG] Computing summary for N elements
      ```

### Concepts Covered
- Static library architecture  
- Conditional compilation (`#define DEBUG_MODE`)  
- Optional values and safety  
- Encapsulation in classes  
- Namespace hygiene  

---

## 6. Task D — Text Utility Library (Header/Source Separation & Preprocessor Logic)

### Description
This final exercise reinforces modular text processing and preprocessor-based configuration.  
You will implement utility functions that transform and summarize text collections.  
Logging is controlled by the compile-time flag `ENABLE_LOG`.


### Required Behavior
Implement inside namespace `textlib::util`:

- `std::string to_upper(const std::string& input);`  
  → Convert all alphabetic characters to uppercase using `std::transform`.

- `std::optional<std::string> find_longest(const std::vector<std::string>& words);`  
  → Return `std::nullopt` if empty; otherwise, the longest string.

- `std::string join(const std::vector<std::string>& words, char sep);`  
  → Concatenate words separated by `sep` (no trailing separator).

- `void log_summary(const std::vector<std::string>& words);`  
  → If `ENABLE_LOG` is defined, print:  
    ```
    [LOG] Count: X, Longest: Y
    ```
    Otherwise, do nothing.

- `std::string summary(const std::vector<std::string>& words);`  
  → Always call `log_summary(words)` internally.  
  → Return `"Count=X, Longest=Y"`, or `"Count=0, Longest=N/A"` if empty.

### Concepts Covered
- Header/source separation  
- Conditional compilation (`#ifdef ENABLE_LOG`)  
- Optional values  
- Text processing utilities  
- Reusable library design  

---

## 7. Building and Running

Recommended workflow:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```
CI/CTest runs automatically when you push.
All tests must pass for full credit.

## 8. Grading
100% autograded: your score = proportion of passing tests.

No manual grading.
