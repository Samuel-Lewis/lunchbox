# Compilation
CXX = g++
CXXFLAGS = -pedantic -Wall -c # -g -Wextra

all: tests/lbLog_example \
	tests/lbString_example

lb%.o: src/lb%.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

tests/lb%_example: examples/lb%_example.cpp lb%.o
	$(CXX) $^ -o $@

clean:
	rm -f tests/*