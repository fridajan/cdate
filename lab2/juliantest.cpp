//This is the julian test class

// MyTestSuite1.h
#include <cxxtest/TestSuite.h>
#include "julian.h"

class JulianTestSuite : public CxxTest::TestSuite
{

	public:
	    void testDefaultConstructor(void)
	    {
	    	Julian& j = new Julian();
	        
	        TS_ASSERT_EQUALS(j.year(), 1);
	    }
};