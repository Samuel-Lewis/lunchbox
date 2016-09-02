#
# Generic Makefile
#  https://github.com/Samuel-Lewis/lunchbox
#
#  Samuel Lewis
#  15th Feb 2016
#
# COMMANDS TO USE
#  make		makes all
#  make run	makes all and executes the product
#  make debug	makes all with added flag of -DDEBUG (defines DEBUG)
#  make clean	cleans up all .o files and the product
#

# PROJECT NAME
PROJECT = main

# COMPILER
CC =g++
VERSION =-std=c++11
CC_OPTIONS =-pedantic -Wall -Wextra -O2#-ansi

# Includes and linkers
HEADERS =# -I
LIBS =



#########################
# No need to edit below here

# Sources
SOURCES = $(shell find . -type f -name "*.cpp")
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
