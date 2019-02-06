CXX = g++ 

CXXFLAGS = -std=c++1y -Wno-everything

PROGS = lab1.o

lab1: lab1.o
	$(CXX) $(CXXFLAGS) -o lab1 $(PROGS)

lab1.o: lab1.cpp
	$(CXX) $(CXXFLAGS) -c lab1.cpp

clean:
	rm -f lab1 $(PROGS)

