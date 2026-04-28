.PHONY = all clean tidy-check format

# define the commands we will use for compilation and library building
CXX = clang++-19

# define useful flags to cc/ld/etc.
CXXFLAGS += -g3 -gdwarf-4 -Wall -Wpedantic --std=c++2b -O0

# define common dependencies
OBJS = Vector.o
HEADERS = Vector.hpp
TESTOBJS = test_vector.o test_suite.o catch.o

# compile everything; this is the default rule that fires if a user
# just types "make" in the same directory as this Makefile
all: test_suite

test_suite: $(TESTOBJS) $(OBJS) 
	$(CXX) $(CXXFLAGS) -o test_suite $(TESTOBJS) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

tidy-check: 
	clang-tidy-19 \
        --extra-arg=--std=c++2b \
        -warnings-as-errors=* \
        -header-filter=.* \
        Vector.cpp

format:
	clang-format-19 -i --verbose --style=Chromium Vector.cpp Vector.hpp

clean:
	rm -f *.o test_suite
