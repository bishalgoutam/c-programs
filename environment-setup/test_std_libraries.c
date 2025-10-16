/**
 * @file test_std_libraries.c
 * @brief Test availability and functionality of standard C libraries
 * @author Bishal Goutam
 * @date October 2025
 * 
 * This program tests the availability and basic functionality of
 * standard C libraries to ensure proper development environment setup.
 */

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <assert.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <stddef.h>

// Define math constants if not available
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Test C99 and later headers if available
#if __STDC_VERSION__ >= 199901L
    #include <stdbool.h>
    #include <stdint.h>
    #include <inttypes.h>
    #include <complex.h>
    #include <tgmath.h>
    #include <fenv.h>
    #include <iso646.h>
#endif

// Test C11 headers if available
#if __STDC_VERSION__ >= 201112L
    #include <stdalign.h>
    #include <stdatomic.h>
    #include <stdnoreturn.h>
    #include <threads.h>
    #include <uchar.h>
#endif

int main(void) {
    printf("=== Standard C Library Availability Test ===\n\n");

    // Core libraries test
    printf("📚 Core Standard Libraries:\n");
    printf("✓ stdio.h     - Standard Input/Output\n");
    printf("✓ stdlib.h    - General Utilities\n");
    printf("✓ string.h    - String Handling\n");
    printf("✓ math.h      - Mathematics\n");
    printf("✓ time.h      - Date and Time\n");
    printf("✓ ctype.h     - Character Handling\n");
    printf("✓ limits.h    - Implementation Limits\n");
    printf("✓ float.h     - Floating Point Characteristics\n");
    printf("✓ errno.h     - Error Codes\n");
    printf("✓ assert.h    - Assertion Facility\n");
    printf("✓ stdarg.h    - Variable Arguments\n");
    printf("✓ setjmp.h    - Non-local Jumps\n");
    printf("✓ signal.h    - Signal Handling\n");
    printf("✓ stddef.h    - Common Definitions\n");

    // C99 libraries test
    printf("\n📚 C99 Standard Libraries:\n");
    #if __STDC_VERSION__ >= 199901L
        printf("✓ stdbool.h   - Boolean Type\n");
        printf("✓ stdint.h    - Integer Types\n");
        printf("✓ inttypes.h  - Format Conversion\n");
        printf("✓ complex.h   - Complex Arithmetic\n");
        printf("✓ tgmath.h    - Type-generic Math\n");
        printf("✓ fenv.h      - Floating-point Environment\n");
        printf("✓ iso646.h    - Alternative Operators\n");
    #else
        printf("⚠ C99 libraries not available (using pre-C99 compiler)\n");
    #endif

    // C11 libraries test
    printf("\n📚 C11 Standard Libraries:\n");
    #if __STDC_VERSION__ >= 201112L
        printf("✓ stdalign.h  - Alignment\n");
        printf("✓ stdatomic.h - Atomic Operations\n");
        printf("✓ stdnoreturn.h - Non-returning Functions\n");
        printf("✓ threads.h   - Thread Support\n");
        printf("✓ uchar.h     - Unicode Utilities\n");
    #else
        printf("⚠ C11 libraries not available (using pre-C11 compiler)\n");
    #endif

    printf("\n🧪 Functional Tests:\n");

    // Test stdio.h
    printf("\n1. Testing stdio.h:\n");
    FILE* test_file = fopen("test_stdio.tmp", "w");
    if (test_file) {
        fprintf(test_file, "Test content");
        fclose(test_file);
        printf("   ✓ File operations working\n");
        remove("test_stdio.tmp");
    } else {
        printf("   ✗ File operations failed\n");
    }

    // Test stdlib.h
    printf("\n2. Testing stdlib.h:\n");
    void* ptr = malloc(100);
    if (ptr) {
        printf("   ✓ Dynamic memory allocation working\n");
        free(ptr);
    } else {
        printf("   ✗ Dynamic memory allocation failed\n");
    }
    
    srand(42);
    int random_val = rand();
    printf("   ✓ Random number generation: %d\n", random_val);

    // Test string.h
    printf("\n3. Testing string.h:\n");
    char str1[20] = "Hello";
    char str2[20] = "World";
    char str3[50];
    
    strcpy(str3, str1);
    strcat(str3, " ");
    strcat(str3, str2);
    
    if (strcmp(str3, "Hello World") == 0) {
        printf("   ✓ String operations working: '%s'\n", str3);
    } else {
        printf("   ✗ String operations failed\n");
    }

    // Test math.h
    printf("\n4. Testing math.h:\n");
    double x = 4.0;
    double sqrt_result = sqrt(x);
    double pow_result = pow(2.0, 3.0);
    double sin_result = sin(M_PI / 2);
    
    printf("   ✓ sqrt(%.1f) = %.2f\n", x, sqrt_result);
    printf("   ✓ pow(2, 3) = %.1f\n", pow_result);
    printf("   ✓ sin(π/2) = %.6f\n", sin_result);

    // Test time.h
    printf("\n5. Testing time.h:\n");
    time_t current_time = time(NULL);
    struct tm* time_info = localtime(&current_time);
    
    if (time_info) {
        printf("   ✓ Current year: %d\n", time_info->tm_year + 1900);
        printf("   ✓ Current month: %d\n", time_info->tm_mon + 1);
        printf("   ✓ Current day: %d\n", time_info->tm_mday);
    } else {
        printf("   ✗ Time functions failed\n");
    }

    // Test ctype.h
    printf("\n6. Testing ctype.h:\n");
    char test_char = 'A';
    printf("   ✓ isalpha('%c'): %s\n", test_char, isalpha(test_char) ? "true" : "false");
    printf("   ✓ isdigit('5'): %s\n", isdigit('5') ? "true" : "false");
    printf("   ✓ tolower('%c'): '%c'\n", test_char, tolower(test_char));

    // Test limits.h
    printf("\n7. Testing limits.h:\n");
    printf("   ✓ CHAR_BIT: %d\n", CHAR_BIT);
    printf("   ✓ INT_MAX: %d\n", INT_MAX);
    printf("   ✓ INT_MIN: %d\n", INT_MIN);
    printf("   ✓ LONG_MAX: %ld\n", LONG_MAX);

    // Test float.h
    printf("\n8. Testing float.h:\n");
    printf("   ✓ FLT_MAX: %g\n", FLT_MAX);
    printf("   ✓ DBL_MAX: %g\n", DBL_MAX);
    printf("   ✓ FLT_DIG: %d\n", FLT_DIG);
    printf("   ✓ DBL_DIG: %d\n", DBL_DIG);

    // Test errno.h
    printf("\n9. Testing errno.h:\n");
    errno = 0;
    FILE* nonexistent = fopen("nonexistent_file_12345.txt", "r");
    if (!nonexistent && errno != 0) {
        printf("   ✓ errno mechanism working (errno: %d)\n", errno);
    } else {
        printf("   ⚠ errno mechanism may not be working properly\n");
    }

    // Test assert.h
    printf("\n10. Testing assert.h:\n");
    assert(1 == 1);  // Should not abort
    printf("   ✓ assert() macro working\n");

    // Test C99 specific features
    #if __STDC_VERSION__ >= 199901L
        printf("\n11. Testing C99 features:\n");
        
        // Test stdbool.h
        bool test_bool = true;
        printf("   ✓ bool type: %s\n", test_bool ? "true" : "false");
        
        // Test stdint.h
        uint32_t test_uint32 = 0x12345678;
        int64_t test_int64 = -1234567890123LL;
        printf("   ✓ uint32_t: 0x%08X\n", test_uint32);
        printf("   ✓ int64_t: %lld\n", (long long)test_int64);
        
        // Test variable-length arrays
        int n = 5;
        int vla[n];
        for (int i = 0; i < n; i++) {
            vla[i] = i * i;
        }
        // Verify VLA works
        if (vla[4] == 16) {
            printf("   ✓ Variable-length arrays working\n");
        }
        
        // Test complex numbers
        #ifdef __STDC_NO_COMPLEX__
            printf("   ⚠ Complex numbers not supported\n");
        #else
            double complex z = 1.0 + 2.0 * I;
            printf("   ✓ Complex numbers: %.1f + %.1fi\n", creal(z), cimag(z));
        #endif
    #endif

    // Test C11 specific features
    #if __STDC_VERSION__ >= 201112L
        printf("\n12. Testing C11 features:\n");
        
        // Test static_assert
        _Static_assert(sizeof(int) >= 2, "int must be at least 2 bytes");
        printf("   ✓ _Static_assert working\n");
        
        // Test _Alignof
        printf("   ✓ _Alignof(int): %zu\n", _Alignof(int));
        printf("   ✓ _Alignof(double): %zu\n", _Alignof(double));
        
        // Test _Generic (if supported)
        #define TYPE_NAME(x) _Generic((x), \
            int: "int", \
            float: "float", \
            double: "double", \
            default: "unknown")
        
        int test_int = 42;
        float test_float = 3.14f;
        printf("   ✓ _Generic: %d is %s\n", test_int, TYPE_NAME(test_int));
        printf("   ✓ _Generic: %.2f is %s\n", test_float, TYPE_NAME(test_float));
    #endif

    printf("\n🎉 Standard library test completed!\n");
    printf("\nCompiler Information:\n");
    
    #ifdef __GNUC__
        printf("   Compiler: GCC %d.%d.%d\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
    #elif defined(__clang__)
        printf("   Compiler: Clang %s\n", __clang_version__);
    #elif defined(_MSC_VER)
        printf("   Compiler: Microsoft Visual C++ %d\n", _MSC_VER);
    #else
        printf("   Compiler: Unknown\n");
    #endif

    #if defined(__STDC_VERSION__)
        printf("   C Standard: ");
        #if __STDC_VERSION__ >= 201710L
            printf("C18\n");
        #elif __STDC_VERSION__ >= 201112L
            printf("C11\n");
        #elif __STDC_VERSION__ >= 199901L
            printf("C99\n");
        #elif __STDC_VERSION__ >= 199409L
            printf("C95\n");
        #else
            printf("C90\n");
        #endif
    #else
        printf("   C Standard: Pre-C90 or unknown\n");
    #endif

    printf("   Architecture: %zu-bit\n", sizeof(void*) * 8);
    
    return 0;
}