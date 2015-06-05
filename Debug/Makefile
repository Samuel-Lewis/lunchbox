# Compilation
COMPILER = g++
FLAGS = -c -pedantic -Wall -g -Wextra

# Sources and file names
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXE = main

#Obligatory ‘all’. Damn websub…
all: $(EXE)

# Object Compilation
%.o: %.cpp
	$(COMPILER) $(FLAGS) -o $@ $^

# Final compilation and output
$(EXE): $(OBJECTS) 
	$(COMPILER) $(OBJECTS)  -o $(EXE)

# Clean all objects files, and edit auto saves.
clean:
	rm -f *.o *~ *.log $(EXE)
