# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Linker flags
LDFLAGS =

# Source files
SRCS = $(wildcard *.cpp)

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = Bin2Dec

# Default target
all: $(TARGET)

.PHONY: clean

# Linking
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(TARGET)

# Compiling
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJS) $(TARGET)