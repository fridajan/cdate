%.out:	%.cpp
	g++ -g -std=c++0x -Wall $*.cpp -o $*.out

test:
	g++ -c -std=c++0x GregAndJulianDate.cpp
	g++ -c -std=c++0x gregorian.cpp
	cxxtest/cxxtestgen.py --error-printer -o test.cpp test_gregorian.cpp 
	g++ -std=c++0x -o test.out -I cxxtest/ test.cpp gregorian.o GregAndJulianDate.o
