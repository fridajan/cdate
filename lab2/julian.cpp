#include "kattistime.h"
#include "julian.h"
#include "GregAndJulianDate.h" 
#include <math.h>       /* floor */
#include <tuple>
#include <string>
#include <stdio.h>

#include <iostream>

namespace lab2{
	
	int Julian::daysAMonth(int month, int year) const{
		int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if(year % 4 == 0){
			daysPerMonth[1] = 29;
		}
		return daysPerMonth[month-1];
	}

	bool Julian::validDate(int year, int month, int day) const
	{
		if(year < 1858 || year > 2558) {
			return false;
		} if(month < 1 || month > months_per_year()) {
			return false;
		} if(day < 1 || day > daysAMonth(month, year)) {
			return false;
		}
		return true;
	}

	std::tuple<int,int,int> Julian::fromJDNtoJulianDate(double JDN) const
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
	    k_time(&mytime);

        // För att få ut datum lokalt 
        struct tm *t = gmtime(&mytime);
        int year = t->tm_year+1900;
        int month = t->tm_mon + 1;      // månaderna och dagarna
        int day   = t->tm_mday;         // indexerade från ETT

       	//std::cout << year << ":" << month << ":" << day << std::endl;

		//Gregorian time to JDN
		if(validDate(year, month, day)) {
			int a = (14-month)/12;
			int y = year+4800-a;
			int m = month + 12*a -3;

		    current_time = day + (153*m+2)/5 + 365*y + (y/4)-(y/100)+(y/400)-32045;
		} else {
			throw std::out_of_range("exception_in_constructor");			
		}
		
		
		//printf("%lf\n", current_time);
        //printf("%lf\n", current_time-2400000.5);
	};

	Julian::Julian(int year, int month, int day)
	{
    	if(validDate(year, month, day)) {
    		if (month <= 2) {
        		year--;
        		month += 12;
    		}
		    current_time = (double) ((floor((365.25 * (year + 4716))) +
            	floor((30.6001 * (month + 1))) + day) - 1524.5);
		} else {
			throw std::out_of_range("exception_in_constructor");			
		}
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
		int tmp = ((int)round(current_time)) % 7;
		++tmp;
		return tmp ;
	};

	std::string Julian::week_day_name() const{
		int wkDay = this->week_day();
		return m_weekDays[wkDay-1];
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
    	if(n > 0){
    		for(int i = 0; i < n; ++i){
    			current_time = add_one_month(current_time);
    		}
    	}else{
    		for(int i = n; i < 0; ++i){
    			current_time = sub_one_month(current_time);
    		}
    	}
    };

    double Julian::add_one_month(double current_time){
    	int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    	std::tuple<int,int,int> d = this->fromJDNtoJulianDate(current_time);
		int year = std::get<0>(d);
		int month = std::get<1>(d);
		int day = std::get<2>(d);

		if(month == 12){
			month = 1;
			++year;
		}else{
			++month;
		}

		if(year % 4 == 0){
			daysPerMonth[1] = 29;
		}
		if(day > daysPerMonth[month-1]){
			day = 30;
		}
		Julian new_date(year, month, day);
		return new_date.current_time;
    }

    double Julian::sub_one_month(double current_time){
    	int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    	std::tuple<int,int,int> d = this->fromJDNtoJulianDate(current_time);
		int year = std::get<0>(d);
		int month = std::get<1>(d);
		int day = std::get<2>(d);

		if(month == 1){
			month = 12;
			--year;
		}else{
			--month;
		}

		if(year % 4 == 0){
			daysPerMonth[1] = 29;
		}
		if(day > daysPerMonth[month-1]){
			day = 30;
		}
		Julian new_date(year, month, day);
		return new_date.current_time;
    }


}