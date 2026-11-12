*This project has been created as part of the 42 curriculum by yabaadi*.

# ft_printf

## Description

ft_printf is a C library developed as part of the 42 curriculum. The goal of this project is to recreate the behavior of the standard `printf()` function from the C standard library.

The project focuses on variadic functions, format parsing, type conversions, and formatted output using the `write()` function.

The library is compiled into a static archive named `libftprintf.a`.

## Supported Conversions

The function supports the following conversions:

| Conversion | Description |
|---|---|
| `%c` | Prints a character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal format. |
| `%d` | Prints a decimal integer. |
| `%i` | Prints an integer. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints a hexadecimal number in lowercase. |
| `%X` | Prints a hexadecimal number in uppercase. |
| `%%` | Prints a percent sign. |

## Bonus

The bonus part supports the following flags:

| Flag | Description |
|---|---|
| `#` | Adds `0x` or `0X` to non-zero hexadecimal values. |
| `+` | Always shows the sign for positive decimal integers. |
| Space | Adds a space before positive decimal integers when `+` is not used. |

## Instructions

### Compilation

Run the following command at the root of the repository:

```bash
make
```

This compiles the source files and creates `libftprintf.a`

Available Makefile rules:

- `make` / `make all`: Compile the library.
- `make clean`: Remove object files.
- `make fclean`: Remove object files and `libftprintf.a`.
- `make re`: Rebuild the library.

### Usage

Include `ft_printf.h` in your C source file:

```c
#include "./headers/ft_printf.h"
```

Compile your program with the library:

```bash
cc main.c libftprintf.a -o program
```

Run it:

```bash
./program
```

Example:

```c
ft_printf("Hello %s, number: %d\n", "World", 42);
```

## Algorithm and Data Structure

### Algorithm

The function processes the format string one character at a time.

- If the current character is not `%`, it is printed directly.
- If `%` is found, the function checks the next characters to identify any flags.
- It then identifies the conversion character.
- Based on the conversion, it retrieves the correct argument using `va_arg()` and prints it in the required format.
- The function keeps track of the number of characters printed and returns that count.

### Data Structure

A structure named `t_flags` is used to store the flags found in the format string.

It contains information such as `hash`, `plus`, and `space`.

This structure makes it easier to pass flag information to the functions responsible for printing each conversion.

A `va_list` is used to access the additional arguments passed to the variadic function.

## Resources

- **42 ft_printf subject:** Project requirements and specifications.
- **C reference:** https://en.cppreference.com/w/c/io/fprintf
- **Linux man-pages:** https://man7.org/linux/man-pages/man3/printf.3.html
- **Variadic functions:** https://www.youtube.com/watch?v=3iX9a_l9W9Y

> **AI Usage**
>
> I used AI to clarify C concepts, understand variadic functions, review function specifications, and identify potential edge cases. I wrote, debugged, and tested the implementation myself