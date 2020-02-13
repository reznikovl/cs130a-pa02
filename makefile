CXX = g++
CXXFLAGS = -Wall -Wno-uninitialized -std=c++11
BINARIES = prog1.out

all: prog1

prog1: Quash.cpp Main.cpp
	$(CXX) $(CXXFLAGS) -o prog1.out Quash.cpp Main.cpp 

clean:
	/bin/rm -f $(BINARIES) *.o