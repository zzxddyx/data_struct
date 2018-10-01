exe:main.o TextQuery.o
	g++ -o -std=c++11 exe main.o TextQuery.o
main.o:main.cpp TextQuery.h
	g++ -c -std=c++11 main.cpp
TextQuery.o:TextQuery.cpp TextQuery.h
	g++ -c -std=c++11 TextQuery.cpp


