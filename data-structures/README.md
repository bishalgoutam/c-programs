# Data Structures in C

This section implements fundamental data structures from scratch in C, providing deep understanding of how data is organized and manipulated efficiently in memory.

## 📚 Data Structures Covered

### 1. Linked Lists
- **Singly Linked List**: Basic insertion, deletion, traversal
- **Doubly Linked List**: Bidirectional navigation
- **Circular Linked List**: Ring buffer implementations
- **Memory Management**: Proper allocation and deallocation
- **Applications**: Dynamic arrays, undo functionality

### 2. Stacks & Queues
- **Stack (LIFO)**: Array and linked list implementations
- **Queue (FIFO)**: Circular buffer and linked implementations
- **Priority Queue**: Heap-based priority management
- **Deque**: Double-ended queue operations
- **Applications**: Expression evaluation, BFS/DFS, job scheduling

### 3. Trees
- **Binary Tree**: Basic tree operations
- **Binary Search Tree (BST)**: Search, insert, delete
- **AVL Tree**: Self-balancing binary search tree
- **Tree Traversals**: Inorder, preorder, postorder
- **Applications**: File systems, expression trees, decision trees

### 4. Graphs
- **Graph Representation**: Adjacency matrix and list
- **Graph Traversal**: BFS (Breadth-First Search), DFS (Depth-First Search)
- **Shortest Path**: Dijkstra's algorithm, Floyd-Warshall
- **Minimum Spanning Tree**: Kruskal's and Prim's algorithms
- **Applications**: Network routing, social networks, dependency resolution

### 5. Hash Tables
- **Hash Functions**: Division, multiplication, universal hashing
- **Collision Handling**: Chaining, open addressing
- **Dynamic Resizing**: Load factor management
- **Performance Analysis**: Time and space complexity
- **Applications**: Caches, symbol tables, databases

## 🎯 Learning Objectives

By completing this section, you will:

1. **Understand time and space complexity** of different data structures
2. **Implement efficient algorithms** for data manipulation
3. **Choose appropriate data structures** for specific problems
4. **Manage memory effectively** in complex data structures
5. **Analyze and optimize** data structure performance
6. **Design custom data structures** for specialized needs

## 📊 Complexity Analysis

### Time Complexity Comparison

| Operation | Array | Linked List | BST (Avg) | Hash Table (Avg) |
|-----------|-------|-------------|-----------|------------------|
| Access    | O(1)  | O(n)        | O(log n)  | O(1)             |
| Search    | O(n)  | O(n)        | O(log n)  | O(1)             |
| Insert    | O(n)  | O(1)        | O(log n)  | O(1)             |
| Delete    | O(n)  | O(1)        | O(log n)  | O(1)             |

### Space Complexity
- **Arrays**: O(n) - contiguous memory
- **Linked Lists**: O(n) - with pointer overhead
- **Trees**: O(n) - recursive structure overhead
- **Hash Tables**: O(n) - with load factor considerations

## 🛠️ Implementation Patterns

### Generic Data Structure Design
```c
// Generic node structure
typedef struct node {
    void* data;
    struct node* next;
} node_t;

// Generic list operations
typedef struct {
    node_t* head;
    node_t* tail;
    size_t count;
    size_t data_size;
    int (*compare)(const void* a, const void* b);
    void (*destroy)(void* data);
} list_t;

// Generic operations
list_t* list_create(size_t data_size, 
                   int (*compare)(const void*, const void*),
                   void (*destroy)(void*));
int list_insert(list_t* list, const void* data);
int list_remove(list_t* list, const void* data);
void* list_find(list_t* list, const void* data);
void list_destroy(list_t* list);
```

### Memory Management Best Practices
```c
// Safe memory allocation with error checking
void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Node creation with initialization
node_t* create_node(const void* data, size_t data_size) {
    node_t* node = safe_malloc(sizeof(node_t));
    node->data = safe_malloc(data_size);
    memcpy(node->data, data, data_size);
    node->next = NULL;
    return node;
}

// Proper cleanup
void destroy_node(node_t* node, void (*destroy_data)(void*)) {
    if (node) {
        if (destroy_data && node->data) {
            destroy_data(node->data);
        }
        free(node->data);
        free(node);
    }
}
```

## 🔍 Algorithm Implementation Examples

### Binary Search Tree Operations
```c
typedef struct bst_node {
    int data;
    struct bst_node* left;
    struct bst_node* right;
} bst_node_t;

// Insertion with recursion
bst_node_t* bst_insert(bst_node_t* root, int data) {
    if (root == NULL) {
        bst_node_t* new_node = safe_malloc(sizeof(bst_node_t));
        new_node->data = data;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    
    if (data < root->data) {
        root->left = bst_insert(root->left, data);
    } else if (data > root->data) {
        root->right = bst_insert(root->right, data);
    }
    
    return root;
}

// Search operation
bst_node_t* bst_search(bst_node_t* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    
    if (data < root->data) {
        return bst_search(root->left, data);
    }
    
    return bst_search(root->right, data);
}
```

### Hash Table Implementation
```c
#define HASH_TABLE_SIZE 101

typedef struct hash_entry {
    char* key;
    void* value;
    struct hash_entry* next;
} hash_entry_t;

typedef struct {
    hash_entry_t* buckets[HASH_TABLE_SIZE];
    size_t count;
} hash_table_t;

// Simple hash function
unsigned int hash(const char* key) {
    unsigned int hash_value = 0;
    while (*key) {
        hash_value = (hash_value * 31) + *key++;
    }
    return hash_value % HASH_TABLE_SIZE;
}

// Insert operation with collision handling
int hash_table_insert(hash_table_t* table, const char* key, void* value) {
    unsigned int index = hash(key);
    hash_entry_t* entry = table->buckets[index];
    
    // Check for existing key
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value;  // Update existing
            return 1;
        }
        entry = entry->next;
    }
    
    // Create new entry
    hash_entry_t* new_entry = safe_malloc(sizeof(hash_entry_t));
    new_entry->key = strdup(key);
    new_entry->value = value;
    new_entry->next = table->buckets[index];
    table->buckets[index] = new_entry;
    table->count++;
    
    return 1;
}
```

## 🧪 Testing and Validation

### Unit Testing Framework
```c
// Simple testing macros
#define TEST_ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            printf("FAIL: %s\n", message); \
            return 0; \
        } \
    } while(0)

#define TEST_PASS(message) \
    printf("PASS: %s\n", message)

// Example test function
int test_linked_list() {
    list_t* list = list_create(sizeof(int), compare_int, NULL);
    
    int value = 42;
    list_insert(list, &value);
    TEST_ASSERT(list->count == 1, "List should have 1 element");
    
    int* found = list_find(list, &value);
    TEST_ASSERT(found != NULL && *found == 42, "Should find inserted value");
    
    list_destroy(list);
    TEST_PASS("Linked list basic operations");
    return 1;
}
```

### Performance Benchmarking
```c
#include <time.h>

void benchmark_data_structure() {
    clock_t start, end;
    const int iterations = 100000;
    
    start = clock();
    // Perform operations
    for (int i = 0; i < iterations; i++) {
        // Data structure operations
    }
    end = clock();
    
    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time);
    printf("Operations per second: %f\n", iterations / cpu_time);
}
```

## 📖 Study Path

### Week 1-2: Linear Data Structures
- Implement and test linked lists
- Build stack and queue implementations
- Compare array vs linked implementations

### Week 3-4: Tree Structures
- Binary tree implementation and traversals
- Binary search tree with full operations
- Introduction to balanced trees

### Week 5-6: Advanced Structures
- Hash table with collision handling
- Graph representations and algorithms
- Performance analysis and optimization

### Week 7-8: Integration and Projects
- Combine multiple data structures
- Build real-world applications
- Optimize for specific use cases

## 🎯 Real-World Applications

- **Database Indexing**: B-trees and hash indexes
- **Caching Systems**: LRU cache with hash table + doubly linked list
- **Compiler Design**: Symbol tables, parse trees
- **Network Protocols**: Routing tables, packet queues
- **Operating Systems**: Process scheduling, file systems

---

**Remember**: Understanding the trade-offs between different data structures is key to choosing the right tool for each problem!