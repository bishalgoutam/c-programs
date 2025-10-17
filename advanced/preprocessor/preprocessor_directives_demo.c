/**
 * Preprocessor Directives - Comprehensive C Implementation
 * 
 * This program demonstrates:
 * - Macro definitions and function-like macros
 * - Conditional compilation directives
 * - File inclusion and header guards
 * - Predefined macros and compiler information
 * - Macro operators (stringification, token pasting)
 * - Pragma directives and compiler-specific features
 * - Debug and release build configurations
 * - Platform-specific conditional compilation
 * - Advanced macro techniques and best practices
 * - Macro pitfalls and how to avoid them
 * 
 * @author Bishal Goutam
 * @since C99 Standard
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <math.h>

// Basic macro definitions
#define PI 3.14159265359
#define MAX_SIZE 1000
#define BUFFER_SIZE 256
#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define VERSION_PATCH 0

// Function-like macros
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define CLAMP(x, min, max) (MIN(MAX((x), (min)), (max)))

// Multi-line macros using backslash continuation
#define SWAP(a, b, type) do { \
    type temp = (a); \
    (a) = (b); \
    (b) = temp; \
} while(0)

// Stringification operator (#)
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

// Token pasting operator (##)
#define CONCAT(a, b) a ## b
#define MAKE_FUNCTION(name) CONCAT(function_, name)

// Variadic macros (C99)
#define DEBUG_PRINT(level, ...) \
    printf("[DEBUG %d] " __VA_ARGS__, level)

#define LOG_ERROR(...) \
    fprintf(stderr, "[ERROR] %s:%d: ", __FILE__, __LINE__); \
    fprintf(stderr, __VA_ARGS__); \
    fprintf(stderr, "\n")

// Conditional compilation
#ifdef DEBUG
    #define DBG_PRINT(fmt, ...) printf("DEBUG: " fmt "\n", ##__VA_ARGS__)
#else
    #define DBG_PRINT(fmt, ...) /* Nothing */
#endif

// Platform-specific macros
#ifdef _WIN32
    #define PLATFORM "Windows"
    #define PATH_SEPARATOR '\\'
    #include <windows.h>
#elif defined(__linux__)
    #define PLATFORM "Linux"
    #define PATH_SEPARATOR '/'
    #include <unistd.h>
#elif defined(__APPLE__)
    #define PLATFORM "macOS"
    #define PATH_SEPARATOR '/'
    #include <unistd.h>
#else
    #define PLATFORM "Unknown"
    #define PATH_SEPARATOR '/'
#endif

// Compiler-specific macros
#if defined(__GNUC__)
    #define COMPILER "GCC"
    #define FORCE_INLINE __attribute__((always_inline)) inline
    #define PACKED __attribute__((packed))
    #define UNUSED __attribute__((unused))
#elif defined(_MSC_VER)
    #define COMPILER "MSVC"
    #define FORCE_INLINE __forceinline
    #define PACKED
    #define UNUSED
#elif defined(__clang__)
    #define COMPILER "Clang"
    #define FORCE_INLINE __attribute__((always_inline)) inline
    #define PACKED __attribute__((packed))
    #define UNUSED __attribute__((unused))
#else
    #define COMPILER "Unknown"
    #define FORCE_INLINE inline
    #define PACKED
    #define UNUSED
#endif

// Configuration macros
#define CONFIG_MAX_USERS 100
#define CONFIG_TIMEOUT 30
#define CONFIG_BUFFER_SIZE 4096

// Feature flags
#define FEATURE_LOGGING 1
#define FEATURE_ENCRYPTION 0
#define FEATURE_COMPRESSION 1

// Advanced macro techniques
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define OFFSET_OF(type, member) ((size_t)&((type*)0)->member)
#define CONTAINER_OF(ptr, type, member) \
    ((type*)((char*)(ptr) - OFFSET_OF(type, member)))

// Macro for loop unrolling
#define UNROLL_4(statement) do { \
    statement; \
    statement; \
    statement; \
    statement; \
} while(0)

// Error handling macros
#define CHECK_NULL(ptr) do { \
    if ((ptr) == NULL) { \
        LOG_ERROR("Null pointer: %s", #ptr); \
        return -1; \
    } \
} while(0)

#define ASSERT_MSG(condition, message) do { \
    if (!(condition)) { \
        LOG_ERROR("Assertion failed: %s - %s", #condition, message); \
        abort(); \
    } \
} while(0)

// Benchmarking macros
#define BENCHMARK_START() \
    clock_t _benchmark_start = clock()

#define BENCHMARK_END(name) do { \
    clock_t _benchmark_end = clock(); \
    double _benchmark_time = ((double)(_benchmark_end - _benchmark_start)) / CLOCKS_PER_SEC; \
    printf("Benchmark %s: %.6f seconds\n", name, _benchmark_time); \
} while(0)

// Version checking macros
#if __STDC_VERSION__ >= 199901L
    #define C99_SUPPORTED 1
#else
    #define C99_SUPPORTED 0
#endif

#if __STDC_VERSION__ >= 201112L
    #define C11_SUPPORTED 1
#else
    #define C11_SUPPORTED 0
#endif

// Function prototypes
void demonstrate_basic_macros(void);
void demonstrate_function_like_macros(void);
void demonstrate_conditional_compilation(void);
void demonstrate_predefined_macros(void);
void demonstrate_stringification_and_pasting(void);
void demonstrate_variadic_macros(void);
void demonstrate_platform_detection(void);
void demonstrate_compiler_detection(void);
void demonstrate_advanced_techniques(void);
void demonstrate_macro_pitfalls(void);
void demonstrate_practical_examples(void);
void demonstrate_debugging_macros(void);

// Helper structures for demonstrations
struct Point {
    int x;
    int y;
};

struct Config {
    int max_users;
    int timeout;
    size_t buffer_size;
    char platform[32];
};

// Test functions that will be created with macros
void MAKE_FUNCTION(test1)(void);
void MAKE_FUNCTION(test2)(void);

int main(void) {
    printf("=== C Preprocessor Directives Demo ===\n\n");
    
    demonstrate_basic_macros();
    demonstrate_function_like_macros();
    demonstrate_conditional_compilation();
    demonstrate_predefined_macros();
    demonstrate_stringification_and_pasting();
    demonstrate_variadic_macros();
    demonstrate_platform_detection();
    demonstrate_compiler_detection();
    demonstrate_advanced_techniques();
    demonstrate_macro_pitfalls();
    demonstrate_practical_examples();
    demonstrate_debugging_macros();
    
    return 0;
}

/**
 * Demonstrates basic macro definitions
 */
void demonstrate_basic_macros(void) {
    printf("1. Basic Macro Definitions\n");
    printf("==========================\n");
    
    printf("Symbolic constants defined with #define:\n");
    printf("  #define PI 3.14159265359\n");
    printf("  #define MAX_SIZE 1000\n");
    printf("  #define BUFFER_SIZE 256\n\n");
    
    printf("Using symbolic constants:\n");
    printf("  PI = %f\n", PI);
    printf("  MAX_SIZE = %d\n", MAX_SIZE);
    printf("  BUFFER_SIZE = %d\n", BUFFER_SIZE);
    
    // Calculate circle area using PI
    double radius = 5.0;
    double area = PI * radius * radius;
    printf("  Circle area (radius=%.1f): %.2f\n", radius, area);
    
    // Create arrays using macro-defined sizes
    int array[MAX_SIZE];
    char buffer[BUFFER_SIZE];
    
    printf("  Created array of size %d\n", MAX_SIZE);
    printf("  Created buffer of size %d\n", BUFFER_SIZE);
    
    // Version information
    printf("\nVersion macros:\n");
    printf("  Version: %d.%d.%d\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
    
    printf("\nBenefits of symbolic constants:\n");
    printf("  ✓ Easy to maintain and modify\n");
    printf("  ✓ Single point of definition\n");
    printf("  ✓ Self-documenting code\n");
    printf("  ✓ Compile-time substitution\n");
    printf("  ✓ No runtime overhead\n");
    
    printf("\n");
}

/**
 * Demonstrates function-like macros
 */
void demonstrate_function_like_macros(void) {
    printf("2. Function-like Macros\n");
    printf("=======================\n");
    
    printf("Function-like macro definitions:\n");
    printf("  #define SQUARE(x) ((x) * (x))\n");
    printf("  #define MAX(a, b) ((a) > (b) ? (a) : (b))\n");
    printf("  #define MIN(a, b) ((a) < (b) ? (a) : (b))\n");
    printf("  #define ABS(x) ((x) < 0 ? -(x) : (x))\n\n");
    
    int a = 5, b = 10, c = -7;
    
    printf("Testing with values: a=%d, b=%d, c=%d\n", a, b, c);
    printf("  SQUARE(a) = %d\n", SQUARE(a));
    printf("  SQUARE(b) = %d\n", SQUARE(b));
    printf("  MAX(a, b) = %d\n", MAX(a, b));
    printf("  MIN(a, b) = %d\n", MIN(a, b));
    printf("  ABS(c) = %d\n", ABS(c));
    
    // More complex expressions
    printf("\nTesting with expressions:\n");
    printf("  SQUARE(a + 1) = %d\n", SQUARE(a + 1));
    printf("  MAX(a * 2, b - 3) = %d\n", MAX(a * 2, b - 3));
    printf("  CLAMP(15, 5, 10) = %d\n", CLAMP(15, 5, 10));
    printf("  CLAMP(3, 5, 10) = %d\n", CLAMP(3, 5, 10));
    printf("  CLAMP(7, 5, 10) = %d\n", CLAMP(7, 5, 10));
    
    // Multi-statement macro
    printf("\nMulti-statement macro (SWAP):\n");
    int x = 100, y = 200;
    printf("  Before swap: x=%d, y=%d\n", x, y);
    SWAP(x, y, int);
    printf("  After swap:  x=%d, y=%d\n", x, y);
    
    printf("\nFunction-like Macro Guidelines:\n");
    printf("  • Always use parentheses around parameters\n");
    printf("  • Use parentheses around entire expression\n");
    printf("  • Use do-while(0) for multi-statement macros\n");
    printf("  • Be careful with side effects\n");
    printf("  • Consider inline functions for complex logic\n");
    
    printf("\n");
}

/**
 * Demonstrates conditional compilation
 */
void demonstrate_conditional_compilation(void) {
    printf("3. Conditional Compilation\n");
    printf("==========================\n");
    
    printf("Conditional compilation directives:\n");
    printf("  #ifdef, #ifndef, #if, #elif, #else, #endif\n\n");
    
    // Debug mode demonstration
    printf("Debug mode compilation:\n");
#ifdef DEBUG
    printf("  DEBUG mode is ENABLED\n");
    printf("  Extra debugging information available\n");
#else
    printf("  DEBUG mode is DISABLED\n");
    printf("  Optimized for production\n");
#endif
    
    // Feature flags
    printf("\nFeature flags:\n");
#if FEATURE_LOGGING
    printf("  ✓ Logging feature ENABLED\n");
#else
    printf("  ✗ Logging feature DISABLED\n");
#endif

#if FEATURE_ENCRYPTION
    printf("  ✓ Encryption feature ENABLED\n");
#else
    printf("  ✗ Encryption feature DISABLED\n");
#endif

#if FEATURE_COMPRESSION
    printf("  ✓ Compression feature ENABLED\n");
#else
    printf("  ✗ Compression feature DISABLED\n");
#endif
    
    // C standard version checking
    printf("\nC Standard Support:\n");
#if C99_SUPPORTED
    printf("  ✓ C99 features available\n");
#else
    printf("  ✗ C99 features not available\n");
#endif

#if C11_SUPPORTED
    printf("  ✓ C11 features available\n");
#else
    printf("  ✗ C11 features not available\n");
#endif
    
    // Numerical comparisons
    printf("\nConfiguration values:\n");
#if CONFIG_MAX_USERS > 50
    printf("  High capacity configuration (max users: %d)\n", CONFIG_MAX_USERS);
#else
    printf("  Low capacity configuration (max users: %d)\n", CONFIG_MAX_USERS);
#endif

#if CONFIG_TIMEOUT >= 30
    printf("  Long timeout configuration (%d seconds)\n", CONFIG_TIMEOUT);
#else
    printf("  Short timeout configuration (%d seconds)\n", CONFIG_TIMEOUT);
#endif
    
    // Using DBG_PRINT macro (only works if DEBUG is defined)
    DBG_PRINT("This debug message will only appear if DEBUG is defined");
    
    printf("\n");
}

/**
 * Demonstrates predefined macros
 */
void demonstrate_predefined_macros(void) {
    printf("4. Predefined Macros\n");
    printf("====================\n");
    
    printf("Standard predefined macros:\n");
    printf("  __FILE__: %s\n", __FILE__);
    printf("  __LINE__: %d\n", __LINE__);
    printf("  __DATE__: %s\n", __DATE__);
    printf("  __TIME__: %s\n", __TIME__);
    printf("  __FUNCTION__: %s\n", __FUNCTION__);
    
    printf("\nC standard version:\n");
#ifdef __STDC__
    printf("  __STDC__: %d (Standard C compiler)\n", __STDC__);
#endif
    
#ifdef __STDC_VERSION__
    printf("  __STDC_VERSION__: %ld\n", __STDC_VERSION__);
    if (__STDC_VERSION__ >= 201112L) {
        printf("    (C11 or later)\n");
    } else if (__STDC_VERSION__ >= 199901L) {
        printf("    (C99)\n");
    } else {
        printf("    (C90)\n");
    }
#endif

    printf("\nCompiler-specific macros:\n");
#ifdef __GNUC__
    printf("  GCC version: %d.%d.%d\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#endif

#ifdef _MSC_VER
    printf("  MSVC version: %d\n", _MSC_VER);
#endif

#ifdef __clang__
    printf("  Clang version: %d.%d.%d\n", __clang_major__, __clang_minor__, __clang_patchlevel__);
#endif

    printf("\nArchitecture information:\n");
#ifdef _WIN64
    printf("  64-bit Windows platform\n");
#elif defined(_WIN32)
    printf("  32-bit Windows platform\n");
#endif

#ifdef __x86_64__
    printf("  x86_64 architecture\n");
#elif defined(__i386__)
    printf("  x86 architecture\n");
#elif defined(__arm__)
    printf("  ARM architecture\n");
#endif

    printf("\nOptimization level:\n");
#ifdef __OPTIMIZE__
    printf("  Optimization enabled\n");
#else
    printf("  No optimization\n");
#endif

#ifdef NDEBUG
    printf("  NDEBUG defined (assert disabled)\n");
#else
    printf("  NDEBUG not defined (assert enabled)\n");
#endif

    printf("\n");
}

/**
 * Demonstrates stringification and token pasting
 */
void demonstrate_stringification_and_pasting(void) {
    printf("5. Stringification and Token Pasting\n");
    printf("=====================================\n");
    
    printf("Stringification operator (#):\n");
    printf("  #define STRINGIFY(x) #x\n");
    printf("  #define TOSTRING(x) STRINGIFY(x)\n\n");
    
    int value = 42;
    printf("Testing stringification:\n");
    printf("  STRINGIFY(value) = \"%s\"\n", STRINGIFY(value));
    printf("  STRINGIFY(Hello World) = \"%s\"\n", STRINGIFY(Hello World));
    printf("  TOSTRING(MAX_SIZE) = \"%s\"\n", TOSTRING(MAX_SIZE));
    printf("  TOSTRING(PI) = \"%s\"\n", TOSTRING(PI));
    
    printf("\nToken pasting operator (##):\n");
    printf("  #define CONCAT(a, b) a ## b\n");
    printf("  #define MAKE_FUNCTION(name) CONCAT(function_, name)\n\n");
    
    // Create variables using token pasting
    int CONCAT(var_, 1) = 100;
    int CONCAT(var_, 2) = 200;
    int CONCAT(var_, 3) = 300;
    
    printf("Created variables using token pasting:\n");
    printf("  var_1 = %d\n", var_1);
    printf("  var_2 = %d\n", var_2);
    printf("  var_3 = %d\n", var_3);
    
    // Function names created with token pasting
    printf("\nCalling functions created with token pasting:\n");
    MAKE_FUNCTION(test1)();
    MAKE_FUNCTION(test2)();
    
    // Combined stringification and token pasting
    #define PRINT_VAR(n) printf("  " STRINGIFY(CONCAT(var_, n)) " = %d\n", CONCAT(var_, n))
    
    printf("\nCombined stringification and token pasting:\n");
    PRINT_VAR(1);
    PRINT_VAR(2);
    PRINT_VAR(3);
    
    printf("\n");
}

/**
 * Demonstrates variadic macros
 */
void demonstrate_variadic_macros(void) {
    printf("6. Variadic Macros (C99)\n");
    printf("========================\n");
    
    printf("Variadic macro definition:\n");
    printf("  #define DEBUG_PRINT(level, ...) \\\n");
    printf("      printf(\"[DEBUG %%d] \" __VA_ARGS__, level)\n\n");
    
    printf("Testing variadic macros:\n");
    DEBUG_PRINT(1, "Simple message\n");
    DEBUG_PRINT(2, "Message with value: %d\n", 42);
    DEBUG_PRINT(3, "Message with multiple values: %d, %s, %.2f\n", 
                100, "test", 3.14);
    
    printf("\nError logging macro:\n");
    printf("  #define LOG_ERROR(...) \\\n");
    printf("      fprintf(stderr, \"[ERROR] %%s:%%d: \", __FILE__, __LINE__); \\\n");
    printf("      fprintf(stderr, __VA_ARGS__); \\\n");
    printf("      fprintf(stderr, \"\\n\")\n\n");
    
    printf("Testing error logging:\n");
    LOG_ERROR("File not found: %s", "data.txt");
    LOG_ERROR("Invalid parameter: %d (expected > 0)", -5);
    LOG_ERROR("Connection timeout after %d seconds", 30);
    
    // GNU extension: named variadic arguments
    #ifdef __GNUC__
    #define NAMED_VARIADIC(format, args...) \
        printf("Named variadic: " format "\n", ##args)
    
    printf("\nGNU extension - named variadic arguments:\n");
    NAMED_VARIADIC("No arguments");
    NAMED_VARIADIC("One argument: %d", 123);
    NAMED_VARIADIC("Multiple arguments: %d, %s", 456, "hello");
    #endif
    
    printf("\nVariadic Macro Guidelines:\n");
    printf("  • Use __VA_ARGS__ to represent variable arguments\n");
    printf("  • ##__VA_ARGS__ handles empty argument lists (GNU)\n");
    printf("  • Useful for debugging and logging macros\n");
    printf("  • C99 or later required\n");
    
    printf("\n");
}

/**
 * Demonstrates platform detection
 */
void demonstrate_platform_detection(void) {
    printf("7. Platform Detection\n");
    printf("=====================\n");
    
    printf("Detected platform: %s\n", PLATFORM);
    printf("Path separator: '%c'\n", PATH_SEPARATOR);
    
    printf("\nPlatform-specific features:\n");
    
#ifdef _WIN32
    printf("  Windows-specific features:\n");
    printf("    • Windows API available\n");
    printf("    • Backslash path separators\n");
    printf("    • Case-insensitive file system\n");
    
#elif defined(__linux__)
    printf("  Linux-specific features:\n");
    printf("    • POSIX API available\n");
    printf("    • Forward slash path separators\n");
    printf("    • Case-sensitive file system\n");
    printf("    • Process ID: %d\n", getpid());
    
#elif defined(__APPLE__)
    printf("  macOS-specific features:\n");
    printf("    • POSIX and Cocoa APIs available\n");
    printf("    • Forward slash path separators\n");
    printf("    • Case-insensitive file system (usually)\n");
    printf("    • Process ID: %d\n", getpid());
    
#else
    printf("  Unknown platform\n");
    printf("    • Using generic implementations\n");
#endif

    printf("\nPlatform Detection Macros:\n");
    printf("  Windows: _WIN32, _WIN64, _MSC_VER\n");
    printf("  Linux: __linux__, __gnu_linux__\n");
    printf("  macOS: __APPLE__, __MACH__\n");
    printf("  Unix: __unix__, __unix\n");
    printf("  POSIX: _POSIX_VERSION\n");
    
    printf("\n");
}

/**
 * Demonstrates compiler detection
 */
void demonstrate_compiler_detection(void) {
    printf("8. Compiler Detection\n");
    printf("=====================\n");
    
    printf("Detected compiler: %s\n", COMPILER);
    
    printf("\nCompiler-specific attributes:\n");
    printf("  FORCE_INLINE: %s\n", TOSTRING(FORCE_INLINE));
    printf("  PACKED: %s\n", TOSTRING(PACKED));
    printf("  UNUSED: %s\n", TOSTRING(UNUSED));
    
    // Test compiler-specific features
    FORCE_INLINE int inline_function(int x) {
        return x * 2;
    }
    
    UNUSED int unused_variable = 42;
    
    printf("\nTesting inline function: inline_function(21) = %d\n", 
           inline_function(21));
    
    printf("\nCompiler Detection Macros:\n");
    printf("  GCC: __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__\n");
    printf("  Clang: __clang__, __clang_major__, __clang_minor__\n");
    printf("  MSVC: _MSC_VER, _MSC_FULL_VER\n");
    printf("  Intel: __INTEL_COMPILER\n");
    
    printf("\nCompiler Features:\n");
#ifdef __GNUC__
    printf("  ✓ GCC attributes available\n");
    printf("  ✓ Builtin functions available\n");
    printf("  ✓ Statement expressions available\n");
#endif

#ifdef _MSC_VER
    printf("  ✓ MSVC pragmas available\n");
    printf("  ✓ Microsoft extensions available\n");
#endif

#ifdef __clang__
    printf("  ✓ Clang attributes available\n");
    printf("  ✓ Clang static analyzer available\n");
#endif

    printf("\n");
}

/**
 * Demonstrates advanced macro techniques
 */
void demonstrate_advanced_techniques(void) {
    printf("9. Advanced Macro Techniques\n");
    printf("============================\n");
    
    // Array size calculation
    printf("Array size calculation:\n");
    int test_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("  Array elements: ");
    for (size_t i = 0; i < ARRAY_SIZE(test_array); i++) {
        printf("%d ", test_array[i]);
    }
    printf("\n");
    printf("  ARRAY_SIZE(test_array) = %zu\n", ARRAY_SIZE(test_array));
    
    // Offset calculation
    printf("\nStructure offset calculation:\n");
    printf("  struct Point { int x; int y; }\n");
    printf("  OFFSET_OF(struct Point, x) = %zu\n", OFFSET_OF(struct Point, x));
    printf("  OFFSET_OF(struct Point, y) = %zu\n", OFFSET_OF(struct Point, y));
    
    // Container of demonstration
    struct Point point = {100, 200};
    int* y_ptr = &point.y;
    struct Point* container = CONTAINER_OF(y_ptr, struct Point, y);
    printf("  Original point: (%d, %d)\n", point.x, point.y);
    printf("  Retrieved via CONTAINER_OF: (%d, %d)\n", container->x, container->y);
    
    // Loop unrolling
    printf("\nLoop unrolling demonstration:\n");
    int counter = 0;
    printf("  Before unrolled loop: counter = %d\n", counter);
    UNROLL_4(counter++);
    printf("  After unrolled loop: counter = %d\n", counter);
    
    // X-Macro technique for code generation
    printf("\nX-Macro technique (error codes):\n");
    
    #define ERROR_CODES \
        X(SUCCESS, 0, "Operation successful") \
        X(ERROR_NULL_POINTER, 1, "Null pointer error") \
        X(ERROR_OUT_OF_MEMORY, 2, "Out of memory") \
        X(ERROR_INVALID_ARGUMENT, 3, "Invalid argument") \
        X(ERROR_FILE_NOT_FOUND, 4, "File not found")
    
    // Generate enum
    enum ErrorCode {
        #define X(name, value, description) name = value,
        ERROR_CODES
        #undef X
    };
    
    // Generate error description function
    const char* get_error_description(enum ErrorCode code) {
        switch (code) {
            #define X(name, value, description) case name: return description;
            ERROR_CODES
            #undef X
            default: return "Unknown error";
        }
    }
    
    printf("  Error codes generated with X-Macro:\n");
    printf("    SUCCESS: %s\n", get_error_description(SUCCESS));
    printf("    ERROR_NULL_POINTER: %s\n", get_error_description(ERROR_NULL_POINTER));
    printf("    ERROR_OUT_OF_MEMORY: %s\n", get_error_description(ERROR_OUT_OF_MEMORY));
    
    printf("\n");
}

/**
 * Demonstrates common macro pitfalls
 */
void demonstrate_macro_pitfalls(void) {
    printf("10. Macro Pitfalls and Solutions\n");
    printf("================================\n");
    
    printf("Common macro pitfalls:\n\n");
    
    // Pitfall 1: Missing parentheses
    printf("1. Missing parentheses:\n");
    #define BAD_SQUARE(x) x * x
    #define GOOD_SQUARE(x) ((x) * (x))
    
    int result1 = BAD_SQUARE(2 + 3);   // Expands to: 2 + 3 * 2 + 3 = 11
    int result2 = GOOD_SQUARE(2 + 3);  // Expands to: ((2 + 3) * (2 + 3)) = 25
    
    printf("  BAD_SQUARE(2 + 3) = %d (wrong!)\n", result1);
    printf("  GOOD_SQUARE(2 + 3) = %d (correct)\n", result2);
    
    // Pitfall 2: Side effects
    printf("\n2. Side effects:\n");
    int x = 5;
    printf("  Before: x = %d\n", x);
    int result3 = GOOD_SQUARE(++x);  // x is incremented twice!
    printf("  After GOOD_SQUARE(++x): x = %d, result = %d\n", x, result3);
    
    // Pitfall 3: Multiple statement macros without do-while
    printf("\n3. Multiple statement macros:\n");
    #define BAD_SWAP(a, b, type) \
        type temp = a; \
        a = b; \
        b = temp;
    
    // This would break with if-else:
    // if (condition) BAD_SWAP(x, y, int); else something();
    
    printf("  BAD_SWAP can break if-else statements\n");
    printf("  GOOD: Use do-while(0) wrapper\n");
    
    // Pitfall 4: Macro vs function comparison
    printf("\n4. Macro vs Function trade-offs:\n");
    printf("  Macros:\n");
    printf("    ✓ No function call overhead\n");
    printf("    ✓ Type generic\n");
    printf("    ✓ Compile-time evaluation\n");
    printf("    ✗ Code bloat\n");
    printf("    ✗ No type checking\n");
    printf("    ✗ Side effects\n");
    printf("    ✗ Debugging difficulties\n");
    
    printf("  Functions:\n");
    printf("    ✓ Type safety\n");
    printf("    ✓ Scope rules\n");
    printf("    ✓ Easier debugging\n");
    printf("    ✓ No side effects\n");
    printf("    ✗ Function call overhead\n");
    printf("    ✗ Type specific\n");
    
    // Pitfall 5: Comma operator issues
    printf("\n5. Comma operator issues:\n");
    #define BAD_MAX(a, b) a > b ? a : b
    #define SAFER_MAX(a, b) ((a) > (b) ? (a) : (b))
    
    // This could be problematic in certain contexts
    printf("  Use parentheses to avoid comma operator issues\n");
    
    printf("\nMacro Best Practices:\n");
    printf("  • Always use parentheses around parameters\n");
    printf("  • Use parentheses around entire macro body\n");
    printf("  • Use do-while(0) for multi-statement macros\n");
    printf("  • Avoid side effects in macro parameters\n");
    printf("  • Use UPPERCASE for macro names\n");
    printf("  • Consider inline functions for complex logic\n");
    printf("  • Test macros thoroughly\n");
    printf("  • Document macro behavior clearly\n");
    
    printf("\n");
}

/**
 * Demonstrates practical macro examples
 */
void demonstrate_practical_examples(void) {
    printf("11. Practical Examples\n");
    printf("======================\n");
    
    // Configuration system
    printf("Configuration system using macros:\n");
    struct Config config = {
        .max_users = CONFIG_MAX_USERS,
        .timeout = CONFIG_TIMEOUT,
        .buffer_size = CONFIG_BUFFER_SIZE,
    };
    strcpy(config.platform, PLATFORM);
    
    printf("  Configuration loaded:\n");
    printf("    Max users: %d\n", config.max_users);
    printf("    Timeout: %d seconds\n", config.timeout);
    printf("    Buffer size: %zu bytes\n", config.buffer_size);
    printf("    Platform: %s\n", config.platform);
    
    // Memory allocation with error checking
    printf("\nSafe memory allocation:\n");
    void* ptr1 = malloc(1024);
    if (ptr1 != NULL) {
        printf("  ✓ Memory allocated successfully\n");
        free(ptr1);
    } else {
        printf("  ✗ Memory allocation failed\n");
    }
    
    // Assertion with custom message
    printf("\nCustom assertions:\n");
    int test_value = 42;
    ASSERT_MSG(test_value > 0, "Value must be positive");
    printf("  ✓ Assertion passed\n");
    
    // Benchmarking
    printf("\nBenchmarking example:\n");
    BENCHMARK_START();
    
    // Simulate some work
    volatile int sum = 0;
    for (int i = 0; i < 1000000; i++) {
        sum += i;
    }
    
    BENCHMARK_END("Million iterations");
    
    // API versioning
    printf("\nAPI versioning:\n");
    printf("  Current API version: %d.%d.%d\n", 
           VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
    
#if VERSION_MAJOR >= 1 && VERSION_MINOR >= 0
    printf("  ✓ Feature XYZ available\n");
#else
    printf("  ✗ Feature XYZ not available\n");
#endif
    
    printf("\n");
}

/**
 * Demonstrates debugging macros
 */
void demonstrate_debugging_macros(void) {
    printf("12. Debugging Macros\n");
    printf("====================\n");
    
    // Conditional debug output
    printf("Conditional debug output:\n");
    DBG_PRINT("This is a debug message");
    DBG_PRINT("Debug value: %d", 123);
    
    // Function entry/exit tracing
    #ifdef DEBUG
    #define TRACE_ENTER() printf("TRACE: Entering %s\n", __FUNCTION__)
    #define TRACE_EXIT() printf("TRACE: Exiting %s\n", __FUNCTION__)
    #else
    #define TRACE_ENTER()
    #define TRACE_EXIT()
    #endif
    
    void traced_function(void) {
        TRACE_ENTER();
        printf("  Doing some work in traced function\n");
        TRACE_EXIT();
    }
    
    printf("\nFunction tracing:\n");
    traced_function();
    
    // Variable dumping
    #define DUMP_VAR(var, fmt) printf("  %s = " fmt " (at %s:%d)\n", \
                                      #var, var, __FILE__, __LINE__)
    
    printf("\nVariable dumping:\n");
    int debug_int = 42;
    float debug_float = 3.14f;
    const char* debug_string = "Hello";
    
    DUMP_VAR(debug_int, "%d");
    DUMP_VAR(debug_float, "%.2f");
    DUMP_VAR(debug_string, "%s");
    
    // Memory debugging
    #ifdef DEBUG
    #define DEBUG_MALLOC(size) ({ \
        void* ptr = malloc(size); \
        printf("DEBUG: malloc(%zu) = %p at %s:%d\n", \
               (size_t)(size), ptr, __FILE__, __LINE__); \
        ptr; \
    })
    
    #define DEBUG_FREE(ptr) do { \
        printf("DEBUG: free(%p) at %s:%d\n", ptr, __FILE__, __LINE__); \
        free(ptr); \
        ptr = NULL; \
    } while(0)
    #else
    #define DEBUG_MALLOC(size) malloc(size)
    #define DEBUG_FREE(ptr) free(ptr)
    #endif
    
    printf("\nMemory debugging:\n");
    void* debug_ptr = DEBUG_MALLOC(256);
    if (debug_ptr) {
        printf("  Memory allocation successful\n");
        DEBUG_FREE(debug_ptr);
        printf("  Memory freed\n");
    }
    
    printf("\nDebugging Macro Tips:\n");
    printf("  • Use conditional compilation for debug code\n");
    printf("  • Include file and line information\n");
    printf("  • Provide different verbosity levels\n");
    printf("  • Use statement expressions for complex debugging\n");
    printf("  • Be careful with side effects in debug macros\n");
    printf("  • Consider performance impact of debug code\n");
    
    printf("\n");
}

// Function implementations created with token pasting
void MAKE_FUNCTION(test1)(void) {
    printf("  function_test1() called\n");
}

void MAKE_FUNCTION(test2)(void) {
    printf("  function_test2() called\n");
}