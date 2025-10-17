/**
 * Preprocessor Directives - Comprehensive C Examples
 * 
 * This program demonstrates:
 * - File inclusion (#include)
 * - Macro definitions (#define)
 * - Conditional compilation (#if, #ifdef, #ifndef, etc.)
 * - Line control (#line)
 * - Error generation (#error)
 * - Pragma directives (#pragma)
 * - Predefined macros
 * - Function-like macros
 * - Macro operators (# and ##)
 * - Advanced preprocessing techniques
 * 
 * @author Bishal Goutam
 * @since C99 Standard
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Conditional inclusion example
#ifdef _WIN32
    #include <windows.h>
    #define PLATFORM "Windows"
#elif defined(__linux__)
    #include <unistd.h>
    #define PLATFORM "Linux"
#elif defined(__APPLE__)
    #include <unistd.h>
    #define PLATFORM "macOS"
#else
    #define PLATFORM "Unknown"
#endif

// Simple macro definitions
#define PI 3.14159265359
#define MAX_SIZE 100
#define VERSION_MAJOR 2
#define VERSION_MINOR 1
#define VERSION_PATCH 0

// Function-like macros
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))

// Multi-line macro
#define SWAP(a, b, type) do { \
    type temp = (a); \
    (a) = (b); \
    (b) = temp; \
} while(0)

// Stringification operator (#)
#define TO_STRING(x) #x
#define STRINGIFY(x) TO_STRING(x)

// Token concatenation operator (##)
#define CONCAT(a, b) a##b
#define MAKE_FUNCTION(name) \
    void function_##name(void) { \
        printf("Function " #name " called\n"); \
    }

// Conditional compilation based on debug mode
#ifdef DEBUG
    #define DEBUG_PRINT(fmt, ...) \
        printf("DEBUG: %s:%d: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
    #define DEBUG_PRINT(fmt, ...) do {} while(0)
#endif

// Configuration macros
#define FEATURE_LOGGING 1
#define FEATURE_CACHING 0
#define MAX_USERS 1000

// Version checking
#if VERSION_MAJOR >= 2
    #define NEW_API_AVAILABLE
#endif

// Error checking at compile time
#if MAX_SIZE <= 0
    #error "MAX_SIZE must be positive"
#endif

// Generate functions using macros
MAKE_FUNCTION(initialize)
MAKE_FUNCTION(cleanup)
MAKE_FUNCTION(process)

// Function prototypes
void demonstrate_basic_macros(void);
void demonstrate_function_macros(void);
void demonstrate_conditional_compilation(void);
void demonstrate_stringification(void);
void demonstrate_token_concatenation(void);
void demonstrate_predefined_macros(void);
void demonstrate_variadic_macros(void);
void demonstrate_advanced_techniques(void);
void demonstrate_common_pitfalls(void);
void demonstrate_practical_examples(void);

// Utility functions
void log_message(const char *level, const char *message);

int main(void) {
    printf("=== C Preprocessor Directives Demo ===\n\n");
    
    demonstrate_basic_macros();
    demonstrate_function_macros();
    demonstrate_conditional_compilation();
    demonstrate_stringification();
    demonstrate_token_concatenation();
    demonstrate_predefined_macros();
    demonstrate_variadic_macros();
    demonstrate_advanced_techniques();
    demonstrate_common_pitfalls();
    demonstrate_practical_examples();
    
    return 0;
}

/**
 * Demonstrates basic macro definitions and usage
 */
void demonstrate_basic_macros(void) {
    printf("1. Basic Macro Definitions\n");
    printf("==========================\n");
    
    printf("Mathematical constants:\n");
    printf("  PI = %.6f\n", PI);
    printf("  Circle area (radius=5): %.2f\n", PI * 5 * 5);
    
    printf("\nConfiguration macros:\n");
    printf("  MAX_SIZE = %d\n", MAX_SIZE);
    printf("  Version: %d.%d.%d\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
    
    // Macro replacement demonstration
    printf("\nMacro replacement:\n");
    printf("  Original: #define MAX_SIZE 100\n");
    printf("  Usage: int array[MAX_SIZE];\n");
    printf("  After preprocessing: int array[%d];\n", MAX_SIZE);
    
    // Undefined macro
    #ifdef UNDEFINED_MACRO
        printf("  UNDEFINED_MACRO is defined\n");
    #else
        printf("  UNDEFINED_MACRO is not defined\n");
    #endif
    
    // Undefining and redefining
    #undef MAX_SIZE
    #define MAX_SIZE 200
    printf("  After #undef and redefine: MAX_SIZE = %d\n", MAX_SIZE);
    
    printf("\n");
}

/**
 * Demonstrates function-like macros
 */
void demonstrate_function_macros(void) {
    printf("2. Function-like Macros\n");
    printf("=======================\n");
    
    int a = 5, b = 3;
    float x = -2.5f, y = 7.8f;
    
    printf("Mathematical macros:\n");
    printf("  SQUARE(%d) = %d\n", a, SQUARE(a));
    printf("  MAX(%d, %d) = %d\n", a, b, MAX(a, b));
    printf("  MIN(%.1f, %.1f) = %.1f\n", x, y, MIN(x, y));
    printf("  ABS(%.1f) = %.1f\n", x, ABS(x));
    
    // Demonstrate macro vs function differences
    printf("\nMacro vs Function differences:\n");
    printf("  Macro: No function call overhead\n");
    printf("  Macro: Type-generic (works with any numeric type)\n");
    printf("  Function: Type-safe, side effects controlled\n");
    
    // Side effects demonstration
    printf("\nSide effects in macros:\n");
    int c = 4;
    printf("  c = %d\n", c);
    printf("  SQUARE(++c) = %d (c is now %d)\n", SQUARE(++c), c);
    // Note: ++c is evaluated twice in the macro!
    
    // Safe multi-statement macro
    printf("\nMulti-statement macro (SWAP):\n");
    int p = 10, q = 20;
    printf("  Before swap: p = %d, q = %d\n", p, q);
    SWAP(p, q, int);
    printf("  After swap: p = %d, q = %d\n", p, q);
    
    printf("\n");
}

/**
 * Demonstrates conditional compilation
 */
void demonstrate_conditional_compilation(void) {
    printf("3. Conditional Compilation\n");
    printf("==========================\n");
    
    printf("Platform detection:\n");
    printf("  Current platform: %s\n", PLATFORM);
    
    #ifdef _WIN32
        printf("  Windows-specific code would be compiled here\n");
    #elif defined(__linux__)
        printf("  Linux-specific code would be compiled here\n");
    #elif defined(__APPLE__)
        printf("  macOS-specific code would be compiled here\n");
    #else
        printf("  Generic Unix code would be compiled here\n");
    #endif
    
    printf("\nFeature flags:\n");
    #if FEATURE_LOGGING
        printf("  Logging feature: ENABLED\n");
        log_message("INFO", "Logging is enabled");
    #else
        printf("  Logging feature: DISABLED\n");
    #endif
    
    #if FEATURE_CACHING
        printf("  Caching feature: ENABLED\n");
    #else
        printf("  Caching feature: DISABLED\n");
    #endif
    
    printf("\nVersion-based compilation:\n");
    #ifdef NEW_API_AVAILABLE
        printf("  New API features available (version >= 2.0)\n");
    #else
        printf("  Using legacy API (version < 2.0)\n");
    #endif
    
    // Nested conditionals
    printf("\nNested conditionals:\n");
    #if VERSION_MAJOR >= 2
        #if VERSION_MINOR >= 1
            printf("  Advanced features available (v2.1+)\n");
        #else
            printf("  Basic v2.0 features available\n");
        #endif
    #else
        printf("  Legacy version (v1.x)\n");
    #endif
    
    printf("\n");
}

/**
 * Demonstrates stringification operator
 */
void demonstrate_stringification(void) {
    printf("4. Stringification Operator (#)\n");
    printf("===============================\n");
    
    printf("Converting tokens to strings:\n");
    printf("  TO_STRING(Hello) = \"%s\"\n", TO_STRING(Hello));
    printf("  TO_STRING(123) = \"%s\"\n", TO_STRING(123));
    printf("  TO_STRING(PI) = \"%s\"\n", TO_STRING(PI));
    
    // Stringify macro values
    printf("\nStringifying macro values:\n");
    printf("  STRINGIFY(PI) = \"%s\"\n", STRINGIFY(PI));
    printf("  STRINGIFY(MAX_SIZE) = \"%s\"\n", STRINGIFY(MAX_SIZE));
    
    // Debug macro using stringification
    #define PRINT_VAR(var) printf(#var " = %d\n", var)
    
    printf("\nDebug printing macro:\n");
    int temperature = 25;
    int humidity = 60;
    
    PRINT_VAR(temperature);
    PRINT_VAR(humidity);
    
    printf("\n");
}

/**
 * Demonstrates token concatenation operator
 */
void demonstrate_token_concatenation(void) {
    printf("5. Token Concatenation Operator (##)\n");
    printf("====================================\n");
    
    printf("Concatenating tokens:\n");
    
    // Simple concatenation
    #define VAR_NAME(n) variable_##n
    int VAR_NAME(1) = 10;
    int VAR_NAME(2) = 20;
    
    printf("  variable_1 = %d\n", variable_1);
    printf("  variable_2 = %d\n", variable_2);
    
    // Generated function calls
    printf("\nGenerated functions:\n");
    function_initialize();
    function_process();
    function_cleanup();
    
    // Array element access
    #define ARRAY_ELEMENT(arr, n) arr##n
    int data1 = 100, data2 = 200, data3 = 300;
    
    printf("\nArray-like access:\n");
    printf("  data1 = %d\n", ARRAY_ELEMENT(data, 1));
    printf("  data2 = %d\n", ARRAY_ELEMENT(data, 2));
    printf("  data3 = %d\n", ARRAY_ELEMENT(data, 3));
    
    // Creating multiple similar functions
    #define DECLARE_GETTER_SETTER(type, name) \
        static type name##_value = 0; \
        type get_##name(void) { return name##_value; } \
        void set_##name(type val) { name##_value = val; }
    
    DECLARE_GETTER_SETTER(int, counter)
    DECLARE_GETTER_SETTER(float, temperature)
    
    printf("\nGenerated getter/setter functions:\n");
    set_counter(42);
    set_temperature(23.5f);
    printf("  counter = %d\n", get_counter());
    printf("  temperature = %.1f\n", get_temperature());
    
    printf("\n");
}

/**
 * Demonstrates predefined macros
 */
void demonstrate_predefined_macros(void) {
    printf("6. Predefined Macros\n");
    printf("====================\n");
    
    printf("Compilation information:\n");
    printf("  __FILE__: %s\n", __FILE__);
    printf("  __LINE__: %d\n", __LINE__);
    printf("  __DATE__: %s\n", __DATE__);
    printf("  __TIME__: %s\n", __TIME__);
    printf("  __FUNCTION__: %s\n", __FUNCTION__);
    
    #ifdef __STDC__
        printf("  __STDC__: %d (Standard C compliant)\n", __STDC__);
    #endif
    
    #ifdef __STDC_VERSION__
        printf("  __STDC_VERSION__: %ld\n", __STDC_VERSION__);
    #endif
    
    #ifdef __GNUC__
        printf("  __GNUC__: %d (GCC compiler)\n", __GNUC__);
    #endif
    
    #ifdef _MSC_VER
        printf("  _MSC_VER: %d (Microsoft Visual C++)\n", _MSC_VER);
    #endif
    
    // Using predefined macros for debugging
    printf("\nDebugging with predefined macros:\n");
    printf("  Current location: %s:%d in %s()\n", __FILE__, __LINE__, __FUNCTION__);
    
    printf("\n");
}

/**
 * Demonstrates variadic macros
 */
void demonstrate_variadic_macros(void) {
    printf("7. Variadic Macros\n");
    printf("==================\n");
    
    // Debug macro with variable arguments
    #define LOG(level, ...) \
        printf("[%s] %s:%d: ", level, __FILE__, __LINE__); \
        printf(__VA_ARGS__); \
        printf("\n")
    
    printf("Variadic debug macros:\n");
    LOG("INFO", "System initialized");
    LOG("WARNING", "Low memory: %d%% used", 85);
    LOG("ERROR", "Failed to open file: %s", "config.txt");
    
    // Variadic macro for array printing
    #define PRINT_INTS(...) do { \
        int values[] = {__VA_ARGS__}; \
        int count = sizeof(values) / sizeof(values[0]); \
        printf("Array: ["); \
        for (int i = 0; i < count; i++) { \
            printf("%d", values[i]); \
            if (i < count - 1) printf(", "); \
        } \
        printf("]\n"); \
    } while(0)
    
    printf("\nVariadic array printing:\n");
    PRINT_INTS(1, 2, 3, 4, 5);
    PRINT_INTS(10, 20);
    
    // Conditional variadic macro
    #define TRACE(...) do { \
        if (sizeof((int[]){__VA_ARGS__}) > 0) { \
            printf("TRACE: "); \
            printf(__VA_ARGS__); \
            printf("\n"); \
        } \
    } while(0)
    
    printf("\nConditional tracing:\n");
    TRACE("Processing user %s with ID %d", "Alice", 1001);
    
    printf("\n");
}

/**
 * Demonstrates advanced preprocessing techniques
 */
void demonstrate_advanced_techniques(void) {
    printf("8. Advanced Preprocessing Techniques\n");
    printf("====================================\n");
    
    // X-Macros for code generation
    #define COLOR_LIST \
        X(RED, "Red") \
        X(GREEN, "Green") \
        X(BLUE, "Blue") \
        X(YELLOW, "Yellow")
    
    // Generate enum
    typedef enum {
        #define X(name, string) COLOR_##name,
        COLOR_LIST
        #undef X
        COLOR_COUNT
    } Color;
    
    // Generate string array
    static const char* color_names[] = {
        #define X(name, string) string,
        COLOR_LIST
        #undef X
    };
    
    printf("X-Macro generated code:\n");
    printf("  Color enum values: RED=%d, GREEN=%d, BLUE=%d\n", 
           COLOR_RED, COLOR_GREEN, COLOR_BLUE);
    printf("  Color names: %s, %s, %s\n", 
           color_names[COLOR_RED], color_names[COLOR_GREEN], color_names[COLOR_BLUE]);
    
    // Recursive macros (limited depth)
    #define REPEAT_1(code) code
    #define REPEAT_2(code) REPEAT_1(code) REPEAT_1(code)
    #define REPEAT_4(code) REPEAT_2(code) REPEAT_2(code)
    
    printf("\nRecursive macro expansion:\n");
    printf("  ");
    REPEAT_4(printf("* "));
    printf("\n");
    
    // Compile-time assertions
    #define STATIC_ASSERT(condition, message) \
        typedef char static_assertion_##message[(condition) ? 1 : -1]
    
    STATIC_ASSERT(sizeof(int) >= 4, int_must_be_at_least_4_bytes);
    printf("  Static assertion passed: int is at least 4 bytes\n");
    
    printf("\n");
}

/**
 * Demonstrates common pitfalls and how to avoid them
 */
void demonstrate_common_pitfalls(void) {
    printf("9. Common Pitfalls and Solutions\n");
    printf("================================\n");
    
    printf("Common macro pitfalls:\n\n");
    
    // 1. Missing parentheses
    #define BAD_SQUARE(x) x * x
    #define GOOD_SQUARE(x) ((x) * (x))
    
    printf("1. Missing parentheses:\n");
    printf("   BAD_SQUARE(2 + 3) = %d (expected 25, got %d)\n", 25, BAD_SQUARE(2 + 3));
    printf("   GOOD_SQUARE(2 + 3) = %d (correct result)\n", GOOD_SQUARE(2 + 3));
    
    // 2. Side effects
    printf("\n2. Side effects:\n");
    int counter = 5;
    printf("   counter = %d\n", counter);
    printf("   GOOD_SQUARE(++counter) = %d, counter = %d\n", GOOD_SQUARE(++counter), counter);
    printf("   Note: counter was incremented twice!\n");
    
    // 3. Multiple statements without do-while
    #define BAD_SWAP(a, b) temp = a; a = b; b = temp
    #define GOOD_SWAP(a, b, type) do { type temp = a; a = b; b = temp; } while(0)
    
    printf("\n3. Multiple statements:\n");
    printf("   BAD_SWAP can break in if statements without braces\n");
    printf("   GOOD_SWAP uses do-while(0) pattern for safety\n");
    
    // 4. Stringification of macros
    #define VALUE 42
    printf("\n4. Stringification:\n");
    printf("   TO_STRING(VALUE) = \"%s\" (gets macro name)\n", TO_STRING(VALUE));
    printf("   STRINGIFY(VALUE) = \"%s\" (gets macro value)\n", STRINGIFY(VALUE));
    
    // 5. Token concatenation pitfalls
    printf("\n5. Token concatenation:\n");
    printf("   Be careful with spaces around ##\n");
    printf("   Use intermediate macros for complex concatenations\n");
    
    printf("\nBest practices:\n");
    printf("   • Use ALL_CAPS for macro names\n");
    printf("   • Wrap multi-token replacements in parentheses\n");
    printf("   • Use do-while(0) for multi-statement macros\n");
    printf("   • Avoid side effects in macro arguments\n");
    printf("   • Use static inline functions when possible\n");
    
    printf("\n");
}

/**
 * Demonstrates practical preprocessing examples
 */
void demonstrate_practical_examples(void) {
    printf("10. Practical Examples\n");
    printf("======================\n");
    
    // Configuration system
    printf("Configuration system:\n");
    #define CONFIG_BUFFER_SIZE 1024
    #define CONFIG_MAX_CONNECTIONS 100
    #define CONFIG_TIMEOUT_MS 5000
    
    printf("   Buffer size: %d bytes\n", CONFIG_BUFFER_SIZE);
    printf("   Max connections: %d\n", CONFIG_MAX_CONNECTIONS);
    printf("   Timeout: %d ms\n", CONFIG_TIMEOUT_MS);
    
    // Debug levels
    #define DEBUG_LEVEL 2
    
    #define DEBUG_ERROR   1
    #define DEBUG_WARNING 2
    #define DEBUG_INFO    3
    #define DEBUG_VERBOSE 4
    
    #define DBG(level, ...) do { \
        if (level <= DEBUG_LEVEL) { \
            printf("[DEBUG-%d] ", level); \
            printf(__VA_ARGS__); \
            printf("\n"); \
        } \
    } while(0)
    
    printf("\nDebug system (level %d):\n", DEBUG_LEVEL);
    DBG(DEBUG_ERROR, "Critical error occurred");
    DBG(DEBUG_WARNING, "Warning: low memory");
    DBG(DEBUG_INFO, "Information message");  // Won't print (level > 2)
    DBG(DEBUG_VERBOSE, "Verbose debugging");  // Won't print (level > 2)
    
    // API versioning
    #define API_VERSION_MAKE(major, minor, patch) \
        ((major) * 10000 + (minor) * 100 + (patch))
    
    #define API_VERSION API_VERSION_MAKE(2, 1, 0)
    #define MIN_API_VERSION API_VERSION_MAKE(2, 0, 0)
    
    printf("\nAPI versioning:\n");
    printf("   Current API version: %d\n", API_VERSION);
    printf("   Minimum required: %d\n", MIN_API_VERSION);
    
    #if API_VERSION >= MIN_API_VERSION
        printf("   API compatibility: OK\n");
    #else
        printf("   API compatibility: FAILED\n");
    #endif
    
    // Compiler-specific optimizations
    #ifdef __GNUC__
        #define LIKELY(x)   __builtin_expect(!!(x), 1)
        #define UNLIKELY(x) __builtin_expect(!!(x), 0)
        #define FORCE_INLINE __attribute__((always_inline)) inline
    #else
        #define LIKELY(x)   (x)
        #define UNLIKELY(x) (x)
        #define FORCE_INLINE inline
    #endif
    
    printf("\nCompiler optimizations:\n");
    printf("   Branch prediction hints available: ");
    #ifdef __GNUC__
        printf("YES (GCC)\n");
    #else
        printf("NO (generic)\n");
    #endif
    
    printf("\n");
}

// Utility function implementations
void log_message(const char *level, const char *message) {
    printf("[LOG-%s] %s\n", level, message);
}

// Generated function implementations (from MAKE_FUNCTION macro)
// These are automatically generated by the macro expansion