.PHONY: clean tidy

# Compiler
CC = g++

# Compiler flags
#	Wall		Turn on (almost) all warnings
#	Werror		Don't compile if there are warnings
#   std=c++11	Use C++11 standard
CFLAGS = -Wall -Werror -std=c++11

# Source files; all .cpp files in this folder
SRC = $(wildcard *.cpp)

# Object files; all source files must be compiled
OBJ = $(SRC:.cpp=.o)

# Headers; all .h files in this folder
HEADER = $(wildcard *.h)

# Executable name
EXE = CardChallenge

# Build program
$(EXE): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $@

# Compile object files
%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

# Clean up all EXE
clean:
	rm -rf *.o

# Clean all including EXE
tidy:
	rm -rf *.o $(EXE)
