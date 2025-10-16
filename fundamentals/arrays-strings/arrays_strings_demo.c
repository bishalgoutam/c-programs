/**
 * Arrays and Strings - Comprehensive C Examples
 * 
 * This program demonstrates:
 * - One-dimensional and multi-dimensional arrays
 * - String handling and manipulation
 * - Array algorithms and operations
 * - Dynamic arrays with malloc/free
 * - String functions from string.h
 * 
 * @author Bishal Goutam
 * @since C99 Standard
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
#define MAX_STRINGS 10

// Function prototypes
void demonstrate_arrays(void);
void demonstrate_multidimensional_arrays(void);
void demonstrate_strings(void);
void demonstrate_string_functions(void);
void demonstrate_dynamic_arrays(void);
void array_algorithms(void);
void string_algorithms(void);

// Utility functions
void print_array(int arr[], int size);
void print_matrix(int rows, int cols, int matrix[rows][cols]);
int linear_search(int arr[], int size, int target);
void bubble_sort(int arr[], int size);

int main(void) {
    printf("=== C Arrays and Strings Demo ===\n\n");
    
    demonstrate_arrays();
    demonstrate_multidimensional_arrays();
    demonstrate_strings();
    demonstrate_string_functions();
    demonstrate_dynamic_arrays();
    array_algorithms();
    string_algorithms();
    
    return 0;
}

/**
 * Demonstrates basic array operations
 */
void demonstrate_arrays(void) {
    printf("1. Basic Arrays\n");
    printf("===============\n");
    
    // Array initialization methods
    int arr1[5] = {1, 2, 3, 4, 5};                    // Complete initialization
    int arr2[5] = {10, 20};                           // Partial initialization
    int arr3[] = {100, 200, 300, 400, 500, 600};     // Size determined by initializer
    int arr4[5];                                       // Uninitialized
    
    // Initialize arr4 manually
    for (int i = 0; i < 5; i++) {
        arr4[i] = (i + 1) * 11;
    }
    
    printf("Array initialization examples:\n");
    printf("  arr1 (complete): ");
    print_array(arr1, 5);
    
    printf("  arr2 (partial): ");
    print_array(arr2, 5);
    
    printf("  arr3 (auto-size): ");
    print_array(arr3, 6);
    
    printf("  arr4 (manual): ");
    print_array(arr4, 5);
    
    // Array properties
    printf("\nArray properties:\n");
    printf("  arr1 size: %zu bytes\n", sizeof(arr1));
    printf("  arr1 elements: %zu\n", sizeof(arr1) / sizeof(arr1[0]));
    printf("  arr3 elements: %zu\n", sizeof(arr3) / sizeof(arr3[0]));
    
    // Array operations
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr1[i];
    }
    printf("  Sum of arr1: %d\n", sum);
    
    printf("\n");
}

/**
 * Demonstrates multi-dimensional arrays
 */
void demonstrate_multidimensional_arrays(void) {
    printf("2. Multi-dimensional Arrays\n");
    printf("===========================\n");
    
    // 2D array initialization
    int matrix[3][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };
    
    // 3D array
    int cube[2][2][2] = {
        {{1, 2}, {3, 4}},
        {{5, 6}, {7, 8}}
    };
    
    printf("2D array (3x4 matrix):\n");
    print_matrix(3, 4, matrix);
    
    printf("\n3D array (2x2x2 cube):\n");
    for (int i = 0; i < 2; i++) {
        printf("  Layer %d:\n", i);
        for (int j = 0; j < 2; j++) {
            printf("    ");
            for (int k = 0; k < 2; k++) {
                printf("%d ", cube[i][j][k]);
            }
            printf("\n");
        }
    }
    
    // Matrix operations
    printf("\nMatrix operations:\n");
    int row_sum = 0;
    for (int j = 0; j < 4; j++) {
        row_sum += matrix[0][j];  // Sum of first row
    }
    printf("  Sum of first row: %d\n", row_sum);
    
    int col_sum = 0;
    for (int i = 0; i < 3; i++) {
        col_sum += matrix[i][0];  // Sum of first column
    }
    printf("  Sum of first column: %d\n", col_sum);
    
    printf("\n");
}

/**
 * Demonstrates string basics
 */
void demonstrate_strings(void) {
    printf("3. String Basics\n");
    printf("================\n");
    
    // String initialization methods
    char str1[] = "Hello, World!";                    // Array initialization
    char str2[20] = "C Programming";                  // Fixed-size array
    char *str3 = "String Literal";                    // Pointer to string literal
    char str4[50];                                     // Uninitialized
    
    // Initialize str4
    strcpy(str4, "Copied String");
    
    printf("String initialization:\n");
    printf("  str1 (array): \"%s\"\n", str1);
    printf("  str2 (fixed): \"%s\"\n", str2);
    printf("  str3 (literal): \"%s\"\n", str3);
    printf("  str4 (copied): \"%s\"\n", str4);
    
    // String properties
    printf("\nString properties:\n");
    printf("  str1 length: %zu\n", strlen(str1));
    printf("  str1 size: %zu bytes\n", sizeof(str1));
    printf("  str2 size: %zu bytes\n", sizeof(str2));
    
    // Character access
    printf("\nCharacter access:\n");
    printf("  str1[0]: '%c'\n", str1[0]);
    printf("  str1[7]: '%c'\n", str1[7]);
    
    // String as character array
    printf("  Characters in str1: ");
    for (int i = 0; str1[i] != '\0'; i++) {
        printf("'%c' ", str1[i]);
    }
    printf("\n");
    
    printf("\n");
}

/**
 * Demonstrates string manipulation functions
 */
void demonstrate_string_functions(void) {
    printf("4. String Functions\n");
    printf("===================\n");
    
    char src[] = "Source String";
    char dest[50] = "Destination: ";
    char buffer[100];
    char input[] = "  Hello, World!  ";
    
    printf("String manipulation:\n");
    printf("  Original dest: \"%s\"\n", dest);
    
    // String concatenation
    strcat(dest, src);
    printf("  After strcat: \"%s\"\n", dest);
    
    // String copy
    strcpy(buffer, "New content");
    printf("  strcpy result: \"%s\"\n", buffer);
    
    // String comparison
    int cmp_result = strcmp("Apple", "Banana");
    printf("  strcmp(\"Apple\", \"Banana\"): %d\n", cmp_result);
    
    // String search
    char text[] = "The quick brown fox jumps over the lazy dog";
    char *found = strstr(text, "fox");
    if (found) {
        printf("  Found \"fox\" at position: %ld\n", found - text);
    }
    
    // Character search
    char *char_pos = strchr(text, 'q');
    if (char_pos) {
        printf("  Found 'q' at position: %ld\n", char_pos - text);
    }
    
    // String length and manipulation
    printf("\nString analysis:\n");
    printf("  Original: \"%s\"\n", input);
    printf("  Length: %zu\n", strlen(input));
    
    // Manual trim (remove leading/trailing spaces)
    char trimmed[50];
    strcpy(trimmed, input);
    
    // Remove leading spaces
    char *start = trimmed;
    while (*start == ' ') start++;
    
    // Remove trailing spaces
    char *end = start + strlen(start) - 1;
    while (end > start && *end == ' ') end--;
    *(end + 1) = '\0';
    
    printf("  Trimmed: \"%s\"\n", start);
    
    printf("\n");
}

/**
 * Demonstrates dynamic arrays
 */
void demonstrate_dynamic_arrays(void) {
    printf("5. Dynamic Arrays\n");
    printf("=================\n");
    
    int size;
    printf("Enter array size: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        size = 5;  // Default size
        printf("Using default size: %d\n", size);
    }
    
    // Allocate memory for array
    int *dynamic_arr = (int*)malloc(size * sizeof(int));
    if (dynamic_arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Initialize array
    printf("Initializing dynamic array:\n");
    for (int i = 0; i < size; i++) {
        dynamic_arr[i] = (i + 1) * 10;
        printf("  dynamic_arr[%d] = %d\n", i, dynamic_arr[i]);
    }
    
    // Resize array (realloc)
    int new_size = size + 3;
    int *resized_arr = (int*)realloc(dynamic_arr, new_size * sizeof(int));
    if (resized_arr != NULL) {
        dynamic_arr = resized_arr;
        
        // Initialize new elements
        for (int i = size; i < new_size; i++) {
            dynamic_arr[i] = (i + 1) * 10;
        }
        
        printf("\nAfter resize (size %d -> %d):\n", size, new_size);
        print_array(dynamic_arr, new_size);
        size = new_size;
    }
    
    // Dynamic 2D array
    int rows = 3, cols = 4;
    int **matrix_2d = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix_2d[i] = (int*)malloc(cols * sizeof(int));
    }
    
    // Initialize 2D array
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix_2d[i][j] = value++;
        }
    }
    
    printf("\nDynamic 2D array (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        printf("  ");
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix_2d[i][j]);
        }
        printf("\n");
    }
    
    // Free memory
    free(dynamic_arr);
    for (int i = 0; i < rows; i++) {
        free(matrix_2d[i]);
    }
    free(matrix_2d);
    
    printf("Dynamic memory freed successfully.\n\n");
}

/**
 * Demonstrates array algorithms
 */
void array_algorithms(void) {
    printf("6. Array Algorithms\n");
    printf("===================\n");
    
    int numbers[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Original array: ");
    print_array(numbers, size);
    
    // Linear search
    int target = 22;
    int index = linear_search(numbers, size, target);
    if (index != -1) {
        printf("Found %d at index %d\n", target, index);
    } else {
        printf("%d not found in array\n", target);
    }
    
    // Find maximum and minimum
    int max = numbers[0], min = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) max = numbers[i];
        if (numbers[i] < min) min = numbers[i];
    }
    printf("Maximum: %d, Minimum: %d\n", max, min);
    
    // Calculate average
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    printf("Average: %.2f\n", (float)sum / size);
    
    // Sort array
    bubble_sort(numbers, size);
    printf("Sorted array: ");
    print_array(numbers, size);
    
    printf("\n");
}

/**
 * Demonstrates string algorithms
 */
void string_algorithms(void) {
    printf("7. String Algorithms\n");
    printf("====================\n");
    
    char text[] = "The Quick Brown Fox Jumps Over The Lazy Dog";
    char word[] = "programming";
    
    printf("Original text: \"%s\"\n", text);
    
    // Count characters
    int char_count[256] = {0};  // ASCII character count
    for (int i = 0; text[i]; i++) {
        char_count[(unsigned char)text[i]]++;
    }
    
    printf("Character frequency:\n");
    for (int i = 0; i < 256; i++) {
        if (char_count[i] > 0 && isprint(i)) {
            printf("  '%c': %d\n", i, char_count[i]);
        }
    }
    
    // Convert to lowercase
    char lowercase[100];
    strcpy(lowercase, text);
    for (int i = 0; lowercase[i]; i++) {
        lowercase[i] = tolower(lowercase[i]);
    }
    printf("Lowercase: \"%s\"\n", lowercase);
    
    // Reverse string
    char reversed[50];
    strcpy(reversed, word);
    int len = strlen(reversed);
    for (int i = 0; i < len / 2; i++) {
        char temp = reversed[i];
        reversed[i] = reversed[len - 1 - i];
        reversed[len - 1 - i] = temp;
    }
    printf("Reversed \"%s\": \"%s\"\n", word, reversed);
    
    // Check palindrome
    char test_palindrome[] = "racecar";
    int is_palindrome = 1;
    int test_len = strlen(test_palindrome);
    for (int i = 0; i < test_len / 2; i++) {
        if (test_palindrome[i] != test_palindrome[test_len - 1 - i]) {
            is_palindrome = 0;
            break;
        }
    }
    printf("\"%s\" is %sa palindrome\n", test_palindrome, 
           is_palindrome ? "" : "not ");
    
    printf("\n");
}

/**
 * Utility function to print an array
 */
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * Utility function to print a 2D matrix
 */
void print_matrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        printf("  ");
        for (int j = 0; j < cols; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * Linear search algorithm
 */
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

/**
 * Bubble sort algorithm
 */
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}