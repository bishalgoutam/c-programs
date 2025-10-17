/**
 * Searching Algorithms - Comprehensive C Implementation
 * 
 * This program demonstrates:
 * - Linear search algorithms
 * - Binary search and its variations
 * - Hashing-based search methods
 * - String searching algorithms
 * - Advanced searching techniques
 * - Performance analysis and optimization
 * 
 * @author Bishal Goutam
 * @since C99 Standard
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000
#define HASH_TABLE_SIZE 101

// Hash table for demonstration
typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode* table[HASH_TABLE_SIZE];
    int size;
} HashTable;

// Function prototypes - Basic searching
int linear_search(int arr[], int n, int target);
int binary_search(int arr[], int n, int target);
int binary_search_recursive(int arr[], int left, int right, int target);
int binary_search_first_occurrence(int arr[], int n, int target);
int binary_search_last_occurrence(int arr[], int n, int target);

// Function prototypes - Advanced searching
int jump_search(int arr[], int n, int target);
int interpolation_search(int arr[], int n, int target);
int exponential_search(int arr[], int n, int target);
int ternary_search(int arr[], int left, int right, int target);

// Function prototypes - String searching
int naive_string_search(const char* text, const char* pattern);
int kmp_search(const char* text, const char* pattern);
void compute_lps_array(const char* pattern, int* lps);
int rabin_karp_search(const char* text, const char* pattern);

// Function prototypes - Hash table operations
HashTable* hash_table_create(void);
void hash_table_destroy(HashTable* ht);
int hash_function(int key);
void hash_table_insert(HashTable* ht, int key, int value);
int hash_table_search(HashTable* ht, int key);
bool hash_table_delete(HashTable* ht, int key);

// Function prototypes - Utility functions
void print_array(int arr[], int n);
void generate_sorted_array(int arr[], int n);
double measure_search_time(int (*search_func)(int[], int, int), int arr[], int n, int target);

// Demo functions
void demonstrate_basic_searching(void);
void demonstrate_binary_search_variations(void);
void demonstrate_advanced_searching(void);
void demonstrate_string_searching(void);
void demonstrate_hashing(void);
void demonstrate_performance_comparison(void);

int main(void) {
    printf("=== C Searching Algorithms Demo ===\n\n");
    
    srand(time(NULL));
    
    demonstrate_basic_searching();
    demonstrate_binary_search_variations();
    demonstrate_advanced_searching();
    demonstrate_string_searching();
    demonstrate_hashing();
    demonstrate_performance_comparison();
    
    return 0;
}

/**
 * Demonstrates basic searching algorithms
 */
void demonstrate_basic_searching(void) {
    printf("1. Basic Searching Algorithms\n");
    printf("=============================\n");
    
    int unsorted[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50};
    int sorted[] = {11, 12, 22, 25, 34, 50, 64, 76, 88, 90};
    int n = 10;
    
    printf("Unsorted array: ");
    print_array(unsorted, n);
    printf("Sorted array:   ");
    print_array(sorted, n);
    
    // Linear Search
    printf("\nLinear Search (works on any array):\n");
    int target = 22;
    int result = linear_search(unsorted, n, target);
    printf("  Searching for %d in unsorted array: ", target);
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    target = 99;
    result = linear_search(unsorted, n, target);
    printf("  Searching for %d in unsorted array: ", target);
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    // Binary Search
    printf("\nBinary Search (requires sorted array):\n");
    target = 22;
    result = binary_search(sorted, n, target);
    printf("  Searching for %d in sorted array: ", target);
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    target = 99;
    result = binary_search(sorted, n, target);
    printf("  Searching for %d in sorted array: ", target);
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    // Recursive Binary Search
    printf("\nRecursive Binary Search:\n");
    target = 76;
    result = binary_search_recursive(sorted, 0, n - 1, target);
    printf("  Searching for %d: ", target);
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    printf("\nTime Complexity Comparison:\n");
    printf("  Linear Search:  O(n) - checks every element\n");
    printf("  Binary Search:  O(log n) - divides search space in half\n");
    printf("  Note: Binary search requires sorted data\n\n");
}

/**
 * Demonstrates binary search variations
 */
void demonstrate_binary_search_variations(void) {
    printf("2. Binary Search Variations\n");
    printf("===========================\n");
    
    // Array with duplicates
    int arr[] = {1, 2, 2, 2, 3, 4, 4, 5, 6, 6, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array with duplicates: ");
    print_array(arr, n);
    
    int target = 2;
    printf("\nSearching for target = %d:\n", target);
    
    // Standard binary search (any occurrence)
    int result = binary_search(arr, n, target);
    printf("  Standard binary search: ");
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    // First occurrence
    result = binary_search_first_occurrence(arr, n, target);
    printf("  First occurrence: ");
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    // Last occurrence
    result = binary_search_last_occurrence(arr, n, target);
    printf("  Last occurrence: ");
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    target = 6;
    printf("\nSearching for target = %d:\n", target);
    
    result = binary_search_first_occurrence(arr, n, target);
    printf("  First occurrence: ");
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    result = binary_search_last_occurrence(arr, n, target);
    printf("  Last occurrence: ");
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    printf("\nApplications of Binary Search Variations:\n");
    printf("  • Finding insertion point for maintaining sorted order\n");
    printf("  • Counting occurrences of an element\n");
    printf("  • Range queries in sorted data\n");
    printf("  • Finding closest elements\n\n");
}

/**
 * Demonstrates advanced searching algorithms
 */
void demonstrate_advanced_searching(void) {
    printf("3. Advanced Searching Algorithms\n");
    printf("================================\n");
    
    // Generate a larger sorted array for demonstration
    int arr[100];
    generate_sorted_array(arr, 100);
    
    printf("Testing on sorted array of 100 elements: [1, 2, 3, ..., 100]\n");
    
    int target = 67;
    printf("\nSearching for target = %d:\n", target);
    
    // Jump Search
    int result = jump_search(arr, 100, target);
    printf("  Jump Search: ");
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    // Interpolation Search
    result = interpolation_search(arr, 100, target);
    printf("  Interpolation Search: ");
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    // Exponential Search
    result = exponential_search(arr, 100, target);
    printf("  Exponential Search: ");
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    // Ternary Search
    result = ternary_search(arr, 0, 99, target);
    printf("  Ternary Search: ");
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    printf("\nAdvanced Search Algorithm Characteristics:\n");
    printf("  Jump Search:        O(√n) time, good for large sorted arrays\n");
    printf("  Interpolation:      O(log log n) avg, O(n) worst, for uniformly distributed data\n");
    printf("  Exponential:        O(log n) time, good when target is near beginning\n");
    printf("  Ternary Search:     O(log₃ n) time, divides into three parts\n\n");
}

/**
 * Demonstrates string searching algorithms
 */
void demonstrate_string_searching(void) {
    printf("4. String Searching Algorithms\n");
    printf("==============================\n");
    
    const char* text = "ABABDABACDABABCABCABCABCABC";
    const char* pattern1 = "ABABCAB";
    const char* pattern2 = "ABCD";
    
    printf("Text:    \"%s\"\n", text);
    printf("Pattern: \"%s\"\n", pattern1);
    
    // Naive String Search
    int result = naive_string_search(text, pattern1);
    printf("\nNaive String Search: ");
    if (result != -1) {
        printf("Pattern found at index %d\n", result);
    } else {
        printf("Pattern not found\n");
    }
    
    // KMP Search
    result = kmp_search(text, pattern1);
    printf("KMP Search: ");
    if (result != -1) {
        printf("Pattern found at index %d\n", result);
    } else {
        printf("Pattern not found\n");
    }
    
    // Rabin-Karp Search
    result = rabin_karp_search(text, pattern1);
    printf("Rabin-Karp Search: ");
    if (result != -1) {
        printf("Pattern found at index %d\n", result);
    } else {
        printf("Pattern not found\n");
    }
    
    printf("\nSearching for pattern: \"%s\"\n", pattern2);
    
    result = naive_string_search(text, pattern2);
    printf("Naive Search: ");
    if (result != -1) {
        printf("Pattern found at index %d\n", result);
    } else {
        printf("Pattern not found\n");
    }
    
    result = kmp_search(text, pattern2);
    printf("KMP Search: ");
    if (result != -1) {
        printf("Pattern found at index %d\n", result);
    } else {
        printf("Pattern not found\n");
    }
    
    printf("\nString Search Algorithm Characteristics:\n");
    printf("  Naive:      O(nm) time, simple implementation\n");
    printf("  KMP:        O(n + m) time, preprocesses pattern\n");
    printf("  Rabin-Karp: O(n + m) avg, O(nm) worst, uses hashing\n");
    printf("  Where n = text length, m = pattern length\n\n");
}

/**
 * Demonstrates hash table based searching
 */
void demonstrate_hashing(void) {
    printf("5. Hash Table Based Searching\n");
    printf("=============================\n");
    
    HashTable* ht = hash_table_create();
    
    printf("Creating hash table and inserting key-value pairs:\n");
    
    // Insert some key-value pairs
    int keys[] = {1, 12, 23, 34, 45, 56, 67, 78, 89, 90};
    int values[] = {10, 120, 230, 340, 450, 560, 670, 780, 890, 900};
    int n = 10;
    
    for (int i = 0; i < n; i++) {
        hash_table_insert(ht, keys[i], values[i]);
        printf("  Inserted: key=%d, value=%d\n", keys[i], values[i]);
    }
    
    printf("\nSearching in hash table:\n");
    
    // Search for existing keys
    for (int i = 0; i < n; i += 2) {
        int result = hash_table_search(ht, keys[i]);
        printf("  Search key %d: ", keys[i]);
        if (result != -1) {
            printf("Found, value = %d\n", result);
        } else {
            printf("Not found\n");
        }
    }
    
    // Search for non-existing key
    int non_existing = 99;
    int result = hash_table_search(ht, non_existing);
    printf("  Search key %d: ", non_existing);
    if (result != -1) {
        printf("Found, value = %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    printf("\nDeleting some keys:\n");
    if (hash_table_delete(ht, 23)) {
        printf("  Successfully deleted key 23\n");
    }
    if (hash_table_delete(ht, 67)) {
        printf("  Successfully deleted key 67\n");
    }
    
    // Search after deletion
    printf("\nSearching after deletion:\n");
    result = hash_table_search(ht, 23);
    printf("  Search key 23: %s\n", (result != -1) ? "Found" : "Not found");
    result = hash_table_search(ht, 67);
    printf("  Search key 67: %s\n", (result != -1) ? "Found" : "Not found");
    
    printf("\nHash Table Characteristics:\n");
    printf("  Average case: O(1) for search, insert, delete\n");
    printf("  Worst case:   O(n) when all keys hash to same bucket\n");
    printf("  Space:        O(n) for storing n elements\n");
    printf("  Load factor:  Affects performance, typically kept < 0.75\n");
    
    hash_table_destroy(ht);
    printf("  Hash table destroyed\n\n");
}

/**
 * Demonstrates performance comparison of searching algorithms
 */
void demonstrate_performance_comparison(void) {
    printf("6. Performance Comparison\n");
    printf("=========================\n");
    
    int sizes[] = {1000, 5000, 10000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        printf("Array size: %d elements\n", n);
        
        // Generate sorted array
        int* arr = malloc(n * sizeof(int));
        generate_sorted_array(arr, n);
        
        // Target to search (middle element)
        int target = n / 2;
        
        // Measure search times
        double time_taken;
        
        // Linear Search
        time_taken = measure_search_time(linear_search, arr, n, target);
        printf("  Linear Search:      %.6f seconds\n", time_taken);
        
        // Binary Search
        time_taken = measure_search_time(binary_search, arr, n, target);
        printf("  Binary Search:      %.6f seconds\n", time_taken);
        
        // Jump Search
        time_taken = measure_search_time(jump_search, arr, n, target);
        printf("  Jump Search:        %.6f seconds\n", time_taken);
        
        // Interpolation Search
        time_taken = measure_search_time(interpolation_search, arr, n, target);
        printf("  Interpolation:      %.6f seconds\n", time_taken);
        
        free(arr);
        printf("\n");
    }
    
    printf("Performance Analysis:\n");
    printf("  • Linear search time increases linearly with array size\n");
    printf("  • Binary search remains fast even for large arrays\n");
    printf("  • Advanced searches can be faster for specific distributions\n");
    printf("  • Hash tables provide constant-time average performance\n");
    printf("  • Choice depends on data characteristics and constraints\n\n");
}

// Basic Search Algorithm Implementations

int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

int binary_search_recursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] > target) {
            return binary_search_recursive(arr, left, mid - 1, target);
        }
        
        return binary_search_recursive(arr, mid + 1, right, target);
    }
    
    return -1;
}

int binary_search_first_occurrence(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1; // Continue searching in left half
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int binary_search_last_occurrence(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1; // Continue searching in right half
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

// Advanced Search Algorithm Implementations

int jump_search(int arr[], int n, int target) {
    int step = sqrt(n);
    int prev = 0;
    
    // Find the block where element is present
    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }
    
    // Linear search in the identified block
    while (arr[prev] < target) {
        prev++;
        if (prev == min(step, n)) {
            return -1;
        }
    }
    
    if (arr[prev] == target) {
        return prev;
    }
    
    return -1;
}

int interpolation_search(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }
        
        // Interpolation formula
        int pos = low + (((double)(target - arr[low]) / (arr[high] - arr[low])) * (high - low));
        
        if (arr[pos] == target) {
            return pos;
        }
        
        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    
    return -1;
}

int exponential_search(int arr[], int n, int target) {
    if (arr[0] == target) {
        return 0;
    }
    
    // Find range for binary search
    int i = 1;
    while (i < n && arr[i] <= target) {
        i = i * 2;
    }
    
    // Binary search in found range
    return binary_search_recursive(arr, i / 2, min(i, n - 1), target);
}

int ternary_search(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        
        if (arr[mid1] == target) {
            return mid1;
        }
        if (arr[mid2] == target) {
            return mid2;
        }
        
        if (target < arr[mid1]) {
            return ternary_search(arr, left, mid1 - 1, target);
        } else if (target > arr[mid2]) {
            return ternary_search(arr, mid2 + 1, right, target);
        } else {
            return ternary_search(arr, mid1 + 1, mid2 - 1, target);
        }
    }
    
    return -1;
}

// String Search Algorithm Implementations

int naive_string_search(const char* text, const char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            return i;
        }
    }
    
    return -1;
}

int kmp_search(const char* text, const char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    
    int* lps = malloc(m * sizeof(int));
    compute_lps_array(pattern, lps);
    
    int i = 0; // index for text
    int j = 0; // index for pattern
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        
        if (j == m) {
            free(lps);
            return i - j;
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    free(lps);
    return -1;
}

void compute_lps_array(const char* pattern, int* lps) {
    int m = strlen(pattern);
    int len = 0;
    lps[0] = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int rabin_karp_search(const char* text, const char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int d = 256; // number of characters in alphabet
    int q = 101; // a prime number
    
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;
    
    // Calculate h = pow(d, m-1) % q
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }
    
    // Calculate hash value of pattern and first window of text
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    
    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            // Check characters one by one
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == m) {
                return i;
            }
        }
        
        // Calculate hash value for next window
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) {
                t = t + q;
            }
        }
    }
    
    return -1;
}

// Hash Table Implementations

HashTable* hash_table_create(void) {
    HashTable* ht = malloc(sizeof(HashTable));
    ht->size = 0;
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

void hash_table_destroy(HashTable* ht) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HashNode* current = ht->table[i];
        while (current) {
            HashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht);
}

int hash_function(int key) {
    return key % HASH_TABLE_SIZE;
}

void hash_table_insert(HashTable* ht, int key, int value) {
    int index = hash_function(key);
    HashNode* new_node = malloc(sizeof(HashNode));
    new_node->key = key;
    new_node->value = value;
    new_node->next = ht->table[index];
    ht->table[index] = new_node;
    ht->size++;
}

int hash_table_search(HashTable* ht, int key) {
    int index = hash_function(key);
    HashNode* current = ht->table[index];
    
    while (current) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    
    return -1; // Not found
}

bool hash_table_delete(HashTable* ht, int key) {
    int index = hash_function(key);
    HashNode* current = ht->table[index];
    HashNode* prev = NULL;
    
    while (current) {
        if (current->key == key) {
            if (prev) {
                prev->next = current->next;
            } else {
                ht->table[index] = current->next;
            }
            free(current);
            ht->size--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    
    return false;
}

// Utility Function Implementations

void print_array(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

void generate_sorted_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

double measure_search_time(int (*search_func)(int[], int, int), int arr[], int n, int target) {
    clock_t start = clock();
    
    // Perform search multiple times for better measurement
    for (int i = 0; i < 1000; i++) {
        search_func(arr, n, target);
    }
    
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;
}

// Helper function for min
int min(int a, int b) {
    return (a < b) ? a : b;
}