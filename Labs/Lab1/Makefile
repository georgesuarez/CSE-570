CXX = g++ -Wall

PROGS = lab1.o

lab1: lab1.o
	$(CXX) -o lab1 $(PROGS)

lab1.o: lab1.cpp
	$(CXX) -c lab1.cpp

clean:
	rm -f lab1 $(PROGS)

