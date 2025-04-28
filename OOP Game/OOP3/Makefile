# This is the Makefile
game: Constructors.o Functions.o Battleground.o main.o
	g++ -std=c++11 Constructors.o Functions.o Battleground.o main.o -o game

Constructors.o:Constructors.cpp
	g++ -std=c++11 -c Constructors.cpp

Functions.o:Functions.cpp
	g++ -std=c++11 -c Functions.cpp

Battleground.o:Battleground.cpp
	g++ -std=c++11 -c Battleground.cpp

main.o:main.cpp
	g++ -std=c++11 -c main.cpp

clean: 
	rm -f game c.o Constructors.o Functions.o Battleground.o main.o