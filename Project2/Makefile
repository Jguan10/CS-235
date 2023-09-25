CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -O0

PROG ?= test
OBJS = Character.o Barbarian.o Mage.o Ranger.o Scoundrel.o test.o

all: $(PROG)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -rf $(EXEC) *.o *.out test

rebuild: clean all
