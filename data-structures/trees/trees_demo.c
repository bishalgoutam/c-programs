/**
 * Trees - Comprehensive C Implementation
 * 
 * This program demonstrates:
 * - Binary tree operations
 * - Binary search tree (BST) operations
 * - AVL tree operations (self-balancing)
 * - Tree traversal algorithms
 * - Tree properties and analysis
 * - Practical applications
 * 
 * @author Bishal Goutam
 * @since C99 Standard
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

// Tree node structures
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct AVLNode {
    int data;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

// Function prototypes - Binary Tree
TreeNode* tree_create_node(int data);
void tree_destroy(TreeNode* root);
void tree_insert_level_order(TreeNode** root, int data);
TreeNode* tree_search(TreeNode* root, int data);
void tree_inorder(TreeNode* root);
void tree_preorder(TreeNode* root);
void tree_postorder(TreeNode* root);
void tree_level_order(TreeNode* root);
int tree_height(TreeNode* root);
int tree_count_nodes(TreeNode* root);
int tree_count_leaves(TreeNode* root);
bool tree_is_complete(TreeNode* root);
bool tree_is_full(TreeNode* root);

// Function prototypes - Binary Search Tree
TreeNode* bst_insert(TreeNode* root, int data);
TreeNode* bst_delete(TreeNode* root, int data);
TreeNode* bst_find_min(TreeNode* root);
TreeNode* bst_find_max(TreeNode* root);
bool bst_is_valid(TreeNode* root);
TreeNode* bst_lca(TreeNode* root, int n1, int n2); // Lowest Common Ancestor

// Function prototypes - AVL Tree
AVLNode* avl_create_node(int data);
void avl_destroy(AVLNode* root);
int avl_height(AVLNode* node);
int avl_balance(AVLNode* node);
AVLNode* avl_rotate_right(AVLNode* y);
AVLNode* avl_rotate_left(AVLNode* x);
AVLNode* avl_insert(AVLNode* root, int data);
AVLNode* avl_delete(AVLNode* root, int data);
void avl_inorder(AVLNode* root);

// Utility functions
void print_tree_structure(TreeNode* root, int space);
void print_avl_structure(AVLNode* root, int space);

// Demo functions
void demonstrate_binary_tree(void);
void demonstrate_binary_search_tree(void);
void demonstrate_avl_tree(void);
void demonstrate_tree_traversals(void);
void demonstrate_tree_properties(void);
void demonstrate_applications(void);

int main(void) {
    printf("=== C Trees Demo ===\n\n");
    
    demonstrate_binary_tree();
    demonstrate_binary_search_tree();
    demonstrate_avl_tree();
    demonstrate_tree_traversals();
    demonstrate_tree_properties();
    demonstrate_applications();
    
    return 0;
}

/**
 * Demonstrates basic binary tree operations
 */
void demonstrate_binary_tree(void) {
    printf("1. Binary Tree Operations\n");
    printf("=========================\n");
    
    // Create a sample binary tree
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    
    TreeNode* root = tree_create_node(1);
    root->left = tree_create_node(2);
    root->right = tree_create_node(3);
    root->left->left = tree_create_node(4);
    root->left->right = tree_create_node(5);
    root->right->right = tree_create_node(6);
    
    printf("Binary tree structure:\n");
    print_tree_structure(root, 0);
    
    printf("\nTree properties:\n");
    printf("  Height: %d\n", tree_height(root));
    printf("  Total nodes: %d\n", tree_count_nodes(root));
    printf("  Leaf nodes: %d\n", tree_count_leaves(root));
    printf("  Is complete: %s\n", tree_is_complete(root) ? "Yes" : "No");
    printf("  Is full: %s\n", tree_is_full(root) ? "Yes" : "No");
    
    printf("\nSearching for elements:\n");
    TreeNode* found = tree_search(root, 5);
    printf("  Search for 5: %s\n", found ? "Found" : "Not found");
    
    found = tree_search(root, 7);
    printf("  Search for 7: %s\n", found ? "Found" : "Not found");
    
    tree_destroy(root);
    printf("  Tree destroyed\n\n");
}

/**
 * Demonstrates binary search tree operations
 */
void demonstrate_binary_search_tree(void) {
    printf("2. Binary Search Tree (BST)\n");
    printf("===========================\n");
    
    TreeNode* bst = NULL;
    
    printf("Inserting elements: 50, 30, 70, 20, 40, 60, 80\n");
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < n; i++) {
        bst = bst_insert(bst, values[i]);
    }
    
    printf("\nBST structure:\n");
    print_tree_structure(bst, 0);
    
    printf("\nInorder traversal (should be sorted): ");
    tree_inorder(bst);
    printf("\n");
    
    printf("\nBST properties:\n");
    printf("  Is valid BST: %s\n", bst_is_valid(bst) ? "Yes" : "No");
    printf("  Minimum value: %d\n", bst_find_min(bst)->data);
    printf("  Maximum value: %d\n", bst_find_max(bst)->data);
    
    printf("\nSearching elements:\n");
    TreeNode* found = tree_search(bst, 40);
    printf("  Search for 40: %s\n", found ? "Found" : "Not found");
    
    found = tree_search(bst, 45);
    printf("  Search for 45: %s\n", found ? "Found" : "Not found");
    
    printf("\nLowest Common Ancestor:\n");
    TreeNode* lca = bst_lca(bst, 20, 40);
    printf("  LCA of 20 and 40: %d\n", lca ? lca->data : -1);
    
    lca = bst_lca(bst, 60, 80);
    printf("  LCA of 60 and 80: %d\n", lca ? lca->data : -1);
    
    printf("\nDeleting elements:\n");
    printf("  Deleting 20 (leaf node)\n");
    bst = bst_delete(bst, 20);
    printf("  Inorder after deletion: ");
    tree_inorder(bst);
    printf("\n");
    
    printf("  Deleting 30 (node with two children)\n");
    bst = bst_delete(bst, 30);
    printf("  Inorder after deletion: ");
    tree_inorder(bst);
    printf("\n");
    
    tree_destroy(bst);
    printf("  BST destroyed\n\n");
}

/**
 * Demonstrates AVL tree operations
 */
void demonstrate_avl_tree(void) {
    printf("3. AVL Tree (Self-Balancing)\n");
    printf("============================\n");
    
    AVLNode* avl = NULL;
    
    printf("Inserting elements: 10, 20, 30, 40, 50, 25\n");
    printf("(This would create an unbalanced BST, but AVL maintains balance)\n");
    
    int values[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < n; i++) {
        printf("\nInserting %d:\n", values[i]);
        avl = avl_insert(avl, values[i]);
        printf("  AVL structure after insertion:\n");
        print_avl_structure(avl, 0);
    }
    
    printf("\nFinal AVL tree structure:\n");
    print_avl_structure(avl, 0);
    
    printf("\nInorder traversal: ");
    avl_inorder(avl);
    printf("\n");
    
    printf("\nAVL properties:\n");
    printf("  Height: %d\n", avl_height(avl));
    printf("  Root balance factor: %d\n", avl_balance(avl));
    
    printf("\nDeleting elements: 40, 25\n");
    avl = avl_delete(avl, 40);
    printf("After deleting 40:\n");
    print_avl_structure(avl, 0);
    
    avl = avl_delete(avl, 25);
    printf("After deleting 25:\n");
    print_avl_structure(avl, 0);
    
    avl_destroy(avl);
    printf("  AVL tree destroyed\n\n");
}

/**
 * Demonstrates different tree traversal methods
 */
void demonstrate_tree_traversals(void) {
    printf("4. Tree Traversal Methods\n");
    printf("=========================\n");
    
    // Create a sample tree
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    //  /
    // 7
    
    TreeNode* root = tree_create_node(1);
    root->left = tree_create_node(2);
    root->right = tree_create_node(3);
    root->left->left = tree_create_node(4);
    root->left->right = tree_create_node(5);
    root->right->right = tree_create_node(6);
    root->left->left->left = tree_create_node(7);
    
    printf("Tree structure:\n");
    print_tree_structure(root, 0);
    
    printf("\nTraversal methods:\n");
    
    printf("  Inorder (Left, Root, Right): ");
    tree_inorder(root);
    printf("\n");
    
    printf("  Preorder (Root, Left, Right): ");
    tree_preorder(root);
    printf("\n");
    
    printf("  Postorder (Left, Right, Root): ");
    tree_postorder(root);
    printf("\n");
    
    printf("  Level-order (Breadth-first): ");
    tree_level_order(root);
    printf("\n");
    
    printf("\nTraversal applications:\n");
    printf("  Inorder: Gets sorted sequence in BST\n");
    printf("  Preorder: Used for tree copying, expression parsing\n");
    printf("  Postorder: Used for tree deletion, expression evaluation\n");
    printf("  Level-order: Used for tree printing, finding level of node\n");
    
    tree_destroy(root);
    printf("\n");
}

/**
 * Demonstrates tree properties and analysis
 */
void demonstrate_tree_properties(void) {
    printf("5. Tree Properties and Analysis\n");
    printf("===============================\n");
    
    // Create different types of trees for comparison
    
    // Complete binary tree
    TreeNode* complete = tree_create_node(1);
    complete->left = tree_create_node(2);
    complete->right = tree_create_node(3);
    complete->left->left = tree_create_node(4);
    complete->left->right = tree_create_node(5);
    complete->right->left = tree_create_node(6);
    
    printf("Complete binary tree:\n");
    print_tree_structure(complete, 0);
    printf("  Is complete: %s\n", tree_is_complete(complete) ? "Yes" : "No");
    printf("  Is full: %s\n", tree_is_full(complete) ? "Yes" : "No");
    printf("  Height: %d\n", tree_height(complete));
    
    // Full binary tree (but not complete)
    TreeNode* full = tree_create_node(1);
    full->left = tree_create_node(2);
    full->right = tree_create_node(3);
    full->left->left = tree_create_node(4);
    full->left->right = tree_create_node(5);
    full->right->left = tree_create_node(6);
    full->right->right = tree_create_node(7);
    
    printf("\nFull binary tree:\n");
    print_tree_structure(full, 0);
    printf("  Is complete: %s\n", tree_is_complete(full) ? "Yes" : "No");
    printf("  Is full: %s\n", tree_is_full(full) ? "Yes" : "No");
    printf("  Height: %d\n", tree_height(full));
    
    // Skewed tree (worst case)
    TreeNode* skewed = tree_create_node(1);
    skewed->right = tree_create_node(2);
    skewed->right->right = tree_create_node(3);
    skewed->right->right->right = tree_create_node(4);
    
    printf("\nSkewed tree (worst case):\n");
    print_tree_structure(skewed, 0);
    printf("  Is complete: %s\n", tree_is_complete(skewed) ? "Yes" : "No");
    printf("  Is full: %s\n", tree_is_full(skewed) ? "Yes" : "No");
    printf("  Height: %d\n", tree_height(skewed));
    
    printf("\nComplexity analysis:\n");
    printf("  Balanced tree operations: O(log n)\n");
    printf("  Skewed tree operations: O(n)\n");
    printf("  Complete tree space efficiency: Excellent\n");
    printf("  Full tree guarantees: Every node has 0 or 2 children\n");
    
    tree_destroy(complete);
    tree_destroy(full);
    tree_destroy(skewed);
    printf("\n");
}

/**
 * Demonstrates practical applications of trees
 */
void demonstrate_applications(void) {
    printf("6. Practical Applications\n");
    printf("=========================\n");
    
    printf("Binary Search Tree applications:\n");
    printf("  • Database indexing\n");
    printf("  • File system organization\n");
    printf("  • Expression parsing\n");
    printf("  • Symbol tables in compilers\n");
    printf("  • Priority queues\n");
    
    printf("\nAVL Tree applications:\n");
    printf("  • Database systems requiring guaranteed O(log n) operations\n");
    printf("  • Memory management systems\n");
    printf("  • Real-time systems with strict time requirements\n");
    
    printf("\nGeneral Tree applications:\n");
    printf("  • Hierarchical data representation\n");
    printf("  • Decision trees in AI/ML\n");
    printf("  • Syntax trees in compilers\n");
    printf("  • Organization charts\n");
    printf("  • Game trees in AI\n");
    
    printf("\nSpecial tree types:\n");
    printf("  • Heap: Priority queue implementation\n");
    printf("  • Trie: String searching and autocomplete\n");
    printf("  • B-tree: Database and file system indexing\n");
    printf("  • Red-Black tree: Standard library implementations\n");
    printf("  • Segment tree: Range query problems\n");
    
    printf("\nTree traversal applications:\n");
    printf("  • File system navigation\n");
    printf("  • HTML/XML parsing\n");
    printf("  • Compiler syntax analysis\n");
    printf("  • Game AI pathfinding\n");
    
    printf("\n");
}

// Binary Tree implementation

TreeNode* tree_create_node(int data) {
    TreeNode* node = malloc(sizeof(TreeNode));
    if (node) {
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void tree_destroy(TreeNode* root) {
    if (root) {
        tree_destroy(root->left);
        tree_destroy(root->right);
        free(root);
    }
}

TreeNode* tree_search(TreeNode* root, int data) {
    if (!root || root->data == data) {
        return root;
    }
    
    TreeNode* left_result = tree_search(root->left, data);
    if (left_result) return left_result;
    
    return tree_search(root->right, data);
}

void tree_inorder(TreeNode* root) {
    if (root) {
        tree_inorder(root->left);
        printf("%d ", root->data);
        tree_inorder(root->right);
    }
}

void tree_preorder(TreeNode* root) {
    if (root) {
        printf("%d ", root->data);
        tree_preorder(root->left);
        tree_preorder(root->right);
    }
}

void tree_postorder(TreeNode* root) {
    if (root) {
        tree_postorder(root->left);
        tree_postorder(root->right);
        printf("%d ", root->data);
    }
}

void tree_level_order(TreeNode* root) {
    if (!root) return;
    
    // Simple queue implementation for level order
    TreeNode* queue[1000];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        TreeNode* current = queue[front++];
        printf("%d ", current->data);
        
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
}

int tree_height(TreeNode* root) {
    if (!root) return -1;
    
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);
    
    return 1 + (left_height > right_height ? left_height : right_height);
}

int tree_count_nodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + tree_count_nodes(root->left) + tree_count_nodes(root->right);
}

int tree_count_leaves(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return tree_count_leaves(root->left) + tree_count_leaves(root->right);
}

bool tree_is_complete(TreeNode* root) {
    if (!root) return true;
    
    TreeNode* queue[1000];
    int front = 0, rear = 0;
    bool flag = false;
    
    queue[rear++] = root;
    
    while (front < rear) {
        TreeNode* current = queue[front++];
        
        if (current->left) {
            if (flag) return false;
            queue[rear++] = current->left;
        } else {
            flag = true;
        }
        
        if (current->right) {
            if (flag) return false;
            queue[rear++] = current->right;
        } else {
            flag = true;
        }
    }
    
    return true;
}

bool tree_is_full(TreeNode* root) {
    if (!root) return true;
    
    if (!root->left && !root->right) return true;
    
    if (root->left && root->right) {
        return tree_is_full(root->left) && tree_is_full(root->right);
    }
    
    return false;
}

// Binary Search Tree implementation

TreeNode* bst_insert(TreeNode* root, int data) {
    if (!root) {
        return tree_create_node(data);
    }
    
    if (data < root->data) {
        root->left = bst_insert(root->left, data);
    } else if (data > root->data) {
        root->right = bst_insert(root->right, data);
    }
    
    return root;
}

TreeNode* bst_delete(TreeNode* root, int data) {
    if (!root) return root;
    
    if (data < root->data) {
        root->left = bst_delete(root->left, data);
    } else if (data > root->data) {
        root->right = bst_delete(root->right, data);
    } else {
        // Node to be deleted found
        if (!root->left) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children
        TreeNode* temp = bst_find_min(root->right);
        root->data = temp->data;
        root->right = bst_delete(root->right, temp->data);
    }
    
    return root;
}

TreeNode* bst_find_min(TreeNode* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

TreeNode* bst_find_max(TreeNode* root) {
    while (root && root->right) {
        root = root->right;
    }
    return root;
}

bool bst_is_valid_helper(TreeNode* root, int min_val, int max_val) {
    if (!root) return true;
    
    if (root->data <= min_val || root->data >= max_val) {
        return false;
    }
    
    return bst_is_valid_helper(root->left, min_val, root->data) &&
           bst_is_valid_helper(root->right, root->data, max_val);
}

bool bst_is_valid(TreeNode* root) {
    return bst_is_valid_helper(root, INT_MIN, INT_MAX);
}

TreeNode* bst_lca(TreeNode* root, int n1, int n2) {
    if (!root) return NULL;
    
    if (root->data > n1 && root->data > n2) {
        return bst_lca(root->left, n1, n2);
    }
    
    if (root->data < n1 && root->data < n2) {
        return bst_lca(root->right, n1, n2);
    }
    
    return root;
}

// AVL Tree implementation

AVLNode* avl_create_node(int data) {
    AVLNode* node = malloc(sizeof(AVLNode));
    if (node) {
        node->data = data;
        node->height = 1;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void avl_destroy(AVLNode* root) {
    if (root) {
        avl_destroy(root->left);
        avl_destroy(root->right);
        free(root);
    }
}

int avl_height(AVLNode* node) {
    return node ? node->height : 0;
}

int avl_balance(AVLNode* node) {
    return node ? avl_height(node->left) - avl_height(node->right) : 0;
}

AVLNode* avl_rotate_right(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = 1 + (avl_height(y->left) > avl_height(y->right) ? 
                     avl_height(y->left) : avl_height(y->right));
    x->height = 1 + (avl_height(x->left) > avl_height(x->right) ? 
                     avl_height(x->left) : avl_height(x->right));
    
    return x;
}

AVLNode* avl_rotate_left(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = 1 + (avl_height(x->left) > avl_height(x->right) ? 
                     avl_height(x->left) : avl_height(x->right));
    y->height = 1 + (avl_height(y->left) > avl_height(y->right) ? 
                     avl_height(y->left) : avl_height(y->right));
    
    return y;
}

AVLNode* avl_insert(AVLNode* root, int data) {
    // Step 1: Perform normal BST insertion
    if (!root) {
        return avl_create_node(data);
    }
    
    if (data < root->data) {
        root->left = avl_insert(root->left, data);
    } else if (data > root->data) {
        root->right = avl_insert(root->right, data);
    } else {
        return root; // Duplicate keys not allowed
    }
    
    // Step 2: Update height
    root->height = 1 + (avl_height(root->left) > avl_height(root->right) ? 
                        avl_height(root->left) : avl_height(root->right));
    
    // Step 3: Get balance factor
    int balance = avl_balance(root);
    
    // Step 4: Perform rotations if needed
    // Left Left Case
    if (balance > 1 && data < root->left->data) {
        return avl_rotate_right(root);
    }
    
    // Right Right Case
    if (balance < -1 && data > root->right->data) {
        return avl_rotate_left(root);
    }
    
    // Left Right Case
    if (balance > 1 && data > root->left->data) {
        root->left = avl_rotate_left(root->left);
        return avl_rotate_right(root);
    }
    
    // Right Left Case
    if (balance < -1 && data < root->right->data) {
        root->right = avl_rotate_right(root->right);
        return avl_rotate_left(root);
    }
    
    return root;
}

AVLNode* avl_delete(AVLNode* root, int data) {
    // Step 1: Perform standard BST delete
    if (!root) return root;
    
    if (data < root->data) {
        root->left = avl_delete(root->left, data);
    } else if (data > root->data) {
        root->right = avl_delete(root->right, data);
    } else {
        if (!root->left || !root->right) {
            AVLNode* temp = root->left ? root->left : root->right;
            
            if (!temp) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            AVLNode* temp = root->right;
            while (temp->left) temp = temp->left;
            
            root->data = temp->data;
            root->right = avl_delete(root->right, temp->data);
        }
    }
    
    if (!root) return root;
    
    // Step 2: Update height
    root->height = 1 + (avl_height(root->left) > avl_height(root->right) ? 
                        avl_height(root->left) : avl_height(root->right));
    
    // Step 3: Get balance factor
    int balance = avl_balance(root);
    
    // Step 4: Perform rotations if needed
    if (balance > 1 && avl_balance(root->left) >= 0) {
        return avl_rotate_right(root);
    }
    
    if (balance > 1 && avl_balance(root->left) < 0) {
        root->left = avl_rotate_left(root->left);
        return avl_rotate_right(root);
    }
    
    if (balance < -1 && avl_balance(root->right) <= 0) {
        return avl_rotate_left(root);
    }
    
    if (balance < -1 && avl_balance(root->right) > 0) {
        root->right = avl_rotate_right(root->right);
        return avl_rotate_left(root);
    }
    
    return root;
}

void avl_inorder(AVLNode* root) {
    if (root) {
        avl_inorder(root->left);
        printf("%d ", root->data);
        avl_inorder(root->right);
    }
}

// Utility functions for tree visualization

void print_tree_structure(TreeNode* root, int space) {
    const int COUNT = 10;
    if (!root) return;
    
    space += COUNT;
    
    print_tree_structure(root->right, space);
    
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    
    print_tree_structure(root->left, space);
}

void print_avl_structure(AVLNode* root, int space) {
    const int COUNT = 10;
    if (!root) return;
    
    space += COUNT;
    
    print_avl_structure(root->right, space);
    
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d(h:%d,b:%d)\n", root->data, root->height, avl_balance(root));
    
    print_avl_structure(root->left, space);
}