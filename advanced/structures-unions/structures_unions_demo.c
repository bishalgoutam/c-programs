/**
 * Structures and Unions - Comprehensive C Implementation
 * 
 * This program demonstrates:
 * - Structure definition and usage
 * - Union concepts and memory sharing
 * - Nested structures and complex data types
 * - Bit fields and packed structures
 * - Structure alignment and padding
 * - Structure pointers and dynamic allocation
 * - Structure arrays and linked structures
 * - Anonymous structures and unions
 * - Structure initialization techniques
 * - Memory layout and optimization
 * 
 * @author Bishal Goutam
 * @since C99 Standard
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>

// Basic structure definitions
struct Point {
    double x;
    double y;
};

struct Rectangle {
    struct Point top_left;
    struct Point bottom_right;
};

// Union demonstration
union Number {
    int integer;
    float floating;
    char bytes[4];
};

// Bit fields structure
struct PackedData {
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    unsigned int value : 6;
    unsigned int type : 3;
    unsigned int reserved : 21;
};

// Complex nested structure
struct Student {
    unsigned int id;
    char name[50];
    char email[100];
    float gpa;
    struct {
        int day;
        int month;
        int year;
    } birth_date;
    struct {
        char street[100];
        char city[50];
        char state[20];
        int zip_code;
    } address;
    char courses[10][30];
    int course_count;
};

// Self-referential structure (linked list)
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Structure with function pointer
struct Calculator {
    double (*add)(double a, double b);
    double (*subtract)(double a, double b);
    double (*multiply)(double a, double b);
    double (*divide)(double a, double b);
    char name[20];
};

// Union for type-safe variant
enum DataType {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_BOOL
};

struct Variant {
    enum DataType type;
    union {
        int int_value;
        float float_value;
        char* string_value;
        bool bool_value;
    } data;
};

// Flexible array member (C99 feature)
struct DynamicArray {
    size_t size;
    size_t capacity;
    int elements[];  // Flexible array member
};

// Anonymous structures and unions (C11 feature)
struct Employee {
    int id;
    char name[50];
    union {
        struct {
            double hourly_rate;
            int hours_worked;
        };  // Anonymous struct
        struct {
            double monthly_salary;
            double bonus;
        };
    };  // Anonymous union
    enum { HOURLY, SALARIED } pay_type;
};

// Packed structure (compiler-specific)
#pragma pack(push, 1)
struct PackedStruct {
    char a;
    int b;
    short c;
};
#pragma pack(pop)

// Function prototypes - Basic operations
void demonstrate_basic_structures(void);
void demonstrate_unions(void);
void demonstrate_nested_structures(void);
void demonstrate_bit_fields(void);
void demonstrate_structure_pointers(void);
void demonstrate_structure_arrays(void);
void demonstrate_self_referential_structures(void);
void demonstrate_function_pointers_in_structures(void);

// Function prototypes - Advanced operations
void demonstrate_variant_types(void);
void demonstrate_flexible_arrays(void);
void demonstrate_anonymous_structures(void);
void demonstrate_packed_structures(void);
void demonstrate_structure_alignment(void);
void demonstrate_structure_copying(void);
void demonstrate_structure_comparison(void);
void demonstrate_structure_serialization(void);

// Utility function prototypes
struct Point create_point(double x, double y);
struct Rectangle create_rectangle(struct Point tl, struct Point br);
double calculate_distance(struct Point p1, struct Point p2);
double calculate_area(struct Rectangle rect);
void print_point(const struct Point* p);
void print_rectangle(const struct Rectangle* rect);
void print_student(const struct Student* student);
struct Node* create_node(int data);
void insert_node(struct Node** head, int data);
void print_list(const struct Node* head);
void free_list(struct Node* head);

// Calculator function implementations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

// Variant helper functions
struct Variant create_int_variant(int value);
struct Variant create_float_variant(float value);
struct Variant create_string_variant(const char* value);
struct Variant create_bool_variant(bool value);
void print_variant(const struct Variant* var);
void free_variant(struct Variant* var);

// Dynamic array functions
struct DynamicArray* create_dynamic_array(size_t initial_capacity);
void dynamic_array_push(struct DynamicArray** arr, int value);
void print_dynamic_array(const struct DynamicArray* arr);
void free_dynamic_array(struct DynamicArray* arr);

int main(void) {
    printf("=== C Structures and Unions Demo ===\n\n");
    
    demonstrate_basic_structures();
    demonstrate_unions();
    demonstrate_nested_structures();
    demonstrate_bit_fields();
    demonstrate_structure_pointers();
    demonstrate_structure_arrays();
    demonstrate_self_referential_structures();
    demonstrate_function_pointers_in_structures();
    demonstrate_variant_types();
    demonstrate_flexible_arrays();
    demonstrate_anonymous_structures();
    demonstrate_packed_structures();
    demonstrate_structure_alignment();
    demonstrate_structure_copying();
    demonstrate_structure_comparison();
    demonstrate_structure_serialization();
    
    return 0;
}

/**
 * Demonstrates basic structure operations
 */
void demonstrate_basic_structures(void) {
    printf("1. Basic Structures\n");
    printf("===================\n");
    
    printf("Structure Definition:\n");
    printf("  struct Point {\n");
    printf("      double x;\n");
    printf("      double y;\n");
    printf("  };\n\n");
    
    // Structure initialization methods
    printf("Structure Initialization Methods:\n");
    
    // Method 1: Designated initializers (C99)
    struct Point p1 = {.x = 10.5, .y = 20.3};
    printf("  Designated initializers: p1 = {.x = 10.5, .y = 20.3}\n");
    print_point(&p1);
    
    // Method 2: Positional initialization
    struct Point p2 = {5.0, 15.0};
    printf("  Positional initialization: p2 = {5.0, 15.0}\n");
    print_point(&p2);
    
    // Method 3: Assignment after declaration
    struct Point p3;
    p3.x = 0.0;
    p3.y = 0.0;
    printf("  Assignment after declaration: p3.x = 0.0, p3.y = 0.0\n");
    print_point(&p3);
    
    // Method 4: Function-based initialization
    struct Point p4 = create_point(7.5, 12.8);
    printf("  Function-based: p4 = create_point(7.5, 12.8)\n");
    print_point(&p4);
    
    // Structure operations
    printf("\nStructure Operations:\n");
    double distance = calculate_distance(p1, p2);
    printf("  Distance between p1 and p2: %.2f\n", distance);
    
    // Structure assignment (shallow copy)
    struct Point p5 = p1;
    printf("  Structure assignment: p5 = p1\n");
    print_point(&p5);
    
    printf("\n");
}

/**
 * Demonstrates union concepts and memory sharing
 */
void demonstrate_unions(void) {
    printf("2. Unions\n");
    printf("=========\n");
    
    printf("Union Definition:\n");
    printf("  union Number {\n");
    printf("      int integer;\n");
    printf("      float floating;\n");
    printf("      char bytes[4];\n");
    printf("  };\n\n");
    
    printf("Union Memory Layout:\n");
    printf("  All members share the same memory location\n");
    printf("  Size of union = size of largest member\n");
    printf("  Size of union Number: %zu bytes\n\n", sizeof(union Number));
    
    union Number num;
    
    // Integer access
    num.integer = 0x12345678;
    printf("Setting integer value: 0x12345678\n");
    printf("  As integer: %d (0x%08X)\n", num.integer, num.integer);
    printf("  As float: %f\n", num.floating);
    printf("  As bytes: ");
    for (int i = 0; i < 4; i++) {
        printf("0x%02X ", (unsigned char)num.bytes[i]);
    }
    printf("\n");
    
    // Float access
    num.floating = 3.14159f;
    printf("\nSetting float value: 3.14159\n");
    printf("  As float: %f\n", num.floating);
    printf("  As integer: %d (0x%08X)\n", num.integer, num.integer);
    printf("  As bytes: ");
    for (int i = 0; i < 4; i++) {
        printf("0x%02X ", (unsigned char)num.bytes[i]);
    }
    printf("\n");
    
    // Practical union usage - IP address
    union IPAddress {
        uint32_t address;
        struct {
            uint8_t octet1;
            uint8_t octet2;
            uint8_t octet3;
            uint8_t octet4;
        } octets;
    };
    
    printf("\nPractical Union Example - IP Address:\n");
    union IPAddress ip;
    ip.address = 0xC0A80101;  // 192.168.1.1 in hex
    
    printf("  IP address as uint32: 0x%08X\n", ip.address);
    printf("  IP address as octets: %d.%d.%d.%d\n",
           ip.octets.octet4, ip.octets.octet3,  // Little-endian
           ip.octets.octet2, ip.octets.octet1);
    
    printf("\n");
}

/**
 * Demonstrates nested structures
 */
void demonstrate_nested_structures(void) {
    printf("3. Nested Structures\n");
    printf("====================\n");
    
    printf("Creating nested structures (Rectangle with Points):\n");
    
    struct Point top_left = {0.0, 10.0};
    struct Point bottom_right = {10.0, 0.0};
    struct Rectangle rect = create_rectangle(top_left, bottom_right);
    
    printf("Rectangle created:\n");
    print_rectangle(&rect);
    
    double area = calculate_area(rect);
    printf("Rectangle area: %.2f square units\n", area);
    
    // Accessing nested structure members
    printf("\nAccessing nested members:\n");
    printf("  rect.top_left.x = %.2f\n", rect.top_left.x);
    printf("  rect.top_left.y = %.2f\n", rect.top_left.y);
    printf("  rect.bottom_right.x = %.2f\n", rect.bottom_right.x);
    printf("  rect.bottom_right.y = %.2f\n", rect.bottom_right.y);
    
    // Complex nested structure example
    printf("\nComplex Nested Structure - Student:\n");
    struct Student student = {
        .id = 12345,
        .name = "Alice Johnson",
        .email = "alice.johnson@university.edu",
        .gpa = 3.85,
        .birth_date = {15, 8, 2000},
        .address = {
            .street = "123 College Ave",
            .city = "University City",
            .state = "CA",
            .zip_code = 90210
        },
        .course_count = 0
    };
    
    // Add courses
    strcpy(student.courses[student.course_count++], "Computer Science");
    strcpy(student.courses[student.course_count++], "Mathematics");
    strcpy(student.courses[student.course_count++], "Physics");
    
    print_student(&student);
    
    printf("\n");
}

/**
 * Demonstrates bit fields
 */
void demonstrate_bit_fields(void) {
    printf("4. Bit Fields\n");
    printf("=============\n");
    
    printf("Bit Field Structure:\n");
    printf("  struct PackedData {\n");
    printf("      unsigned int flag1 : 1;      // 1 bit\n");
    printf("      unsigned int flag2 : 1;      // 1 bit\n");
    printf("      unsigned int value : 6;      // 6 bits\n");
    printf("      unsigned int type : 3;       // 3 bits\n");
    printf("      unsigned int reserved : 21;  // 21 bits\n");
    printf("  };\n\n");
    
    printf("Size comparison:\n");
    printf("  Regular struct with int fields: %zu bytes\n", 5 * sizeof(int));
    printf("  Bit field struct: %zu bytes\n", sizeof(struct PackedData));
    printf("  Space saved: %zu bytes (%.1f%%)\n",
           5 * sizeof(int) - sizeof(struct PackedData),
           (1.0 - (double)sizeof(struct PackedData) / (5 * sizeof(int))) * 100);
    
    struct PackedData data = {0};
    
    // Setting bit field values
    data.flag1 = 1;
    data.flag2 = 0;
    data.value = 42;  // 6 bits can hold 0-63
    data.type = 5;    // 3 bits can hold 0-7
    data.reserved = 0;
    
    printf("\nBit field values:\n");
    printf("  flag1: %u\n", data.flag1);
    printf("  flag2: %u\n", data.flag2);
    printf("  value: %u\n", data.value);
    printf("  type: %u\n", data.type);
    printf("  reserved: %u\n", data.reserved);
    
    // Bit field limitations
    printf("\nBit Field Limitations:\n");
    printf("  • Cannot take address of bit field members\n");
    printf("  • Cannot have arrays of bit fields\n");
    printf("  • Implementation-defined layout and alignment\n");
    printf("  • Cannot use sizeof on bit field members\n");
    
    // Practical example: CPU flags register
    struct CPUFlags {
        unsigned int carry : 1;
        unsigned int zero : 1;
        unsigned int interrupt : 1;
        unsigned int decimal : 1;
        unsigned int break_flag : 1;
        unsigned int unused : 1;
        unsigned int overflow : 1;
        unsigned int negative : 1;
    };
    
    printf("\nPractical Example - CPU Flags Register:\n");
    struct CPUFlags flags = {0};
    flags.carry = 1;
    flags.zero = 0;
    flags.interrupt = 1;
    
    printf("  CPU Flags: C=%u Z=%u I=%u D=%u B=%u U=%u V=%u N=%u\n",
           flags.carry, flags.zero, flags.interrupt, flags.decimal,
           flags.break_flag, flags.unused, flags.overflow, flags.negative);
    
    printf("\n");
}

/**
 * Demonstrates structure pointers and dynamic allocation
 */
void demonstrate_structure_pointers(void) {
    printf("5. Structure Pointers\n");
    printf("=====================\n");
    
    printf("Pointer Access Methods:\n");
    
    // Stack-allocated structure
    struct Point stack_point = {10.0, 20.0};
    struct Point* ptr_to_stack = &stack_point;
    
    printf("  Stack-allocated structure:\n");
    printf("    Direct access: stack_point.x = %.1f\n", stack_point.x);
    printf("    Pointer access: (*ptr_to_stack).x = %.1f\n", (*ptr_to_stack).x);
    printf("    Arrow operator: ptr_to_stack->x = %.1f\n", ptr_to_stack->x);
    
    // Dynamically allocated structure
    printf("\n  Dynamically allocated structure:\n");
    struct Point* heap_point = malloc(sizeof(struct Point));
    if (heap_point) {
        heap_point->x = 30.0;
        heap_point->y = 40.0;
        
        printf("    heap_point->x = %.1f\n", heap_point->x);
        printf("    heap_point->y = %.1f\n", heap_point->y);
        
        free(heap_point);
        heap_point = NULL;  // Prevent dangling pointer
    }
    
    // Array of structures
    printf("\n  Array of structures (dynamic):\n");
    struct Point* point_array = malloc(5 * sizeof(struct Point));
    if (point_array) {
        for (int i = 0; i < 5; i++) {
            point_array[i].x = i * 2.0;
            point_array[i].y = i * 3.0;
            printf("    point_array[%d]: (%.1f, %.1f)\n", 
                   i, point_array[i].x, point_array[i].y);
        }
        
        free(point_array);
    }
    
    // Pointer to structure member
    printf("\n  Pointer to structure member:\n");
    struct Point test_point = {100.0, 200.0};
    double* x_ptr = &test_point.x;
    double* y_ptr = &test_point.y;
    
    printf("    Original: (%.1f, %.1f)\n", test_point.x, test_point.y);
    *x_ptr = 150.0;
    *y_ptr = 250.0;
    printf("    Modified via pointers: (%.1f, %.1f)\n", test_point.x, test_point.y);
    
    printf("\n");
}

/**
 * Demonstrates structure arrays
 */
void demonstrate_structure_arrays(void) {
    printf("6. Structure Arrays\n");
    printf("===================\n");
    
    // Static array of structures
    printf("Static array of structures:\n");
    struct Point points[] = {
        {0.0, 0.0},
        {1.0, 1.0},
        {2.0, 4.0},
        {3.0, 9.0},
        {4.0, 16.0}
    };
    
    size_t num_points = sizeof(points) / sizeof(points[0]);
    printf("  Array contains %zu points:\n", num_points);
    
    for (size_t i = 0; i < num_points; i++) {
        printf("    Point %zu: ", i);
        print_point(&points[i]);
    }
    
    // Calculate total distance of path
    double total_distance = 0.0;
    for (size_t i = 1; i < num_points; i++) {
        double segment = calculate_distance(points[i-1], points[i]);
        total_distance += segment;
        printf("  Segment %zu-%zu distance: %.2f\n", i-1, i, segment);
    }
    printf("  Total path distance: %.2f\n", total_distance);
    
    // Dynamic array of structures
    printf("\nDynamic array of structures:\n");
    size_t capacity = 10;
    struct Student* students = malloc(capacity * sizeof(struct Student));
    
    if (students) {
        // Initialize some students
        struct Student sample_students[] = {
            {1001, "John Doe", "john@university.edu", 3.5, {10, 5, 1999}, 
             {"123 Main St", "Anytown", "ST", 12345}, {}, 0},
            {1002, "Jane Smith", "jane@university.edu", 3.8, {22, 12, 2000},
             {"456 Oak Ave", "Somewhere", "ST", 54321}, {}, 0},
            {1003, "Bob Johnson", "bob@university.edu", 3.2, {5, 8, 1998},
             {"789 Pine St", "Elsewhere", "ST", 98765}, {}, 0}
        };
        
        size_t num_students = sizeof(sample_students) / sizeof(sample_students[0]);
        
        // Copy to dynamic array
        for (size_t i = 0; i < num_students; i++) {
            students[i] = sample_students[i];
        }
        
        printf("  Loaded %zu students:\n", num_students);
        for (size_t i = 0; i < num_students; i++) {
            printf("    Student %zu: ID=%u, Name=%s, GPA=%.1f\n",
                   i + 1, students[i].id, students[i].name, students[i].gpa);
        }
        
        // Find student with highest GPA
        size_t best_student = 0;
        for (size_t i = 1; i < num_students; i++) {
            if (students[i].gpa > students[best_student].gpa) {
                best_student = i;
            }
        }
        
        printf("  Highest GPA: %s (%.1f)\n", 
               students[best_student].name, students[best_student].gpa);
        
        free(students);
    }
    
    printf("\n");
}

/**
 * Demonstrates self-referential structures (linked lists)
 */
void demonstrate_self_referential_structures(void) {
    printf("7. Self-Referential Structures\n");
    printf("===============================\n");
    
    printf("Linked List Implementation:\n");
    printf("  struct Node {\n");
    printf("      int data;\n");
    printf("      struct Node* next;\n");
    printf("      struct Node* prev;  // For doubly-linked list\n");
    printf("  };\n\n");
    
    struct Node* head = NULL;
    
    // Build a linked list
    printf("Building linked list:\n");
    int values[] = {10, 20, 30, 40, 50};
    size_t num_values = sizeof(values) / sizeof(values[0]);
    
    for (size_t i = 0; i < num_values; i++) {
        insert_node(&head, values[i]);
        printf("  Inserted %d\n", values[i]);
    }
    
    printf("\nLinked list contents:\n");
    print_list(head);
    
    // Count nodes
    int count = 0;
    struct Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    printf("  Total nodes: %d\n", count);
    
    // Find a value
    int search_value = 30;
    current = head;
    int position = 0;
    bool found = false;
    
    while (current) {
        if (current->data == search_value) {
            printf("  Found %d at position %d\n", search_value, position);
            found = true;
            break;
        }
        current = current->next;
        position++;
    }
    
    if (!found) {
        printf("  Value %d not found\n", search_value);
    }
    
    // Calculate sum
    int sum = 0;
    current = head;
    while (current) {
        sum += current->data;
        current = current->next;
    }
    printf("  Sum of all values: %d\n", sum);
    
    // Cleanup
    free_list(head);
    printf("  ✓ Memory freed\n");
    
    printf("\n");
}

/**
 * Demonstrates function pointers in structures
 */
void demonstrate_function_pointers_in_structures(void) {
    printf("8. Function Pointers in Structures\n");
    printf("===================================\n");
    
    printf("Calculator structure with function pointers:\n");
    printf("  struct Calculator {\n");
    printf("      double (*add)(double a, double b);\n");
    printf("      double (*subtract)(double a, double b);\n");
    printf("      double (*multiply)(double a, double b);\n");
    printf("      double (*divide)(double a, double b);\n");
    printf("      char name[20];\n");
    printf("  };\n\n");
    
    // Initialize calculator
    struct Calculator calc = {
        .add = add,
        .subtract = subtract,
        .multiply = multiply,
        .divide = divide
    };
    strcpy(calc.name, "Basic Calculator");
    
    printf("Calculator: %s\n", calc.name);
    
    double a = 15.5, b = 4.2;
    printf("  Operating on %.1f and %.1f:\n", a, b);
    printf("    Addition: %.1f + %.1f = %.2f\n", a, b, calc.add(a, b));
    printf("    Subtraction: %.1f - %.1f = %.2f\n", a, b, calc.subtract(a, b));
    printf("    Multiplication: %.1f × %.1f = %.2f\n", a, b, calc.multiply(a, b));
    printf("    Division: %.1f ÷ %.1f = %.2f\n", a, b, calc.divide(a, b));
    
    // Array of function pointers
    printf("\nArray of function pointers:\n");
    double (*operations[])(double, double) = {add, subtract, multiply, divide};
    const char* op_names[] = {"+", "-", "×", "÷"};
    
    for (int i = 0; i < 4; i++) {
        double result = operations[i](a, b);
        printf("  %.1f %s %.1f = %.2f\n", a, op_names[i], b, result);
    }
    
    printf("\n");
}

/**
 * Demonstrates variant types using unions
 */
void demonstrate_variant_types(void) {
    printf("9. Variant Types (Type-Safe Unions)\n");
    printf("===================================\n");
    
    printf("Variant structure for type-safe unions:\n");
    printf("  struct Variant {\n");
    printf("      enum DataType type;\n");
    printf("      union {\n");
    printf("          int int_value;\n");
    printf("          float float_value;\n");
    printf("          char* string_value;\n");
    printf("          bool bool_value;\n");
    printf("      } data;\n");
    printf("  };\n\n");
    
    // Create variants of different types
    struct Variant variants[] = {
        create_int_variant(42),
        create_float_variant(3.14159f),
        create_string_variant("Hello, Variants!"),
        create_bool_variant(true)
    };
    
    size_t num_variants = sizeof(variants) / sizeof(variants[0]);
    
    printf("Created %zu variants:\n", num_variants);
    for (size_t i = 0; i < num_variants; i++) {
        printf("  Variant %zu: ", i + 1);
        print_variant(&variants[i]);
    }
    
    // Cleanup string variants
    for (size_t i = 0; i < num_variants; i++) {
        free_variant(&variants[i]);
    }
    
    printf("\n");
}

/**
 * Demonstrates flexible array members (C99)
 */
void demonstrate_flexible_arrays(void) {
    printf("10. Flexible Array Members (C99)\n");
    printf("================================\n");
    
    printf("Dynamic array with flexible array member:\n");
    printf("  struct DynamicArray {\n");
    printf("      size_t size;\n");
    printf("      size_t capacity;\n");
    printf("      int elements[];  // Flexible array member\n");
    printf("  };\n\n");
    
    // Create dynamic array
    struct DynamicArray* arr = create_dynamic_array(5);
    if (!arr) {
        printf("Failed to create dynamic array\n");
        return;
    }
    
    printf("Created dynamic array with capacity %zu\n", arr->capacity);
    
    // Add elements
    printf("Adding elements:\n");
    for (int i = 1; i <= 10; i++) {
        dynamic_array_push(&arr, i * i);
        printf("  Added %d (size now %zu)\n", i * i, arr->size);
    }
    
    printf("\nFinal array contents:\n");
    print_dynamic_array(arr);
    
    free_dynamic_array(arr);
    printf("✓ Array freed\n");
    
    printf("\n");
}

/**
 * Demonstrates anonymous structures and unions (C11)
 */
void demonstrate_anonymous_structures(void) {
    printf("11. Anonymous Structures and Unions (C11)\n");
    printf("==========================================\n");
    
    printf("Employee structure with anonymous union:\n");
    printf("  struct Employee {\n");
    printf("      int id;\n");
    printf("      char name[50];\n");
    printf("      union {              // Anonymous union\n");
    printf("          struct {         // Anonymous struct for hourly\n");
    printf("              double hourly_rate;\n");
    printf("              int hours_worked;\n");
    printf("          };\n");
    printf("          struct {         // Anonymous struct for salaried\n");
    printf("              double monthly_salary;\n");
    printf("              double bonus;\n");
    printf("          };\n");
    printf("      };\n");
    printf("      enum { HOURLY, SALARIED } pay_type;\n");
    printf("  };\n\n");
    
    // Create hourly employee
    struct Employee hourly_emp = {
        .id = 1001,
        .name = "John Worker",
        .hourly_rate = 25.50,  // Direct access due to anonymous struct
        .hours_worked = 40,
        .pay_type = HOURLY
    };
    
    printf("Hourly Employee:\n");
    printf("  ID: %d\n", hourly_emp.id);
    printf("  Name: %s\n", hourly_emp.name);
    printf("  Hourly Rate: $%.2f\n", hourly_emp.hourly_rate);
    printf("  Hours Worked: %d\n", hourly_emp.hours_worked);
    printf("  Weekly Pay: $%.2f\n", hourly_emp.hourly_rate * hourly_emp.hours_worked);
    
    // Create salaried employee
    struct Employee salaried_emp = {
        .id = 1002,
        .name = "Jane Manager",
        .monthly_salary = 5000.00,  // Direct access due to anonymous struct
        .bonus = 1000.00,
        .pay_type = SALARIED
    };
    
    printf("\nSalaried Employee:\n");
    printf("  ID: %d\n", salaried_emp.id);
    printf("  Name: %s\n", salaried_emp.name);
    printf("  Monthly Salary: $%.2f\n", salaried_emp.monthly_salary);
    printf("  Bonus: $%.2f\n", salaried_emp.bonus);
    printf("  Total Monthly Pay: $%.2f\n", 
           salaried_emp.monthly_salary + salaried_emp.bonus);
    
    printf("\n");
}

/**
 * Demonstrates packed structures
 */
void demonstrate_packed_structures(void) {
    printf("12. Packed Structures\n");
    printf("=====================\n");
    
    printf("Comparing normal vs packed structures:\n");
    
    struct NormalStruct {
        char a;
        int b;
        short c;
    };
    
    printf("  Normal struct { char, int, short }:\n");
    printf("    Size: %zu bytes\n", sizeof(struct NormalStruct));
    printf("    Expected without padding: %zu bytes\n", 
           sizeof(char) + sizeof(int) + sizeof(short));
    printf("    Padding overhead: %zu bytes\n",
           sizeof(struct NormalStruct) - (sizeof(char) + sizeof(int) + sizeof(short)));
    
    printf("\n  Packed struct (same layout):\n");
    printf("    Size: %zu bytes\n", sizeof(struct PackedStruct));
    printf("    Space saved: %zu bytes\n",
           sizeof(struct NormalStruct) - sizeof(struct PackedStruct));
    
    // Show memory layout
    struct NormalStruct normal = {0x11, 0x22334455, 0x6677};
    struct PackedStruct packed = {0x11, 0x22334455, 0x6677};
    
    printf("\nMemory layout comparison:\n");
    printf("  Normal struct bytes: ");
    unsigned char* normal_bytes = (unsigned char*)&normal;
    for (size_t i = 0; i < sizeof(struct NormalStruct); i++) {
        printf("%02X ", normal_bytes[i]);
    }
    printf("\n");
    
    printf("  Packed struct bytes: ");
    unsigned char* packed_bytes = (unsigned char*)&packed;
    for (size_t i = 0; i < sizeof(struct PackedStruct); i++) {
        printf("%02X ", packed_bytes[i]);
    }
    printf("\n");
    
    printf("\nPacked Structure Considerations:\n");
    printf("  ✓ Saves memory space\n");
    printf("  ✓ Useful for network protocols and file formats\n");
    printf("  ✗ May cause performance penalties on some architectures\n");
    printf("  ✗ Unaligned access may be slower or cause faults\n");
    printf("  ✗ Compiler and platform specific\n");
    
    printf("\n");
}

/**
 * Demonstrates structure alignment analysis
 */
void demonstrate_structure_alignment(void) {
    printf("13. Structure Alignment Analysis\n");
    printf("================================\n");
    
    // Different structure layouts
    struct BadAlignment {
        char a;     // 1 byte + 3 bytes padding
        int b;      // 4 bytes
        char c;     // 1 byte + 7 bytes padding
        double d;   // 8 bytes
    };
    
    struct GoodAlignment {
        double d;   // 8 bytes (largest first)
        int b;      // 4 bytes
        char a;     // 1 byte
        char c;     // 1 byte + 2 bytes padding
    };
    
    struct BestAlignment {
        double d;   // 8 bytes
        int b;      // 4 bytes
        char a;     // 1 byte
        char c;     // 1 byte
        char e;     // 1 byte
        char f;     // 1 byte + 0 bytes padding
    };
    
    printf("Structure size comparison:\n");
    printf("  Bad alignment (char, int, char, double): %zu bytes\n", 
           sizeof(struct BadAlignment));
    printf("  Good alignment (double, int, char, char): %zu bytes\n", 
           sizeof(struct GoodAlignment));
    printf("  Best alignment (double, int, 4×char): %zu bytes\n", 
           sizeof(struct BestAlignment));
    
    printf("\nAlignment requirements:\n");
    printf("  char:   %zu-byte alignment\n", _Alignof(char));
    printf("  int:    %zu-byte alignment\n", _Alignof(int));
    printf("  double: %zu-byte alignment\n", _Alignof(double));
    
    printf("\nStructure alignment:\n");
    printf("  BadAlignment:  %zu-byte alignment\n", _Alignof(struct BadAlignment));
    printf("  GoodAlignment: %zu-byte alignment\n", _Alignof(struct GoodAlignment));
    printf("  BestAlignment: %zu-byte alignment\n", _Alignof(struct BestAlignment));
    
    // Show memory offsets
    printf("\nMember offsets in BadAlignment:\n");
    printf("  a: offset %zu\n", offsetof(struct BadAlignment, a));
    printf("  b: offset %zu\n", offsetof(struct BadAlignment, b));
    printf("  c: offset %zu\n", offsetof(struct BadAlignment, c));
    printf("  d: offset %zu\n", offsetof(struct BadAlignment, d));
    
    printf("\nMember offsets in GoodAlignment:\n");
    printf("  d: offset %zu\n", offsetof(struct GoodAlignment, d));
    printf("  b: offset %zu\n", offsetof(struct GoodAlignment, b));
    printf("  a: offset %zu\n", offsetof(struct GoodAlignment, a));
    printf("  c: offset %zu\n", offsetof(struct GoodAlignment, c));
    
    printf("\nAlignment Best Practices:\n");
    printf("  • Order members by size (largest first)\n");
    printf("  • Group small members together\n");
    printf("  • Use padding explicitly when needed\n");
    printf("  • Consider cache line size for performance\n");
    printf("  • Use tools to analyze structure layout\n");
    
    printf("\n");
}

/**
 * Demonstrates structure copying methods
 */
void demonstrate_structure_copying(void) {
    printf("14. Structure Copying\n");
    printf("=====================\n");
    
    // Create original structure
    struct Student original = {
        .id = 5001,
        .name = "Alice Cooper",
        .email = "alice.cooper@university.edu",
        .gpa = 3.9,
        .birth_date = {25, 12, 1999},
        .address = {
            .street = "789 University Blvd",
            .city = "College Town",
            .state = "NY",
            .zip_code = 10001
        },
        .course_count = 2
    };
    
    strcpy(original.courses[0], "Advanced Programming");
    strcpy(original.courses[1], "Data Structures");
    
    printf("Original student:\n");
    printf("  ID: %u, Name: %s, GPA: %.1f\n", 
           original.id, original.name, original.gpa);
    
    // Method 1: Assignment (shallow copy)
    printf("\nMethod 1: Assignment (shallow copy)\n");
    struct Student copy1 = original;
    
    printf("  Copy1 after assignment:\n");
    printf("    ID: %u, Name: %s, GPA: %.1f\n", 
           copy1.id, copy1.name, copy1.gpa);
    
    // Modify copy
    copy1.id = 5002;
    strcpy(copy1.name, "Bob Cooper");
    copy1.gpa = 3.7;
    
    printf("  After modifying copy1:\n");
    printf("    Original: ID=%u, Name=%s\n", original.id, original.name);
    printf("    Copy1:    ID=%u, Name=%s\n", copy1.id, copy1.name);
    
    // Method 2: memcpy
    printf("\nMethod 2: memcpy\n");
    struct Student copy2;
    memcpy(&copy2, &original, sizeof(struct Student));
    
    printf("  Copy2 via memcpy: ID=%u, Name=%s\n", copy2.id, copy2.name);
    
    // Method 3: Field-by-field copy (for complex structures)
    printf("\nMethod 3: Field-by-field copy\n");
    struct Student copy3;
    copy3.id = original.id;
    strcpy(copy3.name, original.name);
    strcpy(copy3.email, original.email);
    copy3.gpa = original.gpa;
    copy3.birth_date = original.birth_date;  // Nested struct assignment
    copy3.address = original.address;        // Nested struct assignment
    copy3.course_count = original.course_count;
    
    for (int i = 0; i < original.course_count; i++) {
        strcpy(copy3.courses[i], original.courses[i]);
    }
    
    printf("  Copy3 field-by-field: ID=%u, Name=%s\n", copy3.id, copy3.name);
    
    printf("\nStructure Copying Considerations:\n");
    printf("  • Assignment works for simple structures\n");
    printf("  • Pointers are copied by value (shallow copy)\n");
    printf("  • Deep copy required for dynamic memory\n");
    printf("  • memcpy is byte-wise copy (fast but not type-safe)\n");
    printf("  • Field-by-field copy gives most control\n");
    
    printf("\n");
}

/**
 * Demonstrates structure comparison methods
 */
void demonstrate_structure_comparison(void) {
    printf("15. Structure Comparison\n");
    printf("========================\n");
    
    struct Point p1 = {10.0, 20.0};
    struct Point p2 = {10.0, 20.0};
    struct Point p3 = {15.0, 25.0};
    
    printf("Comparing points:\n");
    printf("  p1: "); print_point(&p1);
    printf("  p2: "); print_point(&p2);
    printf("  p3: "); print_point(&p3);
    
    // Method 1: Field-by-field comparison
    printf("\nMethod 1: Field-by-field comparison\n");
    bool p1_eq_p2 = (p1.x == p2.x) && (p1.y == p2.y);
    bool p1_eq_p3 = (p1.x == p3.x) && (p1.y == p3.y);
    
    printf("  p1 == p2: %s\n", p1_eq_p2 ? "true" : "false");
    printf("  p1 == p3: %s\n", p1_eq_p3 ? "true" : "false");
    
    // Method 2: memcmp (careful with padding!)
    printf("\nMethod 2: memcmp (be careful with padding!)\n");
    int cmp_p1_p2 = memcmp(&p1, &p2, sizeof(struct Point));
    int cmp_p1_p3 = memcmp(&p1, &p3, sizeof(struct Point));
    
    printf("  memcmp(p1, p2): %d\n", cmp_p1_p2);
    printf("  memcmp(p1, p3): %d\n", cmp_p1_p3);
    
    // Demonstrate padding issue
    struct PaddedStruct {
        char a;
        int b;
    };
    
    printf("\nPadding issue demonstration:\n");
    struct PaddedStruct s1 = {1, 100};
    struct PaddedStruct s2 = {1, 100};
    
    // Manually modify padding bytes (undefined behavior in practice)
    unsigned char* s1_bytes = (unsigned char*)&s1;
    unsigned char* s2_bytes = (unsigned char*)&s2;
    
    printf("  Structures with same logical values:\n");
    printf("  s1: a=%d, b=%d\n", s1.a, s1.b);
    printf("  s2: a=%d, b=%d\n", s2.a, s2.b);
    
    printf("  Field-by-field equal: %s\n", 
           (s1.a == s2.a && s1.b == s2.b) ? "true" : "false");
    printf("  memcmp equal: %s\n", 
           (memcmp(&s1, &s2, sizeof(struct PaddedStruct)) == 0) ? "true" : "false");
    
    printf("\nComparison Best Practices:\n");
    printf("  • Use field-by-field comparison for reliable results\n");
    printf("  • memcmp can be unreliable due to padding bytes\n");
    printf("  • Write comparison functions for complex structures\n");
    printf("  • Consider floating-point precision in comparisons\n");
    printf("  • Zero-initialize structures to clear padding\n");
    
    printf("\n");
}

/**
 * Demonstrates basic structure serialization
 */
void demonstrate_structure_serialization(void) {
    printf("16. Structure Serialization\n");
    printf("===========================\n");
    
    printf("Serialization is converting structures to/from byte streams\n");
    printf("for storage or network transmission.\n\n");
    
    struct Point original = {123.45, 678.90};
    printf("Original point: "); print_point(&original);
    
    // Simple binary serialization (not portable)
    printf("\nBinary serialization (not portable):\n");
    unsigned char buffer[sizeof(struct Point)];
    memcpy(buffer, &original, sizeof(struct Point));
    
    printf("  Serialized bytes: ");
    for (size_t i = 0; i < sizeof(struct Point); i++) {
        printf("%02X ", buffer[i]);
    }
    printf("\n");
    
    // Deserialize
    struct Point deserialized;
    memcpy(&deserialized, buffer, sizeof(struct Point));
    printf("  Deserialized point: "); print_point(&deserialized);
    
    // Text-based serialization (portable)
    printf("\nText-based serialization (portable):\n");
    char text_buffer[256];
    snprintf(text_buffer, sizeof(text_buffer), 
             "POINT %.6f %.6f", original.x, original.y);
    printf("  Serialized text: %s\n", text_buffer);
    
    // Deserialize text
    struct Point from_text;
    if (sscanf(text_buffer, "POINT %lf %lf", &from_text.x, &from_text.y) == 2) {
        printf("  Deserialized from text: "); print_point(&from_text);
    }
    
    // JSON-like serialization
    printf("\nJSON-like serialization:\n");
    char json_buffer[512];
    snprintf(json_buffer, sizeof(json_buffer),
             "{\"x\":%.6f,\"y\":%.6f}", original.x, original.y);
    printf("  JSON representation: %s\n", json_buffer);
    
    printf("\nSerialization Considerations:\n");
    printf("  • Binary serialization is fast but not portable\n");
    printf("  • Text serialization is portable but larger\n");
    printf("  • Endianness affects binary portability\n");
    printf("  • Padding bytes should not be serialized\n");
    printf("  • Consider version compatibility\n");
    printf("  • Use standard formats (JSON, XML, Protocol Buffers)\n");
    
    printf("\n");
}

// Utility Function Implementations

struct Point create_point(double x, double y) {
    struct Point p = {x, y};
    return p;
}

struct Rectangle create_rectangle(struct Point tl, struct Point br) {
    struct Rectangle rect = {tl, br};
    return rect;
}

double calculate_distance(struct Point p1, struct Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

double calculate_area(struct Rectangle rect) {
    double width = rect.bottom_right.x - rect.top_left.x;
    double height = rect.top_left.y - rect.bottom_right.y;
    return width * height;
}

void print_point(const struct Point* p) {
    printf("(%.2f, %.2f)\n", p->x, p->y);
}

void print_rectangle(const struct Rectangle* rect) {
    printf("  Top-left: "); print_point(&rect->top_left);
    printf("  Bottom-right: "); print_point(&rect->bottom_right);
}

void print_student(const struct Student* student) {
    printf("Student Information:\n");
    printf("  ID: %u\n", student->id);
    printf("  Name: %s\n", student->name);
    printf("  Email: %s\n", student->email);
    printf("  GPA: %.2f\n", student->gpa);
    printf("  Birth Date: %d/%d/%d\n", 
           student->birth_date.month, student->birth_date.day, student->birth_date.year);
    printf("  Address: %s, %s, %s %d\n",
           student->address.street, student->address.city, 
           student->address.state, student->address.zip_code);
    printf("  Courses (%d):\n", student->course_count);
    for (int i = 0; i < student->course_count; i++) {
        printf("    %d. %s\n", i + 1, student->courses[i]);
    }
}

struct Node* create_node(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    if (node) {
        node->data = data;
        node->next = NULL;
        node->prev = NULL;
    }
    return node;
}

void insert_node(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    if (!new_node) return;
    
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}

void print_list(const struct Node* head) {
    printf("  ");
    const struct Node* current = head;
    while (current) {
        printf("%d", current->data);
        if (current->next) printf(" -> ");
        current = current->next;
    }
    printf("\n");
}

void free_list(struct Node* head) {
    while (head) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

// Calculator functions
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { return b != 0.0 ? a / b : 0.0; }

// Variant functions
struct Variant create_int_variant(int value) {
    struct Variant var = {TYPE_INT, .data.int_value = value};
    return var;
}

struct Variant create_float_variant(float value) {
    struct Variant var = {TYPE_FLOAT, .data.float_value = value};
    return var;
}

struct Variant create_string_variant(const char* value) {
    struct Variant var = {TYPE_STRING};
    var.data.string_value = malloc(strlen(value) + 1);
    if (var.data.string_value) {
        strcpy(var.data.string_value, value);
    }
    return var;
}

struct Variant create_bool_variant(bool value) {
    struct Variant var = {TYPE_BOOL, .data.bool_value = value};
    return var;
}

void print_variant(const struct Variant* var) {
    switch (var->type) {
        case TYPE_INT:
            printf("int(%d)", var->data.int_value);
            break;
        case TYPE_FLOAT:
            printf("float(%.2f)", var->data.float_value);
            break;
        case TYPE_STRING:
            printf("string(\"%s\")", var->data.string_value ? var->data.string_value : "NULL");
            break;
        case TYPE_BOOL:
            printf("bool(%s)", var->data.bool_value ? "true" : "false");
            break;
        default:
            printf("unknown_type");
    }
    printf("\n");
}

void free_variant(struct Variant* var) {
    if (var->type == TYPE_STRING && var->data.string_value) {
        free(var->data.string_value);
        var->data.string_value = NULL;
    }
}

// Dynamic array functions
struct DynamicArray* create_dynamic_array(size_t initial_capacity) {
    struct DynamicArray* arr = malloc(sizeof(struct DynamicArray) + 
                                      initial_capacity * sizeof(int));
    if (arr) {
        arr->size = 0;
        arr->capacity = initial_capacity;
    }
    return arr;
}

void dynamic_array_push(struct DynamicArray** arr, int value) {
    if (!arr || !*arr) return;
    
    if ((*arr)->size >= (*arr)->capacity) {
        // Need to reallocate
        size_t new_capacity = (*arr)->capacity * 2;
        struct DynamicArray* new_arr = realloc(*arr, sizeof(struct DynamicArray) + 
                                               new_capacity * sizeof(int));
        if (new_arr) {
            new_arr->capacity = new_capacity;
            *arr = new_arr;
        } else {
            return;  // Reallocation failed
        }
    }
    
    (*arr)->elements[(*arr)->size++] = value;
}

void print_dynamic_array(const struct DynamicArray* arr) {
    if (!arr) return;
    
    printf("  Array (size=%zu, capacity=%zu): [", arr->size, arr->capacity);
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d", arr->elements[i]);
        if (i < arr->size - 1) printf(", ");
    }
    printf("]\n");
}

void free_dynamic_array(struct DynamicArray* arr) {
    free(arr);
}