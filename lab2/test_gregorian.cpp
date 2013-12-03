#include <cxxtest/TestSuite.h>

#include "gregorian.h"
#include "GregAndJulianDate.h" 
#include <iostream>

class MyTestSuite : public CxxTest::TestSuite 
{
public:

    // Testcase 1
    void test_constructor( void )
    {
        lab2::Gregorian g1(2013, 11, 13);
    	TS_ASSERT_EQUALS( 2013, g1.year());
        TS_ASSERT_EQUALS( 11, g1.month());
        TS_ASSERT_EQUALS( 13, g1.day());

        lab2::Gregorian g2(1992, 9, 22);
        TS_ASSERT_EQUALS( 1992, g2.year());
        TS_ASSERT_EQUALS( 9, g2.month());
        TS_ASSERT_EQUALS( 22, g2.day());

        g1 = g2;
        TS_ASSERT_EQUALS( 1992, g1.year());
        TS_ASSERT_EQUALS( 9, g1.month());
        TS_ASSERT_EQUALS( 22, g1.day());
    }

    // Testcase 2
    void test_week_day( void )
    {
        lab2::Gregorian g1(2013, 11, 11);
        TS_ASSERT_EQUALS( 1, g1.week_day());
        TS_ASSERT_EQUALS( "monday", g1.week_day_name());

        lab2::Gregorian g2(2013, 11, 17);
        TS_ASSERT_EQUALS( 7, g2.week_day());
        TS_ASSERT_EQUALS( "sunday", g2.week_day_name());

        lab2::Gregorian g3(2000, 2, 29);
        TS_ASSERT_EQUALS( 2, g3.week_day());
        TS_ASSERT_EQUALS( "tuesday", g3.week_day_name());
    }

    // Testcase 3
    void test_plus_minus_operators( void )
    {
        // Test ++ and --
        lab2::Gregorian g1(2013, 12, 31);
        ++g1;
        TS_ASSERT_EQUALS( 2014, g1.year());
        TS_ASSERT_EQUALS( 1, g1.month());
        TS_ASSERT_EQUALS( 1, g1.day());
        --g1;
        TS_ASSERT_EQUALS( 2013, g1.year());
        TS_ASSERT_EQUALS( 12, g1.month());
        TS_ASSERT_EQUALS( 31, g1.day());  

        lab2::Gregorian g2(2013, 1, 31);
        ++g2;
        TS_ASSERT_EQUALS( 2013, g2.year());
        TS_ASSERT_EQUALS( 2, g2.month());
        TS_ASSERT_EQUALS( 1, g2.day());
        --g2;
        TS_ASSERT_EQUALS( 2013, g2.year());
        TS_ASSERT_EQUALS( 1, g2.month());
        TS_ASSERT_EQUALS( 31, g2.day());

        lab2::Gregorian g3(2000, 2, 28);
        ++g3;
        TS_ASSERT_EQUALS( 2000, g3.year());
        TS_ASSERT_EQUALS( 2, g3.month());
        TS_ASSERT_EQUALS( 29, g3.day());
        ++g3;
        TS_ASSERT_EQUALS( 2000, g3.year());
        TS_ASSERT_EQUALS( 3, g3.month());
        TS_ASSERT_EQUALS( 1, g3.day());
        --g3;
        TS_ASSERT_EQUALS( 2000, g3.year());
        TS_ASSERT_EQUALS( 2, g3.month());
        TS_ASSERT_EQUALS( 29, g3.day());

        //TODO
        // Test += and -=

    }

    // Testcase 4
    void test_add_year( void )
    {
        lab2::Gregorian g1(1999, 12, 31);
        g1.add_year();
        TS_ASSERT_EQUALS( 2000, g1.year());

        g1.add_year(10);
        TS_ASSERT_EQUALS( 2010, g1.year());
    }

    // Testcase 5
    void test_add_month( void )
    {
        lab2::Gregorian g1(1999, 12, 31);
        g1.add_month();
        TS_ASSERT_EQUALS( 2000, g1.year());
        TS_ASSERT_EQUALS( 1, g1.month());
        TS_ASSERT_EQUALS( 31, g1.day());

        g1.add_month();
        TS_ASSERT_EQUALS( 2000, g1.year());
        TS_ASSERT_EQUALS( 3, g1.month());
        TS_ASSERT_EQUALS( 1, g1.day()); //Enligt labbpeket

        g1.add_month(24);
        TS_ASSERT_EQUALS( 2002, g1.year());
        TS_ASSERT_EQUALS( 3, g1.month());
        TS_ASSERT_EQUALS( 1, g1.day()); //Enligt labbpeket


        lab2::Gregorian g2(1992, 2, 29);
        
        g2.add_month(29);
        TS_ASSERT_EQUALS(1994, g2.year());
        TS_ASSERT_EQUALS(7, g2.month());
        TS_ASSERT_EQUALS(28, g2.day());
    }

    // Testcase 6
    void test_ostream( void )
    {
        lab2::Gregorian g1(2013, 11, 27);
        std::cout << g1 << std::endl;
    }
};

