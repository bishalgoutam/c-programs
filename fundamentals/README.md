# C Programming Fundamentals

This section covers the essential building blocks of C programming. These concepts form the foundation that every C programmer must master.

## 📚 Topics Covered

### 1. Variables & Data Types
- **Basic Data Types**: int, float, double, char
- **Variable Declaration**: Different ways to declare and initialize variables
- **Type Modifiers**: signed, unsigned, short, long
- **Constants**: #define, const keyword, enum
- **Scope and Lifetime**: local, global, static variables

### 2. Operators
- **Arithmetic Operators**: +, -, *, /, %
- **Relational Operators**: ==, !=, <, >, <=, >=
- **Logical Operators**: &&, ||, !
- **Assignment Operators**: =, +=, -=, *=, /=, %=
- **Increment/Decrement**: ++, -- (prefix and postfix)
- **Bitwise Operators**: &, |, ^, ~, <<, >>

### 3. Control Structures
- **Conditional Statements**: if, if-else, else-if, switch-case
- **Loops**: for, while, do-while
- **Loop Control**: break, continue, goto
- **Nested Structures**: nested loops, nested conditionals

### 4. Functions
- **Function Declaration and Definition**
- **Function Parameters**: pass by value, pass by reference
- **Return Types**: void, int, custom types
- **Function Prototypes**
- **Recursion**: recursive functions and algorithms
- **Storage Classes**: auto, static, extern, register

### 5. Arrays & Strings
- **One-dimensional Arrays**: declaration, initialization, access
- **Multi-dimensional Arrays**: 2D arrays, matrix operations
- **Strings**: string handling, string functions
- **Array and String Manipulation**
- **Character Arrays vs String Literals**

## 🎯 Learning Objectives

After completing this section, you will be able to:

1. **Understand and use all basic C data types effectively**
2. **Write programs using various operators and understand operator precedence**
3. **Implement control flow using conditional statements and loops**
4. **Create and use functions with different parameter passing mechanisms**
5. **Work with arrays and strings for data storage and manipulation**
6. **Apply proper variable scope and storage class concepts**
7. **Debug and troubleshoot basic C programs**

## 📝 Program Structure

Each topic includes:
- **Concept explanation** with detailed comments
- **Practical examples** demonstrating real-world usage
- **Common pitfalls** and how to avoid them
- **Best practices** for clean, readable code
- **Exercise problems** to reinforce learning

## 🚀 Getting Started

1. Start with **variables-datatypes/** to understand basic data handling
2. Move to **operators/** to learn about operations and expressions
3. Progress to **control-structures/** for program flow control
4. Advance to **functions/** for modular programming
5. Complete with **arrays-strings/** for data collection handling

## 💡 Key Programming Concepts

### Variable Declaration Best Practices
```c
// Good practices
int student_count = 0;          // Descriptive name, initialized
const double PI = 3.14159;      // Use const for unchanging values
static int function_calls = 0;  // Static for persistent local variables

// Avoid
int a, b, c;                    // Non-descriptive names
int x;                          // Uninitialized variable
```

### Function Design Principles
```c
// Good function design
int calculate_average(int scores[], int count) {
    if (count <= 0) return 0;   // Input validation
    
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += scores[i];
    }
    return sum / count;
}
```

### Memory and Performance Tips
- Initialize variables when declaring them
- Use appropriate data types (don't use `int` when `char` suffices)
- Minimize global variable usage
- Prefer `const` for read-only data
- Use meaningful variable and function names

## 🔧 Compilation Commands

### Basic Compilation
```bash
gcc -o program_name source_file.c
```

### With Debugging and Warnings
```bash
gcc -g -Wall -Wextra -o program_name source_file.c
```

### C99 Standard with Optimization
```bash
gcc -std=c99 -O2 -o program_name source_file.c
```

## 📖 Recommended Study Order

1. **Week 1**: Variables & Data Types
2. **Week 2**: Operators  
3. **Week 3**: Control Structures
4. **Week 4**: Functions
5. **Week 5**: Arrays & Strings
6. **Week 6**: Review and Practice Projects

Each week includes both theoretical understanding and hands-on programming practice.

---

**Remember**: Practice is key to mastering C programming. Try to write code daily and experiment with different approaches to solve problems!