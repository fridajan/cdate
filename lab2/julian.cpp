#include "kattistime.h"
#include "date.h"
#include "julian.h"
#include <math.h>       /* floor */

#include <iostream>

namespace lab2{
	Julian::Julian()
	{
		// För att få nuvarande tid
        time_t mytime;
        time(&mytime);

        // För att få ut datum lokalt 
        struct tm *t = gmtime(&mytime);
        j_year  = t->tm_year + 1900;
        j_month = t->tm_mon + 1;      // månaderna och dagarna
        j_day   = t->tm_mday;         // indexerade från ETT


    	int a = (14-j_month)/12;
		int y_tmp = j_month+4800-a;
		int m_tmp = j_month + 12*a -3;

		current_time = j_day + (153*m_tmp+2)/5 + 365*y_tmp + (y_tmp/4)-32083;
		// Gregorian::: j_day_number = j_day + (153*j_month+2)/5 + 365*j_year + (j_year/4)-(j_year/100)+(j_year/400)-32045;
	};

	Julian::Julian(int year, int month, int day): j_year(year), j_month(month), j_day(day)
	{

    	int a = (14-month)/12;
		int y_tmp = year+4800-a;
		int m_tmp = month + 12*a -3;

		current_time = j_day + (153 * m_tmp + 2)/5 + 365 * y_tmp + (y_tmp/4)-32083;
		std::cout << current_time << std::endl;
	}

	Julian & Julian::operator= (const Date & date){
		long td = date.current_time;

	    float z, a, b, c, d, e;

    	td += 0.5;
    	z = floor(td);

    	a = z;
    	b = a + 1524;
    	c = floor((b - 122.1) / 365.25);
    	d = floor(365.25 * c);
    	e = floor((b - d) / 30.6001);

    	int month = floor((e < 14) ? (e - 1) : (e - 13));
    	int year = floor((month > 2) ? (c - 4716) : (c - 4715));
    	int day = b - d - floor(30.6001 * e);

    	j_year = year;
    	j_month = month;
    	j_day = day;

		return *this;
	}
	int Julian::year() const{ 
		return j_year;
	};

	int Julian::month() const{ 
		return j_month;
	};

	int Julian::day() const{ 
		return j_day;
	};
}