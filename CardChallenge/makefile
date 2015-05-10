.PHONY: clean tidy todo search searchn

# Compiler
CC = g++

# Compiler flags
#	Wall		Turn on (almost) all warnings.
#	Werror		Don't compile if there are warnings.
#   std=c++11	Use C++11 standard.
CFLAGS = -Wall -Werror -std=c++11

# Source files; all .cpp files in this folder
SRC = $(wildcard *.cpp)

# Object files; all source files must be compiled
OBJ = $(SRC:.cpp=.o)

# Headers; all .h files in this folder
HEADER = $(wildcard *.h)

# Executable name
EXE = Main

# Build program
$(EXE): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $@

# Compile object files
%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

# Run card challenge
play:  $(EXE)
	./$(EXE) 

# Clean up all object files
clean:
	rm -rf *.o

# Clean all including EXE
tidy:
	rm -rf *.o $(EXE)

# Grep all source files for TODO:s
todo:
	@grep -i "TODO" $(SRC) $(HEADER)

# Search all source files for occurances of $(key)
#   n       Print line numbers with matches.
#
# Usage: make KEY="pattern" search
search:
	@grep -n "$(key)" $(SRC) $(HEADER)

# Search all source files for occurances of $(key)
#   i       Ignore case.
#   n       Print line numbers with matches.
#
# Usage: make KEY="pattern" search
searchn:
	@grep -in "$(key)" $(SRC) $(HEADER)
