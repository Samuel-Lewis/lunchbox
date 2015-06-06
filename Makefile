# Compilation
COMPILER = g++
FLAGS = -pedantic -c# -g -Wall -Wextra

# Sources and file names
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXE = main

all: $(EXE)

# Object Compilation
%.o: %.cpp
	$(COMPILER) $(FLAGS) -o $@ $^

# Final compilation and output
$(EXE): $(OBJECTS) 
	$(COMPILER) $(OBJECTS) -o $(EXE)

# Clean all objects files, and edit auto saves.
clean:
	rm -f *.o *~ $(EXE)
