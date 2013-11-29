#include "kattistime.h"
#include "julian.h"
#include "GregAndJulianDate.h" 
#include <math.h>       /* floor */
#include <tuple>
#include <string>
#include <stdio.h>

#include <iostream>

namespace lab2{
	
	std::tuple<int,int,int> Julian::fromJDNtoJulianDate(long double JDN) const
	{	
	    double z, a, b, c, d, e;
	    //printf("JDN1: %lf\n", JDN);
    	JDN += 0.5;
    	//std::cout<<"JDN2:"<<JDN<<std::endl;
    	z = floor(JDN);
		//std::cout<<"JDN3:"<<z<<std::endl;
    	a = z;
    	b = a + 1524;
    	c = floor((b - 122.1) / 365.25);
    	d = floor(365.25 * c);
    	e = floor((b - d) / 30.6001);

    	int month = floor((e < 14) ? (e - 1) : (e - 13));
    	int year = floor((month > 2) ? (c - 4716) : (c - 4715));
    	int day = b - d - floor(30.6001 * e);

    	return std::make_tuple (year, month, day);
	};

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

       	//std::cout << year << ":" << month << ":" << day << std::endl;

    	int a = (14-month)/12;
		int y = year+4800-a;
		int m = month + 12*a -3;

		//Gregorian time to JDN
		current_time = day + (153*m+2)/5 + 365*y + (y/4)-(y/100)+(y/400)-32045;
		
		//printf("%lf\n", current_time);
        //printf("%lf\n", current_time-2400000.5);
	};

	Julian::Julian(int year, int month, int day)
	{
    	/*int a = (14-month)/12;
		int y_tmp = year+4800-a;
		int m_tmp = month + 12*a -3;

		//Julian time to JDN
		current_time = day + (153 * m_tmp + 2)/5 + 365 * y_tmp + (y_tmp/4)-32083;*/
		
		/* Algorithm as given in Meeus, Astronomical Algorithms, Chapter 7, page 61 */
		if (month <= 2) {
        	year--;
        	month += 12;
    	}


    	current_time = (long double) ((floor((365.25 * (year + 4716))) +
            floor((30.6001 * (month + 1))) +
            day) - 1524.5);
		
		//printf("%lf:%d\n", current_time, day);
        //printf("%lf\n", current_time-2400000.5);
	}

	Julian::Julian(const Date& date)
	{
		current_time = date.current_time;
	};

	Julian & Julian::operator= (const Date & date){
	   	current_time = date.current_time;
		return *this;
	}

	int Julian::year() const{ 
		return std::get<0>(this->fromJDNtoJulianDate(current_time)); //Calculate from JDN*/
	};

	int Julian::month() const{ 
		return std::get<1>(this->fromJDNtoJulianDate(current_time)); //Calculate from JDN*/
	};

	int Julian::day() const{ 
		return std::get<2>(this->fromJDNtoJulianDate(current_time)); //Calculate from JDN*/
	};

	int Julian::week_day() const{
		return (int)current_time % 7;
	};

	std::string Julian::week_day_name() const{
		int week_day = (int)current_time % 7;
		return m_weekDays[week_day];
	};

	int Julian::days_this_month() const{
		int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if((this->year() % 4) == 0){
			daysPerMonth[1] = 29; //february
		}
		int index = this->month() - 1;
		return daysPerMonth[index];
	};

	std::string Julian::month_name() const{
		int index = this->month() - 1;
		return m_months[index];
	};

	void Julian::add_year(int n){
		
		std::tuple<int,int,int> d = this->fromJDNtoJulianDate(current_time);
		int year = std::get<0>(d);
		int month = std::get<1>(d);
		int day = std::get<2>(d);
		if(((year+n) % 4) != 0 && month == 2 && day == 29){
			day = 28;
		}
		Julian tmp(year+n, month, day);
		current_time = tmp.current_time;
	};
    void Julian::add_month(int n){
    	int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    	std::tuple<int,int,int> d = this->fromJDNtoJulianDate(current_time);
		int year = std::get<0>(d);
		int month = std::get<1>(d);
		int day = std::get<2>(d);

		if(year%4 == 0){
			daysPerMonth[1] = 29;
		}
		//printf("%d:%d:%d\n", year, month+n, day);
		Julian tmp(year, month+n, day);
		if(day > daysPerMonth[month + n- 1]){ //sista dagen i månaden
			tmp.current_time = tmp.current_time - day + 30;
				
		}
		current_time = tmp.current_time;
    	/*float jds = 0.0;

		for(int i = 0; i < abs(n); ++i){
			int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

			std::tuple<int,int,int> d = this->fromJDNtoJulianDate(current_time + jds);
			int year = std::get<0>(d);
			int month = std::get<1>(d);

			if(year % 4 == 0){ //leap year
				daysPerMonth[1] = 29; //february
			}else{
				daysPerMonth[1] = 28; //february
			}
			//std::cout << daysPerMonth[month-1] << ": "<< month << ": "<<  daysPerMonth[month]<< std::endl;
			int monthAdd;
			if(daysPerMonth[month-1] > daysPerMonth[month]){
				monthAdd = daysPerMonth[month-1] - 1;
			}else if(daysPerMonth[month-1] < daysPerMonth[month]){
				monthAdd = daysPerMonth[month-1] + 1;
			}else{
				monthAdd = daysPerMonth[month-1];
			}
			//std::cout << monthAdd << ": "<< month << ": "<< std::endl;
			if(n > 0)jds += monthAdd;
			else jds -= monthAdd;

		}*/

		//current_time = current_time + jds;
    };



}