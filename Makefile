# Compilation
CXX = g++
CXXFLAGS = -pedantic -c # -g -Wall -Wextra

# Sources and file names
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
all: $(EXE)

# Object Compilation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

# Final compilation and output
$(EXE): $(OBJECTS) 
	$(CXX) $(OBJECTS) -o $(EXE)

# Clean all objects files, and edit auto saves.
clean:
	rm -f $(OBJECTS) *~ $(EXE)
