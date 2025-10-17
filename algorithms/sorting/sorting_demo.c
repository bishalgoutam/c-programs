/**
 * Sorting Algorithms - Comprehensive C Implementation
 * 
 * This program demonstrates:
 * - Basic sorting algorithms (Bubble, Selection, Insertion)
 * - Advanced sorting algorithms (Merge, Quick, Heap)
 * - Specialized sorting algorithms (Counting, Radix, Bucket)
 * - Performance analysis and comparison
 * - Practical applications and optimizations
 * 
 * @author Bishal Goutam
 * @since C99 Standard
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Function prototypes - Basic sorting algorithms
void bubble_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void insertion_sort(int arr[], int n);

// Function prototypes - Advanced sorting algorithms
void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void heap_sort(int arr[], int n);
void heapify(int arr[], int n, int i);

// Function prototypes - Specialized sorting algorithms
void counting_sort(int arr[], int n, int max_val);
void radix_sort(int arr[], int n);
void bucket_sort(float arr[], int n);

// Function prototypes - Utility functions
void print_array(int arr[], int n);
void print_float_array(float arr[], int n);
void copy_array(int source[], int dest[], int n);
void generate_random_array(int arr[], int n, int max_val);
void generate_random_float_array(float arr[], int n);
bool is_sorted(int arr[], int n);
double measure_time(void (*sort_func)(int[], int), int arr[], int n);

// Demo functions
void demonstrate_basic_sorting(void);
void demonstrate_advanced_sorting(void);
void demonstrate_specialized_sorting(void);
void demonstrate_performance_comparison(void);
void demonstrate_sorting_analysis(void);

int main(void) {
    printf("=== C Sorting Algorithms Demo ===\n\n");
    
    srand(time(NULL)); // Seed for random number generation
    
    demonstrate_basic_sorting();
    demonstrate_advanced_sorting();
    demonstrate_specialized_sorting();
    demonstrate_performance_comparison();
    demonstrate_sorting_analysis();
    
    return 0;
}

/**
 * Demonstrates basic sorting algorithms
 */
void demonstrate_basic_sorting(void) {
    printf("1. Basic Sorting Algorithms\n");
    printf("===========================\n");
    
    int original[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50};
    int n = sizeof(original) / sizeof(original[0]);
    int arr[10];
    
    printf("Original array: ");
    print_array(original, n);
    
    // Bubble Sort
    printf("\nBubble Sort:\n");
    copy_array(original, arr, n);
    printf("  Before: ");
    print_array(arr, n);
    bubble_sort(arr, n);
    printf("  After:  ");
    print_array(arr, n);
    printf("  Sorted: %s\n", is_sorted(arr, n) ? "Yes" : "No");
    
    // Selection Sort
    printf("\nSelection Sort:\n");
    copy_array(original, arr, n);
    printf("  Before: ");
    print_array(arr, n);
    selection_sort(arr, n);
    printf("  After:  ");
    print_array(arr, n);
    printf("  Sorted: %s\n", is_sorted(arr, n) ? "Yes" : "No");
    
    // Insertion Sort
    printf("\nInsertion Sort:\n");
    copy_array(original, arr, n);
    printf("  Before: ");
    print_array(arr, n);
    insertion_sort(arr, n);
    printf("  After:  ");
    print_array(arr, n);
    printf("  Sorted: %s\n", is_sorted(arr, n) ? "Yes" : "No");
    
    printf("\nBasic sorting characteristics:\n");
    printf("  Bubble Sort:    O(n²) time, O(1) space, Stable\n");
    printf("  Selection Sort: O(n²) time, O(1) space, Unstable\n");
    printf("  Insertion Sort: O(n²) time, O(1) space, Stable\n");
    printf("  Note: These are simple but inefficient for large datasets\n\n");
}

/**
 * Demonstrates advanced sorting algorithms
 */
void demonstrate_advanced_sorting(void) {
    printf("2. Advanced Sorting Algorithms\n");
    printf("==============================\n");
    
    int original[] = {38, 27, 43, 3, 9, 82, 10, 1, 54, 33};
    int n = sizeof(original) / sizeof(original[0]);
    int arr[10];
    
    printf("Original array: ");
    print_array(original, n);
    
    // Merge Sort
    printf("\nMerge Sort (Divide and Conquer):\n");
    copy_array(original, arr, n);
    printf("  Before: ");
    print_array(arr, n);
    merge_sort(arr, 0, n - 1);
    printf("  After:  ");
    print_array(arr, n);
    printf("  Sorted: %s\n", is_sorted(arr, n) ? "Yes" : "No");
    
    // Quick Sort
    printf("\nQuick Sort (Divide and Conquer):\n");
    copy_array(original, arr, n);
    printf("  Before: ");
    print_array(arr, n);
    quick_sort(arr, 0, n - 1);
    printf("  After:  ");
    print_array(arr, n);
    printf("  Sorted: %s\n", is_sorted(arr, n) ? "Yes" : "No");
    
    // Heap Sort
    printf("\nHeap Sort (Using Max Heap):\n");
    copy_array(original, arr, n);
    printf("  Before: ");
    print_array(arr, n);
    heap_sort(arr, n);
    printf("  After:  ");
    print_array(arr, n);
    printf("  Sorted: %s\n", is_sorted(arr, n) ? "Yes" : "No");
    
    printf("\nAdvanced sorting characteristics:\n");
    printf("  Merge Sort: O(n log n) time, O(n) space, Stable\n");
    printf("  Quick Sort: O(n log n) avg, O(n²) worst, O(log n) space, Unstable\n");
    printf("  Heap Sort:  O(n log n) time, O(1) space, Unstable\n");
    printf("  Note: These are efficient for large datasets\n\n");
}

/**
 * Demonstrates specialized sorting algorithms
 */
void demonstrate_specialized_sorting(void) {
    printf("3. Specialized Sorting Algorithms\n");
    printf("=================================\n");
    
    // Counting Sort (for integers with limited range)
    printf("Counting Sort (for integers 0-100):\n");
    int count_arr[] = {4, 2, 2, 8, 3, 3, 1, 7, 4, 1, 2, 6};
    int count_n = sizeof(count_arr) / sizeof(count_arr[0]);
    
    printf("  Before: ");
    print_array(count_arr, count_n);
    counting_sort(count_arr, count_n, 10);
    printf("  After:  ");
    print_array(count_arr, count_n);
    printf("  Sorted: %s\n", is_sorted(count_arr, count_n) ? "Yes" : "No");
    
    // Radix Sort (for non-negative integers)
    printf("\nRadix Sort (for multi-digit numbers):\n");
    int radix_arr[] = {170, 45, 75, 90, 2, 802, 24, 66};
    int radix_n = sizeof(radix_arr) / sizeof(radix_arr[0]);
    
    printf("  Before: ");
    print_array(radix_arr, radix_n);
    radix_sort(radix_arr, radix_n);
    printf("  After:  ");
    print_array(radix_arr, radix_n);
    printf("  Sorted: %s\n", is_sorted(radix_arr, radix_n) ? "Yes" : "No");
    
    // Bucket Sort (for floating point numbers)
    printf("\nBucket Sort (for floating point numbers 0.0-1.0):\n");
    float bucket_arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434, 0.789, 0.123};
    int bucket_n = sizeof(bucket_arr) / sizeof(bucket_arr[0]);
    
    printf("  Before: ");
    print_float_array(bucket_arr, bucket_n);
    bucket_sort(bucket_arr, bucket_n);
    printf("  After:  ");
    print_float_array(bucket_arr, bucket_n);
    
    printf("\nSpecialized sorting characteristics:\n");
    printf("  Counting Sort: O(n + k) time, O(k) space, Stable\n");
    printf("  Radix Sort:    O(d × (n + k)) time, O(n + k) space, Stable\n");
    printf("  Bucket Sort:   O(n + k) avg time, O(n × k) space, Stable\n");
    printf("  Note: These work well with specific data distributions\n\n");
}

/**
 * Demonstrates performance comparison of sorting algorithms
 */
void demonstrate_performance_comparison(void) {
    printf("4. Performance Comparison\n");
    printf("=========================\n");
    
    int sizes[] = {100, 500, 1000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        printf("Array size: %d elements\n", n);
        
        int *test_array = malloc(n * sizeof(int));
        generate_random_array(test_array, n, 1000);
        
        // Test different sorting algorithms
        double time_taken;
        
        // Bubble Sort (only for small arrays)
        if (n <= 500) {
            time_taken = measure_time(bubble_sort, test_array, n);
            printf("  Bubble Sort:    %.6f seconds\n", time_taken);
        } else {
            printf("  Bubble Sort:    Skipped (too slow for large arrays)\n");
        }
        
        // Selection Sort (only for small arrays)
        if (n <= 500) {
            time_taken = measure_time(selection_sort, test_array, n);
            printf("  Selection Sort: %.6f seconds\n", time_taken);
        } else {
            printf("  Selection Sort: Skipped (too slow for large arrays)\n");
        }
        
        // Insertion Sort
        time_taken = measure_time(insertion_sort, test_array, n);
        printf("  Insertion Sort: %.6f seconds\n", time_taken);
        
        // Note: For measure_time to work with merge_sort and quick_sort,
        // we'd need wrapper functions. For simplicity, showing concept.
        printf("  Merge Sort:     ~%.6f seconds (estimated)\n", 
               (double)n * log(n) / 1000000);
        printf("  Quick Sort:     ~%.6f seconds (estimated)\n", 
               (double)n * log(n) / 1200000);
        printf("  Heap Sort:      ~%.6f seconds (estimated)\n", 
               (double)n * log(n) / 800000);
        
        free(test_array);
        printf("\n");
    }
    
    printf("Performance insights:\n");
    printf("  • O(n²) algorithms become impractical for n > 1000\n");
    printf("  • O(n log n) algorithms scale well with large datasets\n");
    printf("  • Specialized algorithms can be faster for specific data\n");
    printf("  • Memory usage varies: in-place vs. requiring extra space\n\n");
}

/**
 * Demonstrates sorting algorithm analysis and selection criteria
 */
void demonstrate_sorting_analysis(void) {
    printf("5. Sorting Algorithm Analysis\n");
    printf("=============================\n");
    
    printf("Algorithm Selection Guide:\n\n");
    
    printf("Choose Insertion Sort when:\n");
    printf("  • Small datasets (n < 50)\n");
    printf("  • Nearly sorted data\n");
    printf("  • Simple implementation needed\n");
    printf("  • Online algorithm required (sorts as data arrives)\n");
    
    printf("\nChoose Merge Sort when:\n");
    printf("  • Guaranteed O(n log n) performance needed\n");
    printf("  • Stable sorting required\n");
    printf("  • External sorting (large datasets)\n");
    printf("  • Parallel processing available\n");
    
    printf("\nChoose Quick Sort when:\n");
    printf("  • Average-case performance is important\n");
    printf("  • Memory is limited (in-place sorting)\n");
    printf("  • Random or well-distributed data\n");
    printf("  • Cache efficiency matters\n");
    
    printf("\nChoose Heap Sort when:\n");
    printf("  • Worst-case O(n log n) guarantee needed\n");
    printf("  • Memory is very limited\n");
    printf("  • Selection of top-k elements\n");
    
    printf("\nChoose Counting Sort when:\n");
    printf("  • Integer data with small range\n");
    printf("  • Linear time sorting needed\n");
    printf("  • Stability is important\n");
    
    printf("\nChoose Radix Sort when:\n");
    printf("  • Fixed-width integer or string data\n");
    printf("  • Very large datasets\n");
    printf("  • Linear time complexity needed\n");
    
    printf("\nStability comparison:\n");
    printf("  Stable:   Merge, Insertion, Bubble, Counting, Radix, Bucket\n");
    printf("  Unstable: Quick, Heap, Selection\n");
    
    printf("\nSpace complexity comparison:\n");
    printf("  O(1):     Bubble, Selection, Insertion, Heap, Quick (avg)\n");
    printf("  O(n):     Merge, Counting (range), Bucket\n");
    printf("  O(log n): Quick (worst case for recursion stack)\n");
    
    printf("\nReal-world applications:\n");
    printf("  • Database indexing: Often uses external merge sort\n");
    printf("  • Graphics rendering: Radix sort for depth sorting\n");
    printf("  • String processing: Often uses specialized string sorts\n");
    printf("  • Real-time systems: Insertion sort for small, incremental data\n");
    printf("  • Standard libraries: Usually hybrid approaches (Introsort)\n");
    
    printf("\n");
}

// Basic Sorting Algorithm Implementations

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // If no swapping occurred, array is sorted
        if (!swapped) break;
    }
}

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap minimum element with first element
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Advanced Sorting Algorithm Implementations

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    // Merge the temporary arrays back
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose last element as pivot
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

void heap_sort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        // Call heapify on reduced heap
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        heapify(arr, n, largest);
    }
}

// Specialized Sorting Algorithm Implementations

void counting_sort(int arr[], int n, int max_val) {
    // Create count array
    int *count = calloc(max_val + 1, sizeof(int));
    int *output = malloc(n * sizeof(int));
    
    // Count occurrences
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // Modify count array to store actual positions
    for (int i = 1; i <= max_val; i++) {
        count[i] += count[i - 1];
    }
    
    // Build output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    // Copy output array to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    
    free(count);
    free(output);
}

void radix_sort(int arr[], int n) {
    // Find maximum number to know number of digits
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Do counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        // Modified counting sort for radix
        int output[n];
        int count[10] = {0};
        
        // Count occurrences of digits
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }
        
        // Change count[i] to actual position
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        
        // Build output array
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        
        // Copy output array to arr[]
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

void bucket_sort(float arr[], int n) {
    // Create n empty buckets
    float **buckets = malloc(n * sizeof(float*));
    int *bucket_sizes = calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        buckets[i] = malloc(n * sizeof(float));
    }
    
    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (int)(n * arr[i]);
        if (bucket_index >= n) bucket_index = n - 1;
        
        buckets[bucket_index][bucket_sizes[bucket_index]++] = arr[i];
    }
    
    // Sort individual buckets using insertion sort
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < bucket_sizes[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }
    
    // Concatenate all buckets
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket_sizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }
    
    free(buckets);
    free(bucket_sizes);
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

void print_float_array(float arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%.3f", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

void copy_array(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

void generate_random_array(int arr[], int n, int max_val) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % max_val;
    }
}

void generate_random_float_array(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (float)rand() / RAND_MAX;
    }
}

bool is_sorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

double measure_time(void (*sort_func)(int[], int), int arr[], int n) {
    int *test_arr = malloc(n * sizeof(int));
    copy_array(arr, test_arr, n);
    
    clock_t start = clock();
    sort_func(test_arr, n);
    clock_t end = clock();
    
    free(test_arr);
    
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}