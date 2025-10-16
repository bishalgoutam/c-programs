# Algorithms in C

This section implements fundamental algorithms in C, focusing on problem-solving techniques, algorithmic thinking, and optimization strategies.

## 📚 Algorithm Categories

### 1. Sorting Algorithms
- **Simple Sorts**: Bubble sort, selection sort, insertion sort
- **Efficient Sorts**: Merge sort, quick sort, heap sort
- **Special Purpose**: Counting sort, radix sort, bucket sort
- **Stability Analysis**: Stable vs unstable sorting
- **Performance Comparison**: Time/space complexity analysis

### 2. Searching Algorithms
- **Linear Search**: Sequential search with variations
- **Binary Search**: Iterative and recursive implementations
- **Hash-Based Search**: Hash table lookup algorithms
- **Tree Search**: BST search, tree traversal algorithms
- **String Search**: KMP, Boyer-Moore, Rabin-Karp

### 3. Recursion
- **Basic Recursion**: Factorial, Fibonacci, power calculation
- **Tree Recursion**: Tree traversals, path finding
- **Backtracking**: N-Queens, maze solving, sudoku
- **Divide and Conquer**: Binary search, merge sort, quick sort
- **Tail Recursion**: Optimization techniques

### 4. Dynamic Programming
- **Memoization**: Top-down approach with caching
- **Tabulation**: Bottom-up approach with tables
- **Classic Problems**: Knapsack, longest common subsequence
- **Optimization**: Space and time optimization techniques
- **Applications**: Path finding, resource allocation

### 5. Greedy Algorithms
- **Greedy Choice**: Local optimal leading to global optimal
- **Activity Selection**: Interval scheduling problems
- **Huffman Coding**: Optimal compression algorithm
- **Minimum Spanning Tree**: Kruskal's and Prim's algorithms
- **Dijkstra's Algorithm**: Shortest path finding

## 🎯 Learning Objectives

After mastering this section, you will:

1. **Analyze algorithm complexity** using Big O notation
2. **Choose appropriate algorithms** for specific problems
3. **Implement efficient sorting and searching** algorithms
4. **Apply recursive thinking** to problem decomposition
5. **Use dynamic programming** for optimization problems
6. **Design greedy algorithms** for applicable scenarios
7. **Optimize algorithms** for performance and memory usage

## 📊 Algorithm Complexity Analysis

### Sorting Algorithm Comparison

| Algorithm      | Best Case | Average Case | Worst Case | Space | Stable |
|----------------|-----------|--------------|------------|-------|--------|
| Bubble Sort    | O(n)      | O(n²)        | O(n²)      | O(1)  | Yes    |
| Selection Sort | O(n²)     | O(n²)        | O(n²)      | O(1)  | No     |
| Insertion Sort | O(n)      | O(n²)        | O(n²)      | O(1)  | Yes    |
| Merge Sort     | O(n log n)| O(n log n)   | O(n log n) | O(n)  | Yes    |
| Quick Sort     | O(n log n)| O(n log n)   | O(n²)      | O(log n)| No   |
| Heap Sort      | O(n log n)| O(n log n)   | O(n log n) | O(1)  | No     |

### Search Algorithm Comparison

| Algorithm     | Best Case | Average Case | Worst Case | Requirements |
|---------------|-----------|--------------|------------|--------------|
| Linear Search | O(1)      | O(n)         | O(n)       | None         |
| Binary Search | O(1)      | O(log n)     | O(log n)   | Sorted array |
| Hash Search   | O(1)      | O(1)         | O(n)       | Hash table   |

## 🛠️ Implementation Patterns

### Generic Sorting Framework
```c
// Generic comparison function type
typedef int (*compare_func_t)(const void* a, const void* b);

// Generic swap function
void swap(void* a, void* b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

// Generic quick sort implementation
void quick_sort(void* base, size_t count, size_t size, compare_func_t compare) {
    if (count < 2) return;
    
    char* arr = (char*)base;
    size_t pivot = partition(arr, count, size, compare);
    
    quick_sort(arr, pivot, size, compare);
    quick_sort(arr + (pivot + 1) * size, count - pivot - 1, size, compare);
}

// Comparison functions for different types
int compare_int(const void* a, const void* b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

int compare_string(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}
```

### Dynamic Programming Framework
```c
// Memoization structure
typedef struct {
    int** memo;
    int rows;
    int cols;
} memo_table_t;

memo_table_t* create_memo_table(int rows, int cols) {
    memo_table_t* table = malloc(sizeof(memo_table_t));
    table->memo = malloc(rows * sizeof(int*));
    table->rows = rows;
    table->cols = cols;
    
    for (int i = 0; i < rows; i++) {
        table->memo[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            table->memo[i][j] = -1;  // Uncomputed value
        }
    }
    return table;
}

// Example: Longest Common Subsequence with memoization
int lcs_memo(const char* str1, const char* str2, int m, int n, memo_table_t* table) {
    if (m == 0 || n == 0) return 0;
    
    if (table->memo[m][n] != -1) {
        return table->memo[m][n];
    }
    
    if (str1[m-1] == str2[n-1]) {
        table->memo[m][n] = 1 + lcs_memo(str1, str2, m-1, n-1, table);
    } else {
        int left = lcs_memo(str1, str2, m, n-1, table);
        int up = lcs_memo(str1, str2, m-1, n, table);
        table->memo[m][n] = (left > up) ? left : up;
    }
    
    return table->memo[m][n];
}
```

### Recursive Algorithm Template
```c
// General recursive problem-solving template
int solve_recursive(problem_state_t* state) {
    // Base case(s)
    if (is_base_case(state)) {
        return base_case_solution(state);
    }
    
    // Recursive case
    int best_solution = INT_MIN;  // or appropriate initial value
    
    // Generate all possible next states
    state_list_t* next_states = generate_next_states(state);
    
    for (int i = 0; i < next_states->count; i++) {
        int current_solution = solve_recursive(&next_states->states[i]);
        
        // Update best solution based on problem requirements
        if (current_solution > best_solution) {
            best_solution = current_solution;
        }
    }
    
    free_state_list(next_states);
    return best_solution;
}
```

## 🔍 Advanced Algorithm Implementations

### Merge Sort with Optimizations
```c
void merge_sort_optimized(int arr[], int temp[], int left, int right) {
    // Use insertion sort for small arrays
    if (right - left <= 10) {
        insertion_sort_range(arr, left, right);
        return;
    }
    
    int mid = left + (right - left) / 2;
    
    merge_sort_optimized(arr, temp, left, mid);
    merge_sort_optimized(arr, temp, mid + 1, right);
    
    // Skip merge if already sorted
    if (arr[mid] <= arr[mid + 1]) {
        return;
    }
    
    merge(arr, temp, left, mid, right);
}

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    
    // Copy to temporary array
    for (int idx = left; idx <= right; idx++) {
        temp[idx] = arr[idx];
    }
    
    // Merge back to original array
    while (i <= mid && j <= right) {
        if (temp[i] <= temp[j]) {
            arr[k++] = temp[i++];
        } else {
            arr[k++] = temp[j++];
        }
    }
    
    // Copy remaining elements
    while (i <= mid) arr[k++] = temp[i++];
    while (j <= right) arr[k++] = temp[j++];
}
```

### Dijkstra's Algorithm Implementation
```c
#define INF INT_MAX

typedef struct {
    int vertex;
    int distance;
} heap_node_t;

typedef struct {
    heap_node_t* nodes;
    int* positions;  // Position of vertex in heap
    int size;
    int capacity;
} min_heap_t;

int* dijkstra(int** graph, int vertices, int source) {
    int* distances = malloc(vertices * sizeof(int));
    bool* visited = calloc(vertices, sizeof(bool));
    min_heap_t* heap = create_min_heap(vertices);
    
    // Initialize distances
    for (int i = 0; i < vertices; i++) {
        distances[i] = INF;
    }
    distances[source] = 0;
    
    // Add source to heap
    heap_insert(heap, source, 0);
    
    while (!heap_is_empty(heap)) {
        heap_node_t min_node = heap_extract_min(heap);
        int u = min_node.vertex;
        
        if (visited[u]) continue;
        visited[u] = true;
        
        // Update distances to adjacent vertices
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && !visited[v]) {
                int new_distance = distances[u] + graph[u][v];
                if (new_distance < distances[v]) {
                    distances[v] = new_distance;
                    heap_insert(heap, v, new_distance);
                }
            }
        }
    }
    
    free(visited);
    destroy_min_heap(heap);
    return distances;
}
```

## 🧪 Performance Testing and Benchmarking

### Algorithm Performance Measurement
```c
#include <time.h>
#include <sys/time.h>

typedef struct {
    double setup_time;
    double execution_time;
    double total_time;
    size_t memory_used;
} performance_metrics_t;

performance_metrics_t benchmark_algorithm(void (*algorithm)(int[], int), 
                                         int data[], int size) {
    performance_metrics_t metrics = {0};
    struct timeval start, end;
    
    // Setup phase
    gettimeofday(&start, NULL);
    int* test_data = malloc(size * sizeof(int));
    memcpy(test_data, data, size * sizeof(int));
    gettimeofday(&end, NULL);
    
    metrics.setup_time = (end.tv_sec - start.tv_sec) + 
                        (end.tv_usec - start.tv_usec) / 1000000.0;
    
    // Execution phase
    gettimeofday(&start, NULL);
    algorithm(test_data, size);
    gettimeofday(&end, NULL);
    
    metrics.execution_time = (end.tv_sec - start.tv_sec) + 
                            (end.tv_usec - start.tv_usec) / 1000000.0;
    
    metrics.total_time = metrics.setup_time + metrics.execution_time;
    metrics.memory_used = size * sizeof(int);
    
    free(test_data);
    return metrics;
}

void compare_sorting_algorithms(int data[], int size) {
    printf("Algorithm Performance Comparison (n=%d)\n", size);
    printf("%-15s %-12s %-12s %-12s\n", "Algorithm", "Time (ms)", "Memory (KB)", "Status");
    printf("%s\n", "------------------------------------------------------------");
    
    performance_metrics_t metrics;
    
    metrics = benchmark_algorithm(bubble_sort, data, size);
    printf("%-15s %-12.3f %-12lu %-12s\n", "Bubble Sort", 
           metrics.execution_time * 1000, metrics.memory_used / 1024, "✓");
    
    metrics = benchmark_algorithm(quick_sort_wrapper, data, size);
    printf("%-15s %-12.3f %-12lu %-12s\n", "Quick Sort", 
           metrics.execution_time * 1000, metrics.memory_used / 1024, "✓");
    
    metrics = benchmark_algorithm(merge_sort_wrapper, data, size);
    printf("%-15s %-12.3f %-12lu %-12s\n", "Merge Sort", 
           metrics.execution_time * 1000, metrics.memory_used / 1024, "✓");
}
```

## 📖 Study Progression

### Phase 1: Foundation (Weeks 1-2)
- Master basic sorting algorithms
- Implement linear and binary search
- Understand Big O notation

### Phase 2: Recursive Thinking (Weeks 3-4)
- Practice recursive problem solving
- Implement divide-and-conquer algorithms
- Learn backtracking techniques

### Phase 3: Optimization (Weeks 5-6)
- Master dynamic programming concepts
- Implement greedy algorithms
- Analyze trade-offs between approaches

### Phase 4: Advanced Applications (Weeks 7-8)
- Graph algorithms and path finding
- String matching algorithms
- Algorithm optimization and tuning

## 🎯 Real-World Applications

- **Database Systems**: Query optimization, indexing algorithms
- **Compilers**: Parsing algorithms, optimization passes
- **Graphics**: Rendering algorithms, collision detection
- **Networks**: Routing protocols, load balancing
- **Machine Learning**: Optimization algorithms, clustering
- **Cryptography**: Hash functions, encryption algorithms

---

**Key Insight**: The best algorithm depends on your specific constraints - data size, memory limitations, and performance requirements all matter!