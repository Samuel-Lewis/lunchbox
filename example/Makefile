#
#
# Contexted Makefile
#  https://github.com/Samuel-Lewis/lunchbox
#
# Special Makefile to compile example program
# Will probably break in other contexts. Use the Makefile in repo's root for a template if you need.

# PROJECT NAME
PROJECT = main

# COMPILER
CC = g++
VERSION = -std=c++11
CC_OPTIONS = -pedantic -Wall -Wextra -O2 -D_LB_EXAMPLE#-ansi

# Includes and linkers
HEADERS =# -I
LIBS =

#########################
# No need to edit below here

# Sources
# Intentionally verbose folder structure to avoid misuse elsewhere
SOURCES = $(shell find ./../../lunchbox -type f -name "*.cpp")
SRC_OBJECTS = $(SOURCES:.cpp=.o)

%.o: %.cpp
	$(CC) -c $(CC_OPTIONS) $(HEADERS) $(VERSION) $^ -o $@

$(PROJECT): $(SRC_OBJECTS)
	$(CC) -o $(PROJECT) $(SRC_OBJECTS) $(LIBS)

# Builds
all: $(PROJECT)

test: CC_OPTIONS += -DDEBUG_TESTS
test: all

debug: CC_OPTIONS += -DDEBUG
debug: all

run: $(PROJECT)
	./$(PROJECT)

# Clean
.PHONY: clean
clean:
	rm -f $(PROJECT) $(SRC_OBJECTS)
