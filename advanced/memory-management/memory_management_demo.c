/**
 * Memory Management - Comprehensive C Implementation
 * 
 * This program demonstrates:
 * - Static, automatic, and dynamic memory allocation
 * - malloc(), calloc(), realloc(), and free() functions
 * - Memory leak detection and prevention
 * - Stack vs heap memory management
 * - Pointer arithmetic and memory access
 * - Memory alignment and padding
 * - Custom memory allocators
 * - Garbage collection concepts
 * - Memory debugging techniques
 * - Best practices for memory management
 * 
 * @author Bishal Goutam
 * @since C99 Standard
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#ifdef _WIN32
    #include <crtdbg.h>
    #include <windows.h>
#else
    #include <sys/mman.h>
    #include <unistd.h>
#endif

#define MAX_ALLOCATIONS 1000
#define MEMORY_POOL_SIZE 65536
#define ALIGNMENT 8

// Memory allocation tracking structure
typedef struct MemoryBlock {
    void* ptr;
    size_t size;
    const char* file;
    int line;
    struct MemoryBlock* next;
} MemoryBlock;

// Custom memory pool structure
typedef struct {
    char* pool;
    size_t size;
    size_t used;
    bool* allocated_blocks;
    size_t block_size;
    size_t num_blocks;
} MemoryPool;

// Global variables for memory tracking
static MemoryBlock* allocated_blocks = NULL;
static size_t total_allocated = 0;
static size_t peak_allocation = 0;
static int allocation_count = 0;

// Function prototypes - Basic memory management
void demonstrate_stack_vs_heap(void);
void demonstrate_dynamic_allocation(void);
void demonstrate_memory_functions(void);
void demonstrate_memory_alignment(void);

// Function prototypes - Advanced memory management
void demonstrate_memory_pools(void);
void demonstrate_memory_tracking(void);
void demonstrate_memory_debugging(void);
void demonstrate_memory_optimization(void);

// Function prototypes - Memory tracking functions
void* tracked_malloc(size_t size, const char* file, int line);
void* tracked_calloc(size_t num, size_t size, const char* file, int line);
void* tracked_realloc(void* ptr, size_t size, const char* file, int line);
void tracked_free(void* ptr, const char* file, int line);
void print_memory_report(void);
void cleanup_memory_tracking(void);

// Macros for tracked memory allocation
#define MALLOC(size) tracked_malloc(size, __FILE__, __LINE__)
#define CALLOC(num, size) tracked_calloc(num, size, __FILE__, __LINE__)
#define REALLOC(ptr, size) tracked_realloc(ptr, size, __FILE__, __LINE__)
#define FREE(ptr) tracked_free(ptr, __FILE__, __LINE__)

// Function prototypes - Memory pool functions
MemoryPool* create_memory_pool(size_t block_size, size_t num_blocks);
void* pool_alloc(MemoryPool* pool);
void pool_free(MemoryPool* pool, void* ptr);
void destroy_memory_pool(MemoryPool* pool);
void print_pool_stats(MemoryPool* pool);

// Function prototypes - Utility functions
void demonstrate_memory_leaks(void);
void demonstrate_double_free(void);
void demonstrate_buffer_overflow(void);
void demonstrate_use_after_free(void);
size_t get_alignment(void* ptr);
void* aligned_malloc(size_t size, size_t alignment);
void aligned_free(void* ptr);

// Data structures for demonstrations
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} DynamicArray;

int main(void) {
    printf("=== C Memory Management Demo ===\n\n");
    
#ifdef _WIN32
    // Enable CRT debug heap (Windows only)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    
    demonstrate_stack_vs_heap();
    demonstrate_dynamic_allocation();
    demonstrate_memory_functions();
    demonstrate_memory_alignment();
    demonstrate_memory_pools();
    demonstrate_memory_tracking();
    demonstrate_memory_debugging();
    demonstrate_memory_optimization();
    
    // Final memory report
    printf("=== Final Memory Report ===\n");
    print_memory_report();
    cleanup_memory_tracking();
    
    return 0;
}

/**
 * Demonstrates stack vs heap memory allocation
 */
void demonstrate_stack_vs_heap(void) {
    printf("1. Stack vs Heap Memory\n");
    printf("=======================\n");
    
    printf("Memory Layout in C Programs:\n");
    printf("  ┌─────────────────┐ High addresses\n");
    printf("  │     Stack       │ ← Automatic variables, function calls\n");
    printf("  │        ↓        │   (grows downward)\n");
    printf("  │                 │\n");
    printf("  │        ↑        │\n");
    printf("  │      Heap       │ ← Dynamic allocation (malloc/free)\n");
    printf("  ├─────────────────┤   (grows upward)\n");
    printf("  │   Uninitialized │ ← Global/static uninitialized (.bss)\n");
    printf("  │      Data       │\n");
    printf("  ├─────────────────┤\n");
    printf("  │   Initialized   │ ← Global/static initialized (.data)\n");
    printf("  │      Data       │\n");
    printf("  ├─────────────────┤\n");
    printf("  │   Text/Code     │ ← Program instructions (.text)\n");
    printf("  └─────────────────┘ Low addresses\n\n");
    
    // Stack allocation examples
    printf("Stack Allocation (Automatic Variables):\n");
    int stack_var = 42;
    int stack_array[100];
    char stack_string[256];
    
    printf("  stack_var address:    %p\n", (void*)&stack_var);
    printf("  stack_array address:  %p\n", (void*)stack_array);
    printf("  stack_string address: %p\n", (void*)stack_string);
    
    printf("\nStack Characteristics:\n");
    printf("  ✓ Fast allocation/deallocation\n");
    printf("  ✓ Automatic cleanup (scope-based)\n");
    printf("  ✓ No fragmentation\n");
    printf("  ✗ Limited size (typically 1-8MB)\n");
    printf("  ✗ Fixed size at compile time\n");
    printf("  ✗ Cannot return pointers to local variables\n");
    
    // Heap allocation examples
    printf("\nHeap Allocation (Dynamic Memory):\n");
    int* heap_var = malloc(sizeof(int));
    int* heap_array = malloc(100 * sizeof(int));
    char* heap_string = malloc(256);
    
    if (heap_var && heap_array && heap_string) {
        *heap_var = 42;
        printf("  heap_var address:     %p\n", (void*)heap_var);
        printf("  heap_array address:   %p\n", (void*)heap_array);
        printf("  heap_string address:  %p\n", (void*)heap_string);
        
        free(heap_var);
        free(heap_array);
        free(heap_string);
    }
    
    printf("\nHeap Characteristics:\n");
    printf("  ✓ Large size (limited by system memory)\n");
    printf("  ✓ Dynamic sizing at runtime\n");
    printf("  ✓ Can return pointers from functions\n");
    printf("  ✗ Slower allocation/deallocation\n");
    printf("  ✗ Manual memory management required\n");
    printf("  ✗ Fragmentation possible\n");
    printf("  ✗ Memory leaks if not freed\n\n");
}

/**
 * Demonstrates dynamic memory allocation functions
 */
void demonstrate_dynamic_allocation(void) {
    printf("2. Dynamic Memory Allocation\n");
    printf("============================\n");
    
    printf("Dynamic Allocation Functions:\n");
    printf("  malloc(size)        - Allocate uninitialized memory\n");
    printf("  calloc(num, size)   - Allocate zero-initialized memory\n");
    printf("  realloc(ptr, size)  - Resize existing allocation\n");
    printf("  free(ptr)           - Deallocate memory\n\n");
    
    // malloc() demonstration
    printf("malloc() - Allocate uninitialized memory:\n");
    int* numbers = (int*)malloc(5 * sizeof(int));
    if (numbers == NULL) {
        printf("  ✗ malloc() failed\n");
        return;
    }
    
    printf("  ✓ Allocated memory for 5 integers\n");
    printf("  Uninitialized values: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]); // Undefined values
    }
    printf("\n");
    
    // Initialize the values
    for (int i = 0; i < 5; i++) {
        numbers[i] = (i + 1) * 10;
    }
    printf("  Initialized values:   ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    free(numbers);
    printf("  ✓ Memory freed\n\n");
    
    // calloc() demonstration
    printf("calloc() - Allocate zero-initialized memory:\n");
    int* zeros = (int*)calloc(5, sizeof(int));
    if (zeros == NULL) {
        printf("  ✗ calloc() failed\n");
        return;
    }
    
    printf("  ✓ Allocated memory for 5 integers (zero-initialized)\n");
    printf("  Zero-initialized values: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", zeros[i]);
    }
    printf("\n");
    
    // realloc() demonstration
    printf("\nrealloc() - Resize existing allocation:\n");
    printf("  Original size: 5 integers\n");
    
    zeros = (int*)realloc(zeros, 10 * sizeof(int));
    if (zeros == NULL) {
        printf("  ✗ realloc() failed\n");
        return;
    }
    
    printf("  ✓ Resized to 10 integers\n");
    
    // Initialize new elements
    for (int i = 5; i < 10; i++) {
        zeros[i] = i * i;
    }
    
    printf("  Updated values: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", zeros[i]);
    }
    printf("\n");
    
    free(zeros);
    printf("  ✓ Memory freed\n\n");
    
    // Error handling
    printf("Error Handling:\n");
    
    // Attempt to allocate huge amount
    void* huge_ptr = malloc(SIZE_MAX);
    if (huge_ptr == NULL) {
        printf("  ✓ Properly handled failed allocation (SIZE_MAX)\n");
    } else {
        printf("  ✗ Unexpected: huge allocation succeeded\n");
        free(huge_ptr);
    }
    
    // Null pointer handling
    free(NULL); // This is safe and does nothing
    printf("  ✓ free(NULL) is safe and does nothing\n\n");
}

/**
 * Demonstrates memory-related functions and utilities
 */
void demonstrate_memory_functions(void) {
    printf("3. Memory Functions and Utilities\n");
    printf("=================================\n");
    
    printf("Memory Manipulation Functions:\n");
    printf("  memset()  - Fill memory with constant byte\n");
    printf("  memcpy()  - Copy memory block\n");
    printf("  memmove() - Copy overlapping memory blocks\n");
    printf("  memcmp()  - Compare memory blocks\n");
    printf("  memchr()  - Search for byte in memory\n\n");
    
    // memset() demonstration
    printf("memset() - Fill memory with value:\n");
    char buffer[20];
    memset(buffer, 'A', sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    printf("  Buffer filled with 'A': %s\n", buffer);
    
    memset(buffer, 0, sizeof(buffer));
    printf("  Buffer zeroed: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
    
    // memcpy() demonstration
    printf("\nmemcpy() - Copy memory blocks:\n");
    const char* source = "Hello, Memory!";
    char destination[20];
    
    memcpy(destination, source, strlen(source) + 1);
    printf("  Source: %s\n", source);
    printf("  Copied: %s\n", destination);
    
    // memmove() demonstration
    printf("\nmemmove() - Copy overlapping memory:\n");
    char overlap[] = "abcdefghijk";
    printf("  Original: %s\n", overlap);
    
    memmove(overlap + 2, overlap, 5); // Overlapping regions
    printf("  After memmove(overlap+2, overlap, 5): %s\n", overlap);
    
    // memcmp() demonstration
    printf("\nmemcmp() - Compare memory blocks:\n");
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "World";
    
    int cmp1 = memcmp(str1, str2, 5);
    int cmp2 = memcmp(str1, str3, 5);
    
    printf("  memcmp(\"%s\", \"%s\", 5) = %d\n", str1, str2, cmp1);
    printf("  memcmp(\"%s\", \"%s\", 5) = %d\n", str1, str3, cmp2);
    
    // memchr() demonstration
    printf("\nmemchr() - Search for byte in memory:\n");
    const char* text = "Hello, World!";
    char* found = (char*)memchr(text, 'W', strlen(text));
    
    if (found) {
        printf("  Found 'W' at position: %ld\n", found - text);
        printf("  Substring from 'W': %s\n", found);
    }
    
    printf("\n");
}

/**
 * Demonstrates memory alignment concepts
 */
void demonstrate_memory_alignment(void) {
    printf("4. Memory Alignment\n");
    printf("===================\n");
    
    printf("Memory Alignment Concepts:\n");
    printf("  • CPU reads data in aligned chunks (word boundaries)\n");
    printf("  • Misaligned access can be slower or cause faults\n");
    printf("  • Structures may have padding for alignment\n");
    printf("  • Different data types have different alignment requirements\n\n");
    
    // Basic alignment examples
    printf("Basic Data Type Alignments:\n");
    printf("  char:    alignment = %zu bytes\n", _Alignof(char));
    printf("  short:   alignment = %zu bytes\n", _Alignof(short));
    printf("  int:     alignment = %zu bytes\n", _Alignof(int));
    printf("  long:    alignment = %zu bytes\n", _Alignof(long));
    printf("  float:   alignment = %zu bytes\n", _Alignof(float));
    printf("  double:  alignment = %zu bytes\n", _Alignof(double));
    printf("  pointer: alignment = %zu bytes\n", _Alignof(void*));
    
    // Structure padding demonstration
    printf("\nStructure Padding Example:\n");
    
    struct UnpaddedStruct {
        char a;     // 1 byte
        int b;      // 4 bytes
        char c;     // 1 byte
        double d;   // 8 bytes
    };
    
    printf("  struct { char, int, char, double }\n");
    printf("  Expected size without padding: %zu bytes\n", 
           sizeof(char) + sizeof(int) + sizeof(char) + sizeof(double));
    printf("  Actual size with padding: %zu bytes\n", sizeof(struct UnpaddedStruct));
    printf("  Padding overhead: %zu bytes\n", 
           sizeof(struct UnpaddedStruct) - (sizeof(char) + sizeof(int) + sizeof(char) + sizeof(double)));
    
    // Optimized structure
    struct OptimizedStruct {
        double d;   // 8 bytes (largest alignment first)
        int b;      // 4 bytes
        char a;     // 1 byte
        char c;     // 1 byte
        // 2 bytes padding at end for alignment
    };
    
    printf("\n  struct { double, int, char, char } (optimized order)\n");
    printf("  Size with optimized layout: %zu bytes\n", sizeof(struct OptimizedStruct));
    printf("  Space saved: %zu bytes\n", 
           sizeof(struct UnpaddedStruct) - sizeof(struct OptimizedStruct));
    
    // Manual alignment
    printf("\nManual Memory Alignment:\n");
    
    void* unaligned_ptr = malloc(100);
    if (unaligned_ptr) {
        printf("  malloc() returned: %p\n", unaligned_ptr);
        printf("  Alignment: %zu bytes\n", get_alignment(unaligned_ptr));
        free(unaligned_ptr);
    }
    
    void* aligned_ptr = aligned_malloc(100, 32);
    if (aligned_ptr) {
        printf("  aligned_malloc(100, 32): %p\n", aligned_ptr);
        printf("  Alignment: %zu bytes\n", get_alignment(aligned_ptr));
        aligned_free(aligned_ptr);
    }
    
    printf("\nAlignment Best Practices:\n");
    printf("  • Order struct members by size (largest first)\n");
    printf("  • Use appropriate alignment for performance-critical code\n");
    printf("  • Consider cache line alignment for frequently accessed data\n");
    printf("  • Use packed structures sparingly (may hurt performance)\n\n");
}

/**
 * Demonstrates memory pools
 */
void demonstrate_memory_pools(void) {
    printf("5. Memory Pools\n");
    printf("===============\n");
    
    printf("Memory Pool Benefits:\n");
    printf("  ✓ Faster allocation/deallocation\n");
    printf("  ✓ Reduced fragmentation\n");
    printf("  ✓ Predictable memory usage\n");
    printf("  ✓ Cache-friendly memory layout\n");
    printf("  ✗ Fixed-size allocations\n");
    printf("  ✗ Memory may be wasted if not fully used\n\n");
    
    // Create memory pool
    printf("Creating memory pool (32-byte blocks, 100 blocks):\n");
    MemoryPool* pool = create_memory_pool(32, 100);
    if (!pool) {
        printf("  ✗ Failed to create memory pool\n");
        return;
    }
    
    print_pool_stats(pool);
    
    // Allocate some blocks
    printf("\nAllocating memory blocks:\n");
    void* ptrs[10];
    
    for (int i = 0; i < 10; i++) {
        ptrs[i] = pool_alloc(pool);
        if (ptrs[i]) {
            printf("  Block %d allocated: %p\n", i + 1, ptrs[i]);
            // Write some data to verify the allocation
            sprintf((char*)ptrs[i], "Block %d", i + 1);
        } else {
            printf("  ✗ Failed to allocate block %d\n", i + 1);
        }
    }
    
    print_pool_stats(pool);
    
    // Free some blocks
    printf("\nFreeing some blocks:\n");
    for (int i = 0; i < 5; i++) {
        printf("  Freeing block %d: %s\n", i + 1, (char*)ptrs[i]);
        pool_free(pool, ptrs[i]);
    }
    
    print_pool_stats(pool);
    
    // Allocate again (should reuse freed blocks)
    printf("\nAllocating new blocks (should reuse freed memory):\n");
    for (int i = 0; i < 3; i++) {
        void* new_ptr = pool_alloc(pool);
        if (new_ptr) {
            printf("  New block allocated: %p\n", new_ptr);
        }
    }
    
    print_pool_stats(pool);
    
    // Cleanup
    destroy_memory_pool(pool);
    printf("\n✓ Memory pool destroyed\n\n");
}

/**
 * Demonstrates memory tracking and debugging
 */
void demonstrate_memory_tracking(void) {
    printf("6. Memory Tracking and Debugging\n");
    printf("================================\n");
    
    printf("Memory tracking helps detect:\n");
    printf("  • Memory leaks\n");
    printf("  • Double free errors\n");
    printf("  • Use after free\n");
    printf("  • Buffer overflows\n");
    printf("  • Memory usage patterns\n\n");
    
    printf("Allocating tracked memory:\n");
    
    // Allocate some memory using tracked functions
    int* array1 = (int*)MALLOC(10 * sizeof(int));
    char* string1 = (char*)MALLOC(100);
    double* array2 = (double*)CALLOC(5, sizeof(double));
    
    if (array1 && string1 && array2) {
        printf("  ✓ Allocated array1, string1, and array2\n");
        
        // Use the memory
        for (int i = 0; i < 10; i++) {
            array1[i] = i * i;
        }
        strcpy(string1, "Hello, tracked memory!");
        
        print_memory_report();
        
        // Free some memory
        FREE(string1);
        string1 = NULL;
        
        printf("\nAfter freeing string1:\n");
        print_memory_report();
        
        // Reallocate array1
        array1 = (int*)REALLOC(array1, 20 * sizeof(int));
        if (array1) {
            printf("\n✓ Reallocated array1 to larger size\n");
            print_memory_report();
        }
        
        // Free remaining memory
        FREE(array1);
        FREE(array2);
        
        printf("\nAfter freeing all memory:\n");
        print_memory_report();
    }
    
    printf("\n");
}

/**
 * Demonstrates common memory errors and debugging
 */
void demonstrate_memory_debugging(void) {
    printf("7. Memory Debugging and Common Errors\n");
    printf("=====================================\n");
    
    printf("Common Memory Errors:\n");
    printf("  1. Memory leaks - allocated memory not freed\n");
    printf("  2. Double free - freeing same memory twice\n");
    printf("  3. Use after free - accessing freed memory\n");
    printf("  4. Buffer overflow - writing past allocated boundary\n");
    printf("  5. Uninitialized memory - using uninitialized values\n");
    printf("  6. Null pointer dereference\n\n");
    
    printf("Demonstrating memory leak detection:\n");
    demonstrate_memory_leaks();
    
    printf("Note: In production code, use tools like:\n");
    printf("  • Valgrind (Linux/macOS) - comprehensive memory debugging\n");
    printf("  • AddressSanitizer (GCC/Clang) - fast memory error detector\n");
    printf("  • CRT Debug Heap (Visual Studio) - Windows memory debugging\n");
    printf("  • Static analysis tools - detect issues at compile time\n\n");
}

/**
 * Demonstrates memory optimization techniques
 */
void demonstrate_memory_optimization(void) {
    printf("8. Memory Optimization Techniques\n");
    printf("=================================\n");
    
    printf("Memory Optimization Strategies:\n\n");
    
    // 1. Object pooling
    printf("1. Object Pooling:\n");
    printf("   Instead of malloc/free for each object, reuse objects from a pool\n");
    
    // Simple object pool demonstration
    Node* node_pool[100];
    int pool_size = 0;
    
    // Allocate nodes (simulating object creation)
    for (int i = 0; i < 10; i++) {
        Node* node = malloc(sizeof(Node));
        if (node) {
            node->data = i;
            node->next = NULL;
            node_pool[pool_size++] = node;
        }
    }
    printf("   ✓ Created pool of %d nodes\n", pool_size);
    
    // Cleanup
    for (int i = 0; i < pool_size; i++) {
        free(node_pool[i]);
    }
    
    // 2. Memory-mapped files
    printf("\n2. Memory-Mapped Files:\n");
    printf("   Use mmap() to map files directly into memory for large datasets\n");
    printf("   Benefits: OS handles paging, shared memory between processes\n");
    
    // 3. Stack allocation for small arrays
    printf("\n3. Stack vs Heap Trade-offs:\n");
    printf("   Use stack allocation for small, fixed-size arrays\n");
    printf("   Use heap allocation for large or variable-size data\n");
    
    // Demonstration of dynamic array growth
    printf("\n4. Dynamic Array Growth Strategy:\n");
    DynamicArray* dyn_array = malloc(sizeof(DynamicArray));
    if (dyn_array) {
        dyn_array->data = malloc(4 * sizeof(int));
        dyn_array->size = 0;
        dyn_array->capacity = 4;
        
        printf("   Initial capacity: %zu\n", dyn_array->capacity);
        
        // Add elements, growing as needed
        for (int i = 0; i < 10; i++) {
            if (dyn_array->size >= dyn_array->capacity) {
                // Grow by factor of 2
                size_t new_capacity = dyn_array->capacity * 2;
                int* new_data = realloc(dyn_array->data, new_capacity * sizeof(int));
                if (new_data) {
                    dyn_array->data = new_data;
                    dyn_array->capacity = new_capacity;
                    printf("   Grown to capacity: %zu\n", dyn_array->capacity);
                }
            }
            dyn_array->data[dyn_array->size++] = i;
        }
        
        printf("   Final size: %zu, capacity: %zu\n", dyn_array->size, dyn_array->capacity);
        printf("   Memory efficiency: %.1f%%\n", 
               (double)dyn_array->size / dyn_array->capacity * 100);
        
        free(dyn_array->data);
        free(dyn_array);
    }
    
    printf("\n5. Memory Optimization Tips:\n");
    printf("   • Use appropriate data types (don't use int for boolean)\n");
    printf("   • Pack structures to reduce padding\n");
    printf("   • Use memory pools for frequent allocations\n");
    printf("   • Prefer stack allocation for small, short-lived data\n");
    printf("   • Use memory-mapped files for large read-only data\n");
    printf("   • Implement custom allocators for specific use cases\n");
    printf("   • Profile memory usage to identify bottlenecks\n\n");
}

// Memory Tracking Function Implementations

void* tracked_malloc(size_t size, const char* file, int line) {
    void* ptr = malloc(size);
    if (ptr) {
        MemoryBlock* block = malloc(sizeof(MemoryBlock));
        if (block) {
            block->ptr = ptr;
            block->size = size;
            block->file = file;
            block->line = line;
            block->next = allocated_blocks;
            allocated_blocks = block;
            
            total_allocated += size;
            allocation_count++;
            if (total_allocated > peak_allocation) {
                peak_allocation = total_allocated;
            }
        }
    }
    return ptr;
}

void* tracked_calloc(size_t num, size_t size, const char* file, int line) {
    size_t total_size = num * size;
    void* ptr = calloc(num, size);
    if (ptr) {
        MemoryBlock* block = malloc(sizeof(MemoryBlock));
        if (block) {
            block->ptr = ptr;
            block->size = total_size;
            block->file = file;
            block->line = line;
            block->next = allocated_blocks;
            allocated_blocks = block;
            
            total_allocated += total_size;
            allocation_count++;
            if (total_allocated > peak_allocation) {
                peak_allocation = total_allocated;
            }
        }
    }
    return ptr;
}

void* tracked_realloc(void* ptr, size_t size, const char* file, int line) {
    if (ptr == NULL) {
        return tracked_malloc(size, file, line);
    }
    
    // Find the existing block
    MemoryBlock* current = allocated_blocks;
    MemoryBlock* prev = NULL;
    
    while (current && current->ptr != ptr) {
        prev = current;
        current = current->next;
    }
    
    void* new_ptr = realloc(ptr, size);
    if (new_ptr && current) {
        // Update the tracking information
        total_allocated = total_allocated - current->size + size;
        current->ptr = new_ptr;
        current->size = size;
        current->file = file;
        current->line = line;
        
        if (total_allocated > peak_allocation) {
            peak_allocation = total_allocated;
        }
    }
    
    return new_ptr;
}

void tracked_free(void* ptr, const char* file, int line) {
    if (ptr == NULL) return;
    
    MemoryBlock* current = allocated_blocks;
    MemoryBlock* prev = NULL;
    
    while (current && current->ptr != ptr) {
        prev = current;
        current = current->next;
    }
    
    if (current) {
        if (prev) {
            prev->next = current->next;
        } else {
            allocated_blocks = current->next;
        }
        
        total_allocated -= current->size;
        allocation_count--;
        free(current);
        free(ptr);
    } else {
        printf("Warning: Attempting to free untracked pointer at %s:%d\n", file, line);
    }
}

void print_memory_report(void) {
    printf("  Memory Report:\n");
    printf("    Current allocations: %d\n", allocation_count);
    printf("    Current memory used: %zu bytes\n", total_allocated);
    printf("    Peak memory usage: %zu bytes\n", peak_allocation);
    
    if (allocated_blocks) {
        printf("    Outstanding allocations:\n");
        MemoryBlock* current = allocated_blocks;
        while (current) {
            printf("      %zu bytes at %s:%d\n", current->size, current->file, current->line);
            current = current->next;
        }
    }
}

void cleanup_memory_tracking(void) {
    while (allocated_blocks) {
        MemoryBlock* temp = allocated_blocks;
        allocated_blocks = allocated_blocks->next;
        printf("Memory leak: %zu bytes allocated at %s:%d\n", 
               temp->size, temp->file, temp->line);
        free(temp->ptr);
        free(temp);
    }
}

// Memory Pool Function Implementations

MemoryPool* create_memory_pool(size_t block_size, size_t num_blocks) {
    MemoryPool* pool = malloc(sizeof(MemoryPool));
    if (!pool) return NULL;
    
    // Align block size
    block_size = (block_size + ALIGNMENT - 1) & ~(ALIGNMENT - 1);
    
    pool->pool = malloc(block_size * num_blocks);
    pool->allocated_blocks = calloc(num_blocks, sizeof(bool));
    
    if (!pool->pool || !pool->allocated_blocks) {
        free(pool->pool);
        free(pool->allocated_blocks);
        free(pool);
        return NULL;
    }
    
    pool->size = block_size * num_blocks;
    pool->used = 0;
    pool->block_size = block_size;
    pool->num_blocks = num_blocks;
    
    return pool;
}

void* pool_alloc(MemoryPool* pool) {
    if (!pool) return NULL;
    
    for (size_t i = 0; i < pool->num_blocks; i++) {
        if (!pool->allocated_blocks[i]) {
            pool->allocated_blocks[i] = true;
            pool->used += pool->block_size;
            return pool->pool + (i * pool->block_size);
        }
    }
    
    return NULL; // Pool is full
}

void pool_free(MemoryPool* pool, void* ptr) {
    if (!pool || !ptr) return;
    
    // Calculate block index
    ptrdiff_t offset = (char*)ptr - pool->pool;
    if (offset >= 0 && offset < (ptrdiff_t)pool->size) {
        size_t block_index = offset / pool->block_size;
        if (block_index < pool->num_blocks && pool->allocated_blocks[block_index]) {
            pool->allocated_blocks[block_index] = false;
            pool->used -= pool->block_size;
        }
    }
}

void destroy_memory_pool(MemoryPool* pool) {
    if (pool) {
        free(pool->pool);
        free(pool->allocated_blocks);
        free(pool);
    }
}

void print_pool_stats(MemoryPool* pool) {
    if (!pool) return;
    
    size_t allocated_blocks = 0;
    for (size_t i = 0; i < pool->num_blocks; i++) {
        if (pool->allocated_blocks[i]) {
            allocated_blocks++;
        }
    }
    
    printf("  Pool Statistics:\n");
    printf("    Total blocks: %zu\n", pool->num_blocks);
    printf("    Block size: %zu bytes\n", pool->block_size);
    printf("    Allocated blocks: %zu\n", allocated_blocks);
    printf("    Free blocks: %zu\n", pool->num_blocks - allocated_blocks);
    printf("    Memory utilization: %.1f%%\n", 
           (double)allocated_blocks / pool->num_blocks * 100);
}

// Utility Function Implementations

void demonstrate_memory_leaks(void) {
    printf("  Simulating memory leak (intentional):\n");
    
    // Allocate memory but don't free it (intentional leak for demonstration)
    void* leaked_memory = MALLOC(1024);
    if (leaked_memory) {
        printf("    ✓ Allocated 1024 bytes (not freed - this is a leak)\n");
        // Intentionally not calling FREE(leaked_memory)
    }
    
    print_memory_report();
}

void demonstrate_double_free(void) {
    printf("  Double free prevention:\n");
    
    int* ptr = (int*)MALLOC(sizeof(int));
    if (ptr) {
        *ptr = 42;
        printf("    ✓ Allocated and used memory\n");
        
        FREE(ptr);
        printf("    ✓ Freed memory once\n");
        
        // This would cause double free error
        // FREE(ptr); // Commented out to prevent crash
        printf("    (Double free prevented by not calling FREE again)\n");
    }
}

void demonstrate_buffer_overflow(void) {
    printf("  Buffer overflow detection:\n");
    
    char* buffer = (char*)MALLOC(10);
    if (buffer) {
        // Safe usage
        strncpy(buffer, "Hello", 9);
        buffer[9] = '\0';
        printf("    ✓ Safe string copy: %s\n", buffer);
        
        // This would be unsafe:
        // strcpy(buffer, "This string is way too long for the buffer");
        printf("    (Buffer overflow prevented by using safe functions)\n");
        
        FREE(buffer);
    }
}

void demonstrate_use_after_free(void) {
    printf("  Use after free prevention:\n");
    
    int* ptr = (int*)MALLOC(sizeof(int));
    if (ptr) {
        *ptr = 42;
        printf("    ✓ Value before free: %d\n", *ptr);
        
        FREE(ptr);
        ptr = NULL; // Set to NULL to prevent accidental use
        
        // This would be use after free:
        // printf("Value after free: %d\n", *ptr);
        printf("    (Use after free prevented by setting pointer to NULL)\n");
    }
}

size_t get_alignment(void* ptr) {
    uintptr_t addr = (uintptr_t)ptr;
    size_t alignment = 1;
    
    while (alignment <= 64 && (addr % (alignment * 2)) == 0) {
        alignment *= 2;
    }
    
    return alignment;
}

void* aligned_malloc(size_t size, size_t alignment) {
    void* ptr;
    
#ifdef _WIN32
    ptr = _aligned_malloc(size, alignment);
#else
    if (posix_memalign(&ptr, alignment, size) != 0) {
        ptr = NULL;
    }
#endif
    
    return ptr;
}

void aligned_free(void* ptr) {
#ifdef _WIN32
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}