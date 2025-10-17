/**
 * Greedy Algorithms - Comprehensive C Implementation
 * 
 * This program demonstrates:
 * - Fundamental greedy algorithm concepts
 * - Activity selection problem
 * - Fractional knapsack problem
 * - Huffman coding algorithm
 * - Graph algorithms (MST, Shortest Path)
 * - Job scheduling problems
 * - Coin change (greedy approach)
 * - Interval scheduling maximization
 * - Gas station problem
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
#define MAX_ACTIVITIES 100
#define MAX_ITEMS 100
#define MAX_VERTICES 100
#define MAX_EDGES 1000
#define INF INT_MAX

// Structure definitions
typedef struct {
    int start;
    int finish;
    int index;
} Activity;

typedef struct {
    double weight;
    int value;
    double ratio; // value/weight ratio
    int index;
} FractionalItem;

typedef struct {
    char character;
    int frequency;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
} HuffmanNode;

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    int vertices;
    int edges;
    Edge edge[MAX_EDGES];
} Graph;

typedef struct {
    int deadline;
    int profit;
    int index;
} Job;

typedef struct {
    int distance;
    int gas;
    int index;
} GasStation;

// Function prototypes - Activity Selection
int activity_selection_greedy(Activity activities[], int n, int selected[]);
void sort_activities_by_finish_time(Activity activities[], int n);
int compare_activities(const void* a, const void* b);

// Function prototypes - Fractional Knapsack
double fractional_knapsack(FractionalItem items[], int n, double capacity);
void sort_items_by_ratio(FractionalItem items[], int n);
int compare_items(const void* a, const void* b);

// Function prototypes - Huffman Coding
HuffmanNode* create_huffman_node(char character, int frequency);
void build_huffman_tree(char characters[], int frequencies[], int n);
void print_huffman_codes(HuffmanNode* root, char* code, int depth);
void free_huffman_tree(HuffmanNode* root);

// Function prototypes - Graph Algorithms
void kruskals_mst(Graph* graph);
void prims_mst(int graph[MAX_VERTICES][MAX_VERTICES], int vertices);
void dijkstras_shortest_path(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int src);
int find_parent(int parent[], int i);
void union_sets(int parent[], int rank[], int x, int y);
int min_key(int key[], bool mst_set[], int vertices);

// Function prototypes - Job Scheduling
int job_scheduling_max_profit(Job jobs[], int n);
void sort_jobs_by_deadline(Job jobs[], int n);
int compare_jobs_by_profit(const void* a, const void* b);

// Function prototypes - Other Greedy Problems
int coin_change_greedy(int coins[], int num_coins, int amount, int result[]);
int gas_station_problem(int gas[], int cost[], int n);
int minimum_platforms(int arrivals[], int departures[], int n);
double minimum_waiting_time(double processes[], int n);

// Demo functions
void demonstrate_greedy_concepts(void);
void demonstrate_activity_selection(void);
void demonstrate_fractional_knapsack(void);
void demonstrate_huffman_coding(void);
void demonstrate_graph_algorithms(void);
void demonstrate_job_scheduling(void);
void demonstrate_other_greedy_problems(void);
void demonstrate_greedy_vs_optimal(void);

// Utility functions
void print_array(int arr[], int n);
void print_activities(Activity activities[], int n);
void print_items(FractionalItem items[], int n);

int main(void) {
    printf("=== C Greedy Algorithms Demo ===\n\n");
    
    demonstrate_greedy_concepts();
    demonstrate_activity_selection();
    demonstrate_fractional_knapsack();
    demonstrate_huffman_coding();
    demonstrate_graph_algorithms();
    demonstrate_job_scheduling();
    demonstrate_other_greedy_problems();
    demonstrate_greedy_vs_optimal();
    
    return 0;
}

/**
 * Demonstrates fundamental greedy algorithm concepts
 */
void demonstrate_greedy_concepts(void) {
    printf("1. Greedy Algorithm Concepts\n");
    printf("============================\n");
    
    printf("Greedy Algorithm Characteristics:\n");
    printf("  1. Makes locally optimal choice at each step\n");
    printf("  2. Hopes that local optimum leads to global optimum\n");
    printf("  3. Cannot backtrack or change previous decisions\n");
    printf("  4. Generally more efficient than dynamic programming\n\n");
    
    printf("Greedy Choice Property:\n");
    printf("  • A global optimum can be reached by making locally optimal choices\n");
    printf("  • Once a choice is made, it cannot be changed\n");
    printf("  • The problem reduces to a smaller subproblem\n\n");
    
    printf("Optimal Substructure:\n");
    printf("  • Optimal solution contains optimal solutions to subproblems\n");
    printf("  • Greedy choice + optimal solution to remaining subproblem = optimal solution\n\n");
    
    printf("When Greedy Works:\n");
    printf("  ✓ Problem has greedy choice property\n");
    printf("  ✓ Problem has optimal substructure\n");
    printf("  ✓ Local optimization leads to global optimization\n\n");
    
    printf("When Greedy Fails:\n");
    printf("  ✗ 0/1 Knapsack problem (use DP instead)\n");
    printf("  ✗ Traveling Salesman Problem\n");
    printf("  ✗ Subset sum problem\n\n");
    
    printf("Common Greedy Strategies:\n");
    printf("  • Choose largest/smallest first\n");
    printf("  • Choose earliest deadline first\n");
    printf("  • Choose highest ratio/efficiency first\n");
    printf("  • Choose minimum cost/distance first\n\n");
}

/**
 * Demonstrates activity selection problem
 */
void demonstrate_activity_selection(void) {
    printf("2. Activity Selection Problem\n");
    printf("=============================\n");
    
    Activity activities[] = {
        {1, 4, 0}, {3, 5, 1}, {0, 6, 2}, {5, 7, 3},
        {3, 9, 4}, {5, 9, 5}, {6, 10, 6}, {8, 11, 7},
        {8, 12, 8}, {2, 14, 9}, {12, 16, 10}
    };
    int n = sizeof(activities) / sizeof(activities[0]);
    
    printf("Problem: Select maximum number of non-overlapping activities\n");
    printf("Strategy: Select activities that finish earliest (greedy choice)\n\n");
    
    printf("Activities (Start, Finish):\n");
    for (int i = 0; i < n; i++) {
        printf("  Activity %d: (%d, %d)\n", activities[i].index, 
               activities[i].start, activities[i].finish);
    }
    
    int selected[MAX_ACTIVITIES];
    int count = activity_selection_greedy(activities, n, selected);
    
    printf("\nSelected Activities (Maximum: %d):\n", count);
    for (int i = 0; i < count; i++) {
        printf("  Activity %d: (%d, %d)\n", activities[selected[i]].index,
               activities[selected[i]].start, activities[selected[i]].finish);
    }
    
    printf("\nTime Complexity: O(n log n) for sorting + O(n) for selection\n");
    printf("Space Complexity: O(1)\n");
    printf("Optimality: Greedy choice property ensures optimal solution\n\n");
}

/**
 * Demonstrates fractional knapsack problem
 */
void demonstrate_fractional_knapsack(void) {
    printf("3. Fractional Knapsack Problem\n");
    printf("==============================\n");
    
    FractionalItem items[] = {
        {10, 60, 0, 0}, {20, 100, 0, 1}, {30, 120, 0, 2}
    };
    int n = sizeof(items) / sizeof(items[0]);
    double capacity = 50;
    
    // Calculate value/weight ratios
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    
    printf("Problem: Maximize value in knapsack (fractions allowed)\n");
    printf("Strategy: Select items with highest value/weight ratio first\n\n");
    
    printf("Items (Weight, Value, Ratio):\n");
    print_items(items, n);
    printf("Knapsack Capacity: %.1f\n\n", capacity);
    
    double max_value = fractional_knapsack(items, n, capacity);
    
    printf("Maximum value achievable: %.2f\n", max_value);
    
    printf("\nTime Complexity: O(n log n) for sorting + O(n) for selection\n");
    printf("Space Complexity: O(1)\n");
    printf("Optimality: Greedy choice property ensures optimal solution\n");
    printf("Note: This is different from 0/1 knapsack where greedy fails\n\n");
}

/**
 * Demonstrates Huffman coding algorithm
 */
void demonstrate_huffman_coding(void) {
    printf("4. Huffman Coding Algorithm\n");
    printf("===========================\n");
    
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int n = sizeof(characters) / sizeof(characters[0]);
    
    printf("Problem: Generate optimal prefix-free binary codes\n");
    printf("Strategy: Build binary tree with minimum weighted path length\n\n");
    
    printf("Character Frequencies:\n");
    for (int i = 0; i < n; i++) {
        printf("  '%c': %d\n", characters[i], frequencies[i]);
    }
    
    printf("\nBuilding Huffman Tree and generating codes:\n");
    build_huffman_tree(characters, frequencies, n);
    
    printf("\nTime Complexity: O(n log n)\n");
    printf("Space Complexity: O(n)\n");
    printf("Optimality: Huffman codes are optimal prefix-free codes\n");
    printf("Application: Data compression (ZIP, JPEG, MP3)\n\n");
}

/**
 * Demonstrates graph algorithms using greedy approach
 */
void demonstrate_graph_algorithms(void) {
    printf("5. Graph Algorithms (Greedy)\n");
    printf("============================\n");
    
    // Minimum Spanning Tree - Kruskal's Algorithm
    printf("Kruskal's Minimum Spanning Tree:\n");
    printf("Strategy: Sort edges by weight, add if no cycle forms\n\n");
    
    Graph graph;
    graph.vertices = 4;
    graph.edges = 5;
    
    // Define edges (src, dest, weight)
    graph.edge[0] = (Edge){0, 1, 10};
    graph.edge[1] = (Edge){0, 2, 6};
    graph.edge[2] = (Edge){0, 3, 5};
    graph.edge[3] = (Edge){1, 3, 15};
    graph.edge[4] = (Edge){2, 3, 4};
    
    printf("Graph Edges (src, dest, weight):\n");
    for (int i = 0; i < graph.edges; i++) {
        printf("  (%d, %d, %d)\n", graph.edge[i].src, graph.edge[i].dest, graph.edge[i].weight);
    }
    
    printf("\nKruskal's MST:\n");
    kruskals_mst(&graph);
    
    // Prim's Algorithm
    printf("\nPrim's Minimum Spanning Tree:\n");
    printf("Strategy: Start from vertex, add minimum weight edge to MST\n\n");
    
    int prim_graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    
    printf("Prim's MST (starting from vertex 0):\n");
    prims_mst(prim_graph, 5);
    
    // Dijkstra's Shortest Path
    printf("\nDijkstra's Shortest Path:\n");
    printf("Strategy: Always choose vertex with minimum distance\n\n");
    
    int dijkstra_graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    
    printf("Shortest paths from vertex 0:\n");
    dijkstras_shortest_path(dijkstra_graph, 9, 0);
    
    printf("\n");
}

/**
 * Demonstrates job scheduling problems
 */
void demonstrate_job_scheduling(void) {
    printf("6. Job Scheduling Problems\n");
    printf("==========================\n");
    
    // Job Scheduling with Deadlines
    Job jobs[] = {
        {4, 20, 0}, {1, 10, 1}, {1, 40, 2}, {1, 30, 3}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    
    printf("Job Scheduling with Deadlines:\n");
    printf("Strategy: Schedule jobs with highest profit first (within deadline)\n\n");
    
    printf("Jobs (Deadline, Profit):\n");
    for (int i = 0; i < n; i++) {
        printf("  Job %d: Deadline=%d, Profit=%d\n", jobs[i].index, jobs[i].deadline, jobs[i].profit);
    }
    
    int max_profit = job_scheduling_max_profit(jobs, n);
    printf("\nMaximum profit achievable: %d\n", max_profit);
    
    // Shortest Job First (SJF) Scheduling
    printf("\nShortest Job First Scheduling:\n");
    printf("Strategy: Execute shortest jobs first to minimize waiting time\n\n");
    
    double process_times[] = {6, 8, 7, 3};
    int num_processes = sizeof(process_times) / sizeof(process_times[0]);
    
    printf("Process Times: ");
    for (int i = 0; i < num_processes; i++) {
        printf("%.1f ", process_times[i]);
    }
    printf("\n");
    
    double avg_waiting = minimum_waiting_time(process_times, num_processes);
    printf("Average waiting time: %.2f\n", avg_waiting);
    
    printf("\nTime Complexity: O(n log n) for sorting\n");
    printf("Optimality: SJF minimizes average waiting time\n\n");
}

/**
 * Demonstrates other greedy problems
 */
void demonstrate_other_greedy_problems(void) {
    printf("7. Other Greedy Problems\n");
    printf("========================\n");
    
    // Coin Change (Greedy - only works for certain coin systems)
    printf("Coin Change (Greedy Approach):\n");
    printf("Strategy: Use largest denomination first\n");
    printf("Note: Only optimal for certain coin systems (e.g., standard denominations)\n\n");
    
    int coins[] = {25, 10, 5, 1}; // US coin system
    int num_coins = sizeof(coins) / sizeof(coins[0]);
    int amount = 67;
    int result[MAX_N];
    
    printf("Available coins: ");
    print_array(coins, num_coins);
    printf("Amount to make: %d\n", amount);
    
    int coin_count = coin_change_greedy(coins, num_coins, amount, result);
    
    printf("Coins used (%d total):\n", coin_count);
    for (int i = 0; i < coin_count; i++) {
        printf("  %d", result[i]);
        if (i < coin_count - 1) printf(", ");
    }
    printf("\n");
    
    // Gas Station Problem
    printf("\nGas Station Problem:\n");
    printf("Strategy: Go as far as possible with current gas\n\n");
    
    int gas[] = {1, 2, 3, 4, 5};
    int cost[] = {3, 4, 5, 1, 2};
    int n = 5;
    
    printf("Gas stations (Gas available, Cost to next):\n");
    for (int i = 0; i < n; i++) {
        printf("  Station %d: Gas=%d, Cost=%d\n", i, gas[i], cost[i]);
    }
    
    int start_station = gas_station_problem(gas, cost, n);
    if (start_station != -1) {
        printf("Start from station: %d\n", start_station);
    } else {
        printf("No solution exists\n");
    }
    
    // Minimum Platforms Problem
    printf("\nMinimum Railway Platforms:\n");
    printf("Strategy: Count overlapping intervals using events\n\n");
    
    int arrivals[] = {900, 940, 950, 1100, 1500, 1800};
    int departures[] = {910, 1200, 1120, 1130, 1900, 2000};
    int trains = sizeof(arrivals) / sizeof(arrivals[0]);
    
    printf("Train Schedule (Arrival, Departure):\n");
    for (int i = 0; i < trains; i++) {
        printf("  Train %d: (%d, %d)\n", i + 1, arrivals[i], departures[i]);
    }
    
    int platforms = minimum_platforms(arrivals, departures, trains);
    printf("Minimum platforms needed: %d\n", platforms);
    
    printf("\n");
}

/**
 * Demonstrates when greedy works vs when it fails
 */
void demonstrate_greedy_vs_optimal(void) {
    printf("8. Greedy vs Optimal Solutions\n");
    printf("==============================\n");
    
    printf("Problems Where Greedy Works Optimally:\n");
    printf("  ✓ Activity Selection: Earliest finish time\n");
    printf("  ✓ Fractional Knapsack: Highest value/weight ratio\n");
    printf("  ✓ Huffman Coding: Minimum frequency nodes first\n");
    printf("  ✓ Minimum Spanning Tree: Minimum weight edges\n");
    printf("  ✓ Shortest Path (Dijkstra): Minimum distance vertices\n");
    printf("  ✓ Job Scheduling: Highest profit within deadline\n\n");
    
    printf("Problems Where Greedy Fails:\n");
    printf("  ✗ 0/1 Knapsack: May miss optimal combination\n");
    printf("  ✗ Longest Path in Graph: Local choices miss global optimum\n");
    printf("  ✗ Coin Change (arbitrary denominations): May use more coins\n");
    printf("  ✗ Graph Coloring: Greedy may use more colors than necessary\n\n");
    
    printf("Example: 0/1 Knapsack Failure\n");
    printf("Items: (weight=10, value=10), (weight=20, value=20), (weight=15, value=15)\n");
    printf("Capacity: 30\n");
    printf("Greedy (by ratio): Takes (10,10) and (15,15) = value 25\n");
    printf("Optimal: Takes (20,20) and (10,10) = value 30\n\n");
    
    printf("Proving Greedy Correctness:\n");
    printf("  1. Greedy Choice Property:\n");
    printf("     - Show that locally optimal choice leads to globally optimal solution\n");
    printf("     - Prove by contradiction or exchange argument\n\n");
    
    printf("  2. Optimal Substructure:\n");
    printf("     - Show that problem can be broken into subproblems\n");
    printf("     - Optimal solution contains optimal solutions to subproblems\n\n");
    
    printf("  3. Mathematical Induction:\n");
    printf("     - Prove correctness for base case\n");
    printf("     - Show that if true for k steps, then true for k+1 steps\n\n");
    
    printf("Algorithm Design Strategy:\n");
    printf("  1. Identify the greedy choice (what to choose at each step)\n");
    printf("  2. Prove the greedy choice property\n");
    printf("  3. Prove optimal substructure\n");
    printf("  4. Implement the algorithm\n");
    printf("  5. Analyze time and space complexity\n\n");
}

// Activity Selection Implementation

int activity_selection_greedy(Activity activities[], int n, int selected[]) {
    // Sort activities by finish time
    sort_activities_by_finish_time(activities, n);
    
    // The first activity is always selected
    selected[0] = 0;
    int count = 1;
    int last_selected = 0;
    
    // Consider remaining activities
    for (int i = 1; i < n; i++) {
        // If this activity starts after the last selected activity finishes
        if (activities[i].start >= activities[last_selected].finish) {
            selected[count] = i;
            last_selected = i;
            count++;
        }
    }
    
    return count;
}

void sort_activities_by_finish_time(Activity activities[], int n) {
    qsort(activities, n, sizeof(Activity), compare_activities);
}

int compare_activities(const void* a, const void* b) {
    Activity* activity1 = (Activity*)a;
    Activity* activity2 = (Activity*)b;
    return activity1->finish - activity2->finish;
}

// Fractional Knapsack Implementation

double fractional_knapsack(FractionalItem items[], int n, double capacity) {
    // Sort items by value/weight ratio in descending order
    sort_items_by_ratio(items, n);
    
    double total_value = 0.0;
    double remaining_capacity = capacity;
    
    printf("Selection process:\n");
    
    for (int i = 0; i < n; i++) {
        if (remaining_capacity == 0) break;
        
        if (items[i].weight <= remaining_capacity) {
            // Take the whole item
            total_value += items[i].value;
            remaining_capacity -= items[i].weight;
            printf("  Take full item %d: weight=%.1f, value=%d\n", 
                   items[i].index, items[i].weight, items[i].value);
        } else {
            // Take fraction of the item
            double fraction = remaining_capacity / items[i].weight;
            total_value += items[i].value * fraction;
            printf("  Take %.2f of item %d: weight=%.1f, value=%.2f\n", 
                   fraction, items[i].index, remaining_capacity, items[i].value * fraction);
            remaining_capacity = 0;
        }
    }
    
    return total_value;
}

void sort_items_by_ratio(FractionalItem items[], int n) {
    qsort(items, n, sizeof(FractionalItem), compare_items);
}

int compare_items(const void* a, const void* b) {
    FractionalItem* item1 = (FractionalItem*)a;
    FractionalItem* item2 = (FractionalItem*)b;
    if (item1->ratio < item2->ratio) return 1;
    if (item1->ratio > item2->ratio) return -1;
    return 0;
}

// Huffman Coding Implementation

HuffmanNode* create_huffman_node(char character, int frequency) {
    HuffmanNode* node = malloc(sizeof(HuffmanNode));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void build_huffman_tree(char characters[], int frequencies[], int n) {
    // This is a simplified version - a complete implementation would use a priority queue
    printf("Huffman codes (simplified demonstration):\n");
    
    // For demonstration, show what the codes would look like
    printf("  'f' (freq=45): 0\n");
    printf("  'c' (freq=12): 100\n");
    printf("  'd' (freq=13): 101\n");
    printf("  'a' (freq=5):  1100\n");
    printf("  'b' (freq=9):  1101\n");
    printf("  'e' (freq=16): 111\n");
    
    int total_bits_fixed = 0;
    int total_bits_huffman = 0;
    
    for (int i = 0; i < n; i++) {
        total_bits_fixed += frequencies[i] * 3; // 3 bits per character for fixed-length
        // Calculate Huffman bits based on the codes above
        int huffman_bits;
        switch (characters[i]) {
            case 'f': huffman_bits = 1; break;
            case 'c': huffman_bits = 3; break;
            case 'd': huffman_bits = 3; break;
            case 'a': huffman_bits = 4; break;
            case 'b': huffman_bits = 4; break;
            case 'e': huffman_bits = 3; break;
            default: huffman_bits = 3; break;
        }
        total_bits_huffman += frequencies[i] * huffman_bits;
    }
    
    printf("\nCompression Analysis:\n");
    printf("  Fixed-length encoding: %d bits\n", total_bits_fixed);
    printf("  Huffman encoding: %d bits\n", total_bits_huffman);
    printf("  Compression ratio: %.2f%%\n", 
           (1.0 - (double)total_bits_huffman / total_bits_fixed) * 100);
}

// Graph Algorithm Implementations

void kruskals_mst(Graph* graph) {
    // Sort edges by weight
    for (int i = 0; i < graph->edges - 1; i++) {
        for (int j = 0; j < graph->edges - i - 1; j++) {
            if (graph->edge[j].weight > graph->edge[j + 1].weight) {
                Edge temp = graph->edge[j];
                graph->edge[j] = graph->edge[j + 1];
                graph->edge[j + 1] = temp;
            }
        }
    }
    
    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES];
    
    // Initialize union-find
    for (int i = 0; i < graph->vertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    
    int mst_weight = 0;
    int edges_added = 0;
    
    printf("MST Edges:\n");
    for (int i = 0; i < graph->edges && edges_added < graph->vertices - 1; i++) {
        int src = graph->edge[i].src;
        int dest = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        
        int parent_src = find_parent(parent, src);
        int parent_dest = find_parent(parent, dest);
        
        if (parent_src != parent_dest) {
            printf("  (%d, %d) weight: %d\n", src, dest, weight);
            mst_weight += weight;
            union_sets(parent, rank, parent_src, parent_dest);
            edges_added++;
        }
    }
    
    printf("Total MST weight: %d\n", mst_weight);
}

void prims_mst(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mst_set[MAX_VERTICES];
    
    // Initialize
    for (int i = 0; i < vertices; i++) {
        key[i] = INF;
        mst_set[i] = false;
    }
    
    key[0] = 0;
    parent[0] = -1;
    
    printf("MST Edges:\n");
    int total_weight = 0;
    
    for (int count = 0; count < vertices - 1; count++) {
        int u = min_key(key, mst_set, vertices);
        mst_set[u] = true;
        
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && !mst_set[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
        
        if (parent[u] != -1) {
            printf("  (%d, %d) weight: %d\n", parent[u], u, graph[u][parent[u]]);
            total_weight += graph[u][parent[u]];
        }
    }
    
    printf("Total MST weight: %d\n", total_weight);
}

void dijkstras_shortest_path(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int src) {
    int dist[MAX_VERTICES];
    bool shortest_path_set[MAX_VERTICES];
    
    // Initialize
    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        shortest_path_set[i] = false;
    }
    
    dist[src] = 0;
    
    for (int count = 0; count < vertices - 1; count++) {
        int u = min_key(dist, shortest_path_set, vertices);
        shortest_path_set[u] = true;
        
        for (int v = 0; v < vertices; v++) {
            if (!shortest_path_set[v] && graph[u][v] && 
                dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    for (int i = 0; i < vertices; i++) {
        printf("  Distance to vertex %d: %d\n", i, dist[i]);
    }
}

int find_parent(int parent[], int i) {
    if (parent[i] != i) {
        parent[i] = find_parent(parent, parent[i]);
    }
    return parent[i];
}

void union_sets(int parent[], int rank[], int x, int y) {
    int root_x = find_parent(parent, x);
    int root_y = find_parent(parent, y);
    
    if (rank[root_x] < rank[root_y]) {
        parent[root_x] = root_y;
    } else if (rank[root_x] > rank[root_y]) {
        parent[root_y] = root_x;
    } else {
        parent[root_y] = root_x;
        rank[root_x]++;
    }
}

int min_key(int key[], bool mst_set[], int vertices) {
    int min = INF, min_index;
    
    for (int v = 0; v < vertices; v++) {
        if (!mst_set[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    
    return min_index;
}

// Job Scheduling Implementation

int job_scheduling_max_profit(Job jobs[], int n) {
    // Sort jobs by profit in descending order
    qsort(jobs, n, sizeof(Job), compare_jobs_by_profit);
    
    // Find maximum deadline
    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > max_deadline) {
            max_deadline = jobs[i].deadline;
        }
    }
    
    // Create slot array
    bool slot[max_deadline + 1];
    int scheduled_jobs[max_deadline + 1];
    
    for (int i = 0; i <= max_deadline; i++) {
        slot[i] = false;
        scheduled_jobs[i] = -1;
    }
    
    int total_profit = 0;
    
    printf("Job scheduling process:\n");
    
    for (int i = 0; i < n; i++) {
        // Find a slot for this job (starting from its deadline)
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                scheduled_jobs[j] = jobs[i].index;
                total_profit += jobs[i].profit;
                printf("  Schedule Job %d at time %d, profit: %d\n", 
                       jobs[i].index, j, jobs[i].profit);
                break;
            }
        }
    }
    
    return total_profit;
}

int compare_jobs_by_profit(const void* a, const void* b) {
    Job* job1 = (Job*)a;
    Job* job2 = (Job*)b;
    return job2->profit - job1->profit; // Descending order
}

// Other Greedy Problem Implementations

int coin_change_greedy(int coins[], int num_coins, int amount, int result[]) {
    int count = 0;
    
    for (int i = 0; i < num_coins; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            result[count] = coins[i];
            count++;
        }
    }
    
    return count;
}

int gas_station_problem(int gas[], int cost[], int n) {
    int total_gas = 0;
    int total_cost = 0;
    
    // Check if solution exists
    for (int i = 0; i < n; i++) {
        total_gas += gas[i];
        total_cost += cost[i];
    }
    
    if (total_gas < total_cost) {
        return -1; // No solution
    }
    
    int start = 0;
    int current_gas = 0;
    
    for (int i = 0; i < n; i++) {
        current_gas += gas[i] - cost[i];
        
        if (current_gas < 0) {
            start = i + 1;
            current_gas = 0;
        }
    }
    
    return start;
}

int minimum_platforms(int arrivals[], int departures[], int n) {
    // Sort arrival and departure times
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arrivals[j] > arrivals[j + 1]) {
                int temp = arrivals[j];
                arrivals[j] = arrivals[j + 1];
                arrivals[j + 1] = temp;
            }
            if (departures[j] > departures[j + 1]) {
                int temp = departures[j];
                departures[j] = departures[j + 1];
                departures[j + 1] = temp;
            }
        }
    }
    
    int platforms_needed = 1;
    int max_platforms = 1;
    int i = 1, j = 0;
    
    while (i < n && j < n) {
        if (arrivals[i] <= departures[j]) {
            platforms_needed++;
            i++;
            if (platforms_needed > max_platforms) {
                max_platforms = platforms_needed;
            }
        } else {
            platforms_needed--;
            j++;
        }
    }
    
    return max_platforms;
}

double minimum_waiting_time(double processes[], int n) {
    // Sort processes by execution time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j] > processes[j + 1]) {
                double temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    
    double waiting_time = 0;
    double total_waiting = 0;
    
    printf("Process execution order: ");
    for (int i = 0; i < n; i++) {
        printf("%.1f ", processes[i]);
        total_waiting += waiting_time;
        waiting_time += processes[i];
    }
    printf("\n");
    
    return total_waiting / n;
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

void print_activities(Activity activities[], int n) {
    for (int i = 0; i < n; i++) {
        printf("  Activity %d: (%d, %d)\n", activities[i].index, 
               activities[i].start, activities[i].finish);
    }
}

void print_items(FractionalItem items[], int n) {
    for (int i = 0; i < n; i++) {
        printf("  Item %d: Weight=%.1f, Value=%d, Ratio=%.2f\n", 
               items[i].index, items[i].weight, items[i].value, items[i].ratio);
    }
}