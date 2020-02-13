CXX = g++
CXXFLAGS = -Wall -Wno-uninitialized -std=c++11
BINARIES = prog1.out

prog1: Quash.o Main.o
	$(CXX) $(CXXFLAGS) -o prog1.out Quash.o Main.o 

Quash.o: Quash.cpp Quash.h Element.h
	$(CXX) $(CXXFLAGS) -c $^ 

Main.o: Main.cpp
	$(CXX) $(CXXFLAGS) -c $^ 
clean:
	/bin/rm -f $(BINARIES) *.o