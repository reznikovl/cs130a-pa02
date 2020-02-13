CXX = g++
CXXFLAGS = -Wall -Wno-uninitialized -g -std=c++11
BINARIES = prog1.out

prog1: Quash.h Element.h Quash.o Main.o
	$(CXX) $(CXXFLAGS) -o prog1.out Quash.o Main.o 

Quash.o: Quash.cpp
	$(CXX) $(CXXFLAGS) -c $^ 

Main.o: Main.cpp
	$(CXX) $(CXXFLAGS) -c $^ 
clean:
	/bin/rm -f $(BINARIES) *.o