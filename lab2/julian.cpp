#include "kattistime.h"
#include "julian.h"
#include <math.h>       /* floor */
#include <string>

#include <iostream>

namespace lab2{
	Julian::Julian()
	{
		// För att få nuvarande tid
        time_t mytime;
        time(&mytime);

        // För att få ut datum lokalt 
        struct tm *t = gmtime(&mytime);
        int year = t->tm_year+1900;
        int month = t->tm_mon + 1;      // månaderna och dagarna
        int day   = t->tm_mday;         // indexerade från ETT

       // std::cout << year << ":" << month << ":" << day << std::endl;

    	int a = (14-month)/12;
		int y = year+4800-a;
		int m = month + 12*a -3;

		//Gregorian time to JDN
		current_time = day + (153*m+2)/5 + 365*y + (y/4)-(y/100)+(y/400)-32045;

		this->fromJDNtoJulianDate(current_time);
	};

	Julian::Julian(int year, int month, int day): j_year(year), j_month(month), j_day(day)
	{

    	int a = (14-month)/12;
		int y_tmp = year+4800-a;
		int m_tmp = month + 12*a -3;

		//Julian time to JDN
		current_time = j_day + (153 * m_tmp + 2)/5 + 365 * y_tmp + (y_tmp/4)-32083;
	}

	Julian & Julian::operator= (const Date & date){
	   	this->fromJDNtoJulianDate(date.current_time); //Calculate from JDN
		return *this;
	}
	int Julian::year(){ 
		this->fromJDNtoJulianDate(current_time); //Calculate from JDN
		return j_year;
	};

	int Julian::month(){ 
		this->fromJDNtoJulianDate(current_time); //Calculate from JDN
		return j_month;
	};

	int Julian::day() { 
		this->fromJDNtoJulianDate(current_time); //Calculate from JDN
		return j_day;
	};

	int Julian::week_day() const{
		return (int)current_time % 7;
	};

	std::string Julian::week_day_name() const{
		std::string weekdays[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
		int week_day = (int)current_time % 7;
		return weekdays[week_day];
	};

	int Julian::days_this_month() const{
		int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if((j_year % 4) == 0){
			daysPerMonth[1] = 29; //february
		}
		int index = j_month - 1;
		return daysPerMonth[index];
	};

	std::string Julian::month_name() const{
		int index = j_month - 1;
		std::string months[12] = {"January", "February", "Mars", "April", "May", "June", "July", "August", "September", "October", "Movember", "December"};
		return months[index];
	};

	void Julian::fromJDNtoJulianDate(long JDN){	
	    double z, a, b, c, d, e;

    	JDN += 0.5;
    	z = floor(JDN);

    	a = z;
    	b = a + 1524;
    	c = floor((b - 122.1) / 365.25);
    	d = floor(365.25 * c);
    	e = floor((b - d) / 30.6001);

    	int month = floor((e < 14) ? (e - 1) : (e - 13));
    	int year = floor((month > 2) ? (c - 4716) : (c - 4715));
    	int day = b - d - floor(30.6001 * e);

    	this->j_year = year;
    	this->j_month = month;
    	this->j_day = day;
	}
}