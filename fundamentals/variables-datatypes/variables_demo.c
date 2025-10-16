/**
 * Variables and Data Types - Comprehensive C Examples
 * 
 * This program demonstrates fundamental C concepts:
 * - Variable declarations and initialization
 * - All C data types (primitive and derived)
 * - Type conversions and casting
 * - Constants and preprocessor directives
 * - Memory allocation and variable scope
 * 
 * @author Bishal Goutam
 * @since C99 Standard
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>

// Global variable demonstration
int global_counter = 0;
const int MAX_SIZE = 100;

// Preprocessor macros
#define PI 3.14159
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Custom data types
typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

typedef enum {
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} Day;

// Function prototypes
void demonstrate_basic_types(void);
void demonstrate_arrays(void);
void demonstrate_pointers(void);
void demonstrate_strings(void);
void demonstrate_structures(void);
void demonstrate_type_conversion(void);
void demonstrate_constants(void);
void demonstrate_scope_storage(void);

int main(void) {
    printf("=== C Variables and Data Types Demo ===\n\n");
    
    demonstrate_basic_types();
    demonstrate_arrays();
    demonstrate_pointers();
    demonstrate_strings();
    demonstrate_structures();
    demonstrate_type_conversion();
    demonstrate_constants();
    demonstrate_scope_storage();
    
    return 0;
}

/**
 * Demonstrates basic C data types and their properties
 */
void demonstrate_basic_types(void) {
    printf("1. Basic Data Types\n");
    printf("===================\n");
    
    // Integer types
    char c = 'A';
    signed char sc = -128;
    unsigned char uc = 255;
    
    short s = -32768;
    unsigned short us = 65535;
    
    int i = -2147483648;
    unsigned int ui = 4294967295U;
    
    long l = -2147483648L;
    unsigned long ul = 4294967295UL;
    
    long long ll = -9223372036854775807LL;
    unsigned long long ull = 18446744073709551615ULL;
    
    // Floating point types
    float f = 3.14159f;
    double d = 2.71828;
    long double ld = 1.41421L;
    
    // Boolean type (C99)
    bool flag = true;
    
    printf("Character types:\n");
    printf("  char: %c (value: %d)\n", c, c);
    printf("  signed char: %d\n", sc);
    printf("  unsigned char: %u\n", uc);
    
    printf("\nInteger types:\n");
    printf("  short: %d\n", s);
    printf("  unsigned short: %u\n", us);
    printf("  int: %d\n", i);
    printf("  unsigned int: %u\n", ui);
    printf("  long: %ld\n", l);
    printf("  unsigned long: %lu\n", ul);
    printf("  long long: %lld\n", ll);
    printf("  unsigned long long: %llu\n", ull);
    
    printf("\nFloating point types:\n");
    printf("  float: %.5f\n", f);
    printf("  double: %.5lf\n", d);
    printf("  long double: %.5Lf\n", ld);
    
    printf("\nBoolean type:\n");
    printf("  bool: %s\n", flag ? "true" : "false");
    
    printf("\nData type sizes:\n");
    printf("  sizeof(char): %zu bytes\n", sizeof(char));
    printf("  sizeof(int): %zu bytes\n", sizeof(int));
    printf("  sizeof(float): %zu bytes\n", sizeof(float));
    printf("  sizeof(double): %zu bytes\n", sizeof(double));
    printf("  sizeof(pointer): %zu bytes\n", sizeof(void*));
    
    printf("\n");
}

/**
 * Demonstrates array declarations and usage
 */
void demonstrate_arrays(void) {
    printf("2. Arrays\n");
    printf("=========\n");
    
    // One-dimensional arrays
    int numbers[5] = {10, 20, 30, 40, 50};
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    float grades[3] = {85.5, 92.0, 78.5};
    
    // Two-dimensional array
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    printf("One-dimensional arrays:\n");
    printf("  numbers: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    printf("  vowels: ");
    for (int i = 0; i < 5; i++) {
        printf("%c ", vowels[i]);
    }
    printf("\n");
    
    printf("  grades: ");
    for (int i = 0; i < 3; i++) {
        printf("%.1f ", grades[i]);
    }
    printf("\n");
    
    printf("\nTwo-dimensional array (3x3 matrix):\n");
    for (int i = 0; i < 3; i++) {
        printf("  ");
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("Array size information:\n");
    printf("  numbers array size: %zu bytes\n", sizeof(numbers));
    printf("  numbers elements: %zu\n", sizeof(numbers) / sizeof(numbers[0]));
    
    printf("\n");
}

/**
 * Demonstrates pointer usage and memory management
 */
void demonstrate_pointers(void) {
    printf("3. Pointers\n");
    printf("===========\n");
    
    int value = 42;
    int *ptr = &value;
    int **double_ptr = &ptr;
    
    printf("Pointer basics:\n");
    printf("  value: %d\n", value);
    printf("  value address: %p\n", (void*)&value);
    printf("  ptr points to: %p\n", (void*)ptr);
    printf("  ptr value: %d\n", *ptr);
    printf("  ptr address: %p\n", (void*)&ptr);
    printf("  double_ptr points to: %p\n", (void*)double_ptr);
    printf("  double_ptr value: %d\n", **double_ptr);
    
    // Dynamic memory allocation
    int *dynamic_array = (int*)malloc(5 * sizeof(int));
    if (dynamic_array != NULL) {
        printf("\nDynamic memory allocation:\n");
        for (int i = 0; i < 5; i++) {
            dynamic_array[i] = (i + 1) * 10;
            printf("  dynamic_array[%d] = %d\n", i, dynamic_array[i]);
        }
        free(dynamic_array);
        printf("  Memory freed successfully\n");
    }
    
    // Pointer arithmetic
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;
    
    printf("\nPointer arithmetic:\n");
    printf("  Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");
    
    printf("  Using pointer increment:\n");
    p = arr;  // Reset pointer
    for (int i = 0; i < 5; i++) {
        printf("    arr[%d] = %d (address: %p)\n", i, *p, (void*)p);
        p++;
    }
    
    printf("\n");
}

/**
 * Demonstrates string handling in C
 */
void demonstrate_strings(void) {
    printf("4. Strings\n");
    printf("==========\n");
    
    // String declarations
    char str1[] = "Hello, World!";
    char str2[50] = "C Programming";
    char *str3 = "String Literal";
    
    printf("String declarations:\n");
    printf("  str1 (array): %s\n", str1);
    printf("  str2 (array): %s\n", str2);
    printf("  str3 (pointer): %s\n", str3);
    
    // String operations
    char dest[100];
    strcpy(dest, "Destination: ");
    strcat(dest, str1);
    
    printf("\nString operations:\n");
    printf("  strcpy + strcat result: %s\n", dest);
    printf("  strlen(str1): %zu\n", strlen(str1));
    printf("  strcmp(str1, str2): %d\n", strcmp(str1, str2));
    
    // Character array manipulation
    char buffer[20];
    sprintf(buffer, "Number: %d", 42);
    printf("  sprintf result: %s\n", buffer);
    
    printf("\n");
}

/**
 * Demonstrates structures and user-defined types
 */
void demonstrate_structures(void) {
    printf("5. Structures and User-Defined Types\n");
    printf("====================================\n");
    
    // Structure initialization
    Employee emp1 = {"John Doe", 30, 50000.0f};
    Employee emp2;
    
    // Structure member access
    strcpy(emp2.name, "Jane Smith");
    emp2.age = 28;
    emp2.salary = 55000.0f;
    
    printf("Employee structures:\n");
    printf("  Employee 1: %s, Age: %d, Salary: $%.2f\n", 
           emp1.name, emp1.age, emp1.salary);
    printf("  Employee 2: %s, Age: %d, Salary: $%.2f\n", 
           emp2.name, emp2.age, emp2.salary);
    
    // Enumeration usage
    Day today = WEDNESDAY;
    printf("\nEnumeration:\n");
    printf("  Today is day number: %d\n", today);
    
    switch (today) {
        case MONDAY:
        case TUESDAY:
        case WEDNESDAY:
        case THURSDAY:
        case FRIDAY:
            printf("  It's a weekday\n");
            break;
        case SATURDAY:
        case SUNDAY:
            printf("  It's a weekend\n");
            break;
    }
    
    printf("  Structure size: %zu bytes\n", sizeof(Employee));
    printf("  Enum size: %zu bytes\n", sizeof(Day));
    
    printf("\n");
}

/**
 * Demonstrates type conversion and casting
 */
void demonstrate_type_conversion(void) {
    printf("6. Type Conversion and Casting\n");
    printf("==============================\n");
    
    // Implicit conversion
    int i = 10;
    float f = i;  // int to float
    double d = f; // float to double
    
    printf("Implicit conversions:\n");
    printf("  int %d -> float %.2f -> double %.2f\n", i, f, d);
    
    // Explicit casting
    double pi = 3.14159;
    int truncated = (int)pi;
    
    printf("\nExplicit casting:\n");
    printf("  double %.5f -> int %d (truncated)\n", pi, truncated);
    
    // Mixed arithmetic
    int a = 7, b = 3;
    printf("\nMixed arithmetic:\n");
    printf("  %d / %d = %d (integer division)\n", a, b, a / b);
    printf("  %d / %d = %.2f (float division)\n", a, b, (float)a / b);
    
    // Character and ASCII
    char ch = 'A';
    printf("\nCharacter conversions:\n");
    printf("  char '%c' -> ASCII %d\n", ch, ch);
    printf("  ASCII %d -> char '%c'\n", 65, (char)65);
    
    printf("\n");
}

/**
 * Demonstrates constants and macros
 */
void demonstrate_constants(void) {
    printf("7. Constants and Macros\n");
    printf("=======================\n");
    
    // const keyword
    const int DAYS_IN_WEEK = 7;
    const float TAX_RATE = 0.08f;
    
    printf("Constants:\n");
    printf("  DAYS_IN_WEEK: %d\n", DAYS_IN_WEEK);
    printf("  TAX_RATE: %.2f\n", TAX_RATE);
    printf("  MAX_SIZE (global): %d\n", MAX_SIZE);
    
    // Preprocessor macros
    int radius = 5;
    printf("\nMacros:\n");
    printf("  PI: %.5f\n", PI);
    printf("  SQUARE(%d): %d\n", radius, SQUARE(radius));
    printf("  MAX(10, 20): %d\n", MAX(10, 20));
    
    // System limits
    printf("\nSystem limits:\n");
    printf("  INT_MAX: %d\n", INT_MAX);
    printf("  INT_MIN: %d\n", INT_MIN);
    printf("  CHAR_MAX: %d\n", CHAR_MAX);
    printf("  FLOAT_MAX: %e\n", FLT_MAX);
    
    printf("\n");
}

/**
 * Demonstrates variable scope and storage classes
 */
void demonstrate_scope_storage(void) {
    printf("8. Variable Scope and Storage Classes\n");
    printf("=====================================\n");
    
    // Local variables
    int local_var = 100;
    static int static_var = 0;  // Static local variable
    
    printf("Variable scope:\n");
    printf("  local_var: %d\n", local_var);
    printf("  static_var: %d\n", ++static_var);
    printf("  global_counter: %d\n", ++global_counter);
    
    // Register variable (hint to compiler)
    register int fast_var = 42;
    printf("  register variable: %d\n", fast_var);
    
    // Block scope
    {
        int block_var = 200;
        printf("  block_var (inside block): %d\n", block_var);
    }
    // block_var is not accessible here
    
    printf("\nStorage class information:\n");
    printf("  auto: default for local variables\n");
    printf("  static: retains value between function calls\n");
    printf("  extern: declares external linkage\n");
    printf("  register: suggests storage in CPU register\n");
    
    printf("\n");
}