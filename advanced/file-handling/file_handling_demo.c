/**
 * File Handling - Comprehensive C Implementation
 * 
 * This program demonstrates:
 * - Basic file operations (open, read, write, close)
 * - Different file modes and access patterns
 * - Text file processing (character, line, formatted I/O)
 * - Binary file operations
 * - File positioning and seeking
 * - Directory operations
 * - Error handling and file status checking
 * - Advanced file operations and buffering
 * - File copying and manipulation utilities
 * 
 * @author Bishal Goutam
 * @since C99 Standard
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>

#ifdef _WIN32
    #include <direct.h>
    #include <io.h>
    #define MKDIR(path) _mkdir(path)
    #define ACCESS(path, mode) _access(path, mode)
#else
    #include <unistd.h>
    #include <dirent.h>
    #define MKDIR(path) mkdir(path, 0755)
    #define ACCESS(path, mode) access(path, mode)
#endif

#define MAX_LINE_LENGTH 1000
#define MAX_FILENAME 256
#define BUFFER_SIZE 8192

// Structure for student record (binary file example)
typedef struct {
    int id;
    char name[50];
    float grade;
    char course[30];
} Student;

// Structure for file statistics
typedef struct {
    long size;
    int lines;
    int words;
    int characters;
} FileStats;

// Function prototypes - Basic file operations
void demonstrate_basic_file_operations(void);
void demonstrate_text_file_operations(void);
void demonstrate_binary_file_operations(void);
void demonstrate_file_positioning(void);
void demonstrate_error_handling(void);

// Function prototypes - Advanced operations
void demonstrate_directory_operations(void);
void demonstrate_file_utilities(void);
void demonstrate_buffering_modes(void);
void demonstrate_temporary_files(void);

// Function prototypes - File processing utilities
bool file_exists(const char* filename);
bool create_file(const char* filename, const char* content);
bool copy_file(const char* source, const char* destination);
bool append_to_file(const char* filename, const char* content);
FileStats get_file_statistics(const char* filename);
void print_file_info(const char* filename);

// Function prototypes - Text processing
int count_lines_in_file(const char* filename);
int count_words_in_file(const char* filename);
bool search_in_file(const char* filename, const char* search_term);
void replace_in_file(const char* filename, const char* old_str, const char* new_str);
void reverse_file_content(const char* input_file, const char* output_file);

// Function prototypes - Binary file operations
void write_student_records(const char* filename, Student students[], int count);
void read_student_records(const char* filename);
void update_student_record(const char* filename, int student_id, float new_grade);
void display_student_record(const char* filename, int student_id);

// Demo functions
void demonstrate_file_modes(void);
void demonstrate_formatted_io(void);
void demonstrate_character_io(void);
void demonstrate_line_io(void);

int main(void) {
    printf("=== C File Handling Demo ===\n\n");
    
    // Create test directory if it doesn't exist
    MKDIR("test_files");
    
    demonstrate_basic_file_operations();
    demonstrate_text_file_operations();
    demonstrate_binary_file_operations();
    demonstrate_file_positioning();
    demonstrate_error_handling();
    demonstrate_directory_operations();
    demonstrate_file_utilities();
    demonstrate_buffering_modes();
    demonstrate_temporary_files();
    
    printf("Demo completed. Check the 'test_files' directory for created files.\n");
    return 0;
}

/**
 * Demonstrates basic file operations
 */
void demonstrate_basic_file_operations(void) {
    printf("1. Basic File Operations\n");
    printf("========================\n");
    
    const char* filename = "test_files/basic_example.txt";
    
    printf("File Operations Overview:\n");
    printf("  • fopen()  - Open a file with specified mode\n");
    printf("  • fclose() - Close an opened file\n");
    printf("  • fread()  - Read data from file\n");
    printf("  • fwrite() - Write data to file\n");
    printf("  • fprintf()- Write formatted data to file\n");
    printf("  • fscanf() - Read formatted data from file\n\n");
    
    // Writing to file
    printf("Writing to file '%s':\n", filename);
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing\n");
        return;
    }
    
    fprintf(file, "Hello, File I/O World!\n");
    fprintf(file, "This is line 2\n");
    fprintf(file, "Numbers: %d, %.2f\n", 42, 3.14159);
    fprintf(file, "Current time: %ld\n", time(NULL));
    
    fclose(file);
    printf("  ✓ File written successfully\n");
    
    // Reading from file
    printf("\nReading from file '%s':\n", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading\n");
        return;
    }
    
    char buffer[MAX_LINE_LENGTH];
    int line_number = 1;
    
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("  Line %d: %s", line_number++, buffer);
    }
    
    fclose(file);
    printf("\n");
    
    // File statistics
    FileStats stats = get_file_statistics(filename);
    printf("File Statistics:\n");
    printf("  Size: %ld bytes\n", stats.size);
    printf("  Lines: %d\n", stats.lines);
    printf("  Words: %d\n", stats.words);
    printf("  Characters: %d\n\n", stats.characters);
}

/**
 * Demonstrates different file modes
 */
void demonstrate_file_modes(void) {
    printf("2. File Modes and Access Patterns\n");
    printf("==================================\n");
    
    printf("File Opening Modes:\n");
    printf("  Text Modes:\n");
    printf("    'r'  - Read only (file must exist)\n");
    printf("    'w'  - Write only (creates new or truncates existing)\n");
    printf("    'a'  - Append (creates new or appends to existing)\n");
    printf("    'r+' - Read and write (file must exist)\n");
    printf("    'w+' - Read and write (creates new or truncates existing)\n");
    printf("    'a+' - Read and append (creates new or appends to existing)\n\n");
    
    printf("  Binary Modes (add 'b' to any above):\n");
    printf("    'rb', 'wb', 'ab', 'r+b', 'w+b', 'a+b'\n\n");
    
    const char* test_file = "test_files/modes_test.txt";
    
    // Write mode
    printf("Testing 'w' mode (write):\n");
    FILE* file = fopen(test_file, "w");
    if (file) {
        fprintf(file, "Original content\n");
        fclose(file);
        printf("  ✓ File created with original content\n");
    }
    
    // Append mode
    printf("\nTesting 'a' mode (append):\n");
    file = fopen(test_file, "a");
    if (file) {
        fprintf(file, "Appended content\n");
        fclose(file);
        printf("  ✓ Content appended to file\n");
    }
    
    // Read mode
    printf("\nTesting 'r' mode (read):\n");
    file = fopen(test_file, "r");
    if (file) {
        char buffer[MAX_LINE_LENGTH];
        printf("  File contents:\n");
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("    %s", buffer);
        }
        fclose(file);
    }
    
    // r+ mode (read and write)
    printf("\nTesting 'r+' mode (read and write):\n");
    file = fopen(test_file, "r+");
    if (file) {
        // Read current content
        fseek(file, 0, SEEK_END);
        long size = ftell(file);
        printf("  Current file size: %ld bytes\n", size);
        
        // Append using r+ mode
        fprintf(file, "Added via r+ mode\n");
        fclose(file);
        printf("  ✓ Content added using r+ mode\n");
    }
    
    printf("\n");
}

/**
 * Demonstrates text file operations
 */
void demonstrate_text_file_operations(void) {
    printf("3. Text File Operations\n");
    printf("=======================\n");
    
    demonstrate_character_io();
    demonstrate_line_io();
    demonstrate_formatted_io();
}

/**
 * Demonstrates character-level I/O
 */
void demonstrate_character_io(void) {
    printf("Character I/O Operations:\n");
    
    const char* char_file = "test_files/character_io.txt";
    
    // Writing characters
    printf("  Writing characters to file...\n");
    FILE* file = fopen(char_file, "w");
    if (file) {
        char message[] = "Hello, Character I/O!";
        for (int i = 0; message[i] != '\0'; i++) {
            fputc(message[i], file);
        }
        fputc('\n', file);
        fclose(file);
    }
    
    // Reading characters
    printf("  Reading characters from file:\n    ");
    file = fopen(char_file, "r");
    if (file) {
        int ch;
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
        fclose(file);
    }
    
    // Character statistics
    printf("  Character analysis:\n");
    file = fopen(char_file, "r");
    if (file) {
        int ch, char_count = 0, letter_count = 0, digit_count = 0;
        
        while ((ch = fgetc(file)) != EOF) {
            char_count++;
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                letter_count++;
            } else if (ch >= '0' && ch <= '9') {
                digit_count++;
            }
        }
        
        printf("    Total characters: %d\n", char_count);
        printf("    Letters: %d\n", letter_count);
        printf("    Digits: %d\n", digit_count);
        printf("    Other characters: %d\n", char_count - letter_count - digit_count);
        
        fclose(file);
    }
    
    printf("\n");
}

/**
 * Demonstrates line-level I/O
 */
void demonstrate_line_io(void) {
    printf("Line I/O Operations:\n");
    
    const char* line_file = "test_files/line_io.txt";
    
    // Writing lines
    printf("  Writing lines to file...\n");
    FILE* file = fopen(line_file, "w");
    if (file) {
        fputs("First line of text\n", file);
        fputs("Second line with numbers: 123\n", file);
        fputs("Third line with symbols: @#$%\n", file);
        fputs("Last line\n", file);
        fclose(file);
    }
    
    // Reading lines
    printf("  Reading lines from file:\n");
    file = fopen(line_file, "r");
    if (file) {
        char buffer[MAX_LINE_LENGTH];
        int line_num = 1;
        
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("    Line %d: %s", line_num++, buffer);
        }
        fclose(file);
    }
    
    // Line processing
    printf("  Line processing results:\n");
    int total_lines = count_lines_in_file(line_file);
    printf("    Total lines: %d\n", total_lines);
    
    bool found = search_in_file(line_file, "numbers");
    printf("    Contains 'numbers': %s\n", found ? "Yes" : "No");
    
    printf("\n");
}

/**
 * Demonstrates formatted I/O
 */
void demonstrate_formatted_io(void) {
    printf("Formatted I/O Operations:\n");
    
    const char* formatted_file = "test_files/formatted_io.txt";
    
    // Writing formatted data
    printf("  Writing formatted data to file...\n");
    FILE* file = fopen(formatted_file, "w");
    if (file) {
        fprintf(file, "Student Records:\n");
        fprintf(file, "ID: %d, Name: %s, Grade: %.2f\n", 1001, "John Doe", 85.5);
        fprintf(file, "ID: %d, Name: %s, Grade: %.2f\n", 1002, "Jane Smith", 92.0);
        fprintf(file, "ID: %d, Name: %s, Grade: %.2f\n", 1003, "Bob Johnson", 78.5);
        fprintf(file, "Average: %.2f\n", (85.5 + 92.0 + 78.5) / 3);
        fclose(file);
    }
    
    // Reading formatted data
    printf("  Reading formatted data from file:\n");
    file = fopen(formatted_file, "r");
    if (file) {
        char line[MAX_LINE_LENGTH];
        
        // Skip header
        fgets(line, sizeof(line), file);
        printf("    %s", line);
        
        // Read student records
        int id;
        char name[50];
        float grade;
        
        while (fscanf(file, "ID: %d, Name: %49[^,], Grade: %f\n", &id, name, &grade) == 3) {
            printf("    Student %d: %s (%.1f%%)\n", id, name, grade);
        }
        
        fclose(file);
    }
    
    printf("\n");
}

/**
 * Demonstrates binary file operations
 */
void demonstrate_binary_file_operations(void) {
    printf("4. Binary File Operations\n");
    printf("=========================\n");
    
    // Create sample student data
    Student students[] = {
        {1001, "Alice Johnson", 87.5, "Computer Science"},
        {1002, "Bob Smith", 92.0, "Mathematics"},
        {1003, "Carol Davis", 78.5, "Physics"},
        {1004, "David Wilson", 85.0, "Chemistry"},
        {1005, "Eve Brown", 94.5, "Biology"}
    };
    int student_count = sizeof(students) / sizeof(students[0]);
    
    const char* binary_file = "test_files/students.dat";
    
    printf("Binary vs Text Files:\n");
    printf("  • Binary files store data in its native format\n");
    printf("  • More space-efficient for structured data\n");
    printf("  • Faster read/write operations\n");
    printf("  • Platform-dependent (endianness)\n");
    printf("  • Not human-readable\n\n");
    
    // Write binary data
    printf("Writing student records to binary file...\n");
    write_student_records(binary_file, students, student_count);
    
    // Read binary data
    printf("\nReading student records from binary file:\n");
    read_student_records(binary_file);
    
    // Update a record
    printf("\nUpdating student ID 1003's grade to 82.0...\n");
    update_student_record(binary_file, 1003, 82.0);
    
    // Display specific record
    printf("\nDisplaying updated record:\n");
    display_student_record(binary_file, 1003);
    
    // File size comparison
    printf("\nFile size analysis:\n");
    struct stat st;
    if (stat(binary_file, &st) == 0) {
        printf("  Binary file size: %ld bytes\n", st.st_size);
        printf("  Records stored: %d\n", student_count);
        printf("  Bytes per record: %ld\n", st.st_size / student_count);
        printf("  Struct size: %lu bytes\n", sizeof(Student));
    }
    
    printf("\n");
}

/**
 * Demonstrates file positioning and seeking
 */
void demonstrate_file_positioning(void) {
    printf("5. File Positioning and Seeking\n");
    printf("===============================\n");
    
    const char* position_file = "test_files/positioning.txt";
    
    // Create test file
    FILE* file = fopen(position_file, "w");
    if (file) {
        fprintf(file, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
        fprintf(file, "Line 2: Hello World\n");
        fprintf(file, "Line 3: File positioning demo\n");
        fclose(file);
    }
    
    printf("File Positioning Functions:\n");
    printf("  • fseek()  - Set file position\n");
    printf("  • ftell()  - Get current position\n");
    printf("  • rewind() - Reset to beginning\n");
    printf("  • fgetpos()/fsetpos() - Position with fpos_t\n\n");
    
    file = fopen(position_file, "r");
    if (file) {
        // Get file size
        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        printf("File size: %ld bytes\n", file_size);
        
        // Read from beginning
        rewind(file);
        printf("Position after rewind: %ld\n", ftell(file));
        
        char buffer[20];
        fread(buffer, 1, 10, file);
        buffer[10] = '\0';
        printf("First 10 characters: '%s'\n", buffer);
        printf("Current position: %ld\n", ftell(file));
        
        // Seek to middle
        fseek(file, file_size / 2, SEEK_SET);
        printf("Position after seeking to middle: %ld\n", ftell(file));
        
        fread(buffer, 1, 10, file);
        buffer[10] = '\0';
        printf("10 characters from middle: '%s'\n", buffer);
        
        // Seek relative to current position
        fseek(file, -5, SEEK_CUR);
        printf("Position after seeking back 5: %ld\n", ftell(file));
        
        // Seek from end
        fseek(file, -10, SEEK_END);
        printf("Position after seeking from end: %ld\n", ftell(file));
        
        fread(buffer, 1, 10, file);
        buffer[10] = '\0';
        printf("Last 10 characters: '%s'\n", buffer);
        
        fclose(file);
    }
    
    printf("\n");
}

/**
 * Demonstrates error handling in file operations
 */
void demonstrate_error_handling(void) {
    printf("6. Error Handling\n");
    printf("=================\n");
    
    printf("File Error Handling Techniques:\n");
    printf("  • Check return values of file functions\n");
    printf("  • Use errno for detailed error information\n");
    printf("  • Use perror() for error messages\n");
    printf("  • Always close files properly\n");
    printf("  • Validate file pointers before use\n\n");
    
    // Attempt to open non-existent file
    printf("Attempting to open non-existent file:\n");
    FILE* file = fopen("test_files/nonexistent.txt", "r");
    if (file == NULL) {
        printf("  ✗ fopen() failed\n");
        printf("  Error number: %d\n", errno);
        printf("  Error message: %s\n", strerror(errno));
        perror("  perror() output");
    } else {
        fclose(file);
    }
    
    // Attempt to write to read-only file
    printf("\nAttempting to write to read-only file:\n");
    const char* readonly_file = "test_files/readonly_test.txt";
    
    // Create file first
    file = fopen(readonly_file, "w");
    if (file) {
        fprintf(file, "Read-only content\n");
        fclose(file);
    }
    
    // Try to open for writing (this should work, but demonstrates the concept)
    file = fopen(readonly_file, "r");
    if (file) {
        printf("  ✓ Successfully opened for reading\n");
        
        // Try to write (this will fail)
        int result = fprintf(file, "This should fail");
        if (result < 0) {
            printf("  ✗ Write operation failed\n");
            printf("  Error: %s\n", strerror(errno));
        }
        
        fclose(file);
    }
    
    // Check file existence
    printf("\nChecking file existence:\n");
    const char* test_files[] = {
        "test_files/basic_example.txt",
        "test_files/nonexistent.txt",
        "test_files/students.dat"
    };
    
    for (int i = 0; i < 3; i++) {
        bool exists = file_exists(test_files[i]);
        printf("  %s: %s\n", test_files[i], exists ? "EXISTS" : "NOT FOUND");
    }
    
    printf("\n");
}

/**
 * Demonstrates directory operations
 */
void demonstrate_directory_operations(void) {
    printf("7. Directory Operations\n");
    printf("=======================\n");
    
    printf("Directory Operation Functions:\n");
#ifdef _WIN32
    printf("  Windows: _mkdir(), _rmdir(), _getcwd()\n");
#else
    printf("  Unix/Linux: mkdir(), rmdir(), getcwd(), opendir(), readdir()\n");
#endif
    printf("  Portable: Use conditional compilation for cross-platform code\n\n");
    
    // Create nested directories
    printf("Creating directory structure:\n");
    const char* dirs[] = {
        "test_files/documents",
        "test_files/documents/projects",
        "test_files/documents/backups"
    };
    
    for (int i = 0; i < 3; i++) {
        if (MKDIR(dirs[i]) == 0 || errno == EEXIST) {
            printf("  ✓ Directory created/exists: %s\n", dirs[i]);
        } else {
            printf("  ✗ Failed to create directory: %s (%s)\n", dirs[i], strerror(errno));
        }
    }
    
    // Create files in directories
    printf("\nCreating files in directories:\n");
    const char* files[] = {
        "test_files/documents/readme.txt",
        "test_files/documents/projects/project1.txt",
        "test_files/documents/backups/backup.txt"
    };
    
    for (int i = 0; i < 3; i++) {
        if (create_file(files[i], "Sample content\n")) {
            printf("  ✓ File created: %s\n", files[i]);
        } else {
            printf("  ✗ Failed to create file: %s\n", files[i]);
        }
    }
    
    // Check file and directory information
    printf("\nFile and directory information:\n");
    for (int i = 0; i < 3; i++) {
        print_file_info(files[i]);
    }
    
    printf("\n");
}

/**
 * Demonstrates file utility functions
 */
void demonstrate_file_utilities(void) {
    printf("8. File Utilities\n");
    printf("=================\n");
    
    const char* source_file = "test_files/source.txt";
    const char* copy_file_name = "test_files/copy.txt";
    const char* search_file = "test_files/search_demo.txt";
    
    // Create source file
    printf("Creating source file with sample content...\n");
    create_file(source_file, 
        "The quick brown fox jumps over the lazy dog.\n"
        "This is a sample text file for demonstration.\n"
        "It contains multiple lines of text.\n"
        "We can search, copy, and manipulate this file.\n"
        "Programming in C is fun and educational.\n");
    
    // File copying
    printf("\nTesting file copy utility:\n");
    if (copy_file(source_file, copy_file_name)) {
        printf("  ✓ File copied successfully\n");
        
        FileStats source_stats = get_file_statistics(source_file);
        FileStats copy_stats = get_file_statistics(copy_file_name);
        
        printf("  Source file size: %ld bytes\n", source_stats.size);
        printf("  Copy file size: %ld bytes\n", copy_stats.size);
        printf("  Files match: %s\n", (source_stats.size == copy_stats.size) ? "Yes" : "No");
    }
    
    // File statistics
    printf("\nFile statistics:\n");
    FileStats stats = get_file_statistics(source_file);
    printf("  Lines: %d\n", stats.lines);
    printf("  Words: %d\n", stats.words);
    printf("  Characters: %d\n", stats.characters);
    printf("  Size: %ld bytes\n", stats.size);
    
    // Search functionality
    printf("\nTesting search functionality:\n");
    const char* search_terms[] = {"fox", "programming", "xyz", "text"};
    for (int i = 0; i < 4; i++) {
        bool found = search_in_file(source_file, search_terms[i]);
        printf("  Search for '%s': %s\n", search_terms[i], found ? "FOUND" : "NOT FOUND");
    }
    
    // File manipulation
    printf("\nTesting file manipulation:\n");
    
    // Append content
    if (append_to_file(source_file, "This line was appended.\n")) {
        printf("  ✓ Content appended\n");
    }
    
    // Create replacement demo
    create_file(search_file, "Hello world! This is a world of possibilities.\n");
    printf("  Original content: ");
    FILE* file = fopen(search_file, "r");
    if (file) {
        char buffer[MAX_LINE_LENGTH];
        if (fgets(buffer, sizeof(buffer), file)) {
            printf("%s", buffer);
        }
        fclose(file);
    }
    
    // Replace text
    replace_in_file(search_file, "world", "universe");
    printf("  After replacement: ");
    file = fopen(search_file, "r");
    if (file) {
        char buffer[MAX_LINE_LENGTH];
        if (fgets(buffer, sizeof(buffer), file)) {
            printf("%s", buffer);
        }
        fclose(file);
    }
    
    // Reverse content
    const char* reverse_file = "test_files/reversed.txt";
    reverse_file_content(source_file, reverse_file);
    printf("  ✓ File content reversed and saved to %s\n", reverse_file);
    
    printf("\n");
}

/**
 * Demonstrates buffering modes
 */
void demonstrate_buffering_modes(void) {
    printf("9. Buffering Modes\n");
    printf("==================\n");
    
    printf("Buffering Types:\n");
    printf("  • _IOFBF (Full buffering): Data written when buffer is full\n");
    printf("  • _IOLBF (Line buffering): Data written when newline encountered\n");
    printf("  • _IONBF (No buffering): Data written immediately\n\n");
    
    const char* buffer_file = "test_files/buffering_test.txt";
    
    // Test different buffering modes
    printf("Testing buffering modes:\n");
    
    // Full buffering
    FILE* file = fopen(buffer_file, "w");
    if (file) {
        setvbuf(file, NULL, _IOFBF, BUFFER_SIZE);
        printf("  Full buffering mode set\n");
        
        for (int i = 0; i < 5; i++) {
            fprintf(file, "Line %d with full buffering\n", i + 1);
        }
        
        printf("  Data written to buffer (not yet to disk)\n");
        fflush(file); // Force write
        printf("  Buffer flushed - data now on disk\n");
        fclose(file);
    }
    
    // No buffering
    file = fopen(buffer_file, "a");
    if (file) {
        setvbuf(file, NULL, _IONBF, 0);
        printf("  No buffering mode set\n");
        
        fprintf(file, "Unbuffered line - written immediately\n");
        printf("  Data written immediately to disk\n");
        fclose(file);
    }
    
    // Custom buffer
    char custom_buffer[1024];
    file = fopen(buffer_file, "a");
    if (file) {
        setvbuf(file, custom_buffer, _IOFBF, sizeof(custom_buffer));
        printf("  Custom buffer set (1024 bytes)\n");
        
        fprintf(file, "Using custom buffer\n");
        fclose(file);
    }
    
    printf("\n");
}

/**
 * Demonstrates temporary file operations
 */
void demonstrate_temporary_files(void) {
    printf("10. Temporary Files\n");
    printf("===================\n");
    
    printf("Temporary File Functions:\n");
    printf("  • tmpfile() - Creates temporary file that's automatically deleted\n");
    printf("  • tmpnam()  - Generates unique temporary filename\n");
    printf("  • mktemp()  - Creates temporary filename (deprecated)\n\n");
    
    // Using tmpfile()
    printf("Using tmpfile():\n");
    FILE* temp_file = tmpfile();
    if (temp_file) {
        printf("  ✓ Temporary file created\n");
        
        // Write to temporary file
        fprintf(temp_file, "This is temporary data\n");
        fprintf(temp_file, "It will be automatically deleted\n");
        
        // Read back
        rewind(temp_file);
        char buffer[MAX_LINE_LENGTH];
        printf("  Content written to temporary file:\n");
        while (fgets(buffer, sizeof(buffer), temp_file)) {
            printf("    %s", buffer);
        }
        
        fclose(temp_file); // File is automatically deleted
        printf("  ✓ Temporary file closed and deleted\n");
    }
    
    // Using tmpnam()
    printf("\nUsing tmpnam():\n");
    char temp_name[L_tmpnam];
    if (tmpnam(temp_name)) {
        printf("  Generated temporary filename: %s\n", temp_name);
        
        // Create and use the temporary file
        FILE* named_temp = fopen(temp_name, "w+");
        if (named_temp) {
            fprintf(named_temp, "Named temporary file content\n");
            
            rewind(named_temp);
            char buffer[MAX_LINE_LENGTH];
            if (fgets(buffer, sizeof(buffer), named_temp)) {
                printf("  Content: %s", buffer);
            }
            
            fclose(named_temp);
            
            // Manual cleanup required
            if (remove(temp_name) == 0) {
                printf("  ✓ Temporary file manually deleted\n");
            }
        }
    }
    
    printf("\nBest Practices for Temporary Files:\n");
    printf("  • Use tmpfile() when possible (automatic cleanup)\n");
    printf("  • Always clean up named temporary files\n");
    printf("  • Use secure temporary directories\n");
    printf("  • Set appropriate permissions\n");
    printf("  • Handle errors gracefully\n\n");
}

// Utility Function Implementations

bool file_exists(const char* filename) {
    return ACCESS(filename, 0) == 0;
}

bool create_file(const char* filename, const char* content) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        return false;
    }
    
    if (content) {
        fputs(content, file);
    }
    
    fclose(file);
    return true;
}

bool copy_file(const char* source, const char* destination) {
    FILE* src = fopen(source, "rb");
    if (src == NULL) {
        return false;
    }
    
    FILE* dest = fopen(destination, "wb");
    if (dest == NULL) {
        fclose(src);
        return false;
    }
    
    char buffer[BUFFER_SIZE];
    size_t bytes;
    
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        if (fwrite(buffer, 1, bytes, dest) != bytes) {
            fclose(src);
            fclose(dest);
            return false;
        }
    }
    
    fclose(src);
    fclose(dest);
    return true;
}

bool append_to_file(const char* filename, const char* content) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        return false;
    }
    
    fputs(content, file);
    fclose(file);
    return true;
}

FileStats get_file_statistics(const char* filename) {
    FileStats stats = {0, 0, 0, 0};
    
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return stats;
    }
    
    // Get file size
    fseek(file, 0, SEEK_END);
    stats.size = ftell(file);
    rewind(file);
    
    // Count lines, words, and characters
    int ch, in_word = 0;
    
    while ((ch = fgetc(file)) != EOF) {
        stats.characters++;
        
        if (ch == '\n') {
            stats.lines++;
        }
        
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            stats.words++;
        }
    }
    
    // If file doesn't end with newline, count the last line
    if (stats.characters > 0 && ch != '\n') {
        stats.lines++;
    }
    
    fclose(file);
    return stats;
}

void print_file_info(const char* filename) {
    struct stat file_stat;
    
    if (stat(filename, &file_stat) == 0) {
        printf("  %s:\n", filename);
        printf("    Size: %ld bytes\n", file_stat.st_size);
        printf("    Modified: %s", ctime(&file_stat.st_mtime));
        printf("    Permissions: %o\n", file_stat.st_mode & 0777);
    } else {
        printf("  %s: Unable to get file information\n", filename);
    }
}

int count_lines_in_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }
    
    int lines = 0;
    int ch;
    
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
    }
    
    fclose(file);
    return lines;
}

int count_words_in_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }
    
    int words = 0;
    int in_word = 0;
    int ch;
    
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }
    
    fclose(file);
    return words;
}

bool search_in_file(const char* filename, const char* search_term) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return false;
    }
    
    char buffer[MAX_LINE_LENGTH];
    bool found = false;
    
    while (fgets(buffer, sizeof(buffer), file) && !found) {
        if (strstr(buffer, search_term) != NULL) {
            found = true;
        }
    }
    
    fclose(file);
    return found;
}

void replace_in_file(const char* filename, const char* old_str, const char* new_str) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return;
    }
    
    // Read entire file
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    
    char* content = malloc(file_size + 1);
    if (content == NULL) {
        fclose(file);
        return;
    }
    
    fread(content, 1, file_size, file);
    content[file_size] = '\0';
    fclose(file);
    
    // Perform replacement (simple version)
    char* pos = strstr(content, old_str);
    if (pos != NULL) {
        // Create new content with replacement
        size_t old_len = strlen(old_str);
        size_t new_len = strlen(new_str);
        size_t prefix_len = pos - content;
        size_t suffix_len = strlen(pos + old_len);
        
        char* new_content = malloc(prefix_len + new_len + suffix_len + 1);
        if (new_content != NULL) {
            strncpy(new_content, content, prefix_len);
            strcpy(new_content + prefix_len, new_str);
            strcpy(new_content + prefix_len + new_len, pos + old_len);
            
            // Write back to file
            file = fopen(filename, "w");
            if (file != NULL) {
                fputs(new_content, file);
                fclose(file);
            }
            
            free(new_content);
        }
    }
    
    free(content);
}

void reverse_file_content(const char* input_file, const char* output_file) {
    FILE* input = fopen(input_file, "r");
    if (input == NULL) {
        return;
    }
    
    // Read all lines
    char lines[1000][MAX_LINE_LENGTH];
    int line_count = 0;
    
    while (fgets(lines[line_count], MAX_LINE_LENGTH, input) && line_count < 1000) {
        line_count++;
    }
    fclose(input);
    
    // Write in reverse order
    FILE* output = fopen(output_file, "w");
    if (output != NULL) {
        for (int i = line_count - 1; i >= 0; i--) {
            fputs(lines[i], output);
        }
        fclose(output);
    }
}

// Binary File Operations

void write_student_records(const char* filename, Student students[], int count) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Could not open file for writing\n");
        return;
    }
    
    size_t written = fwrite(students, sizeof(Student), count, file);
    printf("  ✓ Written %zu student records\n", written);
    
    fclose(file);
}

void read_student_records(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file for reading\n");
        return;
    }
    
    Student student;
    int count = 0;
    
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        printf("  Student %d: ID=%d, Name=%s, Grade=%.1f, Course=%s\n",
               ++count, student.id, student.name, student.grade, student.course);
    }
    
    fclose(file);
}

void update_student_record(const char* filename, int student_id, float new_grade) {
    FILE* file = fopen(filename, "r+b");
    if (file == NULL) {
        printf("Error: Could not open file for updating\n");
        return;
    }
    
    Student student;
    bool found = false;
    
    while (fread(&student, sizeof(Student), 1, file) == 1 && !found) {
        if (student.id == student_id) {
            student.grade = new_grade;
            
            // Seek back to overwrite the record
            fseek(file, -sizeof(Student), SEEK_CUR);
            fwrite(&student, sizeof(Student), 1, file);
            found = true;
            printf("  ✓ Updated student ID %d\n", student_id);
        }
    }
    
    if (!found) {
        printf("  ✗ Student ID %d not found\n", student_id);
    }
    
    fclose(file);
}

void display_student_record(const char* filename, int student_id) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file for reading\n");
        return;
    }
    
    Student student;
    bool found = false;
    
    while (fread(&student, sizeof(Student), 1, file) == 1 && !found) {
        if (student.id == student_id) {
            printf("  ID: %d\n", student.id);
            printf("  Name: %s\n", student.name);
            printf("  Grade: %.1f\n", student.grade);
            printf("  Course: %s\n", student.course);
            found = true;
        }
    }
    
    if (!found) {
        printf("  Student ID %d not found\n", student_id);
    }
    
    fclose(file);
}