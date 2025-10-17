/**
 * Functions - Comprehensive C Examples
 * 
 * This program demonstrates:
 * - Function declarations and definitions
 * - Parameter passing (by value, by reference)
 * - Return types and return statements
 * - Recursive functions
 * - Function pointers and callbacks
 * - Static and inline functions
 * 
 * @author Bishal Goutam
 * @since C99 Standard
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototypes
void demonstrate_basic_functions(void);
void demonstrate_parameter_passing(void);
void demonstrate_recursive_functions(void);
void demonstrate_function_pointers(void);
void demonstrate_static_functions(void);
void demonstrate_variadic_functions(void);
void demonstrate_practical_functions(void);

// Basic functions
void greet_user(void);
int add_numbers(int a, int b);
float calculate_average(int arr[], int size);
void print_array(int arr[], int size);

// Parameter passing functions
void swap_by_value(int a, int b);
void swap_by_reference(int *a, int *b);
void modify_array(int arr[], int size);
void modify_string(char *str);

// Recursive functions
int factorial_recursive(int n);
int fibonacci_recursive(int n);
void print_binary(unsigned int n);
int gcd_recursive(int a, int b);

// Mathematical functions
double power(double base, int exp);
int is_prime(int n);
long long factorial_iterative(int n);

// Function pointer examples
int multiply(int a, int b);
int divide_safe(int a, int b);
void apply_operation(int a, int b, int (*operation)(int, int));

// Static functions (declared here, defined later)
static int static_counter(void);
static void helper_function(void);

// Inline function (C99)
inline int square(int x) {
    return x * x;
}

// Variadic function prototype
void print_integers(int count, ...);

int main(void) {
    printf("=== C Functions Demo ===\n\n");
    
    demonstrate_basic_functions();
    demonstrate_parameter_passing();
    demonstrate_recursive_functions();
    demonstrate_function_pointers();
    demonstrate_static_functions();
    demonstrate_variadic_functions();
    demonstrate_practical_functions();
    
    return 0;
}

/**
 * Demonstrates basic function concepts
 */
void demonstrate_basic_functions(void) {
    printf("1. Basic Functions\n");
    printf("==================\n");
    
    // Function with no parameters and no return value
    greet_user();
    
    // Function with parameters and return value
    int sum = add_numbers(15, 25);
    printf("✓ add_numbers(15, 25) = %d\n", sum);
    
    // Function with array parameter
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("✓ Array: ");
    print_array(numbers, size);
    
    float avg = calculate_average(numbers, size);
    printf("✓ Average: %.2f\n", avg);
    
    // Inline function
    int x = 5;
    printf("✓ square(%d) = %d (inline function)\n", x, square(x));
    
    // Function call expressions
    int result = add_numbers(10, add_numbers(5, 3));
    printf("✓ Nested calls: add_numbers(10, add_numbers(5, 3)) = %d\n", result);
    
    printf("\n");
}

/**
 * Demonstrates parameter passing methods
 */
void demonstrate_parameter_passing(void) {
    printf("2. Parameter Passing\n");
    printf("====================\n");
    
    // Pass by value (copies are made)
    int a = 10, b = 20;
    printf("Before swap_by_value: a = %d, b = %d\n", a, b);
    swap_by_value(a, b);
    printf("After swap_by_value:  a = %d, b = %d (unchanged)\n", a, b);
    
    // Pass by reference (addresses are passed)
    printf("\nBefore swap_by_reference: a = %d, b = %d\n", a, b);
    swap_by_reference(&a, &b);
    printf("After swap_by_reference:  a = %d, b = %d (swapped)\n", a, b);
    
    // Array parameter (always passed by reference)
    int arr[] = {1, 2, 3, 4, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    
    printf("\nBefore modify_array: ");
    print_array(arr, arr_size);
    
    modify_array(arr, arr_size);
    printf("After modify_array:  ");
    print_array(arr, arr_size);
    
    // String parameter
    char message[] = "hello world";
    printf("\nBefore modify_string: \"%s\"\n", message);
    modify_string(message);
    printf("After modify_string:  \"%s\"\n", message);
    
    printf("\n");
}

/**
 * Demonstrates recursive functions
 */
void demonstrate_recursive_functions(void) {
    printf("3. Recursive Functions\n");
    printf("======================\n");
    
    // Factorial calculation
    printf("Factorial calculations:\n");
    for (int i = 0; i <= 6; i++) {
        printf("  %d! = %d (recursive), %lld (iterative)\n", 
               i, factorial_recursive(i), factorial_iterative(i));
    }
    
    // Fibonacci sequence
    printf("\nFibonacci sequence (first 10 terms):\n");
    printf("  ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", fibonacci_recursive(i));
    }
    printf("\n");
    
    // Binary representation
    printf("\nBinary representation:\n");
    int decimal_numbers[] = {10, 25, 100, 255};
    int count = sizeof(decimal_numbers) / sizeof(decimal_numbers[0]);
    
    for (int i = 0; i < count; i++) {
        printf("  %d in binary: ", decimal_numbers[i]);
        print_binary(decimal_numbers[i]);
        printf("\n");
    }
    
    // Greatest Common Divisor
    printf("\nGreatest Common Divisor:\n");
    int pairs[][2] = {{48, 18}, {100, 25}, {17, 13}};
    int pair_count = sizeof(pairs) / sizeof(pairs[0]);
    
    for (int i = 0; i < pair_count; i++) {
        int gcd = gcd_recursive(pairs[i][0], pairs[i][1]);
        printf("  GCD(%d, %d) = %d\n", pairs[i][0], pairs[i][1], gcd);
    }
    
    printf("\n");
}

/**
 * Demonstrates function pointers and callbacks
 */
void demonstrate_function_pointers(void) {
    printf("4. Function Pointers and Callbacks\n");
    printf("==================================\n");
    
    // Basic function pointer
    int (*operation)(int, int);
    
    // Point to add_numbers function
    operation = add_numbers;
    printf("✓ Function pointer to add_numbers: %d\n", operation(10, 5));
    
    // Point to multiply function
    operation = multiply;
    printf("✓ Function pointer to multiply: %d\n", operation(10, 5));
    
    // Point to divide_safe function
    operation = divide_safe;
    printf("✓ Function pointer to divide_safe: %d\n", operation(10, 5));
    
    // Array of function pointers
    int (*operations[])(int, int) = {add_numbers, multiply, divide_safe};
    char *operation_names[] = {"Addition", "Multiplication", "Division"};
    int op_count = sizeof(operations) / sizeof(operations[0]);
    
    printf("\nArray of function pointers:\n");
    for (int i = 0; i < op_count; i++) {
        printf("  %s: 20, 4 -> %d\n", operation_names[i], operations[i](20, 4));
    }
    
    // Callback function example
    printf("\nCallback function examples:\n");
    apply_operation(15, 3, add_numbers);
    apply_operation(15, 3, multiply);
    apply_operation(15, 3, divide_safe);
    
    printf("\n");
}

/**
 * Demonstrates static functions and variables
 */
void demonstrate_static_functions(void) {
    printf("5. Static Functions and Variables\n");
    printf("=================================\n");
    
    // Static function calls
    printf("Static counter function calls:\n");
    for (int i = 0; i < 5; i++) {
        printf("  Call %d: counter = %d\n", i + 1, static_counter());
    }
    
    // Static variables in regular functions
    printf("\nFunction with static variable:\n");
    for (int i = 0; i < 3; i++) {
        helper_function();
    }
    
    printf("\n");
}

/**
 * Demonstrates variadic functions (functions with variable arguments)
 */
void demonstrate_variadic_functions(void) {
    printf("6. Variadic Functions\n");
    printf("=====================\n");
    
    // Examples of variadic function calls
    printf("Printing integers using variadic function:\n");
    printf("  ");
    print_integers(3, 10, 20, 30);
    printf("  ");
    print_integers(5, 1, 2, 3, 4, 5);
    printf("  ");
    print_integers(1, 42);
    
    printf("\n");
}

/**
 * Demonstrates practical function applications
 */
void demonstrate_practical_functions(void) {
    printf("7. Practical Function Applications\n");
    printf("==================================\n");
    
    // Mathematical functions
    printf("Mathematical functions:\n");
    printf("  power(2.0, 8) = %.0f\n", power(2.0, 8));
    printf("  power(3.0, 4) = %.0f\n", power(3.0, 4));
    
    // Prime number checking
    printf("\nPrime number checking:\n");
    int test_numbers[] = {17, 18, 19, 20, 23, 24, 25};
    int test_count = sizeof(test_numbers) / sizeof(test_numbers[0]);
    
    for (int i = 0; i < test_count; i++) {
        printf("  %d is %s\n", test_numbers[i], 
               is_prime(test_numbers[i]) ? "prime" : "not prime");
    }
    
    // Function composition
    printf("\nFunction composition:\n");
    int base = 3;
    printf("  square(power(%d, 2)) = %d\n", base, square((int)power(base, 2)));
    
    printf("\n");
}

// Function implementations

void greet_user(void) {
    printf("✓ Hello from greet_user function!\n");
}

int add_numbers(int a, int b) {
    return a + b;
}

float calculate_average(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (float)sum / size;
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap_by_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    // Changes are local to this function
}

void swap_by_reference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    // Changes affect the original variables
}

void modify_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Double each element
    }
}

void modify_string(char *str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 'a' + 'A';  // Convert to uppercase
        }
        str++;
    }
}

int factorial_recursive(int n) {
    if (n < 0) return -1;  // Error case
    if (n == 0 || n == 1) return 1;  // Base case
    return n * factorial_recursive(n - 1);  // Recursive case
}

int fibonacci_recursive(int n) {
    if (n < 0) return -1;  // Error case
    if (n == 0) return 0;  // Base case
    if (n == 1) return 1;  // Base case
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);  // Recursive case
}

void print_binary(unsigned int n) {
    if (n > 1) {
        print_binary(n / 2);  // Recursive call
    }
    printf("%d", n % 2);
}

int gcd_recursive(int a, int b) {
    if (b == 0) return a;  // Base case
    return gcd_recursive(b, a % b);  // Recursive case
}

double power(double base, int exp) {
    if (exp == 0) return 1.0;
    if (exp < 0) return 1.0 / power(base, -exp);
    
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int is_prime(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

long long factorial_iterative(int n) {
    if (n < 0) return -1;
    
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int multiply(int a, int b) {
    return a * b;
}

int divide_safe(int a, int b) {
    return (b != 0) ? a / b : 0;
}

void apply_operation(int a, int b, int (*operation)(int, int)) {
    int result = operation(a, b);
    printf("  Callback result: %d\n", result);
}

static int static_counter(void) {
    static int count = 0;  // Static variable retains its value
    return ++count;
}

static void helper_function(void) {
    static int call_count = 0;  // Static variable
    printf("  helper_function called %d time(s)\n", ++call_count);
}

#include <stdarg.h>  // For variadic functions

void print_integers(int count, ...) {
    va_list args;
    va_start(args, count);
    
    for (int i = 0; i < count; i++) {
        int value = va_arg(args, int);
        printf("%d ", value);
    }
    printf("\n");
    
    va_end(args);
}