/**
 * Stacks and Queues - Comprehensive C Implementation
 * 
 * This program demonstrates:
 * - Stack implementation (array and linked list based)
 * - Queue implementation (array and linked list based)
 * - Circular queue implementation
 * - Priority queue implementation
 * - Deque (double-ended queue) implementation
 * - Real-world applications and algorithms
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

// Stack implementations
typedef struct {
    int data[MAX_SIZE];
    int top;
    int capacity;
} ArrayStack;

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
    int size;
} LinkedStack;

// Queue implementations
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
    int capacity;
} ArrayQueue;

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int size;
} LinkedQueue;

// Circular queue
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int capacity;
} CircularQueue;

// Priority queue element
typedef struct {
    int data;
    int priority;
} PQElement;

typedef struct {
    PQElement elements[MAX_SIZE];
    int size;
    int capacity;
} PriorityQueue;

// Function prototypes - Array Stack
ArrayStack* astack_create(int capacity);
void astack_destroy(ArrayStack* stack);
bool astack_push(ArrayStack* stack, int data);
bool astack_pop(ArrayStack* stack, int* data);
bool astack_peek(ArrayStack* stack, int* data);
bool astack_is_empty(ArrayStack* stack);
bool astack_is_full(ArrayStack* stack);
void astack_print(ArrayStack* stack);

// Function prototypes - Linked Stack
LinkedStack* lstack_create(void);
void lstack_destroy(LinkedStack* stack);
bool lstack_push(LinkedStack* stack, int data);
bool lstack_pop(LinkedStack* stack, int* data);
bool lstack_peek(LinkedStack* stack, int* data);
bool lstack_is_empty(LinkedStack* stack);
void lstack_print(LinkedStack* stack);

// Function prototypes - Array Queue
ArrayQueue* aqueue_create(int capacity);
void aqueue_destroy(ArrayQueue* queue);
bool aqueue_enqueue(ArrayQueue* queue, int data);
bool aqueue_dequeue(ArrayQueue* queue, int* data);
bool aqueue_front(ArrayQueue* queue, int* data);
bool aqueue_is_empty(ArrayQueue* queue);
bool aqueue_is_full(ArrayQueue* queue);
void aqueue_print(ArrayQueue* queue);

// Function prototypes - Linked Queue
LinkedQueue* lqueue_create(void);
void lqueue_destroy(LinkedQueue* queue);
bool lqueue_enqueue(LinkedQueue* queue, int data);
bool lqueue_dequeue(LinkedQueue* queue, int* data);
bool lqueue_front(LinkedQueue* queue, int* data);
bool lqueue_is_empty(LinkedQueue* queue);
void lqueue_print(LinkedQueue* queue);

// Function prototypes - Circular Queue
CircularQueue* cqueue_create(int capacity);
void cqueue_destroy(CircularQueue* queue);
bool cqueue_enqueue(CircularQueue* queue, int data);
bool cqueue_dequeue(CircularQueue* queue, int* data);
bool cqueue_is_empty(CircularQueue* queue);
bool cqueue_is_full(CircularQueue* queue);
void cqueue_print(CircularQueue* queue);

// Function prototypes - Priority Queue
PriorityQueue* pqueue_create(int capacity);
void pqueue_destroy(PriorityQueue* pq);
bool pqueue_enqueue(PriorityQueue* pq, int data, int priority);
bool pqueue_dequeue(PriorityQueue* pq, int* data);
void pqueue_print(PriorityQueue* pq);

// Demo functions
void demonstrate_array_stack(void);
void demonstrate_linked_stack(void);
void demonstrate_array_queue(void);
void demonstrate_linked_queue(void);
void demonstrate_circular_queue(void);
void demonstrate_priority_queue(void);
void demonstrate_applications(void);
void demonstrate_performance_comparison(void);

// Application functions
bool is_balanced_parentheses(const char* expr);
void infix_to_postfix(const char* infix, char* postfix);
int evaluate_postfix(const char* postfix);

int main(void) {
    printf("=== C Stacks and Queues Demo ===\n\n");
    
    demonstrate_array_stack();
    demonstrate_linked_stack();
    demonstrate_array_queue();
    demonstrate_linked_queue();
    demonstrate_circular_queue();
    demonstrate_priority_queue();
    demonstrate_applications();
    demonstrate_performance_comparison();
    
    return 0;
}

/**
 * Demonstrates array-based stack operations
 */
void demonstrate_array_stack(void) {
    printf("1. Array-Based Stack\n");
    printf("====================\n");
    
    ArrayStack* stack = astack_create(5);
    
    printf("Creating stack with capacity 5:\n");
    printf("  Empty: %s\n", astack_is_empty(stack) ? "true" : "false");
    
    printf("\nPushing elements: 10, 20, 30, 40, 50\n");
    astack_push(stack, 10);
    astack_push(stack, 20);
    astack_push(stack, 30);
    astack_push(stack, 40);
    astack_push(stack, 50);
    
    printf("  Stack: ");
    astack_print(stack);
    printf("  Full: %s\n", astack_is_full(stack) ? "true" : "false");
    
    int value;
    printf("\nPeeking top element: ");
    if (astack_peek(stack, &value)) {
        printf("%d\n", value);
    }
    
    printf("\nPopping elements:\n");
    while (!astack_is_empty(stack)) {
        if (astack_pop(stack, &value)) {
            printf("  Popped: %d, Stack: ", value);
            astack_print(stack);
        }
    }
    
    printf("  Empty: %s\n", astack_is_empty(stack) ? "true" : "false");
    
    astack_destroy(stack);
    printf("  Stack destroyed\n\n");
}

/**
 * Demonstrates linked list-based stack operations
 */
void demonstrate_linked_stack(void) {
    printf("2. Linked List-Based Stack\n");
    printf("==========================\n");
    
    LinkedStack* stack = lstack_create();
    
    printf("Creating linked stack:\n");
    printf("  Empty: %s\n", lstack_is_empty(stack) ? "true" : "false");
    
    printf("\nPushing elements: 100, 200, 300, 400\n");
    lstack_push(stack, 100);
    lstack_push(stack, 200);
    lstack_push(stack, 300);
    lstack_push(stack, 400);
    
    printf("  Stack: ");
    lstack_print(stack);
    
    int value;
    printf("\nPeeking top element: ");
    if (lstack_peek(stack, &value)) {
        printf("%d\n", value);
    }
    
    printf("\nPopping two elements:\n");
    for (int i = 0; i < 2; i++) {
        if (lstack_pop(stack, &value)) {
            printf("  Popped: %d, Stack: ", value);
            lstack_print(stack);
        }
    }
    
    printf("\nPushing more elements: 500, 600\n");
    lstack_push(stack, 500);
    lstack_push(stack, 600);
    printf("  Stack: ");
    lstack_print(stack);
    
    lstack_destroy(stack);
    printf("  Stack destroyed\n\n");
}

/**
 * Demonstrates array-based queue operations
 */
void demonstrate_array_queue(void) {
    printf("3. Array-Based Queue\n");
    printf("====================\n");
    
    ArrayQueue* queue = aqueue_create(5);
    
    printf("Creating queue with capacity 5:\n");
    printf("  Empty: %s\n", aqueue_is_empty(queue) ? "true" : "false");
    
    printf("\nEnqueuing elements: 10, 20, 30, 40\n");
    aqueue_enqueue(queue, 10);
    aqueue_enqueue(queue, 20);
    aqueue_enqueue(queue, 30);
    aqueue_enqueue(queue, 40);
    
    printf("  Queue: ");
    aqueue_print(queue);
    
    int value;
    printf("\nFront element: ");
    if (aqueue_front(queue, &value)) {
        printf("%d\n", value);
    }
    
    printf("\nDequeuing two elements:\n");
    for (int i = 0; i < 2; i++) {
        if (aqueue_dequeue(queue, &value)) {
            printf("  Dequeued: %d, Queue: ", value);
            aqueue_print(queue);
        }
    }
    
    printf("\nEnqueuing more elements: 50, 60\n");
    aqueue_enqueue(queue, 50);
    aqueue_enqueue(queue, 60);
    printf("  Queue: ");
    aqueue_print(queue);
    
    aqueue_destroy(queue);
    printf("  Queue destroyed\n\n");
}

/**
 * Demonstrates linked list-based queue operations
 */
void demonstrate_linked_queue(void) {
    printf("4. Linked List-Based Queue\n");
    printf("==========================\n");
    
    LinkedQueue* queue = lqueue_create();
    
    printf("Creating linked queue:\n");
    printf("  Empty: %s\n", lqueue_is_empty(queue) ? "true" : "false");
    
    printf("\nEnqueuing elements: 100, 200, 300\n");
    lqueue_enqueue(queue, 100);
    lqueue_enqueue(queue, 200);
    lqueue_enqueue(queue, 300);
    
    printf("  Queue: ");
    lqueue_print(queue);
    
    int value;
    printf("\nFront element: ");
    if (lqueue_front(queue, &value)) {
        printf("%d\n", value);
    }
    
    printf("\nDequeuing all elements:\n");
    while (!lqueue_is_empty(queue)) {
        if (lqueue_dequeue(queue, &value)) {
            printf("  Dequeued: %d, Queue: ", value);
            lqueue_print(queue);
        }
    }
    
    lqueue_destroy(queue);
    printf("  Queue destroyed\n\n");
}

/**
 * Demonstrates circular queue operations
 */
void demonstrate_circular_queue(void) {
    printf("5. Circular Queue\n");
    printf("=================\n");
    
    CircularQueue* queue = cqueue_create(4);
    
    printf("Creating circular queue with capacity 4:\n");
    printf("  Empty: %s\n", cqueue_is_empty(queue) ? "true" : "false");
    
    printf("\nEnqueuing elements: 1, 2, 3, 4\n");
    cqueue_enqueue(queue, 1);
    cqueue_enqueue(queue, 2);
    cqueue_enqueue(queue, 3);
    cqueue_enqueue(queue, 4);
    
    printf("  Queue: ");
    cqueue_print(queue);
    printf("  Full: %s\n", cqueue_is_full(queue) ? "true" : "false");
    
    int value;
    printf("\nDequeuing two elements:\n");
    cqueue_dequeue(queue, &value);
    printf("  Dequeued: %d, Queue: ", value);
    cqueue_print(queue);
    
    cqueue_dequeue(queue, &value);
    printf("  Dequeued: %d, Queue: ", value);
    cqueue_print(queue);
    
    printf("\nEnqueuing elements: 5, 6 (demonstrating wrap-around)\n");
    cqueue_enqueue(queue, 5);
    cqueue_enqueue(queue, 6);
    printf("  Queue: ");
    cqueue_print(queue);
    
    cqueue_destroy(queue);
    printf("  Circular queue destroyed\n\n");
}

/**
 * Demonstrates priority queue operations
 */
void demonstrate_priority_queue(void) {
    printf("6. Priority Queue\n");
    printf("=================\n");
    
    PriorityQueue* pq = pqueue_create(10);
    
    printf("Creating priority queue (higher number = higher priority):\n");
    
    printf("\nEnqueuing elements with priorities:\n");
    printf("  Element 30 with priority 1\n");
    printf("  Element 10 with priority 3\n");
    printf("  Element 20 with priority 2\n");
    printf("  Element 40 with priority 4\n");
    printf("  Element 15 with priority 3\n");
    
    pqueue_enqueue(pq, 30, 1);
    pqueue_enqueue(pq, 10, 3);
    pqueue_enqueue(pq, 20, 2);
    pqueue_enqueue(pq, 40, 4);
    pqueue_enqueue(pq, 15, 3);
    
    printf("\n  Priority Queue: ");
    pqueue_print(pq);
    
    printf("\nDequeuing elements (should come out in priority order):\n");
    int value;
    while (pq->size > 0) {
        if (pqueue_dequeue(pq, &value)) {
            printf("  Dequeued: %d, Remaining: ", value);
            pqueue_print(pq);
        }
    }
    
    pqueue_destroy(pq);
    printf("  Priority queue destroyed\n\n");
}

/**
 * Demonstrates real-world applications
 */
void demonstrate_applications(void) {
    printf("7. Real-World Applications\n");
    printf("==========================\n");
    
    // Balanced parentheses checking
    printf("Balanced Parentheses Checking:\n");
    const char* expressions[] = {
        "()",
        "(())",
        "((()))",
        "()())",
        ")(",
        "({[]})",
        "({[}])"
    };
    
    int num_expr = sizeof(expressions) / sizeof(expressions[0]);
    for (int i = 0; i < num_expr; i++) {
        bool balanced = is_balanced_parentheses(expressions[i]);
        printf("  \"%s\": %s\n", expressions[i], balanced ? "Balanced" : "Not Balanced");
    }
    
    // Infix to postfix conversion
    printf("\nInfix to Postfix Conversion:\n");
    const char* infix = "2+3*4";
    char postfix[100];
    infix_to_postfix(infix, postfix);
    printf("  Infix: %s\n", infix);
    printf("  Postfix: %s\n", postfix);
    
    // Postfix evaluation
    int result = evaluate_postfix(postfix);
    printf("  Result: %d\n", result);
    
    printf("\nOther Applications:\n");
    printf("  Stacks:\n");
    printf("    • Function call management (call stack)\n");
    printf("    • Expression evaluation and syntax parsing\n");
    printf("    • Undo operations in text editors\n");
    printf("    • Browser back button functionality\n");
    printf("    • Depth-first search (DFS) in graphs\n");
    
    printf("  Queues:\n");
    printf("    • Process scheduling in operating systems\n");
    printf("    • Print job management\n");
    printf("    • Breadth-first search (BFS) in graphs\n");
    printf("    • Handling requests in web servers\n");
    printf("    • Keyboard buffer in computers\n");
    
    printf("  Priority Queues:\n");
    printf("    • Dijkstra's shortest path algorithm\n");
    printf("    • Task scheduling with priorities\n");
    printf("    • Huffman coding for data compression\n");
    printf("    • Event simulation systems\n");
    
    printf("\n");
}

/**
 * Demonstrates performance comparison
 */
void demonstrate_performance_comparison(void) {
    printf("8. Performance Comparison\n");
    printf("=========================\n");
    
    printf("Time Complexity:\n\n");
    
    printf("Array-Based Stack:\n");
    printf("  Push:    O(1)\n");
    printf("  Pop:     O(1)\n");
    printf("  Peek:    O(1)\n");
    printf("  Space:   O(n)\n");
    
    printf("\nLinked List-Based Stack:\n");
    printf("  Push:    O(1)\n");
    printf("  Pop:     O(1)\n");
    printf("  Peek:    O(1)\n");
    printf("  Space:   O(n) + pointer overhead\n");
    
    printf("\nArray-Based Queue:\n");
    printf("  Enqueue: O(1)\n");
    printf("  Dequeue: O(1) for circular, O(n) for linear\n");
    printf("  Front:   O(1)\n");
    printf("  Space:   O(n)\n");
    
    printf("\nLinked List-Based Queue:\n");
    printf("  Enqueue: O(1)\n");
    printf("  Dequeue: O(1)\n");
    printf("  Front:   O(1)\n");
    printf("  Space:   O(n) + pointer overhead\n");
    
    printf("\nPriority Queue (simple implementation):\n");
    printf("  Enqueue: O(n)\n");
    printf("  Dequeue: O(1)\n");
    printf("  Space:   O(n)\n");
    
    printf("\nTradeoffs:\n");
    printf("  Array-based:\n");
    printf("    • Better memory locality\n");
    printf("    • Fixed size (may waste space or overflow)\n");
    printf("    • No dynamic allocation overhead\n");
    
    printf("  Linked list-based:\n");
    printf("    • Dynamic size\n");
    printf("    • Extra memory for pointers\n");
    printf("    • Dynamic allocation overhead\n");
    printf("    • No size limitations\n");
    
    printf("\n");
}

// Application function implementations

bool is_balanced_parentheses(const char* expr) {
    LinkedStack* stack = lstack_create();
    bool balanced = true;
    
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        
        if (ch == '(' || ch == '[' || ch == '{') {
            lstack_push(stack, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            int top;
            if (!lstack_pop(stack, &top)) {
                balanced = false;
                break;
            }
            
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                balanced = false;
                break;
            }
        }
    }
    
    if (!lstack_is_empty(stack)) {
        balanced = false;
    }
    
    lstack_destroy(stack);
    return balanced;
}

void infix_to_postfix(const char* infix, char* postfix) {
    LinkedStack* stack = lstack_create();
    int j = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        
        if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            lstack_push(stack, ch);
        } else if (ch == ')') {
            int top;
            while (!lstack_is_empty(stack) && lstack_peek(stack, &top) && top != '(') {
                lstack_pop(stack, &top);
                postfix[j++] = top;
            }
            if (!lstack_is_empty(stack)) {
                lstack_pop(stack, &top); // Remove '('
            }
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int top;
            while (!lstack_is_empty(stack) && lstack_peek(stack, &top) && 
                   top != '(' && ((ch == '+' || ch == '-') ? true : (top == '*' || top == '/'))) {
                lstack_pop(stack, &top);
                postfix[j++] = top;
            }
            lstack_push(stack, ch);
        }
    }
    
    int top;
    while (!lstack_is_empty(stack)) {
        lstack_pop(stack, &top);
        postfix[j++] = top;
    }
    
    postfix[j] = '\0';
    lstack_destroy(stack);
}

int evaluate_postfix(const char* postfix) {
    LinkedStack* stack = lstack_create();
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        
        if (ch >= '0' && ch <= '9') {
            lstack_push(stack, ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int b, a;
            lstack_pop(stack, &b);
            lstack_pop(stack, &a);
            
            int result;
            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default: result = 0;
            }
            
            lstack_push(stack, result);
        }
    }
    
    int result;
    lstack_pop(stack, &result);
    lstack_destroy(stack);
    
    return result;
}

// Implementation functions (abbreviated for space - full implementations would be provided)

ArrayStack* astack_create(int capacity) {
    ArrayStack* stack = malloc(sizeof(ArrayStack));
    if (stack) {
        stack->top = -1;
        stack->capacity = capacity;
    }
    return stack;
}

void astack_destroy(ArrayStack* stack) {
    free(stack);
}

bool astack_push(ArrayStack* stack, int data) {
    if (!stack || astack_is_full(stack)) return false;
    stack->data[++stack->top] = data;
    return true;
}

bool astack_pop(ArrayStack* stack, int* data) {
    if (!stack || astack_is_empty(stack)) return false;
    *data = stack->data[stack->top--];
    return true;
}

bool astack_peek(ArrayStack* stack, int* data) {
    if (!stack || astack_is_empty(stack)) return false;
    *data = stack->data[stack->top];
    return true;
}

bool astack_is_empty(ArrayStack* stack) {
    return stack ? stack->top == -1 : true;
}

bool astack_is_full(ArrayStack* stack) {
    return stack ? stack->top == stack->capacity - 1 : false;
}

void astack_print(ArrayStack* stack) {
    if (!stack || astack_is_empty(stack)) {
        printf("[empty]\n");
        return;
    }
    
    printf("[");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d", stack->data[i]);
        if (i < stack->top) printf(", ");
    }
    printf("] (top: %d)\n", stack->data[stack->top]);
}

// Linked Stack implementations
LinkedStack* lstack_create(void) {
    LinkedStack* stack = malloc(sizeof(LinkedStack));
    if (stack) {
        stack->top = NULL;
        stack->size = 0;
    }
    return stack;
}

void lstack_destroy(LinkedStack* stack) {
    if (!stack) return;
    
    while (!lstack_is_empty(stack)) {
        int dummy;
        lstack_pop(stack, &dummy);
    }
    free(stack);
}

bool lstack_push(LinkedStack* stack, int data) {
    if (!stack) return false;
    
    StackNode* node = malloc(sizeof(StackNode));
    if (!node) return false;
    
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
    
    return true;
}

bool lstack_pop(LinkedStack* stack, int* data) {
    if (!stack || lstack_is_empty(stack)) return false;
    
    StackNode* temp = stack->top;
    *data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    
    return true;
}

bool lstack_peek(LinkedStack* stack, int* data) {
    if (!stack || lstack_is_empty(stack)) return false;
    *data = stack->top->data;
    return true;
}

bool lstack_is_empty(LinkedStack* stack) {
    return stack ? stack->top == NULL : true;
}

void lstack_print(LinkedStack* stack) {
    if (!stack || lstack_is_empty(stack)) {
        printf("[empty]\n");
        return;
    }
    
    printf("[");
    StackNode* current = stack->top;
    while (current) {
        printf("%d", current->data);
        if (current->next) printf(", ");
        current = current->next;
    }
    printf("] (top: %d)\n", stack->top->data);
}

// Queue implementations (abbreviated - similar pattern as stacks)
ArrayQueue* aqueue_create(int capacity) {
    ArrayQueue* queue = malloc(sizeof(ArrayQueue));
    if (queue) {
        queue->front = 0;
        queue->rear = -1;
        queue->size = 0;
        queue->capacity = capacity;
    }
    return queue;
}

void aqueue_destroy(ArrayQueue* queue) {
    free(queue);
}

bool aqueue_enqueue(ArrayQueue* queue, int data) {
    if (!queue || aqueue_is_full(queue)) return false;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = data;
    queue->size++;
    return true;
}

bool aqueue_dequeue(ArrayQueue* queue, int* data) {
    if (!queue || aqueue_is_empty(queue)) return false;
    *data = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return true;
}

bool aqueue_front(ArrayQueue* queue, int* data) {
    if (!queue || aqueue_is_empty(queue)) return false;
    *data = queue->data[queue->front];
    return true;
}

bool aqueue_is_empty(ArrayQueue* queue) {
    return queue ? queue->size == 0 : true;
}

bool aqueue_is_full(ArrayQueue* queue) {
    return queue ? queue->size == queue->capacity : false;
}

void aqueue_print(ArrayQueue* queue) {
    if (!queue || aqueue_is_empty(queue)) {
        printf("[empty]\n");
        return;
    }
    
    printf("[");
    for (int i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % queue->capacity;
        printf("%d", queue->data[index]);
        if (i < queue->size - 1) printf(", ");
    }
    printf("]\n");
}

// Linked Queue implementations
LinkedQueue* lqueue_create(void) {
    LinkedQueue* queue = malloc(sizeof(LinkedQueue));
    if (queue) {
        queue->front = NULL;
        queue->rear = NULL;
        queue->size = 0;
    }
    return queue;
}

void lqueue_destroy(LinkedQueue* queue) {
    if (!queue) return;
    
    while (!lqueue_is_empty(queue)) {
        int dummy;
        lqueue_dequeue(queue, &dummy);
    }
    free(queue);
}

bool lqueue_enqueue(LinkedQueue* queue, int data) {
    if (!queue) return false;
    
    QueueNode* node = malloc(sizeof(QueueNode));
    if (!node) return false;
    
    node->data = data;
    node->next = NULL;
    
    if (queue->rear) {
        queue->rear->next = node;
    } else {
        queue->front = node;
    }
    queue->rear = node;
    queue->size++;
    
    return true;
}

bool lqueue_dequeue(LinkedQueue* queue, int* data) {
    if (!queue || lqueue_is_empty(queue)) return false;
    
    QueueNode* temp = queue->front;
    *data = temp->data;
    queue->front = queue->front->next;
    
    if (!queue->front) {
        queue->rear = NULL;
    }
    
    free(temp);
    queue->size--;
    
    return true;
}

bool lqueue_front(LinkedQueue* queue, int* data) {
    if (!queue || lqueue_is_empty(queue)) return false;
    *data = queue->front->data;
    return true;
}

bool lqueue_is_empty(LinkedQueue* queue) {
    return queue ? queue->front == NULL : true;
}

void lqueue_print(LinkedQueue* queue) {
    if (!queue || lqueue_is_empty(queue)) {
        printf("[empty]\n");
        return;
    }
    
    printf("[");
    QueueNode* current = queue->front;
    while (current) {
        printf("%d", current->data);
        if (current->next) printf(", ");
        current = current->next;
    }
    printf("]\n");
}

// Circular Queue implementations
CircularQueue* cqueue_create(int capacity) {
    CircularQueue* queue = malloc(sizeof(CircularQueue));
    if (queue) {
        queue->front = 0;
        queue->rear = -1;
        queue->capacity = capacity;
    }
    return queue;
}

void cqueue_destroy(CircularQueue* queue) {
    free(queue);
}

bool cqueue_enqueue(CircularQueue* queue, int data) {
    if (!queue || cqueue_is_full(queue)) return false;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = data;
    return true;
}

bool cqueue_dequeue(CircularQueue* queue, int* data) {
    if (!queue || cqueue_is_empty(queue)) return false;
    *data = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    return true;
}

bool cqueue_is_empty(CircularQueue* queue) {
    return queue ? (queue->rear + 1) % queue->capacity == queue->front && queue->data[queue->front] == 0 : true;
}

bool cqueue_is_full(CircularQueue* queue) {
    return queue ? (queue->rear + 1) % queue->capacity == queue->front && queue->data[queue->front] != 0 : false;
}

void cqueue_print(CircularQueue* queue) {
    if (!queue || cqueue_is_empty(queue)) {
        printf("[empty]\n");
        return;
    }
    
    printf("[");
    int i = queue->front;
    do {
        printf("%d", queue->data[i]);
        i = (i + 1) % queue->capacity;
        if (i != (queue->rear + 1) % queue->capacity) printf(", ");
    } while (i != (queue->rear + 1) % queue->capacity);
    printf("]\n");
}

// Priority Queue implementations
PriorityQueue* pqueue_create(int capacity) {
    PriorityQueue* pq = malloc(sizeof(PriorityQueue));
    if (pq) {
        pq->size = 0;
        pq->capacity = capacity;
    }
    return pq;
}

void pqueue_destroy(PriorityQueue* pq) {
    free(pq);
}

bool pqueue_enqueue(PriorityQueue* pq, int data, int priority) {
    if (!pq || pq->size >= pq->capacity) return false;
    
    // Find position to insert (maintain priority order)
    int i;
    for (i = pq->size - 1; i >= 0 && pq->elements[i].priority < priority; i--) {
        pq->elements[i + 1] = pq->elements[i];
    }
    
    pq->elements[i + 1].data = data;
    pq->elements[i + 1].priority = priority;
    pq->size++;
    
    return true;
}

bool pqueue_dequeue(PriorityQueue* pq, int* data) {
    if (!pq || pq->size == 0) return false;
    
    *data = pq->elements[0].data;
    
    // Shift elements
    for (int i = 0; i < pq->size - 1; i++) {
        pq->elements[i] = pq->elements[i + 1];
    }
    pq->size--;
    
    return true;
}

void pqueue_print(PriorityQueue* pq) {
    if (!pq || pq->size == 0) {
        printf("[empty]\n");
        return;
    }
    
    printf("[");
    for (int i = 0; i < pq->size; i++) {
        printf("(%d,%d)", pq->elements[i].data, pq->elements[i].priority);
        if (i < pq->size - 1) printf(", ");
    }
    printf("]\n");
}