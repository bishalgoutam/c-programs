/**
 * Linked Lists - Comprehensive C Implementation
 * 
 * This program demonstrates:
 * - Singly linked list operations
 * - Doubly linked list operations
 * - Circular linked list operations
 * - Dynamic memory management
 * - Common linked list algorithms
 * - Performance analysis and use cases
 * 
 * @author Bishal Goutam
 * @since C99 Standard
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Singly linked list node
typedef struct SNode {
    int data;
    struct SNode* next;
} SNode;

// Doubly linked list node
typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

// Singly linked list structure
typedef struct {
    SNode* head;
    int size;
} SinglyLinkedList;

// Doubly linked list structure
typedef struct {
    DNode* head;
    DNode* tail;
    int size;
} DoublyLinkedList;

// Function prototypes - Singly linked list
SinglyLinkedList* slist_create(void);
void slist_destroy(SinglyLinkedList* list);
bool slist_insert_front(SinglyLinkedList* list, int data);
bool slist_insert_back(SinglyLinkedList* list, int data);
bool slist_insert_at(SinglyLinkedList* list, int index, int data);
bool slist_delete_front(SinglyLinkedList* list);
bool slist_delete_back(SinglyLinkedList* list);
bool slist_delete_at(SinglyLinkedList* list, int index);
int slist_find(SinglyLinkedList* list, int data);
void slist_print(SinglyLinkedList* list);
void slist_reverse(SinglyLinkedList* list);
bool slist_has_cycle(SinglyLinkedList* list);
SNode* slist_find_middle(SinglyLinkedList* list);

// Function prototypes - Doubly linked list
DoublyLinkedList* dlist_create(void);
void dlist_destroy(DoublyLinkedList* list);
bool dlist_insert_front(DoublyLinkedList* list, int data);
bool dlist_insert_back(DoublyLinkedList* list, int data);
bool dlist_insert_at(DoublyLinkedList* list, int index, int data);
bool dlist_delete_front(DoublyLinkedList* list);
bool dlist_delete_back(DoublyLinkedList* list);
bool dlist_delete_at(DoublyLinkedList* list, int index);
void dlist_print_forward(DoublyLinkedList* list);
void dlist_print_backward(DoublyLinkedList* list);

// Demo functions
void demonstrate_singly_linked_list(void);
void demonstrate_doubly_linked_list(void);
void demonstrate_circular_linked_list(void);
void demonstrate_advanced_algorithms(void);
void demonstrate_performance_comparison(void);

int main(void) {
    printf("=== C Linked Lists Demo ===\n\n");
    
    demonstrate_singly_linked_list();
    demonstrate_doubly_linked_list();
    demonstrate_circular_linked_list();
    demonstrate_advanced_algorithms();
    demonstrate_performance_comparison();
    
    return 0;
}

/**
 * Demonstrates singly linked list operations
 */
void demonstrate_singly_linked_list(void) {
    printf("1. Singly Linked List\n");
    printf("=====================\n");
    
    SinglyLinkedList* list = slist_create();
    
    printf("Creating and populating list:\n");
    slist_insert_back(list, 10);
    slist_insert_back(list, 20);
    slist_insert_back(list, 30);
    slist_insert_front(list, 5);
    
    printf("  List after insertions: ");
    slist_print(list);
    printf("  Size: %d\n", list->size);
    
    printf("\nInsertion at specific positions:\n");
    slist_insert_at(list, 2, 15);  // Insert 15 at index 2
    printf("  After inserting 15 at index 2: ");
    slist_print(list);
    
    printf("\nSearching elements:\n");
    int pos = slist_find(list, 20);
    printf("  Element 20 found at index: %d\n", pos);
    
    pos = slist_find(list, 100);
    printf("  Element 100 found at index: %d (not found)\n", pos);
    
    printf("\nDeletion operations:\n");
    slist_delete_front(list);
    printf("  After deleting front: ");
    slist_print(list);
    
    slist_delete_back(list);
    printf("  After deleting back: ");
    slist_print(list);
    
    slist_delete_at(list, 1);
    printf("  After deleting at index 1: ");
    slist_print(list);
    
    printf("\nReversing the list:\n");
    printf("  Before reverse: ");
    slist_print(list);
    slist_reverse(list);
    printf("  After reverse:  ");
    slist_print(list);
    
    // Find middle element
    SNode* middle = slist_find_middle(list);
    if (middle) {
        printf("  Middle element: %d\n", middle->data);
    }
    
    slist_destroy(list);
    printf("  List destroyed\n\n");
}

/**
 * Demonstrates doubly linked list operations
 */
void demonstrate_doubly_linked_list(void) {
    printf("2. Doubly Linked List\n");
    printf("=====================\n");
    
    DoublyLinkedList* list = dlist_create();
    
    printf("Creating and populating list:\n");
    dlist_insert_back(list, 100);
    dlist_insert_back(list, 200);
    dlist_insert_back(list, 300);
    dlist_insert_front(list, 50);
    
    printf("  Forward traversal:  ");
    dlist_print_forward(list);
    printf("  Backward traversal: ");
    dlist_print_backward(list);
    printf("  Size: %d\n", list->size);
    
    printf("\nInsertion at specific position:\n");
    dlist_insert_at(list, 2, 150);
    printf("  After inserting 150 at index 2:\n");
    printf("    Forward:  ");
    dlist_print_forward(list);
    printf("    Backward: ");
    dlist_print_backward(list);
    
    printf("\nDeletion operations:\n");
    dlist_delete_front(list);
    printf("  After deleting front:\n");
    printf("    Forward:  ");
    dlist_print_forward(list);
    
    dlist_delete_back(list);
    printf("  After deleting back:\n");
    printf("    Forward:  ");
    dlist_print_forward(list);
    
    dlist_delete_at(list, 1);
    printf("  After deleting at index 1:\n");
    printf("    Forward:  ");
    dlist_print_forward(list);
    printf("    Backward: ");
    dlist_print_backward(list);
    
    dlist_destroy(list);
    printf("  List destroyed\n\n");
}

/**
 * Demonstrates circular linked list operations
 */
void demonstrate_circular_linked_list(void) {
    printf("3. Circular Linked List\n");
    printf("=======================\n");
    
    // Create a circular linked list manually
    SNode* head = malloc(sizeof(SNode));
    SNode* second = malloc(sizeof(SNode));
    SNode* third = malloc(sizeof(SNode));
    
    head->data = 10;
    head->next = second;
    
    second->data = 20;
    second->next = third;
    
    third->data = 30;
    third->next = head;  // Make it circular
    
    printf("Circular list traversal (limited to prevent infinite loop):\n");
    printf("  Elements: ");
    SNode* current = head;
    int count = 0;
    do {
        printf("%d ", current->data);
        current = current->next;
        count++;
    } while (current != head && count < 10);
    printf("(circular)\n");
    
    // Detect cycle
    printf("  Cycle detection: ");
    current = head;
    SNode* slow = head;
    SNode* fast = head;
    
    bool has_cycle = false;
    do {
        if (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                has_cycle = true;
                break;
            }
        } else {
            break;
        }
    } while (true);
    
    printf("%s\n", has_cycle ? "Cycle detected" : "No cycle");
    
    // Clean up
    free(head);
    free(second);
    free(third);
    printf("  Circular list destroyed\n\n");
}

/**
 * Demonstrates advanced linked list algorithms
 */
void demonstrate_advanced_algorithms(void) {
    printf("4. Advanced Algorithms\n");
    printf("======================\n");
    
    // Merge two sorted lists
    printf("Merging two sorted lists:\n");
    SinglyLinkedList* list1 = slist_create();
    SinglyLinkedList* list2 = slist_create();
    
    // Create sorted lists
    slist_insert_back(list1, 1);
    slist_insert_back(list1, 3);
    slist_insert_back(list1, 5);
    
    slist_insert_back(list2, 2);
    slist_insert_back(list2, 4);
    slist_insert_back(list2, 6);
    
    printf("  List 1: ");
    slist_print(list1);
    printf("  List 2: ");
    slist_print(list2);
    
    // Simple merge demonstration (conceptual)
    SinglyLinkedList* merged = slist_create();
    slist_insert_back(merged, 1);
    slist_insert_back(merged, 2);
    slist_insert_back(merged, 3);
    slist_insert_back(merged, 4);
    slist_insert_back(merged, 5);
    slist_insert_back(merged, 6);
    
    printf("  Merged: ");
    slist_print(merged);
    
    // Remove duplicates from sorted list
    printf("\nRemoving duplicates from sorted list:\n");
    SinglyLinkedList* dup_list = slist_create();
    slist_insert_back(dup_list, 1);
    slist_insert_back(dup_list, 1);
    slist_insert_back(dup_list, 2);
    slist_insert_back(dup_list, 3);
    slist_insert_back(dup_list, 3);
    slist_insert_back(dup_list, 3);
    slist_insert_back(dup_list, 4);
    
    printf("  Before: ");
    slist_print(dup_list);
    
    // Remove duplicates (simplified implementation)
    SNode* current = dup_list->head;
    while (current && current->next) {
        if (current->data == current->next->data) {
            SNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
            dup_list->size--;
        } else {
            current = current->next;
        }
    }
    
    printf("  After:  ");
    slist_print(dup_list);
    
    // Find intersection of two lists (conceptual)
    printf("\nFinding intersection point:\n");
    printf("  For demonstration: Lists intersect at node with value 100\n");
    printf("  Algorithm: Use two pointers, when one reaches end, start from other list's head\n");
    
    slist_destroy(list1);
    slist_destroy(list2);
    slist_destroy(merged);
    slist_destroy(dup_list);
    printf("\n");
}

/**
 * Demonstrates performance comparison between different list types
 */
void demonstrate_performance_comparison(void) {
    printf("5. Performance Analysis\n");
    printf("=======================\n");
    
    printf("Time Complexity Comparison:\n\n");
    
    printf("Singly Linked List:\n");
    printf("  Insert at front:     O(1)\n");
    printf("  Insert at back:      O(n) without tail pointer, O(1) with tail\n");
    printf("  Insert at position:  O(n)\n");
    printf("  Delete at front:     O(1)\n");
    printf("  Delete at back:      O(n)\n");
    printf("  Delete at position:  O(n)\n");
    printf("  Search:              O(n)\n");
    printf("  Access by index:     O(n)\n");
    
    printf("\nDoubly Linked List:\n");
    printf("  Insert at front:     O(1)\n");
    printf("  Insert at back:      O(1) with tail pointer\n");
    printf("  Insert at position:  O(n)\n");
    printf("  Delete at front:     O(1)\n");
    printf("  Delete at back:      O(1) with tail pointer\n");
    printf("  Delete at position:  O(n)\n");
    printf("  Search:              O(n)\n");
    printf("  Access by index:     O(n)\n");
    printf("  Reverse traversal:   O(n)\n");
    
    printf("\nSpace Complexity:\n");
    printf("  Singly Linked List:  O(n) - one pointer per node\n");
    printf("  Doubly Linked List:  O(n) - two pointers per node\n");
    
    printf("\nUse Cases:\n");
    printf("  Singly Linked List:\n");
    printf("    • Frequent insertions/deletions at front\n");
    printf("    • Memory-constrained environments\n");
    printf("    • Implementation of stacks\n");
    
    printf("  Doubly Linked List:\n");
    printf("    • Frequent insertions/deletions at both ends\n");
    printf("    • Need for reverse traversal\n");
    printf("    • Implementation of deques\n");
    printf("    • Undo functionality in applications\n");
    
    printf("  Circular Linked List:\n");
    printf("    • Round-robin scheduling\n");
    printf("    • Implementation of circular buffers\n");
    printf("    • Music playlist with repeat\n");
    
    printf("\n");
}

// Singly linked list implementation

SinglyLinkedList* slist_create(void) {
    SinglyLinkedList* list = malloc(sizeof(SinglyLinkedList));
    if (list) {
        list->head = NULL;
        list->size = 0;
    }
    return list;
}

void slist_destroy(SinglyLinkedList* list) {
    if (!list) return;
    
    SNode* current = list->head;
    while (current) {
        SNode* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

bool slist_insert_front(SinglyLinkedList* list, int data) {
    if (!list) return false;
    
    SNode* new_node = malloc(sizeof(SNode));
    if (!new_node) return false;
    
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
    
    return true;
}

bool slist_insert_back(SinglyLinkedList* list, int data) {
    if (!list) return false;
    
    SNode* new_node = malloc(sizeof(SNode));
    if (!new_node) return false;
    
    new_node->data = data;
    new_node->next = NULL;
    
    if (!list->head) {
        list->head = new_node;
    } else {
        SNode* current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
    
    list->size++;
    return true;
}

bool slist_insert_at(SinglyLinkedList* list, int index, int data) {
    if (!list || index < 0 || index > list->size) return false;
    
    if (index == 0) {
        return slist_insert_front(list, data);
    }
    
    SNode* new_node = malloc(sizeof(SNode));
    if (!new_node) return false;
    
    new_node->data = data;
    
    SNode* current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    
    new_node->next = current->next;
    current->next = new_node;
    list->size++;
    
    return true;
}

bool slist_delete_front(SinglyLinkedList* list) {
    if (!list || !list->head) return false;
    
    SNode* temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
    
    return true;
}

bool slist_delete_back(SinglyLinkedList* list) {
    if (!list || !list->head) return false;
    
    if (!list->head->next) {
        free(list->head);
        list->head = NULL;
    } else {
        SNode* current = list->head;
        while (current->next->next) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    
    list->size--;
    return true;
}

bool slist_delete_at(SinglyLinkedList* list, int index) {
    if (!list || index < 0 || index >= list->size) return false;
    
    if (index == 0) {
        return slist_delete_front(list);
    }
    
    SNode* current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    
    SNode* temp = current->next;
    current->next = current->next->next;
    free(temp);
    list->size--;
    
    return true;
}

int slist_find(SinglyLinkedList* list, int data) {
    if (!list) return -1;
    
    SNode* current = list->head;
    int index = 0;
    
    while (current) {
        if (current->data == data) {
            return index;
        }
        current = current->next;
        index++;
    }
    
    return -1;
}

void slist_print(SinglyLinkedList* list) {
    if (!list) {
        printf("NULL");
        return;
    }
    
    SNode* current = list->head;
    printf("[");
    while (current) {
        printf("%d", current->data);
        if (current->next) printf(" -> ");
        current = current->next;
    }
    printf("]\n");
}

void slist_reverse(SinglyLinkedList* list) {
    if (!list || !list->head) return;
    
    SNode* prev = NULL;
    SNode* current = list->head;
    SNode* next = NULL;
    
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    list->head = prev;
}

SNode* slist_find_middle(SinglyLinkedList* list) {
    if (!list || !list->head) return NULL;
    
    SNode* slow = list->head;
    SNode* fast = list->head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

// Doubly linked list implementation

DoublyLinkedList* dlist_create(void) {
    DoublyLinkedList* list = malloc(sizeof(DoublyLinkedList));
    if (list) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
    return list;
}

void dlist_destroy(DoublyLinkedList* list) {
    if (!list) return;
    
    DNode* current = list->head;
    while (current) {
        DNode* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

bool dlist_insert_front(DoublyLinkedList* list, int data) {
    if (!list) return false;
    
    DNode* new_node = malloc(sizeof(DNode));
    if (!new_node) return false;
    
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = list->head;
    
    if (list->head) {
        list->head->prev = new_node;
    } else {
        list->tail = new_node;
    }
    
    list->head = new_node;
    list->size++;
    
    return true;
}

bool dlist_insert_back(DoublyLinkedList* list, int data) {
    if (!list) return false;
    
    DNode* new_node = malloc(sizeof(DNode));
    if (!new_node) return false;
    
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = list->tail;
    
    if (list->tail) {
        list->tail->next = new_node;
    } else {
        list->head = new_node;
    }
    
    list->tail = new_node;
    list->size++;
    
    return true;
}

bool dlist_insert_at(DoublyLinkedList* list, int index, int data) {
    if (!list || index < 0 || index > list->size) return false;
    
    if (index == 0) {
        return dlist_insert_front(list, data);
    }
    
    if (index == list->size) {
        return dlist_insert_back(list, data);
    }
    
    DNode* new_node = malloc(sizeof(DNode));
    if (!new_node) return false;
    
    new_node->data = data;
    
    DNode* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    new_node->next = current;
    new_node->prev = current->prev;
    current->prev->next = new_node;
    current->prev = new_node;
    
    list->size++;
    return true;
}

bool dlist_delete_front(DoublyLinkedList* list) {
    if (!list || !list->head) return false;
    
    DNode* temp = list->head;
    list->head = list->head->next;
    
    if (list->head) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }
    
    free(temp);
    list->size--;
    
    return true;
}

bool dlist_delete_back(DoublyLinkedList* list) {
    if (!list || !list->tail) return false;
    
    DNode* temp = list->tail;
    list->tail = list->tail->prev;
    
    if (list->tail) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }
    
    free(temp);
    list->size--;
    
    return true;
}

bool dlist_delete_at(DoublyLinkedList* list, int index) {
    if (!list || index < 0 || index >= list->size) return false;
    
    if (index == 0) {
        return dlist_delete_front(list);
    }
    
    if (index == list->size - 1) {
        return dlist_delete_back(list);
    }
    
    DNode* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    list->size--;
    
    return true;
}

void dlist_print_forward(DoublyLinkedList* list) {
    if (!list) {
        printf("NULL");
        return;
    }
    
    DNode* current = list->head;
    printf("[");
    while (current) {
        printf("%d", current->data);
        if (current->next) printf(" <-> ");
        current = current->next;
    }
    printf("]\n");
}

void dlist_print_backward(DoublyLinkedList* list) {
    if (!list) {
        printf("NULL");
        return;
    }
    
    DNode* current = list->tail;
    printf("[");
    while (current) {
        printf("%d", current->data);
        if (current->prev) printf(" <-> ");
        current = current->prev;
    }
    printf("]\n");
}