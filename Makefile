# Makefile for C Programs Repository
# Author: Bishal Goutam
# Purpose: Compile and manage C programs with proper flags and organization

# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Wpedantic -g -O2
LDFLAGS = 
INCLUDES = -I.

# Directories
SRC_DIR = .
BUILD_DIR = build
BIN_DIR = bin

# Create directories if they don't exist
$(shell mkdir -p $(BUILD_DIR) $(BIN_DIR))

# Source files (find all .c files recursively)
SOURCES = $(shell find $(SRC_DIR) -name "*.c" -type f)
EXECUTABLES = $(SOURCES:%.c=$(BIN_DIR)/%)

# Default target
all: $(EXECUTABLES)

# Rule to compile individual programs
$(BIN_DIR)/%: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ $(LDFLAGS)
	@echo "Compiled: $< -> $@"

# Compile only fundamentals examples
fundamentals: $(filter $(BIN_DIR)/fundamentals/%, $(EXECUTABLES))

# Compile only algorithm examples  
algorithms: $(filter $(BIN_DIR)/algorithms/%, $(EXECUTABLES))

# Compile only data structure examples
data-structures: $(filter $(BIN_DIR)/data-structures/%, $(EXECUTABLES))

# Compile only advanced examples
advanced: $(filter $(BIN_DIR)/advanced/%, $(EXECUTABLES))

# Compile only project examples
projects: $(filter $(BIN_DIR)/projects/%, $(EXECUTABLES))

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "Cleaned build directories"

# Create a specific program (usage: make program PROG=path/to/program.c)
program:
ifndef PROG
	@echo "Usage: make program PROG=path/to/program.c"
else
	$(CC) $(CFLAGS) $(INCLUDES) $(PROG) -o $(BIN_DIR)/$(basename $(notdir $(PROG))) $(LDFLAGS)
	@echo "Compiled: $(PROG) -> $(BIN_DIR)/$(basename $(notdir $(PROG)))"
endif

# Run a specific program (usage: make run PROG=program_name)
run:
ifndef PROG
	@echo "Usage: make run PROG=program_name"
else
	@if [ -f "$(BIN_DIR)/$(PROG)" ]; then \
		echo "Running $(PROG):"; \
		echo "=================="; \
		./$(BIN_DIR)/$(PROG); \
	else \
		echo "Program $(PROG) not found. Available programs:"; \
		find $(BIN_DIR) -type f -executable 2>/dev/null | sed 's|$(BIN_DIR)/||' || echo "No compiled programs found."; \
	fi
endif

# List all available programs
list:
	@echo "Available programs:"
	@find $(BIN_DIR) -type f -executable 2>/dev/null | sed 's|$(BIN_DIR)/||' || echo "No compiled programs found."

# Install development dependencies (if any)
install-deps:
	@echo "No external dependencies required for basic C programs"

# Show help
help:
	@echo "C Programs Repository Makefile"
	@echo "=============================="
	@echo ""
	@echo "Targets:"
	@echo "  all              - Compile all programs"
	@echo "  fundamentals     - Compile fundamental examples"
	@echo "  algorithms       - Compile algorithm examples"
	@echo "  data-structures  - Compile data structure examples"
	@echo "  advanced         - Compile advanced examples"
	@echo "  projects         - Compile project examples"
	@echo "  clean            - Remove all build artifacts"
	@echo "  program PROG=... - Compile specific program"
	@echo "  run PROG=...     - Run specific program"
	@echo "  list             - List all compiled programs"
	@echo "  help             - Show this help message"
	@echo ""
	@echo "Examples:"
	@echo "  make fundamentals"
	@echo "  make program PROG=fundamentals/variables-datatypes/variables_demo.c"
	@echo "  make run PROG=fundamentals/variables-datatypes/variables_demo"
	@echo ""
	@echo "Compiler: $(CC)"
	@echo "Flags: $(CFLAGS)"

# Phony targets
.PHONY: all clean fundamentals algorithms data-structures advanced projects program run list install-deps help