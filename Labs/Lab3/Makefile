main: main.o Parser.o Utility.o LRSet.o Item.o
		g++ -g -std=c++1y main.o Parser.o Utility.o LRSet.o Item.o -o main

main.o: main.cpp
		g++ -g -c main.cpp

Parser.o: Parser.cpp Parser.h
		g++ -g -Wno-everything -c Parser.cpp

Utility.o: Utility.cpp Utility.h
		g++ -g -c Utility.cpp

LRSet.o: LRSet.cpp LRSet.h
		g++ -g -c LRSet.cpp

Item.o: Item.cpp Item.h
		g++ -g -c Item.cpp

clean:
		rm *.o main
