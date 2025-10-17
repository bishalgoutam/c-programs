/**
 * Recursion Examples - Comprehensive C Implementation
 * 
 * This program demonstrates:
 * - Basic recursion concepts and patterns
 * - Mathematical recursion (factorials, Fibonacci, etc.)
 * - String and array recursion
 * - Tree and graph traversal recursion
 * - Divide and conquer algorithms
 * - Dynamic programming with memoization
 * - Tail recursion and optimization
 * 
 * @author Bishal Goutam
 * @since C99 Standard
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 100
#define MAX_MEMO 1000

// Memoization arrays for dynamic programming
static long long fib_memo[MAX_MEMO];
static bool fib_computed[MAX_MEMO];

// Binary tree node for tree traversal examples
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function prototypes - Basic recursion
long long factorial(int n);
long long factorial_tail(int n, long long accumulator);
long long fibonacci(int n);
long long fibonacci_memoized(int n);
void fibonacci_iterative_demo(int n);
int power(int base, int exp);
int power_optimized(int base, int exp);
int gcd(int a, int b);
int lcm(int a, int b);

// Function prototypes - String recursion
int string_length_recursive(const char* str);
void reverse_string_recursive(char* str, int start, int end);
bool is_palindrome_recursive(const char* str, int start, int end);
void print_string_permutations(char* str, int start, int end);
void swap_chars(char* a, char* b);

// Function prototypes - Array recursion
int array_sum_recursive(int arr[], int n);
int find_max_recursive(int arr[], int n);
bool binary_search_recursive_demo(int arr[], int left, int right, int target);
void merge_sort_recursive(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void quick_sort_recursive(int arr[], int low, int high);
int partition(int arr[], int low, int high);

// Function prototypes - Tree traversal
TreeNode* create_tree_node(int data);
TreeNode* insert_bst(TreeNode* root, int data);
void inorder_traversal(TreeNode* root);
void preorder_traversal(TreeNode* root);
void postorder_traversal(TreeNode* root);
int tree_height(TreeNode* root);
int count_nodes(TreeNode* root);
bool search_tree(TreeNode* root, int target);
void free_tree(TreeNode* root);

// Function prototypes - Advanced recursion
int hanoi_moves(int n);
void tower_of_hanoi(int n, char from, char to, char aux);
void print_all_subsets(int arr[], int n, int index, int current_subset[], int current_size);
bool n_queens_solve(int n);
bool n_queens_util(int board[][MAX_SIZE], int col, int n);
bool is_safe(int board[][MAX_SIZE], int row, int col, int n);
void print_board(int board[][MAX_SIZE], int n);

// Function prototypes - Maze and pathfinding
bool solve_maze(int maze[][MAX_SIZE], int n);
bool solve_maze_util(int maze[][MAX_SIZE], int x, int y, int sol[][MAX_SIZE], int n);
bool is_safe_move(int maze[][MAX_SIZE], int x, int y, int n);
void print_maze_solution(int sol[][MAX_SIZE], int n);

// Demo functions
void demonstrate_basic_recursion(void);
void demonstrate_mathematical_recursion(void);
void demonstrate_string_recursion(void);
void demonstrate_array_recursion(void);
void demonstrate_tree_recursion(void);
void demonstrate_advanced_recursion(void);
void demonstrate_optimization_techniques(void);

// Utility functions
void print_array(int arr[], int n);
void initialize_memo(void);

int main(void) {
    printf("=== C Recursion Examples Demo ===\n\n");
    
    initialize_memo();
    
    demonstrate_basic_recursion();
    demonstrate_mathematical_recursion();
    demonstrate_string_recursion();
    demonstrate_array_recursion();
    demonstrate_tree_recursion();
    demonstrate_advanced_recursion();
    demonstrate_optimization_techniques();
    
    return 0;
}

/**
 * Demonstrates basic recursion concepts
 */
void demonstrate_basic_recursion(void) {
    printf("1. Basic Recursion Concepts\n");
    printf("===========================\n");
    
    printf("Recursion Components:\n");
    printf("  1. Base Case: Condition to stop recursion\n");
    printf("  2. Recursive Case: Function calls itself with modified parameters\n");
    printf("  3. Progress: Each call should move closer to base case\n\n");
    
    // Factorial demonstration
    printf("Factorial Examples:\n");
    for (int i = 0; i <= 10; i++) {
        printf("  %d! = %lld\n", i, factorial(i));
    }
    
    printf("\nFactorial with Tail Recursion:\n");
    for (int i = 0; i <= 10; i++) {
        printf("  %d! = %lld\n", i, factorial_tail(i, 1));
    }
    
    // Power demonstration
    printf("\nPower Function Examples:\n");
    printf("  2^0 = %d\n", power(2, 0));
    printf("  2^3 = %d\n", power(2, 3));
    printf("  3^4 = %d\n", power(3, 4));
    printf("  5^5 = %d\n", power(5, 5));
    
    printf("\nOptimized Power Function (O(log n)):\n");
    printf("  2^10 = %d\n", power_optimized(2, 10));
    printf("  3^15 = %d\n", power_optimized(3, 15));
    
    // GCD demonstration
    printf("\nGreatest Common Divisor (Euclidean Algorithm):\n");
    printf("  GCD(48, 18) = %d\n", gcd(48, 18));
    printf("  GCD(100, 25) = %d\n", gcd(100, 25));
    printf("  GCD(17, 13) = %d\n", gcd(17, 13));
    
    printf("\nLeast Common Multiple:\n");
    printf("  LCM(12, 8) = %d\n", lcm(12, 8));
    printf("  LCM(15, 20) = %d\n", lcm(15, 20));
    
    printf("\n");
}

/**
 * Demonstrates mathematical recursion
 */
void demonstrate_mathematical_recursion(void) {
    printf("2. Mathematical Recursion\n");
    printf("=========================\n");
    
    // Fibonacci demonstration
    printf("Fibonacci Sequence (Basic Recursion):\n");
    printf("  Note: This becomes slow for large n due to repeated calculations\n");
    for (int i = 0; i <= 15; i++) {
        printf("  F(%d) = %lld\n", i, fibonacci(i));
    }
    
    printf("\nFibonacci with Memoization (Dynamic Programming):\n");
    for (int i = 0; i <= 30; i++) {
        printf("  F(%d) = %lld\n", i, fibonacci_memoized(i));
    }
    
    printf("\nTime Complexity Analysis:\n");
    printf("  Basic Fibonacci:     O(2^n) - exponential time\n");
    printf("  Memoized Fibonacci:  O(n) - linear time\n");
    printf("  Space Complexity:    O(n) for memoization array\n");
    
    fibonacci_iterative_demo(30);
    
    printf("\n");
}

/**
 * Demonstrates string recursion
 */
void demonstrate_string_recursion(void) {
    printf("3. String Recursion\n");
    printf("===================\n");
    
    char test_string[] = "recursion";
    printf("Original string: \"%s\"\n", test_string);
    
    // String length
    int length = string_length_recursive(test_string);
    printf("Length (recursive): %d\n", length);
    
    // String reversal
    char reverse_str[] = "hello";
    printf("Before reversal: \"%s\"\n", reverse_str);
    reverse_string_recursive(reverse_str, 0, strlen(reverse_str) - 1);
    printf("After reversal:  \"%s\"\n", reverse_str);
    
    // Palindrome check
    char* test_palindromes[] = {"racecar", "hello", "madam", "world", "level"};
    int num_tests = sizeof(test_palindromes) / sizeof(test_palindromes[0]);
    
    printf("\nPalindrome Check:\n");
    for (int i = 0; i < num_tests; i++) {
        bool is_pal = is_palindrome_recursive(test_palindromes[i], 0, strlen(test_palindromes[i]) - 1);
        printf("  \"%s\" is %s palindrome\n", test_palindromes[i], is_pal ? "a" : "not a");
    }
    
    // String permutations
    printf("\nPermutations of \"ABC\":\n");
    char perm_str[] = "ABC";
    print_string_permutations(perm_str, 0, strlen(perm_str) - 1);
    
    printf("\n");
}

/**
 * Demonstrates array recursion
 */
void demonstrate_array_recursion(void) {
    printf("4. Array Recursion\n");
    printf("==================\n");
    
    int arr[] = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    print_array(arr, n);
    
    // Array sum
    int sum = array_sum_recursive(arr, n);
    printf("Sum of elements (recursive): %d\n", sum);
    
    // Find maximum
    int max_val = find_max_recursive(arr, n);
    printf("Maximum element (recursive): %d\n", max_val);
    
    // Binary search on sorted array
    int sorted_arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int sorted_n = sizeof(sorted_arr) / sizeof(sorted_arr[0]);
    
    printf("\nSorted array for binary search: ");
    print_array(sorted_arr, sorted_n);
    
    int targets[] = {7, 12, 19, 1};
    int num_targets = sizeof(targets) / sizeof(targets[0]);
    
    for (int i = 0; i < num_targets; i++) {
        bool found = binary_search_recursive_demo(sorted_arr, 0, sorted_n - 1, targets[i]);
        printf("Binary search for %d: %s\n", targets[i], found ? "Found" : "Not found");
    }
    
    // Merge sort demonstration
    int merge_arr[] = {64, 34, 25, 12, 22, 11, 90};
    int merge_n = sizeof(merge_arr) / sizeof(merge_arr[0]);
    
    printf("\nMerge Sort Demonstration:\n");
    printf("Before sorting: ");
    print_array(merge_arr, merge_n);
    
    merge_sort_recursive(merge_arr, 0, merge_n - 1);
    
    printf("After sorting:  ");
    print_array(merge_arr, merge_n);
    
    // Quick sort demonstration
    int quick_arr[] = {10, 7, 8, 9, 1, 5};
    int quick_n = sizeof(quick_arr) / sizeof(quick_arr[0]);
    
    printf("\nQuick Sort Demonstration:\n");
    printf("Before sorting: ");
    print_array(quick_arr, quick_n);
    
    quick_sort_recursive(quick_arr, 0, quick_n - 1);
    
    printf("After sorting:  ");
    print_array(quick_arr, quick_n);
    
    printf("\n");
}

/**
 * Demonstrates tree recursion
 */
void demonstrate_tree_recursion(void) {
    printf("5. Tree Recursion\n");
    printf("=================\n");
    
    // Create a binary search tree
    TreeNode* root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45};
    int n = sizeof(values) / sizeof(values[0]);
    
    printf("Building Binary Search Tree with values: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
        root = insert_bst(root, values[i]);
    }
    printf("\n");
    
    printf("\nTree Structure:\n");
    printf("        50\n");
    printf("       /  \\\n");
    printf("      30   70\n");
    printf("     / \\   / \\\n");
    printf("    20 40 60 80\n");
    printf("   /   / \\      \n");
    printf("  10  35 45     \n");
    printf("     /          \n");
    printf("    25          \n");
    
    // Tree traversals
    printf("\nTree Traversals:\n");
    printf("Inorder (Left-Root-Right):   ");
    inorder_traversal(root);
    printf("\n");
    
    printf("Preorder (Root-Left-Right):  ");
    preorder_traversal(root);
    printf("\n");
    
    printf("Postorder (Left-Right-Root): ");
    postorder_traversal(root);
    printf("\n");
    
    // Tree properties
    int height = tree_height(root);
    printf("\nTree Height: %d\n", height);
    
    int node_count = count_nodes(root);
    printf("Number of Nodes: %d\n", node_count);
    
    // Tree search
    int search_values[] = {25, 35, 55, 80};
    int search_n = sizeof(search_values) / sizeof(search_values[0]);
    
    printf("\nSearching in BST:\n");
    for (int i = 0; i < search_n; i++) {
        bool found = search_tree(root, search_values[i]);
        printf("  Search for %d: %s\n", search_values[i], found ? "Found" : "Not found");
    }
    
    printf("\nTree recursion characteristics:\n");
    printf("  • Each recursive call operates on a subtree\n");
    printf("  • Base case typically checks for NULL node\n");
    printf("  • Natural fit for tree algorithms\n");
    printf("  • Time complexity often O(h) where h is height\n");
    
    free_tree(root);
    printf("\n");
}

/**
 * Demonstrates advanced recursion techniques
 */
void demonstrate_advanced_recursion(void) {
    printf("6. Advanced Recursion\n");
    printf("=====================\n");
    
    // Tower of Hanoi
    printf("Tower of Hanoi Problem:\n");
    printf("Goal: Move all disks from source to destination using auxiliary rod\n");
    printf("Rules: Only one disk at a time, larger disk cannot be on smaller\n\n");
    
    for (int n = 1; n <= 4; n++) {
        int moves = hanoi_moves(n);
        printf("For %d disk(s), minimum moves required: %d\n", n, moves);
        if (n <= 3) {
            printf("Solution steps for %d disk(s):\n", n);
            tower_of_hanoi(n, 'A', 'C', 'B');
            printf("\n");
        }
    }
    
    // Subset generation
    printf("All Subsets of {1, 2, 3}:\n");
    int set[] = {1, 2, 3};
    int subset[3];
    print_all_subsets(set, 3, 0, subset, 0);
    
    // N-Queens problem
    printf("\nN-Queens Problem:\n");
    printf("Place N queens on NxN chessboard so no two queens attack each other\n");
    
    for (int n = 4; n <= 6; n++) {
        printf("\nSolving %d-Queens:\n", n);
        if (n_queens_solve(n)) {
            printf("Solution found!\n");
        } else {
            printf("No solution exists.\n");
        }
    }
    
    // Maze solving
    printf("\nMaze Solving Problem:\n");
    int maze[MAX_SIZE][MAX_SIZE] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    
    printf("Maze (1 = path, 0 = wall):\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    
    printf("\nSolving maze from (0,0) to (3,3):\n");
    if (solve_maze(maze, 4)) {
        printf("Path found!\n");
    } else {
        printf("No path exists.\n");
    }
    
    printf("\n");
}

/**
 * Demonstrates recursion optimization techniques
 */
void demonstrate_optimization_techniques(void) {
    printf("7. Recursion Optimization Techniques\n");
    printf("====================================\n");
    
    printf("Common Optimization Strategies:\n\n");
    
    printf("1. Memoization (Top-down Dynamic Programming):\n");
    printf("   • Store results of expensive function calls\n");
    printf("   • Return cached result when same inputs occur again\n");
    printf("   • Example: Fibonacci with memoization\n");
    printf("   • Time: O(n), Space: O(n)\n\n");
    
    printf("2. Tail Recursion:\n");
    printf("   • Recursive call is the last operation\n");
    printf("   • Can be optimized to iterative by compiler\n");
    printf("   • Example: Tail recursive factorial\n");
    printf("   • Space: O(1) with optimization\n\n");
    
    printf("3. Iterative Conversion:\n");
    printf("   • Convert recursion to iteration using stack/queue\n");
    printf("   • Reduces function call overhead\n");
    printf("   • Better space complexity for some problems\n\n");
    
    printf("4. Divide and Conquer:\n");
    printf("   • Break problem into smaller subproblems\n");
    printf("   • Solve subproblems recursively\n");
    printf("   • Combine solutions\n");
    printf("   • Examples: Merge sort, Quick sort, Binary search\n\n");
    
    printf("Performance Comparison - Fibonacci(30):\n");
    
    // Time measurement would go here in a real implementation
    printf("  Basic recursion:    Very slow (exponential time)\n");
    printf("  Memoized recursion: Fast (linear time)\n");
    printf("  Iterative solution: Fastest (linear time, less overhead)\n\n");
    
    printf("When to Use Recursion:\n");
    printf("  ✓ Problem has recursive structure (trees, graphs)\n");
    printf("  ✓ Divide and conquer approach applies\n");
    printf("  ✓ Backtracking algorithms\n");
    printf("  ✓ Mathematical definitions are recursive\n");
    printf("  ✗ Simple iterative solution exists\n");
    printf("  ✗ Deep recursion causing stack overflow\n");
    printf("  ✗ Overlapping subproblems without memoization\n\n");
}

// Basic Recursion Implementations

long long factorial(int n) {
    if (n <= 1) {
        return 1; // Base case
    }
    return n * factorial(n - 1); // Recursive case
}

long long factorial_tail(int n, long long accumulator) {
    if (n <= 1) {
        return accumulator; // Base case
    }
    return factorial_tail(n - 1, n * accumulator); // Tail recursive call
}

long long fibonacci(int n) {
    if (n <= 1) {
        return n; // Base cases: F(0) = 0, F(1) = 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

long long fibonacci_memoized(int n) {
    if (n < 0 || n >= MAX_MEMO) return -1;
    
    if (fib_computed[n]) {
        return fib_memo[n];
    }
    
    if (n <= 1) {
        fib_memo[n] = n;
    } else {
        fib_memo[n] = fibonacci_memoized(n - 1) + fibonacci_memoized(n - 2);
    }
    
    fib_computed[n] = true;
    return fib_memo[n];
}

void fibonacci_iterative_demo(int n) {
    printf("\nIterative Fibonacci for comparison:\n");
    long long prev = 0, curr = 1;
    
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            printf("  F(%d) = %lld\n", i, prev);
        } else if (i == 1) {
            printf("  F(%d) = %lld\n", i, curr);
        } else {
            long long next = prev + curr;
            printf("  F(%d) = %lld\n", i, next);
            prev = curr;
            curr = next;
        }
    }
}

int power(int base, int exp) {
    if (exp == 0) {
        return 1; // Base case: any number^0 = 1
    }
    return base * power(base, exp - 1); // Recursive case
}

int power_optimized(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    if (exp % 2 == 0) {
        int half = power_optimized(base, exp / 2);
        return half * half;
    } else {
        return base * power_optimized(base, exp - 1);
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a; // Base case
    }
    return gcd(b, a % b); // Euclidean algorithm
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// String Recursion Implementations

int string_length_recursive(const char* str) {
    if (*str == '\0') {
        return 0; // Base case: end of string
    }
    return 1 + string_length_recursive(str + 1); // Recursive case
}

void reverse_string_recursive(char* str, int start, int end) {
    if (start >= end) {
        return; // Base case: pointers meet or cross
    }
    
    // Swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    
    reverse_string_recursive(str, start + 1, end - 1); // Recursive case
}

bool is_palindrome_recursive(const char* str, int start, int end) {
    if (start >= end) {
        return true; // Base case: single character or empty
    }
    
    if (str[start] != str[end]) {
        return false; // Characters don't match
    }
    
    return is_palindrome_recursive(str, start + 1, end - 1); // Recursive case
}

void print_string_permutations(char* str, int start, int end) {
    if (start == end) {
        printf("  %s\n", str); // Base case: print permutation
        return;
    }
    
    for (int i = start; i <= end; i++) {
        swap_chars(&str[start], &str[i]); // Swap
        print_string_permutations(str, start + 1, end); // Recurse
        swap_chars(&str[start], &str[i]); // Backtrack
    }
}

void swap_chars(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Array Recursion Implementations

int array_sum_recursive(int arr[], int n) {
    if (n <= 0) {
        return 0; // Base case: empty array
    }
    return arr[n - 1] + array_sum_recursive(arr, n - 1); // Recursive case
}

int find_max_recursive(int arr[], int n) {
    if (n == 1) {
        return arr[0]; // Base case: single element
    }
    
    int max_rest = find_max_recursive(arr, n - 1);
    return (arr[n - 1] > max_rest) ? arr[n - 1] : max_rest;
}

bool binary_search_recursive_demo(int arr[], int left, int right, int target) {
    if (left > right) {
        return false; // Base case: element not found
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return true; // Base case: element found
    }
    
    if (arr[mid] > target) {
        return binary_search_recursive_demo(arr, left, mid - 1, target);
    } else {
        return binary_search_recursive_demo(arr, mid + 1, right, target);
    }
}

void merge_sort_recursive(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        merge_sort_recursive(arr, left, mid); // Sort left half
        merge_sort_recursive(arr, mid + 1, right); // Sort right half
        merge(arr, left, mid, right); // Merge sorted halves
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int* L = malloc(n1 * sizeof(int));
    int* R = malloc(n2 * sizeof(int));
    
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    i = 0; j = 0; k = left;
    
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

void quick_sort_recursive(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quick_sort_recursive(arr, low, pi - 1); // Sort before partition
        quick_sort_recursive(arr, pi + 1, high); // Sort after partition
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
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
    
    return (i + 1);
}

// Tree Recursion Implementations

TreeNode* create_tree_node(int data) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* insert_bst(TreeNode* root, int data) {
    if (root == NULL) {
        return create_tree_node(data); // Base case: create new node
    }
    
    if (data < root->data) {
        root->left = insert_bst(root->left, data); // Insert in left subtree
    } else if (data > root->data) {
        root->right = insert_bst(root->right, data); // Insert in right subtree
    }
    
    return root;
}

void inorder_traversal(TreeNode* root) {
    if (root != NULL) {
        inorder_traversal(root->left); // Traverse left subtree
        printf("%d ", root->data); // Process current node
        inorder_traversal(root->right); // Traverse right subtree
    }
}

void preorder_traversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data); // Process current node
        preorder_traversal(root->left); // Traverse left subtree
        preorder_traversal(root->right); // Traverse right subtree
    }
}

void postorder_traversal(TreeNode* root) {
    if (root != NULL) {
        postorder_traversal(root->left); // Traverse left subtree
        postorder_traversal(root->right); // Traverse right subtree
        printf("%d ", root->data); // Process current node
    }
}

int tree_height(TreeNode* root) {
    if (root == NULL) {
        return -1; // Base case: empty tree has height -1
    }
    
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);
    
    return 1 + ((left_height > right_height) ? left_height : right_height);
}

int count_nodes(TreeNode* root) {
    if (root == NULL) {
        return 0; // Base case: empty tree has 0 nodes
    }
    
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

bool search_tree(TreeNode* root, int target) {
    if (root == NULL) {
        return false; // Base case: not found
    }
    
    if (root->data == target) {
        return true; // Base case: found
    }
    
    if (target < root->data) {
        return search_tree(root->left, target);
    } else {
        return search_tree(root->right, target);
    }
}

void free_tree(TreeNode* root) {
    if (root != NULL) {
        free_tree(root->left); // Free left subtree
        free_tree(root->right); // Free right subtree
        free(root); // Free current node
    }
}

// Advanced Recursion Implementations

int hanoi_moves(int n) {
    if (n == 1) {
        return 1;
    }
    return 2 * hanoi_moves(n - 1) + 1;
}

void tower_of_hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("  Move disk 1 from %c to %c\n", from, to);
        return;
    }
    
    tower_of_hanoi(n - 1, from, aux, to);
    printf("  Move disk %d from %c to %c\n", n, from, to);
    tower_of_hanoi(n - 1, aux, to, from);
}

void print_all_subsets(int arr[], int n, int index, int current_subset[], int current_size) {
    if (index == n) {
        printf("  {");
        for (int i = 0; i < current_size; i++) {
            printf("%d", current_subset[i]);
            if (i < current_size - 1) printf(", ");
        }
        printf("}\n");
        return;
    }
    
    // Exclude current element
    print_all_subsets(arr, n, index + 1, current_subset, current_size);
    
    // Include current element
    current_subset[current_size] = arr[index];
    print_all_subsets(arr, n, index + 1, current_subset, current_size + 1);
}

bool n_queens_solve(int n) {
    int board[MAX_SIZE][MAX_SIZE];
    
    // Initialize board
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    
    if (n_queens_util(board, 0, n)) {
        print_board(board, n);
        return true;
    }
    
    return false;
}

bool n_queens_util(int board[][MAX_SIZE], int col, int n) {
    if (col >= n) {
        return true; // All queens placed successfully
    }
    
    for (int i = 0; i < n; i++) {
        if (is_safe(board, i, col, n)) {
            board[i][col] = 1; // Place queen
            
            if (n_queens_util(board, col + 1, n)) {
                return true;
            }
            
            board[i][col] = 0; // Backtrack
        }
    }
    
    return false;
}

bool is_safe(int board[][MAX_SIZE], int row, int col, int n) {
    // Check row on left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }
    
    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    return true;
}

void print_board(int board[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        printf("  ");
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
}

bool solve_maze(int maze[][MAX_SIZE], int n) {
    int sol[MAX_SIZE][MAX_SIZE];
    
    // Initialize solution matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sol[i][j] = 0;
        }
    }
    
    if (solve_maze_util(maze, 0, 0, sol, n)) {
        print_maze_solution(sol, n);
        return true;
    }
    
    return false;
}

bool solve_maze_util(int maze[][MAX_SIZE], int x, int y, int sol[][MAX_SIZE], int n) {
    if (x == n - 1 && y == n - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }
    
    if (is_safe_move(maze, x, y, n)) {
        sol[x][y] = 1;
        
        // Move right
        if (solve_maze_util(maze, x, y + 1, sol, n)) {
            return true;
        }
        
        // Move down
        if (solve_maze_util(maze, x + 1, y, sol, n)) {
            return true;
        }
        
        sol[x][y] = 0; // Backtrack
        return false;
    }
    
    return false;
}

bool is_safe_move(int maze[][MAX_SIZE], int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1);
}

void print_maze_solution(int sol[][MAX_SIZE], int n) {
    printf("Solution path (1 = path, 0 = not part of path):\n");
    for (int i = 0; i < n; i++) {
        printf("  ");
        for (int j = 0; j < n; j++) {
            printf("%d ", sol[i][j]);
        }
        printf("\n");
    }
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

void initialize_memo(void) {
    for (int i = 0; i < MAX_MEMO; i++) {
        fib_memo[i] = 0;
        fib_computed[i] = false;
    }
}