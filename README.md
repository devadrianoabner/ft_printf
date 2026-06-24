*This project has been created as part of the 42 curriculum by adrianda.*

# ft_printf

## Description

`ft_printf` is a custom C library (`libftprintf.a`) that mimics the behavior of the
standard C library `printf` function.

The primary goal of this project is to learn how to implement and manage variadic
functions in C using `va_list`, `va_start`, `va_arg`, and `va_end`. It also reinforces
robust memory management, defensive programming against edge cases (such as NULL
pointers and extreme integer limits), and strict adherence to the 42 Norm.

### Supported Conversions

| Specifier | Description                    |
|-----------|--------------------------------|
| `%c`      | Single character               |
| `%s`      | String                         |
| `%p`      | Pointer address (hexadecimal)  |
| `%d`      | Decimal integer                |
| `%i`      | Integer                        |
| `%u`      | Unsigned integer               |
| `%x`      | Lowercase hexadecimal          |
| `%X`      | Uppercase hexadecimal          |
| `%%`      | Literal percent sign           |

---

## Instructions

### Build

From the project root:

| Command      | Effect                                                    |
|--------------|-----------------------------------------------------------|
| `make`       | Compiles the sources, builds libft, and creates `libftprintf.a` |
| `make clean` | Removes the object files (`.o`)                          |
| `make fclean`| Removes the object files and `libftprintf.a`             |
| `make re`    | Runs `fclean`, then `make`                               |

### Use in Another Project

Include the header in your source code:

```c
#include "ft_printf.h"
```

Compile your program, linking the library:

```bash
cc your_file.c libftprintf.a -o your_program
```

---

## Algorithms and Data Structures

To ensure high performance, security, and clean code, this implementation relies on
specific architectural choices rather than standard procedural checks.

### O(1) Dispatch Table

Instead of using a long, slow chain of `if/else if` statements to determine the correct
conversion format, the project uses an **Array of Function Pointers**
(`t_handler dispatch[256]`).

**How it works:** The ASCII value of the format specifier character (e.g., `'x'` = 120)
serves as the direct index for the array. Unused indices are safely zeroed out (`NULL`)
using `ft_bzero`.

**Justification:** This guarantees **O(1) time complexity** for routing. It completely
decouples the parsing logic from the conversion logic, making the system highly scalable
(adding a new conversion requires only one new line in the array) and inherently prevents
segmentation faults when encountering invalid flags by gracefully ignoring them.

### Zero-Allocation Mathematical Recursion

For number and pointer conversions (`%d`, `%u`, `%x`, `%X`, `%p`), the algorithm
strictly avoids dynamic memory allocation (`malloc`).

**How it works:** Numbers are converted to the requested base (10 or 16) mathematically
and printed directly to standard output using recursive `write` calls. Extreme values
such as `INT_MIN` or memory addresses are handled safely via `long long` and
`unsigned long long` type casting.

**Justification:** This approach eliminates the risk of memory leaks entirely and reduces
the overhead of dynamic allocation, resulting in a faster, safer, and self-contained
execution.

---

## Resources

### References

- [Linux man pages, section 3](https://man7.org/linux/man-pages/man3/printf.3.html) —
  Reference behavior for the original functions (`man 3 printf`, `man 3 stdarg`)
- [42's Norm documentation (norminette)](https://github.com/42School/norminette) —
  The coding-style rules enforced throughout the project

### AI Usage

AI was utilized primarily as a **Socratic mentor** to understand underlying C concepts
and architecture, rather than as a code generator. Specific tasks included:

- **Recursion Debugging:** Identifying a logical trap where the `0x` prefix for the `%p`
  conversion was being duplicated due to being placed inside the recursive counting
  function instead of the parent handler.
- **Memory Management & Undefined Behavior:** Discussing the exact placement of `va_end`
  to prevent memory leaks when breaking out of loops due to invalid format syntax
  (e.g., an isolated `%` at the end of a string).
- **Architecture Validation:** Validating the safety of the `dispatch[256]` array
  approach and understanding how `gcc` handles Undefined Behavior for invalid flags
  natively versus at runtime.