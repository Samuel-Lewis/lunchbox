# Compilation
CXX = g++
CXXFLAGS = -pedantic -Wall -c # -g -Wextra

# Sources and file names
SOURCES = $(shell find . -type f -name "*.cpp")
OBJECTS = $(SOURCES:.cpp=.o)
EXE = PROJ_NAME
all: $(EXE)

# Object Compilation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Final compilation and output
$(EXE): $(OBJECTS) 
	$(CXX) $(OBJECTS) -o $(EXE)

# Clean all objects files, and edit auto saves.
clean:
	rm -f $(OBJECTS) *~ $(EXE)
