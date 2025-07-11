# GCC and G++ Usage Tutorial

## Table of Contents
1. [What are GCC and G++?](#1-what-are-gcc-and-g)
2. [Basic Compilation Process](#2-basic-compilation-process)
3. [Common Compilation Options](#3-common-compilation-options)
4. [Multi-file Compilation](#4-multi-file-compilation)
5. [Static and Dynamic Libraries](#5-static-and-dynamic-libraries)
6. [Debugging and Optimization](#6-debugging-and-optimization)

---

## 1 What are GCC and G++?

- **GCC (GNU Compiler Collection)**  
  A compiler collection for C/C++/Objective-C/Fortran and other languages. By default, it processes C programs.

- **G++**  
  The frontend for GCC specifically designed for compiling C++ programs. Automatically links the C++ standard library.

| Feature         | GCC            | G++            |
|-----------------|----------------|----------------|
| Default Language| C              | C++            |
| Standard Library| Manual linking | Automatic link |
| File Extension  | Relies on extension | Auto-detects C++ |

---

## 2 Basic Compilation Process

### Single File Compilation Example
```bash
# Compile C program
gcc hello.c -o hello_c

# Compile C++ program
g++ hello.cpp -o hello_cpp
```

### Step-by-Step Compilation
```bash
# ========================================================
# 1. PREPROCESSING(预处理): Source Code Expansion
#    - Handles all preprocessor directives starting with '#'
#    - Expands #include files (recursive header insertion)
#    - Processes #define macros (textual substitution)
#    - Conditional compilation (#ifdef, #if, #else)
#    - Removes comments and unnecessary whitespace
#    - Output: Pure C code without preprocessor directives
# ========================================================
gcc -E main.c -o main.i

# ========================================================
# 2. Compilation(编译): Generate assembly code
# 	The compiler performs a series of lexical analysis(词法分析), 
# 	syntax analysis(语法分析), semantic analysis(语义分析), 
# 	and optimizations(优化) on the preprocessed text file 
# 	main.i, translating it into the text file main.s.
# ========================================================
gcc -S main.i -o main.s

# ========================================================
# 3. ASSEMBLY(汇编): Machine Code Generation
#    - Converts symbolic assembly to binary machine code
#    - Resolves symbolic labels to memory addresses
#    - Generates relocatable object file with:
#        * Machine instructions in .text section
#        * Initialized data in .data section
#        * Uninitialized data in .bss section
#        * Symbol table for linking
#        * Relocation records for address adjustment
#    - Output: Platform-specific object file (ELF format on Linux)
# ========================================================
gcc -c main.s -o main.o

# ========================================================
# 4. LINKING(链接): Executable Construction
#    - Combines multiple object files and libraries
#    - PHASE 1: Symbol Resolution
#        * Matches external references to symbol definitions
#        * Resolves inter-module dependencies
#    - PHASE 2: Relocation
#        * Adjusts relative/absolute memory addresses
#        * Patches call/jump targets
#    - PHASE 3: Library Linking
#        * Static linking: Copies library code into executable
#        * Dynamic linking: Creates runtime binding references
#    - PHASE 4: Final Layout
#        * Creates executable header (ELF, PE, Mach-O)
#        * Organizes memory segments (text, data, heap, stack)
#        * Sets entry point address (usually _start)
#    - Output: Runnable executable with complete memory map
# ========================================================
gcc main.o -o main
```

---

## 3 Common Compilation Options

| Option         | Description                     | Example                   |
|----------------|---------------------------------|---------------------------|
| `-o <file>`    | Specify output filename         | `gcc main.c -o app`      |
| `-c`           | Compile only (generate .o file) | `gcc -c main.c`          |
| `-Wall`        | Enable all warnings             | `g++ -Wall test.cpp`     |
| `-Werror`      | Treat warnings as errors        | `gcc -Werror main.c`     |
| `-O<level>`    | Optimization level (0-3, s, fast)| `g++ -O2 program.cpp`    |
| `-std=`        | Specify language standard       | `gcc -std=c99 app.c`     |
| `-I<dir>`      | Add header search path          | `g++ -Iinclude src.cpp`  |
| `-L<dir>`      | Add library search path         | `gcc -Llib main.c`       |
| `-l<name>`     | Link specific library (e.g., libmath.a → -lmath) | `g++ -lpthread app.cpp` |
| `-static`      | Static linking: Copies library code into executable | `g++ -static app.cpp` |

---

## 4 Multi-file Compilation

### Project Structure
```
project/
├── main.c
├── utils.h
└── utils.c
```

### Compilation Methods
```bash
# Method 1: Direct compilation
gcc main.c utils.c -o program

# Method 2: Separate compilation and linking
gcc -c main.c -o main.o
gcc -c utils.c -o utils.o
gcc main.o utils.o -o program
```

---

## 5 Static and Dynamic Libraries

### Create Static Library (.a)
```bash
# 1. Compile object file
gcc -c libmath.c -o libmath.o

# 2. Package into static library
ar rcs libmath.a libmath.o

# 3. Use static library
gcc main.c -L. -lmath -o static_app
```

### Create Dynamic Library (.so)
```bash
# 1. Compile Position-Independent Code
gcc -fPIC -c libmath.c -o libmath.o

# 2. Create shared library
gcc -shared -o libmath.so libmath.o

# 3. Use dynamic library
gcc main.c -L. -lmath -o dynamic_app
# Set library path at runtime:
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
```

---

## 6 Debugging and Optimization

### Debugging Options
```bash
# Generate debug information
g++ -g program.cpp -o debug_app

# Debug with GDB
gdb ./debug_app
```

### Optimization Levels
| Option   | Description                    |
|----------|--------------------------------|
| `-O0`    | No optimization (default)      |
| `-O1`    | Basic optimization, reduces code size |
| `-O2`    | Recommended level, improves performance |
| `-O3`    | Aggressive optimization, may increase code size |
| `-Os`    | Optimize for size              |
| `-Ofast` | Enable all optimizations, may violate standards |

```bash
# Production optimization example
g++ -O2 -Wall -std=c++17 main.cpp -o release_app
```

### Generate Dependencies
```bash
# Generate Makefile dependency rules
gcc -MM *.c > dependencies.d
```

> Tip: Use `-v` option to view detailed compilation process

Master these core features to efficiently develop projects using GCC/G++!