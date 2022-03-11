CXX = g++
CCFLAGS = -g --std=c++14 -Wall -Werror -pedantic

# this is a "Suffix Rule" - how to create a .o from a .cc file
%.o: %.cc
	$(CXX) $(CCFLAGS) -c $<

highest: highest.o
	$(CXX) $(CCFLAGS) -o highest highest.o

all:  highest

clean:
	rm -f *.o
