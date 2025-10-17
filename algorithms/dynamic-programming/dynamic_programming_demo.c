/**
 * Dynamic Programming Examples - Comprehensive C Implementation
 * 
 * This program demonstrates:
 * - Fundamental DP concepts and patterns
 * - Classic DP problems (Fibonacci, Knapsack, LCS, etc.)
 * - Memoization (Top-down approach)
 * - Tabulation (Bottom-up approach)
 * - Space optimization techniques
 * - 1D and 2D DP problems
 * - String DP problems
 * - Matrix chain multiplication and other advanced problems
 * 
 * @author Bishal Goutam
 * @since C99 Standard
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define MAX_N 1000
#define MAX_CAPACITY 1000
#define INF INT_MAX

// Global memoization tables
static int fib_memo[MAX_N];
static bool fib_computed[MAX_N];
static int lcs_memo[MAX_N][MAX_N];
static int knapsack_memo[MAX_N][MAX_CAPACITY];

// Structure for items in knapsack problem
typedef struct {
    int weight;
    int value;
} Item;

// Function prototypes - Basic DP problems
long long fibonacci_recursive(int n);
long long fibonacci_memoized(int n);
long long fibonacci_tabulation(int n);
int fibonacci_space_optimized(int n);

// Function prototypes - Classic DP problems
int knapsack_recursive(Item items[], int n, int capacity, int index);
int knapsack_memoized(Item items[], int n, int capacity, int index);
int knapsack_tabulation(Item items[], int n, int capacity);
int knapsack_space_optimized(Item items[], int n, int capacity);

// Function prototypes - String DP
int lcs_recursive(const char* str1, const char* str2, int m, int n);
int lcs_memoized(const char* str1, const char* str2, int m, int n);
int lcs_tabulation(const char* str1, const char* str2);
void print_lcs(const char* str1, const char* str2);
int edit_distance(const char* str1, const char* str2);
bool is_subsequence(const char* s, const char* t);

// Function prototypes - Path problems
int unique_paths(int m, int n);
int unique_paths_with_obstacles(int obstacleGrid[][MAX_N], int m, int n);
int min_path_sum(int grid[][MAX_N], int m, int n);
int max_path_sum(int grid[][MAX_N], int m, int n);

// Function prototypes - Array DP
int max_subarray_sum(int arr[], int n);
int max_product_subarray(int arr[], int n);
int longest_increasing_subsequence(int arr[], int n);
int coin_change(int coins[], int num_coins, int amount);
int coin_change_combinations(int coins[], int num_coins, int amount);

// Function prototypes - Advanced DP
int matrix_chain_multiplication(int p[], int n);
int mcm_recursive(int p[], int i, int j);
int mcm_memoized(int p[], int i, int j, int memo[][MAX_N]);
int palindrome_partitioning(const char* str);
int rod_cutting(int prices[], int n);
int house_robber(int houses[], int n);

// Demo functions
void demonstrate_basic_dp_concepts(void);
void demonstrate_fibonacci_variations(void);
void demonstrate_knapsack_problem(void);
void demonstrate_string_dp(void);
void demonstrate_path_problems(void);
void demonstrate_array_dp(void);
void demonstrate_advanced_dp(void);
void demonstrate_optimization_techniques(void);

// Utility functions
void initialize_memos(void);
void reset_memos(void);
void print_array(int arr[], int n);
void print_2d_grid(int grid[][MAX_N], int rows, int cols);
int min_of_three(int a, int b, int c);
int max_of_two(int a, int b);

int main(void) {
    printf("=== C Dynamic Programming Examples ===\n\n");
    
    initialize_memos();
    
    demonstrate_basic_dp_concepts();
    demonstrate_fibonacci_variations();
    demonstrate_knapsack_problem();
    demonstrate_string_dp();
    demonstrate_path_problems();
    demonstrate_array_dp();
    demonstrate_advanced_dp();
    demonstrate_optimization_techniques();
    
    return 0;
}

/**
 * Demonstrates basic dynamic programming concepts
 */
void demonstrate_basic_dp_concepts(void) {
    printf("1. Basic Dynamic Programming Concepts\n");
    printf("=====================================\n");
    
    printf("Dynamic Programming Components:\n");
    printf("  1. Optimal Substructure: Solution can be constructed from optimal solutions of subproblems\n");
    printf("  2. Overlapping Subproblems: Same subproblems are solved multiple times\n");
    printf("  3. Memoization: Store results to avoid recomputation (Top-down)\n");
    printf("  4. Tabulation: Build solution bottom-up using table\n\n");
    
    printf("DP vs Divide & Conquer:\n");
    printf("  • Divide & Conquer: Subproblems are independent (e.g., Merge Sort)\n");
    printf("  • Dynamic Programming: Subproblems overlap (e.g., Fibonacci)\n\n");
    
    printf("Two Main Approaches:\n");
    printf("  1. Top-down (Memoization): Start from main problem, store results\n");
    printf("  2. Bottom-up (Tabulation): Start from smallest subproblems, build up\n\n");
    
    printf("When to Use DP:\n");
    printf("  ✓ Problem has optimal substructure\n");
    printf("  ✓ Overlapping subproblems exist\n");
    printf("  ✓ Brute force has exponential time complexity\n");
    printf("  ✓ Problem asks for optimization (min/max) or counting\n\n");
    
    printf("Common DP Patterns:\n");
    printf("  • Linear DP: f(i) depends on f(i-1), f(i-2), etc.\n");
    printf("  • Grid DP: f(i,j) depends on neighbors\n");
    printf("  • Interval DP: f(i,j) for range [i,j]\n");
    printf("  • Tree DP: DP on tree structures\n");
    printf("  • State Machine DP: Different states with transitions\n\n");
}

/**
 * Demonstrates Fibonacci sequence using different DP approaches
 */
void demonstrate_fibonacci_variations(void) {
    printf("2. Fibonacci Sequence - DP Approaches\n");
    printf("====================================\n");
    
    int n = 15;
    printf("Computing Fibonacci numbers up to F(%d):\n\n", n);
    
    // Show the problem with naive recursion
    printf("Naive Recursion (Exponential Time):\n");
    printf("  Problem: Same subproblems calculated repeatedly\n");
    printf("  Time Complexity: O(2^n)\n");
    printf("  Space Complexity: O(n) - recursion stack\n");
    
    for (int i = 0; i <= 10; i++) {
        printf("  F(%d) = %lld\n", i, fibonacci_recursive(i));
    }
    
    // Memoization approach
    printf("\nMemoization (Top-down DP):\n");
    printf("  Solution: Store computed results in memo table\n");
    printf("  Time Complexity: O(n)\n");
    printf("  Space Complexity: O(n) - memo table + recursion stack\n");
    
    reset_memos();
    for (int i = 0; i <= n; i++) {
        printf("  F(%d) = %lld\n", i, fibonacci_memoized(i));
    }
    
    // Tabulation approach
    printf("\nTabulation (Bottom-up DP):\n");
    printf("  Solution: Build table from bottom to top\n");
    printf("  Time Complexity: O(n)\n");
    printf("  Space Complexity: O(n) - DP table\n");
    
    for (int i = 0; i <= n; i++) {
        printf("  F(%d) = %lld\n", i, fibonacci_tabulation(i));
    }
    
    // Space optimized approach
    printf("\nSpace Optimized DP:\n");
    printf("  Solution: Only keep last two values\n");
    printf("  Time Complexity: O(n)\n");
    printf("  Space Complexity: O(1)\n");
    
    for (int i = 0; i <= n; i++) {
        printf("  F(%d) = %d\n", i, fibonacci_space_optimized(i));
    }
    
    printf("\n");
}

/**
 * Demonstrates the classic 0/1 Knapsack problem
 */
void demonstrate_knapsack_problem(void) {
    printf("3. 0/1 Knapsack Problem\n");
    printf("=======================\n");
    
    Item items[] = {
        {10, 60}, {20, 100}, {30, 120}
    };
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;
    
    printf("Items (Weight, Value):\n");
    for (int i = 0; i < n; i++) {
        printf("  Item %d: Weight = %d, Value = %d\n", i + 1, items[i].weight, items[i].value);
    }
    printf("Knapsack Capacity: %d\n\n", capacity);
    
    // Recursive approach
    printf("Recursive Approach:\n");
    printf("  Time Complexity: O(2^n)\n");
    printf("  Space Complexity: O(n) - recursion stack\n");
    int result_recursive = knapsack_recursive(items, n, capacity, 0);
    printf("  Maximum value: %d\n\n", result_recursive);
    
    // Memoized approach
    printf("Memoized Approach:\n");
    printf("  Time Complexity: O(n * capacity)\n");
    printf("  Space Complexity: O(n * capacity)\n");
    
    // Initialize knapsack memo
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_CAPACITY; j++) {
            knapsack_memo[i][j] = -1;
        }
    }
    
    int result_memoized = knapsack_memoized(items, n, capacity, 0);
    printf("  Maximum value: %d\n\n", result_memoized);
    
    // Tabulation approach
    printf("Tabulation Approach:\n");
    printf("  Time Complexity: O(n * capacity)\n");
    printf("  Space Complexity: O(n * capacity)\n");
    int result_tabulation = knapsack_tabulation(items, n, capacity);
    printf("  Maximum value: %d\n\n", result_tabulation);
    
    // Space optimized approach
    printf("Space Optimized Approach:\n");
    printf("  Time Complexity: O(n * capacity)\n");
    printf("  Space Complexity: O(capacity)\n");
    int result_optimized = knapsack_space_optimized(items, n, capacity);
    printf("  Maximum value: %d\n\n", result_optimized);
}

/**
 * Demonstrates string-based DP problems
 */
void demonstrate_string_dp(void) {
    printf("4. String Dynamic Programming\n");
    printf("=============================\n");
    
    // Longest Common Subsequence
    const char* str1 = "ABCDGH";
    const char* str2 = "AEDFHR";
    
    printf("Longest Common Subsequence (LCS):\n");
    printf("String 1: \"%s\"\n", str1);
    printf("String 2: \"%s\"\n", str2);
    
    // Reset LCS memo
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            lcs_memo[i][j] = -1;
        }
    }
    
    int lcs_len_recursive = lcs_recursive(str1, str2, strlen(str1), strlen(str2));
    printf("LCS Length (Recursive): %d\n", lcs_len_recursive);
    
    // Reset memo for memoized version
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            lcs_memo[i][j] = -1;
        }
    }
    
    int lcs_len_memoized = lcs_memoized(str1, str2, strlen(str1), strlen(str2));
    printf("LCS Length (Memoized): %d\n", lcs_len_memoized);
    
    int lcs_len_tabulation = lcs_tabulation(str1, str2);
    printf("LCS Length (Tabulation): %d\n", lcs_len_tabulation);
    
    printf("Actual LCS: ");
    print_lcs(str1, str2);
    printf("\n");
    
    // Edit Distance
    printf("\nEdit Distance (Levenshtein Distance):\n");
    const char* word1 = "horse";
    const char* word2 = "ros";
    printf("Transform \"%s\" to \"%s\"\n", word1, word2);
    int edit_dist = edit_distance(word1, word2);
    printf("Minimum edit distance: %d\n", edit_dist);
    
    // Subsequence check
    printf("\nSubsequence Check:\n");
    const char* s = "abc";
    const char* t = "aebdc";
    printf("Is \"%s\" a subsequence of \"%s\"? %s\n", 
           s, t, is_subsequence(s, t) ? "Yes" : "No");
    
    printf("\n");
}

/**
 * Demonstrates path-related DP problems
 */
void demonstrate_path_problems(void) {
    printf("5. Path Problems with DP\n");
    printf("========================\n");
    
    // Unique Paths
    printf("Unique Paths in Grid:\n");
    int m = 3, n = 7;
    printf("Grid size: %d x %d\n", m, n);
    int paths = unique_paths(m, n);
    printf("Number of unique paths from top-left to bottom-right: %d\n", paths);
    
    // Unique Paths with Obstacles
    printf("\nUnique Paths with Obstacles:\n");
    int obstacle_grid[MAX_N][MAX_N] = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    int obs_m = 3, obs_n = 3;
    
    printf("Grid (0 = free, 1 = obstacle):\n");
    print_2d_grid(obstacle_grid, obs_m, obs_n);
    
    int paths_obs = unique_paths_with_obstacles(obstacle_grid, obs_m, obs_n);
    printf("Number of unique paths: %d\n", paths_obs);
    
    // Minimum Path Sum
    printf("\nMinimum Path Sum:\n");
    int min_grid[MAX_N][MAX_N] = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    int min_m = 3, min_n = 3;
    
    printf("Grid with costs:\n");
    print_2d_grid(min_grid, min_m, min_n);
    
    int min_sum = min_path_sum(min_grid, min_m, min_n);
    printf("Minimum path sum: %d\n", min_sum);
    
    // Maximum Path Sum
    printf("\nMaximum Path Sum:\n");
    int max_grid[MAX_N][MAX_N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int max_m = 3, max_n = 3;
    
    printf("Grid with values:\n");
    print_2d_grid(max_grid, max_m, max_n);
    
    int max_sum = max_path_sum(max_grid, max_m, max_n);
    printf("Maximum path sum: %d\n", max_sum);
    
    printf("\n");
}

/**
 * Demonstrates array-based DP problems
 */
void demonstrate_array_dp(void) {
    printf("6. Array Dynamic Programming\n");
    printf("============================\n");
    
    // Maximum Subarray Sum (Kadane's Algorithm)
    int arr1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Maximum Subarray Sum (Kadane's Algorithm):\n");
    printf("Array: ");
    print_array(arr1, n1);
    int max_sub_sum = max_subarray_sum(arr1, n1);
    printf("Maximum subarray sum: %d\n", max_sub_sum);
    
    // Maximum Product Subarray
    int arr2[] = {2, 3, -2, 4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("\nMaximum Product Subarray:\n");
    printf("Array: ");
    print_array(arr2, n2);
    int max_prod = max_product_subarray(arr2, n2);
    printf("Maximum product subarray: %d\n", max_prod);
    
    // Longest Increasing Subsequence
    int arr3[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    
    printf("\nLongest Increasing Subsequence:\n");
    printf("Array: ");
    print_array(arr3, n3);
    int lis_len = longest_increasing_subsequence(arr3, n3);
    printf("Length of LIS: %d\n", lis_len);
    
    // Coin Change
    int coins[] = {1, 3, 4};
    int num_coins = sizeof(coins) / sizeof(coins[0]);
    int amount = 6;
    
    printf("\nCoin Change Problem:\n");
    printf("Coins: ");
    print_array(coins, num_coins);
    printf("Target amount: %d\n", amount);
    int min_coins = coin_change(coins, num_coins, amount);
    if (min_coins == INF) {
        printf("Cannot make the amount with given coins\n");
    } else {
        printf("Minimum coins needed: %d\n", min_coins);
    }
    
    // Coin Change Combinations
    int combinations = coin_change_combinations(coins, num_coins, amount);
    printf("Number of ways to make amount: %d\n", combinations);
    
    printf("\n");
}

/**
 * Demonstrates advanced DP problems
 */
void demonstrate_advanced_dp(void) {
    printf("7. Advanced Dynamic Programming\n");
    printf("===============================\n");
    
    // Matrix Chain Multiplication
    printf("Matrix Chain Multiplication:\n");
    int p[] = {1, 2, 3, 4, 5}; // Matrix dimensions: A1(1x2), A2(2x3), A3(3x4), A4(4x5)
    int matrices = sizeof(p) / sizeof(p[0]) - 1;
    
    printf("Matrix dimensions: ");
    for (int i = 0; i < matrices; i++) {
        printf("A%d(%dx%d) ", i + 1, p[i], p[i + 1]);
    }
    printf("\n");
    
    int min_multiplications = matrix_chain_multiplication(p, matrices);
    printf("Minimum scalar multiplications: %d\n", min_multiplications);
    
    // Rod Cutting Problem
    printf("\nRod Cutting Problem:\n");
    int prices[] = {0, 1, 5, 8, 9, 10, 17, 17, 20};
    int rod_length = 8;
    
    printf("Price table (length -> price):\n");
    for (int i = 1; i <= rod_length; i++) {
        printf("  Length %d: $%d\n", i, prices[i]);
    }
    
    int max_revenue = rod_cutting(prices, rod_length);
    printf("Maximum revenue for rod of length %d: $%d\n", rod_length, max_revenue);
    
    // House Robber Problem
    printf("\nHouse Robber Problem:\n");
    int houses[] = {2, 7, 9, 3, 1};
    int num_houses = sizeof(houses) / sizeof(houses[0]);
    
    printf("House values: ");
    print_array(houses, num_houses);
    printf("Rule: Cannot rob adjacent houses\n");
    
    int max_robbery = house_robber(houses, num_houses);
    printf("Maximum money that can be robbed: $%d\n", max_robbery);
    
    // Palindrome Partitioning
    printf("\nPalindrome Partitioning:\n");
    const char* partition_str = "aab";
    printf("String: \"%s\"\n", partition_str);
    int min_cuts = palindrome_partitioning(partition_str);
    printf("Minimum cuts for palindrome partitioning: %d\n", min_cuts);
    
    printf("\n");
}

/**
 * Demonstrates DP optimization techniques
 */
void demonstrate_optimization_techniques(void) {
    printf("8. DP Optimization Techniques\n");
    printf("=============================\n");
    
    printf("Space Optimization Strategies:\n\n");
    
    printf("1. Rolling Array:\n");
    printf("   • Instead of 2D table, use only 2 rows\n");
    printf("   • Example: LCS using O(min(m,n)) space instead of O(mn)\n");
    printf("   • Applicable when current row depends only on previous row\n\n");
    
    printf("2. State Compression:\n");
    printf("   • Use bit manipulation to represent states\n");
    printf("   • Example: Traveling Salesman Problem with bitmask DP\n");
    printf("   • Reduces space when states can be represented as bits\n\n");
    
    printf("3. Coordinate Compression:\n");
    printf("   • Map large coordinate values to smaller range\n");
    printf("   • Useful when range is large but actual values are sparse\n");
    printf("   • Example: DP on large grid with few interesting points\n\n");
    
    printf("Time Optimization Strategies:\n\n");
    
    printf("1. Matrix Exponentiation:\n");
    printf("   • For linear recurrence relations\n");
    printf("   • Reduces O(n) to O(log n) using matrix multiplication\n");
    printf("   • Example: nth Fibonacci in O(log n) time\n\n");
    
    printf("2. Convex Hull Optimization:\n");
    printf("   • For DP with specific mathematical properties\n");
    printf("   • Reduces O(n²) to O(n log n) or O(n)\n");
    printf("   • Example: Some divide and conquer optimization problems\n\n");
    
    printf("3. Monotonic Queue/Deque:\n");
    printf("   • For sliding window maximum/minimum problems\n");
    printf("   • Maintains optimal candidates in sorted order\n");
    printf("   • Example: Maximum subarray of fixed size\n\n");
    
    printf("Common DP Patterns and When to Use:\n\n");
    
    printf("Pattern                    | Time      | Space     | Use Case\n");
    printf("---------------------------|-----------|-----------|----------------------------------\n");
    printf("1D Array DP               | O(n)      | O(n)      | Linear sequences, Fibonacci-like\n");
    printf("2D Grid DP                | O(mn)     | O(mn)     | Path problems, string matching\n");
    printf("Interval DP               | O(n³)     | O(n²)     | Matrix chain, palindrome partition\n");
    printf("Tree DP                   | O(n)      | O(n)      | Tree traversal, subtree problems\n");
    printf("Bitmask DP                | O(n×2ⁿ)   | O(2ⁿ)     | Subset problems, TSP\n");
    printf("Digit DP                  | O(d×s)    | O(d×s)    | Number theory, digit constraints\n");
    
    printf("\nChoosing Between Approaches:\n");
    printf("  • Use memoization when:\n");
    printf("    - Not all subproblems need to be solved\n");
    printf("    - Recursive solution is more intuitive\n");
    printf("    - Problem has irregular structure\n\n");
    printf("  • Use tabulation when:\n");
    printf("    - All subproblems need to be solved\n");
    printf("    - Want to avoid recursion overhead\n");
    printf("    - Need space optimization\n");
    printf("    - Want predictable memory access patterns\n\n");
}

// Basic DP Implementations

long long fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

long long fibonacci_memoized(int n) {
    if (n < 0 || n >= MAX_N) return -1;
    
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

long long fibonacci_tabulation(int n) {
    if (n <= 1) return n;
    
    long long dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}

int fibonacci_space_optimized(int n) {
    if (n <= 1) return n;
    
    int prev2 = 0, prev1 = 1, current;
    
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}

// Knapsack Problem Implementations

int knapsack_recursive(Item items[], int n, int capacity, int index) {
    if (index == n || capacity == 0) {
        return 0;
    }
    
    if (items[index].weight > capacity) {
        return knapsack_recursive(items, n, capacity, index + 1);
    }
    
    int include = items[index].value + knapsack_recursive(items, n, capacity - items[index].weight, index + 1);
    int exclude = knapsack_recursive(items, n, capacity, index + 1);
    
    return max_of_two(include, exclude);
}

int knapsack_memoized(Item items[], int n, int capacity, int index) {
    if (index == n || capacity == 0) {
        return 0;
    }
    
    if (knapsack_memo[index][capacity] != -1) {
        return knapsack_memo[index][capacity];
    }
    
    int result;
    if (items[index].weight > capacity) {
        result = knapsack_memoized(items, n, capacity, index + 1);
    } else {
        int include = items[index].value + knapsack_memoized(items, n, capacity - items[index].weight, index + 1);
        int exclude = knapsack_memoized(items, n, capacity, index + 1);
        result = max_of_two(include, exclude);
    }
    
    knapsack_memo[index][capacity] = result;
    return result;
}

int knapsack_tabulation(Item items[], int n, int capacity) {
    int dp[n + 1][capacity + 1];
    
    // Initialize base cases
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (items[i - 1].weight <= w) {
                dp[i][w] = max_of_two(
                    items[i - 1].value + dp[i - 1][w - items[i - 1].weight],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    return dp[n][capacity];
}

int knapsack_space_optimized(Item items[], int n, int capacity) {
    int dp[capacity + 1];
    
    // Initialize
    for (int i = 0; i <= capacity; i++) {
        dp[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int w = capacity; w >= items[i].weight; w--) {
            dp[w] = max_of_two(dp[w], dp[w - items[i].weight] + items[i].value);
        }
    }
    
    return dp[capacity];
}

// String DP Implementations

int lcs_recursive(const char* str1, const char* str2, int m, int n) {
    if (m == 0 || n == 0) {
        return 0;
    }
    
    if (str1[m - 1] == str2[n - 1]) {
        return 1 + lcs_recursive(str1, str2, m - 1, n - 1);
    } else {
        return max_of_two(lcs_recursive(str1, str2, m, n - 1), 
                         lcs_recursive(str1, str2, m - 1, n));
    }
}

int lcs_memoized(const char* str1, const char* str2, int m, int n) {
    if (m == 0 || n == 0) {
        return 0;
    }
    
    if (lcs_memo[m][n] != -1) {
        return lcs_memo[m][n];
    }
    
    int result;
    if (str1[m - 1] == str2[n - 1]) {
        result = 1 + lcs_memoized(str1, str2, m - 1, n - 1);
    } else {
        result = max_of_two(lcs_memoized(str1, str2, m, n - 1),
                           lcs_memoized(str1, str2, m - 1, n));
    }
    
    lcs_memo[m][n] = result;
    return result;
}

int lcs_tabulation(const char* str1, const char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[m + 1][n + 1];
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max_of_two(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[m][n];
}

void print_lcs(const char* str1, const char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[m + 1][n + 1];
    
    // Build LCS table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max_of_two(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // Backtrack to find LCS
    char lcs[dp[m][n] + 1];
    int index = dp[m][n];
    lcs[index] = '\0';
    
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs[index - 1] = str1[i - 1];
            i--; j--; index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    printf("\"%s\"", lcs);
}

int edit_distance(const char* str1, const char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[m + 1][n + 1];
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j; // Insert all characters of str2
            } else if (j == 0) {
                dp[i][j] = i; // Delete all characters of str1
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // No operation needed
            } else {
                dp[i][j] = 1 + min_of_three(
                    dp[i][j - 1],     // Insert
                    dp[i - 1][j],     // Delete
                    dp[i - 1][j - 1]  // Replace
                );
            }
        }
    }
    
    return dp[m][n];
}

bool is_subsequence(const char* s, const char* t) {
    int m = strlen(s);
    int n = strlen(t);
    
    if (m == 0) return true;
    if (n == 0) return false;
    
    int i = 0; // Index for s
    for (int j = 0; j < n && i < m; j++) {
        if (s[i] == t[j]) {
            i++;
        }
    }
    
    return i == m;
}

// Path Problems Implementations

int unique_paths(int m, int n) {
    int dp[m][n];
    
    // Initialize first row and column
    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    
    return dp[m - 1][n - 1];
}

int unique_paths_with_obstacles(int obstacleGrid[][MAX_N], int m, int n) {
    if (obstacleGrid[0][0] == 1) return 0;
    
    int dp[m][n];
    dp[0][0] = 1;
    
    // Initialize first row
    for (int j = 1; j < n; j++) {
        dp[0][j] = (obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1) ? 1 : 0;
    }
    
    // Initialize first column
    for (int i = 1; i < m; i++) {
        dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1) ? 1 : 0;
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    
    return dp[m - 1][n - 1];
}

int min_path_sum(int grid[][MAX_N], int m, int n) {
    int dp[m][n];
    dp[0][0] = grid[0][0];
    
    // Initialize first row
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    
    // Initialize first column
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min_of_two(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    
    return dp[m - 1][n - 1];
}

int max_path_sum(int grid[][MAX_N], int m, int n) {
    int dp[m][n];
    dp[0][0] = grid[0][0];
    
    // Initialize first row
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    
    // Initialize first column
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = max_of_two(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    
    return dp[m - 1][n - 1];
}

// Array DP Implementations

int max_subarray_sum(int arr[], int n) {
    int max_ending_here = arr[0];
    int max_so_far = arr[0];
    
    for (int i = 1; i < n; i++) {
        max_ending_here = max_of_two(arr[i], max_ending_here + arr[i]);
        max_so_far = max_of_two(max_so_far, max_ending_here);
    }
    
    return max_so_far;
}

int max_product_subarray(int arr[], int n) {
    int max_ending_here = arr[0];
    int min_ending_here = arr[0];
    int max_so_far = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) {
            int temp = max_ending_here;
            max_ending_here = min_ending_here;
            min_ending_here = temp;
        }
        
        max_ending_here = max_of_two(arr[i], max_ending_here * arr[i]);
        min_ending_here = min_of_two(arr[i], min_ending_here * arr[i]);
        
        max_so_far = max_of_two(max_so_far, max_ending_here);
    }
    
    return max_so_far;
}

int longest_increasing_subsequence(int arr[], int n) {
    int dp[n];
    int max_length = 1;
    
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                max_length = max_of_two(max_length, dp[i]);
            }
        }
    }
    
    return max_length;
}

int coin_change(int coins[], int num_coins, int amount) {
    int dp[amount + 1];
    
    for (int i = 0; i <= amount; i++) {
        dp[i] = INF;
    }
    
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < num_coins; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INF) {
                dp[i] = min_of_two(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    
    return dp[amount];
}

int coin_change_combinations(int coins[], int num_coins, int amount) {
    int dp[amount + 1];
    
    for (int i = 0; i <= amount; i++) {
        dp[i] = 0;
    }
    
    dp[0] = 1;
    
    for (int i = 0; i < num_coins; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    
    return dp[amount];
}

// Advanced DP Implementations

int matrix_chain_multiplication(int p[], int n) {
    int dp[n][n];
    int i, j, k, length, cost;
    
    // Length 1 chains have zero cost
    for (i = 1; i < n; i++) {
        dp[i][i] = 0;
    }
    
    for (length = 2; length < n; length++) {
        for (i = 1; i < n - length + 1; i++) {
            j = i + length - 1;
            dp[i][j] = INF;
            
            for (k = i; k <= j - 1; k++) {
                cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    
    return dp[1][n - 1];
}

int palindrome_partitioning(const char* str) {
    int n = strlen(str);
    bool is_palindrome[n][n];
    int dp[n];
    
    // Check all substrings for palindrome
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            is_palindrome[i][j] = false;
        }
    }
    
    // Single characters are palindromes
    for (int i = 0; i < n; i++) {
        is_palindrome[i][i] = true;
    }
    
    // Check for 2-character palindromes
    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            is_palindrome[i][i + 1] = true;
        }
    }
    
    // Check for palindromes of length 3 and more
    for (int length = 3; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            if (str[i] == str[j] && is_palindrome[i + 1][j - 1]) {
                is_palindrome[i][j] = true;
            }
        }
    }
    
    // DP for minimum cuts
    for (int i = 0; i < n; i++) {
        if (is_palindrome[0][i]) {
            dp[i] = 0;
        } else {
            dp[i] = i; // Maximum cuts
            for (int j = 0; j < i; j++) {
                if (is_palindrome[j + 1][i] && 1 + dp[j] < dp[i]) {
                    dp[i] = 1 + dp[j];
                }
            }
        }
    }
    
    return dp[n - 1];
}

int rod_cutting(int prices[], int n) {
    int dp[n + 1];
    dp[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++) {
            max_val = max_of_two(max_val, prices[j] + dp[i - j - 1]);
        }
        dp[i] = max_val;
    }
    
    return dp[n];
}

int house_robber(int houses[], int n) {
    if (n == 0) return 0;
    if (n == 1) return houses[0];
    
    int dp[n];
    dp[0] = houses[0];
    dp[1] = max_of_two(houses[0], houses[1]);
    
    for (int i = 2; i < n; i++) {
        dp[i] = max_of_two(dp[i - 1], dp[i - 2] + houses[i]);
    }
    
    return dp[n - 1];
}

// Utility Function Implementations

void initialize_memos(void) {
    for (int i = 0; i < MAX_N; i++) {
        fib_memo[i] = 0;
        fib_computed[i] = false;
    }
    
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            lcs_memo[i][j] = -1;
        }
    }
    
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_CAPACITY; j++) {
            knapsack_memo[i][j] = -1;
        }
    }
}

void reset_memos(void) {
    for (int i = 0; i < MAX_N; i++) {
        fib_computed[i] = false;
    }
}

void print_array(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

void print_2d_grid(int grid[][MAX_N], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("  ");
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int min_of_two(int a, int b) {
    return (a < b) ? a : b;
}

int min_of_three(int a, int b, int c) {
    return min_of_two(min_of_two(a, b), c);
}

int max_of_two(int a, int b) {
    return (a > b) ? a : b;
}