# Makefile template for C projects

# Compiler and compiler flags
CC = gcc
CFLAGS = 

# Source file and executable name
SRC = tem.c
EXEC = practice

# Default rule
all : $(EXEC)

# Rule to build the executable
$(EXEC) : $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

# Rule to build the executable with debugging information
debug : $(SRC)
	$(CC) $(CFLAGS) -g -o $(EXEC) $<
	gdb $(EXEC)
	$(MAKE) clean

# Rule to clean up generated files
clean :
	rm -vf $(EXEC)
