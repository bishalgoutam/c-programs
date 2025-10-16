# C Programming Repository

Welcome to my comprehensive C programming repository! This collection contains well-structured C programs covering fundamental to advanced concepts, organized for learning and reference purposes.

## 📁 Repository Structure

```
c-programs/
├── README.md
├── fundamentals/
│   ├── README.md
│   ├── variables-datatypes/
│   ├── operators/
│   ├── control-structures/
│   ├── functions/
│   └── arrays-strings/
├── advanced/
│   ├── README.md
│   ├── pointers/
│   ├── memory-management/
│   ├── structures-unions/
│   ├── file-handling/
│   └── preprocessor/
├── data-structures/
│   ├── README.md
│   ├── linked-lists/
│   ├── stacks-queues/
│   ├── trees/
│   ├── graphs/
│   └── hash-tables/
├── algorithms/
│   ├── README.md
│   ├── sorting/
│   ├── searching/
│   ├── recursion/
│   ├── dynamic-programming/
│   └── greedy/
└── projects/
    ├── README.md
    ├── calculator/
    ├── file-manager/
    ├── student-management/
    ├── library-system/
    └── mini-compiler/
```

## 🎯 Learning Path

### 1. **Fundamentals** - Start Here!
Essential C programming concepts that form the foundation:
- **Variables & Data Types**: Basic data types, variable declaration, scope
- **Operators**: Arithmetic, relational, logical, bitwise operations
- **Control Structures**: Conditional statements, loops, decision making
- **Functions**: Function declaration, parameters, recursion
- **Arrays & Strings**: Array manipulation, string operations

### 2. **Advanced Concepts**
More sophisticated C programming features:
- **Pointers**: Pointer arithmetic, pointer to pointers, function pointers
- **Memory Management**: Dynamic allocation, malloc, calloc, free
- **Structures & Unions**: Custom data types, nested structures
- **File Handling**: File I/O operations, binary and text files
- **Preprocessor**: Macros, conditional compilation, header files

### 3. **Data Structures**
Implementation of fundamental data structures:
- **Linked Lists**: Singly, doubly, circular linked lists
- **Stacks & Queues**: LIFO and FIFO implementations
- **Trees**: Binary trees, BST, AVL, tree traversals
- **Graphs**: Graph representation, traversal algorithms
- **Hash Tables**: Hash functions, collision handling

### 4. **Algorithms**
Classic algorithmic solutions and techniques:
- **Sorting**: Bubble, selection, insertion, merge, quick sort
- **Searching**: Linear, binary, hash-based searching
- **Recursion**: Recursive problem solving patterns
- **Dynamic Programming**: Optimization problems, memoization
- **Greedy Algorithms**: Optimization using greedy approach

### 5. **Projects**
Real-world applications and complete programs:
- **Calculator**: Scientific calculator with advanced operations
- **File Manager**: File operations and directory management
- **Student Management**: Academic record management system
- **Library System**: Book management and tracking system
- **Mini Compiler**: Basic compiler for a simple language

## 🛠️ Development Environment

### Prerequisites
- **C Compiler**: GCC (recommended), Clang, or Microsoft Visual C++
- **Operating System**: Windows, Linux, or macOS
- **Text Editor/IDE**: VS Code, Code::Blocks, Dev-C++, or any preferred editor

### Compilation Instructions
```bash
# Basic compilation
gcc -o program_name source_file.c

# With debugging information
gcc -g -o program_name source_file.c

# With all warnings
gcc -Wall -Wextra -o program_name source_file.c

# Optimized compilation
gcc -O2 -o program_name source_file.c

# C99 standard compliance
gcc -std=c99 -o program_name source_file.c
```

### Running Programs
```bash
# On Windows
program_name.exe

# On Linux/macOS
./program_name
```

## 📚 Learning Resources

### Recommended Books
- "The C Programming Language" by Brian Kernighan and Dennis Ritchie
- "C Programming: A Modern Approach" by K.N. King
- "Expert C Programming" by Peter van der Linden
- "C Primer Plus" by Stephen Prata

### Online Resources
- [C Reference Documentation](https://en.cppreference.com/w/c)
- [Learn C Programming](https://www.learn-c.org/)
- [C Programming Tutorial](https://www.tutorialspoint.com/cprogramming/)

## 🎨 Code Style Guidelines

### Naming Conventions
- **Variables**: lowercase with underscores (`student_count`, `max_value`)
- **Functions**: lowercase with underscores (`calculate_average`, `find_maximum`)
- **Constants**: uppercase with underscores (`MAX_SIZE`, `PI_VALUE`)
- **Macros**: uppercase with underscores (`DEBUG_MODE`, `BUFFER_SIZE`)

### Formatting
- Use 4 spaces for indentation
- Place opening braces on the same line for functions and control structures
- Add blank lines to separate logical sections
- Use meaningful variable and function names
- Include comprehensive comments

### Example Code Structure
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

// Function prototypes
int calculate_average(int scores[], int count);
void display_results(int average);

int main() {
    printf("Program started\n");
    
    // Your code here
    
    return 0;
}

// Function implementations
int calculate_average(int scores[], int count) {
    // Implementation
}
```

## 🧪 Testing and Validation

Each program includes:
- **Input validation** for robust error handling
- **Test cases** with expected outputs
- **Edge case considerations** for boundary conditions
- **Memory leak checks** for dynamic allocation
- **Documentation** with usage examples

## 🤝 Contributing

Feel free to contribute by:
1. Adding new programs or improving existing ones
2. Fixing bugs or optimizing algorithms
3. Enhancing documentation and comments
4. Suggesting new features or project ideas

## 📄 License

This repository is open source and available under the [MIT License](LICENSE).

## 📞 Contact

- **Author**: Bishal Goutam
- **GitHub**: [bishalgoutam](https://github.com/bishalgoutam)
- **Email**: [your-email@example.com]

---

**Happy Coding!** 🚀

*This repository is continuously updated with new programs and improvements. Star ⭐ this repo to stay updated with the latest additions!*