%.out:	%.cpp
	g++ -g -std=c++0x -Wall $*.cpp -o $*.out

test:
	g++ -c -std=c++0x kattistime.cpp
	g++ -c -std=c++0x GregAndJulianDate.cpp
	g++ -c -std=c++0x gregorian.cpp
	cxxtest/cxxtestgen.py --error-printer -o test.cpp test_gregorian.cpp 
	g++ -std=c++0x -o test.out -I cxxtest/ test.cpp gregorian.o GregAndJulianDate.o kattistime.o

test2:
	g++ -c -std=c++0x kattistime.cpp
	g++ -c -std=c++0x GregAndJulianDate.cpp
	g++ -c -std=c++0x gregorian.cpp
	g++ -c -std=c++0x julian.cpp
	g++ -std=c++0x -Wall datetest.cpp -o datetest.out gregorian.o julian.o GregAndJulianDate.o kattistime.o
