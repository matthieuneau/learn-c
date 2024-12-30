# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c17 -g

# Executable name
TARGET = main

# Source files
SRCS = main.c dynamicArray.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# default rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (not associated with real files)
.PHONY: clean

