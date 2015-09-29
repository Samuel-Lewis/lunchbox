# MAKE SURE TO RENAME TO 'Makefile' BEFORE ATTEMPTING TO MAKE

# Compilation
CXX = g++
INCLUDES = # -I ./lunchbox/include
CXXFLAGS = $(INCLUDES) -pedantic -Wall -Wextra -O2 -c # -g -std=c++11
LIBS = 

# Sources and file names
SOURCES = $(shell find . -type f -name "*.cpp")
OBJECTS = $(SOURCES:.cpp=.o)
OUTDIR = ./
EXE = main.out
all: $(OUTDIR)/$(EXE)

# Object Compilation
$(OUTDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Final compilation and output
$(EXE): $(OBJECTS) 
	$(CXX) $(OBJECTS) $(LIBS) -o $(EXE)

# Clean all objects files and exe.
clean:
	rm -f $(OBJECTS) $(EXE)
