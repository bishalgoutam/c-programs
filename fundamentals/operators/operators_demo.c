/**
 * Operators - Comprehensive C Examples
 * 
 * This program demonstrates:
 * - Arithmetic operators (+, -, *, /, %)
 * - Relational operators (<, >, <=, >=, ==, !=)
 * - Logical operators (&&, ||, !)
 * - Bitwise operators (&, |, ^, ~, <<, >>)
 * - Assignment operators (=, +=, -=, etc.)
 * - Increment/Decrement operators (++, --)
 * - Conditional operator (?:)
 * - Sizeof and other operators
 * 
 * @author Bishal Goutam
 * @since C99 Standard
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Function prototypes
void demonstrate_arithmetic_operators(void);
void demonstrate_relational_operators(void);
void demonstrate_logical_operators(void);
void demonstrate_bitwise_operators(void);
void demonstrate_assignment_operators(void);
void demonstrate_increment_decrement(void);
void demonstrate_conditional_operator(void);
void demonstrate_misc_operators(void);
void demonstrate_operator_precedence(void);
void demonstrate_practical_examples(void);

// Utility functions
void print_binary(unsigned int n, int bits);
void demonstrate_bitwise_operations(unsigned int a, unsigned int b);

int main(void) {
    printf("=== C Operators Demo ===\n\n");
    
    demonstrate_arithmetic_operators();
    demonstrate_relational_operators();
    demonstrate_logical_operators();
    demonstrate_bitwise_operators();
    demonstrate_assignment_operators();
    demonstrate_increment_decrement();
    demonstrate_conditional_operator();
    demonstrate_misc_operators();
    demonstrate_operator_precedence();
    demonstrate_practical_examples();
    
    return 0;
}

/**
 * Demonstrates arithmetic operators
 */
void demonstrate_arithmetic_operators(void) {
    printf("1. Arithmetic Operators\n");
    printf("=======================\n");
    
    int a = 17, b = 5;
    float x = 17.0f, y = 5.0f;
    
    printf("Integer arithmetic (a = %d, b = %d):\n", a, b);
    printf("  Addition:       a + b = %d\n", a + b);
    printf("  Subtraction:    a - b = %d\n", a - b);
    printf("  Multiplication: a * b = %d\n", a * b);
    printf("  Division:       a / b = %d (integer division)\n", a / b);
    printf("  Modulus:        a %% b = %d (remainder)\n", a % b);
    
    printf("\nFloat arithmetic (x = %.1f, y = %.1f):\n", x, y);
    printf("  Addition:       x + y = %.2f\n", x + y);
    printf("  Subtraction:    x - y = %.2f\n", x - y);
    printf("  Multiplication: x * y = %.2f\n", x * y);
    printf("  Division:       x / y = %.2f (float division)\n", x / y);
    // printf("  Modulus:        x %% y = Not allowed for floats\n");
    
    // Mixed arithmetic
    printf("\nMixed arithmetic:\n");
    printf("  int / int:      %d / %d = %d\n", a, b, a / b);
    printf("  float / int:    %.1f / %d = %.2f\n", x, b, x / b);
    printf("  int / float:    %d / %.1f = %.2f\n", a, y, a / y);
    printf("  (float)int/int: (float)%d / %d = %.2f\n", a, b, (float)a / b);
    
    // Unary operators
    int c = 10;
    printf("\nUnary arithmetic operators (c = %d):\n", c);
    printf("  Unary plus:     +c = %d\n", +c);
    printf("  Unary minus:    -c = %d\n", -c);
    
    printf("\n");
}

/**
 * Demonstrates relational operators
 */
void demonstrate_relational_operators(void) {
    printf("2. Relational Operators\n");
    printf("=======================\n");
    
    int a = 10, b = 20, c = 10;
    
    printf("Comparing integers (a = %d, b = %d, c = %d):\n", a, b, c);
    printf("  a < b:  %d < %d  = %s\n", a, b, (a < b) ? "true" : "false");
    printf("  a > b:  %d > %d  = %s\n", a, b, (a > b) ? "true" : "false");
    printf("  a <= c: %d <= %d = %s\n", a, c, (a <= c) ? "true" : "false");
    printf("  a >= c: %d >= %d = %s\n", a, c, (a >= c) ? "true" : "false");
    printf("  a == c: %d == %d = %s\n", a, c, (a == c) ? "true" : "false");
    printf("  a != b: %d != %d = %s\n", a, b, (a != b) ? "true" : "false");
    
    // String comparison (character by character)
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "World";
    
    printf("\nCharacter comparison:\n");
    printf("  '%c' < '%c': %s\n", str1[0], str3[0], (str1[0] < str3[0]) ? "true" : "false");
    printf("  '%c' == '%c': %s\n", str1[0], str2[0], (str1[0] == str2[0]) ? "true" : "false");
    
    // Floating point comparison
    float x = 3.14f, y = 3.14f, z = 2.71f;
    printf("\nFloat comparison (x = %.2f, y = %.2f, z = %.2f):\n", x, y, z);
    printf("  x == y: %.2f == %.2f = %s\n", x, y, (x == y) ? "true" : "false");
    printf("  x > z:  %.2f > %.2f  = %s\n", x, z, (x > z) ? "true" : "false");
    
    printf("\n");
}

/**
 * Demonstrates logical operators
 */
void demonstrate_logical_operators(void) {
    printf("3. Logical Operators\n");
    printf("====================\n");
    
    bool p = true, q = false;
    int a = 5, b = 0, c = 10;
    
    printf("Boolean logic (p = %s, q = %s):\n", p ? "true" : "false", q ? "true" : "false");
    printf("  p && q: %s && %s = %s\n", p ? "true" : "false", q ? "true" : "false", (p && q) ? "true" : "false");
    printf("  p || q: %s || %s = %s\n", p ? "true" : "false", q ? "true" : "false", (p || q) ? "true" : "false");
    printf("  !p:     !%s = %s\n", p ? "true" : "false", (!p) ? "true" : "false");
    printf("  !q:     !%s = %s\n", q ? "true" : "false", (!q) ? "true" : "false");
    
    printf("\nInteger logic (a = %d, b = %d, c = %d):\n", a, b, c);
    printf("  a && b: %d && %d = %s (non-zero is true)\n", a, b, (a && b) ? "true" : "false");
    printf("  a && c: %d && %d = %s\n", a, c, (a && c) ? "true" : "false");
    printf("  a || b: %d || %d = %s\n", a, b, (a || b) ? "true" : "false");
    printf("  b || 0: %d || 0 = %s\n", b, (b || 0) ? "true" : "false");
    printf("  !a:     !%d = %s\n", a, (!a) ? "true" : "false");
    printf("  !b:     !%d = %s\n", b, (!b) ? "true" : "false");
    
    // Complex logical expressions
    printf("\nComplex expressions:\n");
    printf("  (a > 0) && (c < 20): (%d > 0) && (%d < 20) = %s\n", 
           a, c, ((a > 0) && (c < 20)) ? "true" : "false");
    printf("  (b == 0) || (a == c): (%d == 0) || (%d == %d) = %s\n", 
           b, a, c, ((b == 0) || (a == c)) ? "true" : "false");
    printf("  !(a < c): !(%d < %d) = %s\n", 
           a, c, (!(a < c)) ? "true" : "false");
    
    // Short-circuit evaluation
    printf("\nShort-circuit evaluation:\n");
    printf("  Note: In 'false && anything', the second part is not evaluated\n");
    printf("  Note: In 'true || anything', the second part is not evaluated\n");
    
    printf("\n");
}

/**
 * Demonstrates bitwise operators
 */
void demonstrate_bitwise_operators(void) {
    printf("4. Bitwise Operators\n");
    printf("====================\n");
    
    unsigned int a = 12;  // Binary: 1100
    unsigned int b = 10;  // Binary: 1010
    
    printf("Bitwise operations (a = %u, b = %u):\n", a, b);
    
    printf("  a in binary:        ");
    print_binary(a, 8);
    printf("\n");
    printf("  b in binary:        ");
    print_binary(b, 8);
    printf("\n");
    
    demonstrate_bitwise_operations(a, b);
    
    // Bit shifting
    printf("\nBit shifting operations:\n");
    unsigned int x = 5;  // Binary: 101
    printf("  x = %u (binary: ", x);
    print_binary(x, 8);
    printf(")\n");
    
    printf("  x << 1 = %u (binary: ", x << 1);
    print_binary(x << 1, 8);
    printf(") - Left shift by 1\n");
    
    printf("  x << 2 = %u (binary: ", x << 2);
    print_binary(x << 2, 8);
    printf(") - Left shift by 2\n");
    
    printf("  x >> 1 = %u (binary: ", x >> 1);
    print_binary(x >> 1, 8);
    printf(") - Right shift by 1\n");
    
    // Practical bitwise applications
    printf("\nPractical bitwise applications:\n");
    
    // Check if number is even or odd
    int num = 17;
    printf("  %d is %s (using bitwise AND with 1)\n", 
           num, (num & 1) ? "odd" : "even");
    
    // Power of 2 check
    int pow2_test = 16;
    printf("  %d is %s power of 2 (using (n & (n-1)) == 0)\n", 
           pow2_test, ((pow2_test & (pow2_test - 1)) == 0 && pow2_test > 0) ? "a" : "not a");
    
    // Set, clear, toggle bits
    unsigned int flags = 0;
    printf("  Setting bit 2: flags |= (1 << 2) -> ");
    flags |= (1 << 2);
    print_binary(flags, 8);
    printf("\n");
    
    printf("  Clearing bit 2: flags &= ~(1 << 2) -> ");
    flags &= ~(1 << 2);
    print_binary(flags, 8);
    printf("\n");
    
    printf("  Toggling bit 1: flags ^= (1 << 1) -> ");
    flags ^= (1 << 1);
    print_binary(flags, 8);
    printf("\n");
    
    printf("\n");
}

/**
 * Demonstrates assignment operators
 */
void demonstrate_assignment_operators(void) {
    printf("5. Assignment Operators\n");
    printf("=======================\n");
    
    int a = 10;
    printf("Initial value: a = %d\n", a);
    
    // Compound assignment operators
    printf("\nCompound assignment operators:\n");
    
    a += 5;  // a = a + 5
    printf("  a += 5:  a = %d\n", a);
    
    a -= 3;  // a = a - 3
    printf("  a -= 3:  a = %d\n", a);
    
    a *= 2;  // a = a * 2
    printf("  a *= 2:  a = %d\n", a);
    
    a /= 4;  // a = a / 4
    printf("  a /= 4:  a = %d\n", a);
    
    a %= 3;  // a = a % 3
    printf("  a %%= 3:  a = %d\n", a);
    
    // Bitwise assignment operators
    printf("\nBitwise assignment operators:\n");
    unsigned int b = 12;  // Binary: 1100
    printf("  Initial b = %u (binary: ", b);
    print_binary(b, 8);
    printf(")\n");
    
    b &= 10;  // b = b & 10 (Binary: 1010)
    printf("  b &= 10: b = %u (binary: ", b);
    print_binary(b, 8);
    printf(")\n");
    
    b |= 5;   // b = b | 5 (Binary: 0101)
    printf("  b |= 5:  b = %u (binary: ", b);
    print_binary(b, 8);
    printf(")\n");
    
    b ^= 3;   // b = b ^ 3 (Binary: 0011)
    printf("  b ^= 3:  b = %u (binary: ", b);
    print_binary(b, 8);
    printf(")\n");
    
    b <<= 1;  // b = b << 1
    printf("  b <<= 1: b = %u (binary: ", b);
    print_binary(b, 8);
    printf(")\n");
    
    b >>= 2;  // b = b >> 2
    printf("  b >>= 2: b = %u (binary: ", b);
    print_binary(b, 8);
    printf(")\n");
    
    printf("\n");
}

/**
 * Demonstrates increment and decrement operators
 */
void demonstrate_increment_decrement(void) {
    printf("6. Increment and Decrement Operators\n");
    printf("====================================\n");
    
    int a = 5, b = 5;
    
    printf("Initial values: a = %d, b = %d\n", a, b);
    
    // Pre-increment and post-increment
    printf("\nIncrement operators:\n");
    printf("  ++a (pre-increment):  a becomes %d, expression value = %d\n", ++a, a);
    
    a = 5;  // Reset
    printf("  a++ (post-increment): expression value = %d, a becomes %d\n", a++, a);
    
    // Pre-decrement and post-decrement
    printf("\nDecrement operators:\n");
    a = 5;  // Reset
    printf("  --a (pre-decrement):  a becomes %d, expression value = %d\n", --a, a);
    
    a = 5;  // Reset
    printf("  a-- (post-decrement): expression value = %d, a becomes %d\n", a--, a);
    
    // In expressions
    printf("\nIn complex expressions:\n");
    int x = 10, y = 10;
    int result1 = x++ + ++y;  // 10 + 11 = 21
    printf("  x = 10, y = 10\n");
    printf("  result = x++ + ++y = %d (x is now %d, y is now %d)\n", result1, x, y);
    
    x = 10; y = 10;  // Reset
    int result2 = ++x + y++;  // 11 + 10 = 21
    printf("  x = 10, y = 10 (reset)\n");
    printf("  result = ++x + y++ = %d (x is now %d, y is now %d)\n", result2, x, y);
    
    // Array indexing
    printf("\nWith array indexing:\n");
    int arr[] = {10, 20, 30, 40, 50};
    int index = 0;
    
    printf("  arr[index++] = arr[%d] = %d (index becomes %d)\n", 
           index, arr[index++], index);
    
    printf("  arr[++index] = arr[%d] = %d (index becomes %d)\n", 
           ++index, arr[index], index);
    
    printf("\n");
}

/**
 * Demonstrates conditional (ternary) operator
 */
void demonstrate_conditional_operator(void) {
    printf("7. Conditional (Ternary) Operator\n");
    printf("==================================\n");
    
    int a = 10, b = 20;
    
    // Basic ternary operator
    int max = (a > b) ? a : b;
    printf("max = (a > b) ? a : b = (%d > %d) ? %d : %d = %d\n", a, b, a, b, max);
    
    int min = (a < b) ? a : b;
    printf("min = (a < b) ? a : b = (%d < %d) ? %d : %d = %d\n", a, b, a, b, min);
    
    // Nested ternary operators
    int x = 15, y = 25, z = 20;
    int largest = (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
    printf("\nNested ternary (largest of %d, %d, %d): %d\n", x, y, z, largest);
    
    // Ternary with different types
    printf("\nTernary with different expressions:\n");
    int score = 85;
    char *grade = (score >= 90) ? "A" : 
                  (score >= 80) ? "B" : 
                  (score >= 70) ? "C" : 
                  (score >= 60) ? "D" : "F";
    printf("  Score %d gets grade: %s\n", score, grade);
    
    // Ternary in function calls
    printf("\nTernary in function arguments:\n");
    int positive = -5;
    printf("  abs(%d) = %d (using ternary)\n", positive, (positive >= 0) ? positive : -positive);
    
    // Ternary for output formatting
    printf("\nConditional output:\n");
    int count = 1;
    printf("  Found %d item%s\n", count, (count == 1) ? "" : "s");
    
    count = 3;
    printf("  Found %d item%s\n", count, (count == 1) ? "" : "s");
    
    printf("\n");
}

/**
 * Demonstrates miscellaneous operators
 */
void demonstrate_misc_operators(void) {
    printf("8. Miscellaneous Operators\n");
    printf("==========================\n");
    
    // Sizeof operator
    printf("sizeof operator:\n");
    printf("  sizeof(char):      %zu bytes\n", sizeof(char));
    printf("  sizeof(int):       %zu bytes\n", sizeof(int));
    printf("  sizeof(float):     %zu bytes\n", sizeof(float));
    printf("  sizeof(double):    %zu bytes\n", sizeof(double));
    printf("  sizeof(long long): %zu bytes\n", sizeof(long long));
    
    int arr[10];
    printf("  sizeof(arr):       %zu bytes\n", sizeof(arr));
    printf("  sizeof(arr[0]):    %zu bytes\n", sizeof(arr[0]));
    printf("  Array elements:    %zu\n", sizeof(arr) / sizeof(arr[0]));
    
    // Address-of operator (&)
    printf("\nAddress-of operator (&):\n");
    int var = 42;
    printf("  var = %d, address = %p\n", var, (void*)&var);
    
    // Dereference operator (*)
    printf("\nDereference operator (*):\n");
    int *ptr = &var;
    printf("  ptr points to %p, value = %d\n", (void*)ptr, *ptr);
    
    // Member access operators (. and ->)
    struct Point {
        int x, y;
    };
    
    struct Point p1 = {10, 20};
    struct Point *p_ptr = &p1;
    
    printf("\nMember access operators:\n");
    printf("  p1.x = %d, p1.y = %d (dot operator)\n", p1.x, p1.y);
    printf("  p_ptr->x = %d, p_ptr->y = %d (arrow operator)\n", p_ptr->x, p_ptr->y);
    printf("  (*p_ptr).x = %d (equivalent to arrow)\n", (*p_ptr).x);
    
    // Cast operator
    printf("\nCast operator:\n");
    float f = 3.14159f;
    int i = (int)f;
    printf("  (int)%.5f = %d (truncation)\n", f, i);
    
    void *void_ptr = &var;
    int *int_ptr = (int*)void_ptr;
    printf("  Cast void* to int*: %d\n", *int_ptr);
    
    printf("\n");
}

/**
 * Demonstrates operator precedence and associativity
 */
void demonstrate_operator_precedence(void) {
    printf("9. Operator Precedence and Associativity\n");
    printf("========================================\n");
    
    // Arithmetic precedence
    int result1 = 5 + 3 * 2;
    int result2 = (5 + 3) * 2;
    printf("Arithmetic precedence:\n");
    printf("  5 + 3 * 2 = %d (multiplication first)\n", result1);
    printf("  (5 + 3) * 2 = %d (parentheses override precedence)\n", result2);
    
    // Logical precedence
    bool result3 = true || false && false;  // && has higher precedence
    bool result4 = (true || false) && false;
    printf("\nLogical precedence:\n");
    printf("  true || false && false = %s (&& before ||)\n", result3 ? "true" : "false");
    printf("  (true || false) && false = %s (parentheses first)\n", result4 ? "true" : "false");
    
    // Assignment associativity (right-to-left)
    printf("\nAssignment associativity:\n");
    int a, b, c;
    a = b = c = 10;  // Equivalent to: a = (b = (c = 10))
    printf("  a = b = c = 10 results in: a = %d, b = %d, c = %d\n", a, b, c);
    
    // Complex expression
    printf("\nComplex expression:\n");
    int x = 2, y = 3, z = 4;
    int complex_result = x + y * z / 2 - 1;
    printf("  x + y * z / 2 - 1 where x=2, y=3, z=4\n");
    printf("  = 2 + 3 * 4 / 2 - 1\n");
    printf("  = 2 + 12 / 2 - 1\n");
    printf("  = 2 + 6 - 1\n");
    printf("  = %d\n", complex_result);
    
    printf("\n");
}

/**
 * Demonstrates practical operator applications
 */
void demonstrate_practical_examples(void) {
    printf("10. Practical Applications\n");
    printf("==========================\n");
    
    // Bit manipulation for flags
    printf("Flag management using bitwise operators:\n");
    unsigned int permissions = 0;  // Start with no permissions
    
    #define READ_PERMISSION    (1 << 0)  // Bit 0
    #define WRITE_PERMISSION   (1 << 1)  // Bit 1
    #define EXECUTE_PERMISSION (1 << 2)  // Bit 2
    
    // Grant permissions
    permissions |= READ_PERMISSION;
    permissions |= WRITE_PERMISSION;
    printf("  Granted READ and WRITE: permissions = ");
    print_binary(permissions, 8);
    printf("\n");
    
    // Check permissions
    printf("  Has READ permission: %s\n", 
           (permissions & READ_PERMISSION) ? "Yes" : "No");
    printf("  Has EXECUTE permission: %s\n", 
           (permissions & EXECUTE_PERMISSION) ? "Yes" : "No");
    
    // Revoke permission
    permissions &= ~WRITE_PERMISSION;
    printf("  After revoking WRITE: permissions = ");
    print_binary(permissions, 8);
    printf("\n");
    
    // Mathematical shortcuts
    printf("\nMathematical shortcuts:\n");
    int num = 15;
    printf("  Multiply by 2: %d << 1 = %d\n", num, num << 1);
    printf("  Divide by 4: %d >> 2 = %d\n", num, num >> 2);
    printf("  Check if even: %d & 1 = %d (%s)\n", num, num & 1, (num & 1) ? "odd" : "even");
    
    // Swap without temporary variable
    printf("\nSwap without temporary variable:\n");
    int p = 25, q = 35;
    printf("  Before: p = %d, q = %d\n", p, q);
    
    p = p ^ q;
    q = p ^ q;
    p = p ^ q;
    
    printf("  After XOR swap: p = %d, q = %d\n", p, q);
    
    // Min/Max without branching
    printf("\nMin/Max without if statements:\n");
    int val1 = 10, val2 = 20;
    int max_val = val1 > val2 ? val1 : val2;
    int min_val = val1 < val2 ? val1 : val2;
    printf("  max(%d, %d) = %d\n", val1, val2, max_val);
    printf("  min(%d, %d) = %d\n", val1, val2, min_val);
    
    printf("\n");
}

// Utility function implementations

void print_binary(unsigned int n, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 4 == 0 && i > 0) printf(" ");
    }
}

void demonstrate_bitwise_operations(unsigned int a, unsigned int b) {
    printf("  a & b (AND):        ");
    print_binary(a & b, 8);
    printf(" = %u\n", a & b);
    
    printf("  a | b (OR):         ");
    print_binary(a | b, 8);
    printf(" = %u\n", a | b);
    
    printf("  a ^ b (XOR):        ");
    print_binary(a ^ b, 8);
    printf(" = %u\n", a ^ b);
    
    printf("  ~a (NOT):           ");
    print_binary(~a, 8);
    printf(" = %u\n", (unsigned char)~a);
}