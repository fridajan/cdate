%.out:	%.cpp
	g++ -g -std=c++0x -Wall $*.cpp -o $*.out

all:
	g++ -c -std=c++0x character.cpp
	g++ -c -std=c++0x ghost.cpp
	g++ -c -std=c++0x human.cpp
	g++ -c -std=c++0x pill.cpp
	g++ -c -std=c++0x place.cpp
	g++ -std=c++0x -Wall testCharacter.cpp -o testCharacter.out character.o ghost.o human.o pill.o place.o

house:
	g++ -c -std=c++0x character.cpp
	g++ -c -std=c++0x ghost.cpp
	g++ -c -std=c++0x human.cpp
	g++ -c -std=c++0x pill.cpp
	g++ -c -std=c++0x place.cpp
	g++ -std=c++0x -Wall house.cpp -o house.out character.o ghost.o human.o pill.o place.o

