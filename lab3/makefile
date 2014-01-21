%.out:	%.cpp
	g++ -g -std=c++0x -Wall $*.cpp -o $*.out

all:
	g++ -c -std=c++0x Character/character.cpp
	g++ -c -std=c++0x Character/Dead/dead.cpp
	g++ -c -std=c++0x Character/Alive/alive.cpp
	g++ -c -std=c++0x Character/Dead/ghost.cpp
	g++ -c -std=c++0x Character/Alive/human.cpp
	g++ -c -std=c++0x pill.cpp
	g++ -c -std=c++0x place.cpp
	g++ -c -std=c++0x game.cpp
	g++ -std=c++0x -Wall testCharacter.cpp -o testCharacter.out character.o dead.o alive.o ghost.o human.o pill.o place.o game.o

house:
	g++ -c -std=c++0x character.cpp
	g++ -c -std=c++0x dead.cpp
	g++ -c -std=c++0x alive.cpp
	g++ -c -std=c++0x ghost.cpp
	g++ -c -std=c++0x human.cpp
	g++ -c -std=c++0x pill.cpp
	g++ -c -std=c++0x place.cpp
	g++ -std=c++0x -Wall house.cpp -o house.out character.o dead.o alive.o ghost.o human.o pill.o place.o

