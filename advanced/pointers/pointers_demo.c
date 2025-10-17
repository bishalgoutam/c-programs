/**
 * Pointers - Comprehensive C Examples
 * 
 * This program demonstrates:
 * - Basic pointer concepts and syntax
 * - Pointer arithmetic and operations
 * - Pointers to different data types
 * - Pointer arrays and array of pointers
 * - Multi-dimensional arrays and pointers
 * - Function pointers and callbacks
 * - Dynamic memory allocation
 * - Pointer to pointers (double pointers)
 * - Common pointer pitfalls and best practices
 * 
 * @author Bishal Goutam
 * @since C99 Standard
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void demonstrate_basic_pointers(void);
void demonstrate_pointer_arithmetic(void);
void demonstrate_pointers_and_arrays(void);
void demonstrate_pointer_to_pointer(void);
void demonstrate_function_pointers(void);
void demonstrate_dynamic_memory(void);
void demonstrate_string_pointers(void);
void demonstrate_struct_pointers(void);
void demonstrate_common_mistakes(void);
void demonstrate_advanced_techniques(void);

// Utility functions for demonstrations
int add(int a, int b);
int multiply(int a, int b);
int compare_ints(const void *a, const void *b);
void print_array(int *arr, int size);
void swap(int *a, int *b);

// Structure for demonstrations
struct Student {
    int id;
    char name[50];
    float gpa;
};

int main(void) {
    printf("=== C Pointers Demo ===\n\n");
    
    demonstrate_basic_pointers();
    demonstrate_pointer_arithmetic();
    demonstrate_pointers_and_arrays();
    demonstrate_pointer_to_pointer();
    demonstrate_function_pointers();
    demonstrate_dynamic_memory();
    demonstrate_string_pointers();
    demonstrate_struct_pointers();
    demonstrate_common_mistakes();
    demonstrate_advanced_techniques();
    
    return 0;
}

/**
 * Demonstrates basic pointer concepts
 */
void demonstrate_basic_pointers(void) {
    printf("1. Basic Pointer Concepts\n");
    printf("=========================\n");
    
    int num = 42;
    int *ptr = &num;  // Pointer to int
    
    printf("Variable and pointer basics:\n");
    printf("  num = %d\n", num);
    printf("  Address of num (&num) = %p\n", (void*)&num);
    printf("  ptr = %p (stores address of num)\n", (void*)ptr);
    printf("  *ptr = %d (value at address pointed by ptr)\n", *ptr);
    printf("  &ptr = %p (address of pointer itself)\n", (void*)&ptr);
    
    // Modifying value through pointer
    printf("\nModifying value through pointer:\n");
    printf("  Before: num = %d, *ptr = %d\n", num, *ptr);
    *ptr = 100;
    printf("  After *ptr = 100: num = %d, *ptr = %d\n", num, *ptr);
    
    // Different data types
    printf("\nPointers to different data types:\n");
    char ch = 'A';
    float f = 3.14f;
    double d = 2.718281828;
    
    char *char_ptr = &ch;
    float *float_ptr = &f;
    double *double_ptr = &d;
    
    printf("  char: %c at %p (size: %zu bytes)\n", *char_ptr, (void*)char_ptr, sizeof(char_ptr));
    printf("  float: %.2f at %p (size: %zu bytes)\n", *float_ptr, (void*)float_ptr, sizeof(float_ptr));
    printf("  double: %.6f at %p (size: %zu bytes)\n", *double_ptr, (void*)double_ptr, sizeof(double_ptr));
    
    // Null pointer
    printf("\nNull pointer:\n");
    int *null_ptr = NULL;
    printf("  null_ptr = %p\n", (void*)null_ptr);
    printf("  (null_ptr == NULL) = %s\n", (null_ptr == NULL) ? "true" : "false");
    
    printf("\n");
}

/**
 * Demonstrates pointer arithmetic
 */
void demonstrate_pointer_arithmetic(void) {
    printf("2. Pointer Arithmetic\n");
    printf("=====================\n");
    
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;  // Points to first element
    
    printf("Array: [10, 20, 30, 40, 50]\n");
    printf("ptr initially points to arr[0]\n\n");
    
    printf("Pointer arithmetic operations:\n");
    printf("  ptr = %p, *ptr = %d (arr[0])\n", (void*)ptr, *ptr);
    
    ptr++;  // Move to next element
    printf("  ptr++: ptr = %p, *ptr = %d (arr[1])\n", (void*)ptr, *ptr);
    
    ptr += 2;  // Move 2 elements forward
    printf("  ptr += 2: ptr = %p, *ptr = %d (arr[3])\n", (void*)ptr, *ptr);
    
    ptr--;  // Move one element back
    printf("  ptr--: ptr = %p, *ptr = %d (arr[2])\n", (void*)ptr, *ptr);
    
    // Pointer subtraction
    int *start = arr;
    int *end = &arr[4];
    ptrdiff_t difference = end - start;
    printf("\nPointer subtraction:\n");
    printf("  end - start = %td elements\n", difference);
    
    // Array access using pointer arithmetic
    printf("\nArray access using pointer arithmetic:\n");
    ptr = arr;
    for (int i = 0; i < 5; i++) {
        printf("  *(ptr + %d) = arr[%d] = %d\n", i, i, *(ptr + i));
    }
    
    // Comparison of pointers
    printf("\nPointer comparison:\n");
    int *ptr1 = &arr[1];
    int *ptr2 = &arr[3];
    printf("  ptr1 points to arr[1], ptr2 points to arr[3]\n");
    printf("  ptr1 < ptr2: %s\n", (ptr1 < ptr2) ? "true" : "false");
    printf("  ptr1 == ptr2: %s\n", (ptr1 == ptr2) ? "true" : "false");
    
    printf("\n");
}

/**
 * Demonstrates pointers and arrays relationship
 */
void demonstrate_pointers_and_arrays(void) {
    printf("3. Pointers and Arrays\n");
    printf("======================\n");
    
    int numbers[] = {1, 2, 3, 4, 5};
    
    printf("Array name as pointer:\n");
    printf("  Array: [1, 2, 3, 4, 5]\n");
    printf("  numbers = %p (array name is pointer to first element)\n", (void*)numbers);
    printf("  &numbers[0] = %p (address of first element)\n", (void*)&numbers[0]);
    printf("  numbers == &numbers[0]: %s\n", (numbers == &numbers[0]) ? "true" : "false");
    
    // Array notation vs pointer notation
    printf("\nArray notation vs Pointer notation:\n");
    for (int i = 0; i < 5; i++) {
        printf("  numbers[%d] = %d, *(numbers + %d) = %d\n", 
               i, numbers[i], i, *(numbers + i));
    }
    
    // 2D arrays and pointers
    printf("\n2D Arrays and pointers:\n");
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    printf("  2D array matrix[3][4]:\n");
    for (int i = 0; i < 3; i++) {
        printf("    Row %d: ", i);
        for (int j = 0; j < 4; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Accessing 2D array elements using pointers
    printf("\n  Accessing using pointer notation:\n");
    printf("    matrix[1][2] = %d\n", matrix[1][2]);
    printf("    *(*(matrix + 1) + 2) = %d\n", *(*(matrix + 1) + 2));
    printf("    *((int*)matrix + 1*4 + 2) = %d\n", *((int*)matrix + 1*4 + 2));
    
    // Array of pointers vs pointer to array
    printf("\nArray of pointers vs Pointer to array:\n");
    
    // Array of pointers
    char *fruits[] = {"Apple", "Banana", "Cherry", "Date"};
    printf("  Array of pointers to strings:\n");
    for (int i = 0; i < 4; i++) {
        printf("    fruits[%d] = \"%s\" at %p\n", i, fruits[i], (void*)fruits[i]);
    }
    
    // Pointer to array
    int (*array_ptr)[5] = &numbers;
    printf("  Pointer to array of 5 ints:\n");
    printf("    (*array_ptr)[2] = %d\n", (*array_ptr)[2]);
    
    printf("\n");
}

/**
 * Demonstrates pointer to pointer (double pointers)
 */
void demonstrate_pointer_to_pointer(void) {
    printf("4. Pointer to Pointer (Double Pointers)\n");
    printf("=======================================\n");
    
    int value = 100;
    int *ptr = &value;
    int **double_ptr = &ptr;
    
    printf("Multi-level indirection:\n");
    printf("  value = %d at address %p\n", value, (void*)&value);
    printf("  ptr = %p (points to value) at address %p\n", (void*)ptr, (void*)&ptr);
    printf("  double_ptr = %p (points to ptr) at address %p\n", (void*)double_ptr, (void*)&double_ptr);
    
    printf("\nAccessing value through different levels:\n");
    printf("  value = %d\n", value);
    printf("  *ptr = %d\n", *ptr);
    printf("  **double_ptr = %d\n", **double_ptr);
    
    // Modifying value through double pointer
    **double_ptr = 200;
    printf("\nAfter **double_ptr = 200:\n");
    printf("  value = %d\n", value);
    
    // Common use case: modifying pointer in function
    printf("\nCommon use case - Array of strings:\n");
    char *languages[] = {"C", "Python", "Java", "JavaScript", NULL};
    char **lang_ptr = languages;
    
    printf("  Programming languages:\n");
    while (*lang_ptr != NULL) {
        printf("    %s\n", *lang_ptr);
        lang_ptr++;
    }
    
    // Command line arguments simulation
    printf("\nCommand line arguments pattern:\n");
    char *argv[] = {"program", "arg1", "arg2", "arg3", NULL};
    int argc = 4;
    
    printf("  argc = %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("  argv[%d] = \"%s\"\n", i, argv[i]);
    }
    
    printf("\n");
}

/**
 * Demonstrates function pointers and callbacks
 */
void demonstrate_function_pointers(void) {
    printf("5. Function Pointers and Callbacks\n");
    printf("===================================\n");
    
    // Basic function pointer
    int (*operation)(int, int);
    
    printf("Basic function pointers:\n");
    operation = add;
    printf("  add(5, 3) = %d\n", operation(5, 3));
    
    operation = multiply;
    printf("  multiply(5, 3) = %d\n", operation(5, 3));
    
    // Array of function pointers
    printf("\nArray of function pointers:\n");
    int (*operations[])(int, int) = {add, multiply};
    char *op_names[] = {"add", "multiply"};
    
    for (int i = 0; i < 2; i++) {
        printf("  %s(7, 4) = %d\n", op_names[i], operations[i](7, 4));
    }
    
    // Using function pointers for callbacks
    printf("\nUsing qsort with function pointer callback:\n");
    int numbers[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("  Before sorting: ");
    print_array(numbers, size);
    
    qsort(numbers, size, sizeof(int), compare_ints);
    
    printf("  After sorting:  ");
    print_array(numbers, size);
    
    // Pointer to function returning pointer
    printf("\nFunction returning pointer:\n");
    char* (*string_func)(void);
    // This would be assigned to a function that returns char*
    printf("  Function pointer that returns char* declared\n");
    
    printf("\n");
}

/**
 * Demonstrates dynamic memory allocation
 */
void demonstrate_dynamic_memory(void) {
    printf("6. Dynamic Memory Allocation\n");
    printf("============================\n");
    
    // malloc
    printf("Using malloc:\n");
    int *dynamic_arr = malloc(5 * sizeof(int));
    if (dynamic_arr == NULL) {
        printf("  Memory allocation failed!\n");
        return;
    }
    
    // Initialize array
    for (int i = 0; i < 5; i++) {
        dynamic_arr[i] = (i + 1) * 10;
    }
    
    printf("  Allocated array: ");
    print_array(dynamic_arr, 5);
    
    // realloc
    printf("\nUsing realloc to expand array:\n");
    dynamic_arr = realloc(dynamic_arr, 8 * sizeof(int));
    if (dynamic_arr == NULL) {
        printf("  Memory reallocation failed!\n");
        return;
    }
    
    // Initialize new elements
    for (int i = 5; i < 8; i++) {
        dynamic_arr[i] = (i + 1) * 10;
    }
    
    printf("  Expanded array:  ");
    print_array(dynamic_arr, 8);
    
    free(dynamic_arr);
    printf("  Memory freed\n");
    
    // calloc
    printf("\nUsing calloc (initialized to zero):\n");
    int *zero_arr = calloc(6, sizeof(int));
    if (zero_arr != NULL) {
        printf("  Calloc array:    ");
        print_array(zero_arr, 6);
        free(zero_arr);
    }
    
    // Dynamic 2D array allocation
    printf("\nDynamic 2D array allocation:\n");
    int rows = 3, cols = 4;
    int **matrix = malloc(rows * sizeof(int*));
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1;
        }
    }
    
    printf("  Dynamic 2D array:\n");
    for (int i = 0; i < rows; i++) {
        printf("    ");
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Free 2D array
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    printf("  2D array memory freed\n");
    
    printf("\n");
}

/**
 * Demonstrates string pointers and manipulation
 */
void demonstrate_string_pointers(void) {
    printf("7. String Pointers and Manipulation\n");
    printf("====================================\n");
    
    // String literals vs character arrays
    printf("String literals vs character arrays:\n");
    char *str1 = "Hello, World!";  // String literal (read-only)
    char str2[] = "Hello, World!"; // Character array (modifiable)
    
    printf("  str1 (literal): \"%s\" at %p\n", str1, (void*)str1);
    printf("  str2 (array):   \"%s\" at %p\n", str2, (void*)str2);
    
    // str1[0] = 'h';  // This would cause undefined behavior!
    str2[0] = 'h';  // This is safe
    printf("  After str2[0] = 'h': \"%s\"\n", str2);
    
    // Array of string pointers
    printf("\nArray of string pointers:\n");
    char *colors[] = {"Red", "Green", "Blue", "Yellow", "Purple"};
    int num_colors = sizeof(colors) / sizeof(colors[0]);
    
    printf("  Colors array:\n");
    for (int i = 0; i < num_colors; i++) {
        printf("    colors[%d] = \"%s\" at %p\n", i, colors[i], (void*)colors[i]);
    }
    
    // Dynamic string allocation
    printf("\nDynamic string allocation:\n");
    char *dynamic_str = malloc(50 * sizeof(char));
    if (dynamic_str != NULL) {
        strcpy(dynamic_str, "Dynamic string");
        printf("  Dynamic string: \"%s\"\n", dynamic_str);
        
        // Extend the string
        strcat(dynamic_str, " extended!");
        printf("  After extension: \"%s\"\n", dynamic_str);
        
        free(dynamic_str);
        printf("  String memory freed\n");
    }
    
    // String pointer manipulation
    printf("\nString pointer manipulation:\n");
    char sentence[] = "The quick brown fox jumps";
    char *word = sentence;
    
    printf("  Original: \"%s\"\n", sentence);
    printf("  Word by word parsing:\n");
    
    while (*word) {
        // Find start of word (skip spaces)
        while (*word == ' ') word++;
        if (!*word) break;
        
        // Find end of word
        char *word_start = word;
        while (*word && *word != ' ') word++;
        
        // Print word
        printf("    \"");
        for (char *p = word_start; p < word; p++) {
            putchar(*p);
        }
        printf("\"\n");
    }
    
    printf("\n");
}

/**
 * Demonstrates pointers with structures
 */
void demonstrate_struct_pointers(void) {
    printf("8. Pointers with Structures\n");
    printf("===========================\n");
    
    // Structure variable and pointer
    struct Student student1 = {1001, "Alice Johnson", 3.85f};
    struct Student *student_ptr = &student1;
    
    printf("Structure access methods:\n");
    printf("  Direct access:     student1.id = %d\n", student1.id);
    printf("  Pointer access:    (*student_ptr).id = %d\n", (*student_ptr).id);
    printf("  Arrow operator:    student_ptr->id = %d\n", student_ptr->id);
    
    printf("  Student info: ID=%d, Name=\"%s\", GPA=%.2f\n", 
           student_ptr->id, student_ptr->name, student_ptr->gpa);
    
    // Array of structures with pointers
    printf("\nArray of structures:\n");
    struct Student students[] = {
        {1001, "Alice Johnson", 3.85f},
        {1002, "Bob Smith", 3.92f},
        {1003, "Carol Davis", 3.78f}
    };
    
    int num_students = sizeof(students) / sizeof(students[0]);
    
    for (int i = 0; i < num_students; i++) {
        printf("  Student %d: %s (ID: %d, GPA: %.2f)\n",
               i + 1, students[i].name, students[i].id, students[i].gpa);
    }
    
    // Dynamic allocation of structures
    printf("\nDynamic structure allocation:\n");
    struct Student *dynamic_student = malloc(sizeof(struct Student));
    if (dynamic_student != NULL) {
        dynamic_student->id = 1004;
        strcpy(dynamic_student->name, "David Wilson");
        dynamic_student->gpa = 3.95f;
        
        printf("  Dynamic student: %s (ID: %d, GPA: %.2f)\n",
               dynamic_student->name, dynamic_student->id, dynamic_student->gpa);
        
        free(dynamic_student);
        printf("  Structure memory freed\n");
    }
    
    // Array of pointers to structures
    printf("\nArray of pointers to structures:\n");
    struct Student *student_ptrs[] = {&students[0], &students[2], &students[1]};
    
    printf("  Reordered students:\n");
    for (int i = 0; i < 3; i++) {
        printf("    %s (GPA: %.2f)\n", student_ptrs[i]->name, student_ptrs[i]->gpa);
    }
    
    printf("\n");
}

/**
 * Demonstrates common pointer mistakes and how to avoid them
 */
void demonstrate_common_mistakes(void) {
    printf("9. Common Pointer Mistakes\n");
    printf("==========================\n");
    
    printf("Common mistakes to avoid:\n\n");
    
    // 1. Uninitialized pointers
    printf("1. Uninitialized pointers:\n");
    int *uninitialized_ptr;  // Contains garbage value
    printf("   BAD:  int *ptr; // ptr contains random address\n");
    printf("   GOOD: int *ptr = NULL; // or initialize to valid address\n");
    
    // 2. Dereferencing NULL pointer
    printf("\n2. Dereferencing NULL pointer:\n");
    int *null_ptr = NULL;
    printf("   BAD:  *null_ptr = 10; // Segmentation fault!\n");
    printf("   GOOD: if (null_ptr != NULL) *null_ptr = 10;\n");
    
    // 3. Memory leaks
    printf("\n3. Memory leaks:\n");
    printf("   BAD:  ptr = malloc(100); // ... no free(ptr);\n");
    printf("   GOOD: ptr = malloc(100); // ... free(ptr);\n");
    
    // 4. Double free
    printf("\n4. Double free:\n");
    printf("   BAD:  free(ptr); free(ptr); // Error!\n");
    printf("   GOOD: free(ptr); ptr = NULL;\n");
    
    // 5. Using freed memory
    printf("\n5. Using freed memory:\n");
    printf("   BAD:  free(ptr); *ptr = 10; // Undefined behavior!\n");
    printf("   GOOD: free(ptr); ptr = NULL;\n");
    
    // 6. Buffer overflow
    printf("\n6. Buffer overflow:\n");
    printf("   BAD:  int arr[5]; int *p = arr + 10; // Out of bounds!\n");
    printf("   GOOD: Always check array bounds\n");
    
    // 7. Returning pointer to local variable
    printf("\n7. Returning pointer to local variable:\n");
    printf("   BAD:  int* func() { int x = 10; return &x; } // Dangling pointer!\n");
    printf("   GOOD: Return pointer to static/global/dynamic memory\n");
    
    // Demonstrate safe practices
    printf("\nSafe practices demonstration:\n");
    
    // Safe memory allocation and checking
    int *safe_ptr = malloc(10 * sizeof(int));
    if (safe_ptr != NULL) {
        // Use the pointer
        for (int i = 0; i < 10; i++) {
            safe_ptr[i] = i * i;
        }
        
        printf("   Safely allocated and used memory\n");
        
        // Safe cleanup
        free(safe_ptr);
        safe_ptr = NULL;  // Prevent accidental reuse
        printf("   Memory safely freed and pointer nullified\n");
    } else {
        printf("   Memory allocation failed - handled gracefully\n");
    }
    
    printf("\n");
}

/**
 * Demonstrates advanced pointer techniques
 */
void demonstrate_advanced_techniques(void) {
    printf("10. Advanced Pointer Techniques\n");
    printf("===============================\n");
    
    // Generic pointers (void*)
    printf("Generic pointers (void*):\n");
    int int_val = 42;
    float float_val = 3.14f;
    
    void *generic_ptr = &int_val;
    printf("   Pointing to int: %d\n", *(int*)generic_ptr);
    
    generic_ptr = &float_val;
    printf("   Pointing to float: %.2f\n", *(float*)generic_ptr);
    
    // Const pointers
    printf("\nConst pointers:\n");
    int value1 = 10, value2 = 20;
    
    const int *ptr_to_const = &value1;        // Pointer to const int
    int * const const_ptr = &value1;          // Const pointer to int
    const int * const const_ptr_to_const = &value1;  // Const pointer to const int
    
    printf("   ptr_to_const points to: %d\n", *ptr_to_const);
    // *ptr_to_const = 15;  // Error: can't modify value
    ptr_to_const = &value2;  // OK: can change pointer
    printf("   After reassignment: %d\n", *ptr_to_const);
    
    *const_ptr = 15;  // OK: can modify value
    printf("   const_ptr value modified to: %d\n", *const_ptr);
    // const_ptr = &value2;  // Error: can't change pointer
    
    // Pointer arrays and array pointers
    printf("\nPointer arrays vs Array pointers:\n");
    
    // Array of pointers
    int a = 1, b = 2, c = 3;
    int *ptr_array[3] = {&a, &b, &c};
    printf("   Array of pointers: [%d, %d, %d]\n", *ptr_array[0], *ptr_array[1], *ptr_array[2]);
    
    // Pointer to array
    int arr[3] = {4, 5, 6};
    int (*array_pointer)[3] = &arr;
    printf("   Pointer to array: [%d, %d, %d]\n", (*array_pointer)[0], (*array_pointer)[1], (*array_pointer)[2]);
    
    // Function pointer typedefs
    printf("\nFunction pointer typedefs:\n");
    typedef int (*BinaryOperation)(int, int);
    
    BinaryOperation op = add;
    printf("   Using typedef: add(8, 3) = %d\n", op(8, 3));
    
    // Pointer to function pointer
    BinaryOperation *op_ptr = &op;
    printf("   Pointer to function pointer: add(5, 7) = %d\n", (*op_ptr)(5, 7));
    
    printf("\n");
}

// Utility function implementations

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

void print_array(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}