/**
 * Control Structures - Comprehensive C Examples
 * 
 * This program demonstrates:
 * - Conditional statements (if, if-else, nested if, switch)
 * - Loop structures (for, while, do-while, nested loops)
 * - Jump statements (break, continue, goto, return)
 * - Practical applications and best practices
 * 
 * @author Bishal Goutam
 * @since C99 Standard
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function prototypes
void demonstrate_if_statements(void);
void demonstrate_switch_statements(void);
void demonstrate_for_loops(void);
void demonstrate_while_loops(void);
void demonstrate_do_while_loops(void);
void demonstrate_nested_loops(void);
void demonstrate_jump_statements(void);
void demonstrate_practical_examples(void);

// Utility functions
void print_menu(void);
int get_user_choice(void);
void print_multiplication_table(int n);
void find_prime_numbers(int limit);
int calculate_factorial(int n);

int main(void) {
    printf("=== C Control Structures Demo ===\n\n");
    
    demonstrate_if_statements();
    demonstrate_switch_statements();
    demonstrate_for_loops();
    demonstrate_while_loops();
    demonstrate_do_while_loops();
    demonstrate_nested_loops();
    demonstrate_jump_statements();
    demonstrate_practical_examples();
    
    return 0;
}

/**
 * Demonstrates if statements and conditional logic
 */
void demonstrate_if_statements(void) {
    printf("1. If Statements and Conditional Logic\n");
    printf("======================================\n");
    
    int age = 25;
    float temperature = 98.6f;
    char grade = 'B';
    
    // Simple if statement
    if (age >= 18) {
        printf("✓ Age %d: You are an adult\n", age);
    }
    
    // If-else statement
    if (temperature > 100.0f) {
        printf("✓ Temperature %.1f°F: You have a fever\n", temperature);
    } else {
        printf("✓ Temperature %.1f°F: Normal temperature\n", temperature);
    }
    
    // If-else-if ladder
    if (grade == 'A') {
        printf("✓ Grade %c: Excellent!\n", grade);
    } else if (grade == 'B') {
        printf("✓ Grade %c: Good job!\n", grade);
    } else if (grade == 'C') {
        printf("✓ Grade %c: Average performance\n", grade);
    } else if (grade == 'D') {
        printf("✓ Grade %c: Below average\n", grade);
    } else {
        printf("✓ Grade %c: Failing\n", grade);
    }
    
    // Nested if statements
    int score = 85;
    if (score >= 60) {
        printf("✓ Score %d: Passing grade", score);
        if (score >= 90) {
            printf(" - Outstanding!\n");
        } else if (score >= 80) {
            printf(" - Very good!\n");
        } else {
            printf(" - Satisfactory\n");
        }
    } else {
        printf("✓ Score %d: Failing grade\n", score);
    }
    
    // Logical operators
    int x = 10, y = 20, z = 15;
    if (x < y && y > z) {
        printf("✓ Logical AND: x < y AND y > z is true\n");
    }
    
    if (x > 5 || y < 10) {
        printf("✓ Logical OR: x > 5 OR y < 10 is true\n");
    }
    
    if (!(x > y)) {
        printf("✓ Logical NOT: NOT(x > y) is true\n");
    }
    
    // Ternary operator
    int max = (x > y) ? x : y;
    printf("✓ Ternary operator: max(%d, %d) = %d\n", x, y, max);
    
    printf("\n");
}

/**
 * Demonstrates switch statements
 */
void demonstrate_switch_statements(void) {
    printf("2. Switch Statements\n");
    printf("====================\n");
    
    // Basic switch statement
    int day = 3;
    printf("Day %d is: ", day);
    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
        case 7:
            printf("Weekend\n");
            break;
        default:
            printf("Invalid day\n");
            break;
    }
    
    // Switch with character
    char operation = '+';
    int a = 10, b = 5;
    printf("Calculator: %d %c %d = ", a, operation, b);
    
    switch (operation) {
        case '+':
            printf("%d\n", a + b);
            break;
        case '-':
            printf("%d\n", a - b);
            break;
        case '*':
            printf("%d\n", a * b);
            break;
        case '/':
            if (b != 0) {
                printf("%.2f\n", (float)a / b);
            } else {
                printf("Error: Division by zero\n");
            }
            break;
        case '%':
            if (b != 0) {
                printf("%d\n", a % b);
            } else {
                printf("Error: Modulo by zero\n");
            }
            break;
        default:
            printf("Error: Unknown operation\n");
            break;
    }
    
    // Switch with fallthrough (no break)
    int month = 4;
    printf("Month %d has ", month);
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            printf("31 days\n");
            break;
        case 4: case 6: case 9: case 11:
            printf("30 days\n");
            break;
        case 2:
            printf("28 or 29 days\n");
            break;
        default:
            printf("Invalid month\n");
            break;
    }
    
    printf("\n");
}

/**
 * Demonstrates for loops
 */
void demonstrate_for_loops(void) {
    printf("3. For Loops\n");
    printf("============\n");
    
    // Basic for loop
    printf("Basic for loop (0 to 4): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    // For loop with different increment
    printf("Step by 2 (0 to 8): ");
    for (int i = 0; i <= 8; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    
    // Reverse for loop
    printf("Reverse loop (10 to 1): ");
    for (int i = 10; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");
    
    // For loop with array
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // Multiple variables in for loop
    printf("Multiple variables: ");
    for (int i = 0, j = 10; i < 5; i++, j--) {
        printf("(%d,%d) ", i, j);
    }
    printf("\n");
    
    // Infinite for loop (commented out for safety)
    /*
    for (;;) {
        printf("This would run forever\n");
        break; // Must have break to exit
    }
    */
    
    printf("\n");
}

/**
 * Demonstrates while loops
 */
void demonstrate_while_loops(void) {
    printf("4. While Loops\n");
    printf("==============\n");
    
    // Basic while loop
    printf("Basic while loop: ");
    int i = 0;
    while (i < 5) {
        printf("%d ", i);
        i++;
    }
    printf("\n");
    
    // While loop with condition
    printf("Powers of 2 (less than 100): ");
    int power = 1;
    while (power < 100) {
        printf("%d ", power);
        power *= 2;
    }
    printf("\n");
    
    // While loop for input validation
    printf("Simulated input validation (finding 'q'): ");
    char chars[] = "hello world q";
    int index = 0;
    while (chars[index] != 'q' && chars[index] != '\0') {
        printf("%c", chars[index]);
        index++;
    }
    printf(" -> Found '%c' at position %d\n", chars[index], index);
    
    // While loop with user input simulation
    printf("Number guessing simulation: ");
    int secret = 7;
    int guesses[] = {3, 5, 7}; // Simulated guesses
    int guess_count = 0;
    int current_guess;
    
    while (guess_count < 3) {
        current_guess = guesses[guess_count];
        printf("Guess: %d ", current_guess);
        
        if (current_guess == secret) {
            printf("-> Correct!\n");
            break;
        } else if (current_guess < secret) {
            printf("-> Too low! ");
        } else {
            printf("-> Too high! ");
        }
        guess_count++;
    }
    
    printf("\n");
}

/**
 * Demonstrates do-while loops
 */
void demonstrate_do_while_loops(void) {
    printf("5. Do-While Loops\n");
    printf("=================\n");
    
    // Basic do-while loop
    printf("Basic do-while loop: ");
    int i = 0;
    do {
        printf("%d ", i);
        i++;
    } while (i < 5);
    printf("\n");
    
    // Do-while vs while comparison
    printf("Do-while vs while with false condition:\n");
    
    // Do-while executes at least once
    printf("  Do-while: ");
    int j = 10;
    do {
        printf("%d ", j);  // This executes once
        j++;
    } while (j < 5);  // Condition is false
    printf("(executed once despite false condition)\n");
    
    // While loop doesn't execute
    printf("  While: ");
    int k = 10;
    while (k < 5) {  // Condition is false
        printf("%d ", k);  // This never executes
        k++;
    }
    printf("(never executed due to false condition)\n");
    
    // Menu simulation with do-while
    printf("Menu simulation:\n");
    int choice;
    int menu_options[] = {1, 2, 0}; // Simulated user choices
    int option_index = 0;
    
    do {
        printf("  1. Option 1\n");
        printf("  2. Option 2\n");
        printf("  0. Exit\n");
        
        choice = menu_options[option_index++];
        printf("  Choice: %d -> ", choice);
        
        switch (choice) {
            case 1:
                printf("Selected Option 1\n");
                break;
            case 2:
                printf("Selected Option 2\n");
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 0 && option_index < 3);
    
    printf("\n");
}

/**
 * Demonstrates nested loops
 */
void demonstrate_nested_loops(void) {
    printf("6. Nested Loops\n");
    printf("===============\n");
    
    // Simple nested loops - multiplication table
    printf("Multiplication table (1-3):\n");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("%d x %d = %2d  ", i, j, i * j);
        }
        printf("\n");
    }
    
    // Pattern printing
    printf("\nPattern 1 (Right triangle):\n");
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    printf("\nPattern 2 (Number pyramid):\n");
    for (int i = 1; i <= 4; i++) {
        // Print spaces
        for (int j = 1; j <= 4 - i; j++) {
            printf(" ");
        }
        // Print numbers
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    
    // Matrix operations
    printf("\nMatrix addition:\n");
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[3][3];
    
    // Calculate sum
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    // Print result
    for (int i = 0; i < 3; i++) {
        printf("  ");
        for (int j = 0; j < 3; j++) {
            printf("%2d ", result[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
}

/**
 * Demonstrates jump statements
 */
void demonstrate_jump_statements(void) {
    printf("7. Jump Statements\n");
    printf("==================\n");
    
    // Break statement
    printf("Break statement (exit loop at 3): ");
    for (int i = 0; i < 10; i++) {
        if (i == 3) {
            break;
        }
        printf("%d ", i);
    }
    printf("-> Exited at %d\n", 3);
    
    // Continue statement
    printf("Continue statement (skip even numbers): ");
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            continue;
        }
        printf("%d ", i);
    }
    printf("\n");
    
    // Break in nested loops
    printf("Break in nested loops (find first 5):\n");
    for (int i = 0; i < 5; i++) {
        printf("  Row %d: ", i);
        for (int j = 0; j < 10; j++) {
            if (j == 5) {
                printf("-> Found 5, breaking inner loop");
                break;
            }
            printf("%d ", j);
        }
        printf("\n");
    }
    
    // Label and goto (use sparingly)
    printf("Goto statement example (exit nested loops):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("(%d,%d) ", i, j);
            if (i == 1 && j == 1) {
                printf("-> Going to end");
                goto end_loops;
            }
        }
        printf("\n  ");
    }
    
    end_loops:
    printf("\nReached end via goto\n");
    
    printf("\n");
}

/**
 * Demonstrates practical applications
 */
void demonstrate_practical_examples(void) {
    printf("8. Practical Examples\n");
    printf("=====================\n");
    
    // Prime number checker
    int test_numbers[] = {17, 18, 19, 20};
    int test_count = sizeof(test_numbers) / sizeof(test_numbers[0]);
    
    printf("Prime number checking:\n");
    for (int i = 0; i < test_count; i++) {
        int num = test_numbers[i];
        int is_prime = 1;
        
        if (num < 2) {
            is_prime = 0;
        } else {
            for (int j = 2; j * j <= num; j++) {
                if (num % j == 0) {
                    is_prime = 0;
                    break;
                }
            }
        }
        
        printf("  %d is %s\n", num, is_prime ? "prime" : "not prime");
    }
    
    // Factorial calculation
    printf("\nFactorial calculations:\n");
    for (int i = 0; i <= 5; i++) {
        printf("  %d! = %d\n", i, calculate_factorial(i));
    }
    
    // Fibonacci sequence
    printf("\nFibonacci sequence (first 10 terms): ");
    int fib1 = 0, fib2 = 1, next;
    printf("%d %d ", fib1, fib2);
    
    for (int i = 2; i < 10; i++) {
        next = fib1 + fib2;
        printf("%d ", next);
        fib1 = fib2;
        fib2 = next;
    }
    printf("\n");
    
    // Number reversal
    int original = 12345;
    int reversed = 0;
    int temp = original;
    
    while (temp > 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }
    
    printf("\nNumber reversal: %d -> %d\n", original, reversed);
    
    // Perfect number check
    int perfect_candidate = 28;
    int sum_of_divisors = 0;
    
    for (int i = 1; i < perfect_candidate; i++) {
        if (perfect_candidate % i == 0) {
            sum_of_divisors += i;
        }
    }
    
    printf("Perfect number check: %d is %s (sum of divisors: %d)\n", 
           perfect_candidate, 
           (sum_of_divisors == perfect_candidate) ? "perfect" : "not perfect",
           sum_of_divisors);
    
    printf("\n");
}

/**
 * Calculate factorial using iterative approach
 */
int calculate_factorial(int n) {
    if (n < 0) return -1; // Error case
    if (n == 0 || n == 1) return 1;
    
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}