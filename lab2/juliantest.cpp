//This is the julian test class

// MyTestSuite1.h
#include <cxxtest/TestSuite.h>
#include "julian.h"

using namespace lab2;

class JulianTestSuite : public CxxTest::TestSuite
{

	public:
	    void testDefaultConstructor(void)
	    {
	    	Julian *j = new Julian();

	        std::cout << j->year();
	        TS_ASSERT_EQUALS(j->year(), 2013);
	    }
};