main: main.o Parser.o Utility.o
		g++ -std=c++1y main.o Parser.o Utility.o -o main

main.o: main.cpp
		g++ -c main.cpp

Parser.o: Parser.cpp Parser.h
		g++ -Wno-everything -c Parser.cpp

Utility.o: Utility.cpp Utility.h
		g++ -c Utility.cpp

clean:
		rm *.o main
