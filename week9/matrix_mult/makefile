# Project name
PROJECT = matrix_mult

# Compiler flags with threading support
CXXFLAGS = -std=c++11 -Wall -pthread

# Linker flags for threading 
LDFLAGS = -pthread 

# Source files
SRC = matrix_mult.cpp

# Executable file
EXEC = $(PROJECT)

# Default target
all: $(EXEC)  

# Build executable 
$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

# Clean target
clean:
	$(RM) $(EXEC)