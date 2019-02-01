CXXFLAGS += -Wc++11-extensions

grammer: grammer.o Parser.o Utility.o
		g++ -std=c++1y -pedantic grammer.o Parser.o Utility.o -o grammer

grammer.o: grammer.cpp
		g++ -c grammer.cpp

Parser.o: Parser.cpp Parser.h
		g++ -Wno-everything -c Parser.cpp

Utility.o: Utility.cpp Utility.h
		g++ -c Utility.cpp

clean:
		rm *.o grammer
