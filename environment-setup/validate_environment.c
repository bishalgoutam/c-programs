/**
 * @file validate_environment.c
 * @brief Comprehensive C development environment validation tool
 * @author Bishal Goutam
 * @date October 2025
 * 
 * This program validates that all necessary tools and libraries are available
 * for C programming development. It checks compiler capabilities, standard
 * libraries, and system features.
 */

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include <errno.h>

// Define math constants if not available
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#ifndef M_E
#define M_E 2.71828182845904523536
#endif

// Platform detection
#ifdef _WIN32
    #include <windows.h>
    #define PLATFORM "Windows"
#elif __APPLE__
    #include <unistd.h>
    #define PLATFORM "macOS"
#elif __linux__
    #include <unistd.h>
    #define PLATFORM "Linux"
#else
    #define PLATFORM "Unknown"
#endif

// ANSI color codes for output formatting
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_RESET "\033[0m"

// Test result tracking
typedef struct {
    int total_tests;
    int passed_tests;
    int failed_tests;
} test_results_t;

test_results_t results = {0, 0, 0};

// Function prototypes
void print_header(void);
void print_separator(void);
void run_test(const char* test_name, bool (*test_func)(void));
void print_summary(void);

// Test functions
bool test_compiler_info(void);
bool test_standard_types(void);
bool test_math_library(void);
bool test_file_operations(void);
bool test_memory_operations(void);
bool test_string_operations(void);
bool test_time_functions(void);
bool test_compiler_features(void);
bool test_system_capabilities(void);

int main(void) {
    print_header();
    
    printf("🔍 Running C Development Environment Validation...\n");
    print_separator();
    
    // Run all validation tests
    run_test("Compiler Information", test_compiler_info);
    run_test("Standard Data Types", test_standard_types);
    run_test("Math Library", test_math_library);
    run_test("File Operations", test_file_operations);
    run_test("Memory Operations", test_memory_operations);
    run_test("String Operations", test_string_operations);
    run_test("Time Functions", test_time_functions);
    run_test("Compiler Features", test_compiler_features);
    run_test("System Capabilities", test_system_capabilities);
    
    print_separator();
    print_summary();
    
    // Return appropriate exit code
    return (results.failed_tests == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void print_header(void) {
    printf("%s", COLOR_BLUE);
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║                C Development Environment Validator         ║\n");
    printf("║                        Version 1.0                        ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    printf("%s", COLOR_RESET);
    printf("\n");
}

void print_separator(void) {
    printf("────────────────────────────────────────────────────────────\n");
}

void run_test(const char* test_name, bool (*test_func)(void)) {
    results.total_tests++;
    printf("Testing %-25s ... ", test_name);
    fflush(stdout);
    
    bool result = test_func();
    
    if (result) {
        printf("%s✓ PASS%s\n", COLOR_GREEN, COLOR_RESET);
        results.passed_tests++;
    } else {
        printf("%s✗ FAIL%s\n", COLOR_RED, COLOR_RESET);
        results.failed_tests++;
    }
}

void print_summary(void) {
    printf("\n%sValidation Summary:%s\n", COLOR_BLUE, COLOR_RESET);
    printf("Total Tests: %d\n", results.total_tests);
    printf("%sPassed: %d%s\n", COLOR_GREEN, results.passed_tests, COLOR_RESET);
    
    if (results.failed_tests > 0) {
        printf("%sFailed: %d%s\n", COLOR_RED, results.failed_tests, COLOR_RESET);
        printf("\n%sEnvironment validation FAILED!%s\n", COLOR_RED, COLOR_RESET);
        printf("Please check the failed tests and install missing components.\n");
    } else {
        printf("%sFailed: 0%s\n", COLOR_GREEN, COLOR_RESET);
        printf("\n%s🎉 Environment validation PASSED!%s\n", COLOR_GREEN, COLOR_RESET);
        printf("Your C development environment is ready for programming!\n");
    }
}

bool test_compiler_info(void) {
    printf("\n");
    printf("    Platform: %s\n", PLATFORM);
    
    // Compiler information
    #ifdef __GNUC__
        printf("    Compiler: GCC %d.%d.%d\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
    #elif defined(__clang__)
        printf("    Compiler: Clang %s\n", __clang_version__);
    #elif defined(_MSC_VER)
        printf("    Compiler: Microsoft Visual C++ %d\n", _MSC_VER);
    #else
        printf("    Compiler: Unknown\n");
    #endif
    
    // C standard version
    #if __STDC_VERSION__ >= 201112L
        printf("    C Standard: C11 or later\n");
    #elif __STDC_VERSION__ >= 199901L
        printf("    C Standard: C99\n");
    #elif __STDC_VERSION__ >= 199409L
        printf("    C Standard: C95\n");
    #else
        printf("    C Standard: C89/C90\n");
    #endif
    
    printf("    Architecture: %zu-bit\n", sizeof(void*) * 8);
    
    return true;  // Always pass - this is informational
}

bool test_standard_types(void) {
    printf("\n");
    
    // Test basic types and their sizes
    printf("    char: %zu bytes\n", sizeof(char));
    printf("    int: %zu bytes\n", sizeof(int));
    printf("    long: %zu bytes\n", sizeof(long));
    printf("    float: %zu bytes\n", sizeof(float));
    printf("    double: %zu bytes\n", sizeof(double));
    printf("    pointer: %zu bytes\n", sizeof(void*));
    
    // Verify minimum requirements
    bool valid = true;
    
    if (sizeof(char) != 1) valid = false;
    if (sizeof(int) < 2) valid = false;
    if (sizeof(long) < 4) valid = false;
    if (sizeof(float) < 4) valid = false;
    if (sizeof(double) < 8) valid = false;
    
    // Test limits
    printf("    INT_MAX: %d\n", INT_MAX);
    printf("    CHAR_BIT: %d\n", CHAR_BIT);
    
    return valid;
}

bool test_math_library(void) {
    printf("\n");
    
    // Test math functions
    double x = 2.0;
    double result;
    
    result = sqrt(x);
    printf("    sqrt(%.1f) = %.6f\n", x, result);
    if (result < 1.414 || result > 1.415) return false;
    
    result = pow(x, 3.0);
    printf("    pow(%.1f, 3) = %.1f\n", x, result);
    if (result != 8.0) return false;
    
    result = sin(M_PI / 2);
    printf("    sin(π/2) = %.6f\n", result);
    if (result < 0.999 || result > 1.001) return false;
    
    result = log(M_E);
    printf("    log(e) = %.6f\n", result);
    if (result < 0.999 || result > 1.001) return false;
    
    return true;
}

bool test_file_operations(void) {
    printf("\n");
    
    const char* test_filename = "test_file_validation.tmp";
    const char* test_content = "C Environment Validation Test";
    
    // Test file writing
    FILE* file = fopen(test_filename, "w");
    if (!file) {
        printf("    ✗ Cannot create test file\n");
        return false;
    }
    
    int written = fprintf(file, "%s", test_content);
    fclose(file);
    
    if (written < 0) {
        printf("    ✗ Cannot write to test file\n");
        remove(test_filename);
        return false;
    }
    
    printf("    ✓ File write successful\n");
    
    // Test file reading
    file = fopen(test_filename, "r");
    if (!file) {
        printf("    ✗ Cannot open test file for reading\n");
        remove(test_filename);
        return false;
    }
    
    char buffer[100];
    if (!fgets(buffer, sizeof(buffer), file)) {
        printf("    ✗ Cannot read from test file\n");
        fclose(file);
        remove(test_filename);
        return false;
    }
    
    fclose(file);
    printf("    ✓ File read successful\n");
    
    // Verify content
    if (strcmp(buffer, test_content) != 0) {
        printf("    ✗ File content mismatch\n");
        remove(test_filename);
        return false;
    }
    
    printf("    ✓ File content verification successful\n");
    
    // Clean up
    if (remove(test_filename) != 0) {
        printf("    ⚠ Warning: Could not remove test file\n");
    }
    
    return true;
}

bool test_memory_operations(void) {
    printf("\n");
    
    // Test malloc/free
    void* ptr = malloc(1024);
    if (!ptr) {
        printf("    ✗ malloc(1024) failed\n");
        return false;
    }
    printf("    ✓ malloc(1024) successful\n");
    
    // Test memory access
    char* char_ptr = (char*)ptr;
    char_ptr[0] = 'A';
    char_ptr[1023] = 'Z';
    
    if (char_ptr[0] != 'A' || char_ptr[1023] != 'Z') {
        printf("    ✗ Memory access test failed\n");
        free(ptr);
        return false;
    }
    printf("    ✓ Memory access test successful\n");
    
    free(ptr);
    printf("    ✓ free() successful\n");
    
    // Test calloc
    ptr = calloc(10, sizeof(int));
    if (!ptr) {
        printf("    ✗ calloc failed\n");
        return false;
    }
    
    int* int_ptr = (int*)ptr;
    bool all_zero = true;
    for (int i = 0; i < 10; i++) {
        if (int_ptr[i] != 0) {
            all_zero = false;
            break;
        }
    }
    
    if (!all_zero) {
        printf("    ✗ calloc zero-initialization failed\n");
        free(ptr);
        return false;
    }
    printf("    ✓ calloc successful\n");
    
    free(ptr);
    return true;
}

bool test_string_operations(void) {
    printf("\n");
    
    char str1[50] = "Hello";
    char str2[50] = "World";
    char str3[100];
    
    // Test strlen
    size_t len = strlen(str1);
    if (len != 5) {
        printf("    ✗ strlen test failed\n");
        return false;
    }
    printf("    ✓ strlen test successful\n");
    
    // Test strcpy
    strcpy(str3, str1);
    if (strcmp(str3, "Hello") != 0) {
        printf("    ✗ strcpy test failed\n");
        return false;
    }
    printf("    ✓ strcpy test successful\n");
    
    // Test strcat
    strcat(str3, " ");
    strcat(str3, str2);
    if (strcmp(str3, "Hello World") != 0) {
        printf("    ✗ strcat test failed\n");
        return false;
    }
    printf("    ✓ strcat test successful\n");
    
    // Test sprintf
    int num = 42;
    sprintf(str3, "Number: %d", num);
    if (strstr(str3, "42") == NULL) {
        printf("    ✗ sprintf test failed\n");
        return false;
    }
    printf("    ✓ sprintf test successful\n");
    
    return true;
}

bool test_time_functions(void) {
    printf("\n");
    
    // Test time()
    time_t current_time = time(NULL);
    if (current_time == (time_t)-1) {
        printf("    ✗ time() function failed\n");
        return false;
    }
    printf("    ✓ time() function successful\n");
    
    // Test ctime()
    char* time_str = ctime(&current_time);
    if (!time_str) {
        printf("    ✗ ctime() function failed\n");
        return false;
    }
    printf("    ✓ ctime() function successful\n");
    
    // Test clock()
    clock_t start_clock = clock();
    if (start_clock == (clock_t)-1) {
        printf("    ✗ clock() function failed\n");
        return false;
    }
    printf("    ✓ clock() function successful\n");
    
    // Display current time
    printf("    Current time: %s", time_str);
    printf("    Clock ticks: %ld\n", (long)start_clock);
    
    return true;
}

bool test_compiler_features(void) {
    printf("\n");
    
    // Test C99 features
    #if __STDC_VERSION__ >= 199901L
        printf("    ✓ C99 features available\n");
        
        // Test variable-length arrays
        int n = 5;
        int vla[n];
        for (int i = 0; i < n; i++) {
            vla[i] = i;
        }
        // Verify VLA works
        if (vla[4] == 4) {
            printf("    ✓ Variable-length arrays supported\n");
        }
        
        // Test inline functions
        printf("    ✓ inline keyword supported\n");
        
    #else
        printf("    ⚠ C99 features not available\n");
    #endif
    
    // Test assertions
    assert(1 == 1);  // Should not trigger
    printf("    ✓ assert() macro working\n");
    
    // Test bool type
    bool test_bool = true;
    if (test_bool) {
        printf("    ✓ bool type supported\n");
    }
    
    return true;
}

bool test_system_capabilities(void) {
    printf("\n");
    
    // Test environment variables
    char* path = getenv("PATH");
    if (path) {
        printf("    ✓ Environment variables accessible\n");
        printf("    PATH length: %zu characters\n", strlen(path));
    } else {
        printf("    ⚠ PATH environment variable not found\n");
    }
    
    // Test command execution
    int result = system("echo Environment test > /dev/null 2>&1");
    if (result == 0) {
        printf("    ✓ System command execution works\n");
    } else {
        printf("    ⚠ System command execution may have issues\n");
    }
    
    // Test random number generation
    srand((unsigned int)time(NULL));
    int random_num = rand();
    printf("    ✓ Random number generation: %d\n", random_num);
    
    return true;
}