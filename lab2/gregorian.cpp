#include "gregorian.h"
#include "GregAndJulianDate.h" 
#include "kattistime.h"
#include <stdexcept>
#include <math.h>       /* floor */
#include <iostream>
#include <sstream>

namespace lab2 
{

	const int Gregorian::m_daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 
											  31, 31, 30, 31, 30, 31 };
	const int Gregorian::m_monthTable[] = { 0, 3, 3, 6, 1, 4, 
											6, 2, 5, 0, 3, 5 };
	//Century mod 4
	const int Gregorian::m_centuriesTable[] = {6, 4, 2, 0};

	const std::string Gregorian::m_weekDaysName[] = { "monday", "tuesday", "wednesday", 
											"thursday", "friday", "saturday", "sunday"};
	const std::string Gregorian::m_monthsName[] = { "january", "february", "march",
													"april", "may", "june", "july",
													"august", "september", "october",
													"november", "december" };


	Gregorian::Gregorian()
	{
		// För att få nuvarande tid
	    time_t mytime;
	    k_time(&mytime);

	    // För att få ut datum lokalt 
	    struct tm *t = gmtime(&mytime);
	    int year  = t->tm_year + 1900;
	    int month = t->tm_mon + 1;      // månaderna och dagarna
	    int day   = t->tm_mday;         // indexerade från ETT

		if(validDate(year, month, day)) {
		    current_time = toJDN(year, month, day);
		} else {
			throw std::out_of_range("exception_in_constructor");			
		}
	}

	Gregorian::Gregorian(int year, int month, int day)
	{
		if(validDate(year, month, day)) {
			current_time = toJDN(year, month, day);	
		} else {
			throw std::out_of_range("exception_in_constructor");
		}
	}

	Gregorian::Gregorian(const Date& date)
	{
		current_time = date.current_time;
	};

	Gregorian::~Gregorian()
	{
	}

	Gregorian & Gregorian::operator= (const Date & date){
	   	current_time = date.current_time;
		return *this;
	}

	int Gregorian::year() const 
	{ 
		int year;
		int month;
		int day;
		toDate(year, month, day);
		return year; 
	}

	int Gregorian::month() const 
	{ 
		int year;
		int month;
		int day;
		toDate(year, month, day);	
		return month; 
	}

	int Gregorian::day() const 
	{ 
		int year;
		int month;
		int day;
		toDate(year, month, day);
		return day; 
	}

	int Gregorian::week_day() const
	{
		int d = day();
		int m = m_monthTable[month() - 1];
		if(isLeapYear(year()) && (month() == 1 || month() == 2))
		{
			m -= 1;
		}
		int y = (year() % 100) % 28;
		int c = m_centuriesTable[(year() / 100) % 4];

		int weekDay = (d + m + y + (y / 4) + c) % 7;
		if(weekDay == 0) {
			weekDay = 7;
		}
		return weekDay;
	}

	int Gregorian::days_this_month() const
	{
		return daysAMonth(month(), year());
	}

    std::string Gregorian::week_day_name() const
    {
    	return m_weekDays[week_day()-1];
    }

	std::string Gregorian::month_name() const
	{
		return m_months[month() - 1];
    }

	void Gregorian::add_year(int n) 
	{  
		int y = year() + n;
		int m = month();
		int d = day();
		if(m == 2 && d == 29) {
			if(!isLeapYear(y)) {
				d = 28;
			}
		}
		current_time = toJDN(y, m, d);
	}

	 void Gregorian::add_month(int n){
    	if(n > 0){
    		for(int i = 0; i < n; ++i){
    			current_time = add_one_month(current_time);
    		}
    	}else if(n < 0){
    		for(int i = n; i < 0; ++i){
    			current_time = sub_one_month(current_time);
    		}
    	}
    };

    double Gregorian::add_one_month(double current_time){
		int y = year();
		int m = month();
		int d = day(); 

		if(m == 12){
			m = 1;
			++y;
		}else{
			++m;
		}
		if(d > daysAMonth(m, y)){
			d = (d + 30) % daysAMonth(m-1, y);
			if(m == 2 && d > daysAMonth(m, y)){
				d = d % daysAMonth(m, y); //Days of february
				++m;
			}
		}
		Gregorian new_date(y, m, d);
		return new_date.current_time;
    }

    double Gregorian::sub_one_month(double current_time){
    	int y = year();
		int m = month();
		int d = day();

		if(m == 1){
			m = 12;
			--y;
		}else{
			--m;
		}
		if(d > daysAMonth(m, y)){
			d = d - 30;
			if(d > 0){
				++m;
			}else{ //Only in february
				d = daysAMonth(m, y) + d; //Days of february
			}
		}
		Gregorian new_date(y, m, d);
		return new_date.current_time;
    }


	bool Gregorian::isLeapYear(int year) const
	{
		if( (year % 4 == 0 && year % 100 != 0) ||
			(year % 100 == 0 && year % 400 == 0) )
		{
			return true;
		}
		return false;
	}

	int Gregorian::daysAMonth(int month, int year) const
	{
		if(month == 2 && isLeapYear(year)) {
			return 29;
		}
		return m_daysPerMonth[month-1];
	}

	double Gregorian::toJDN(int year, int month, int day) const
	{

    	/*int a = (14-month)/12;
		int y = year+4800-a;
		int m = month + 12*a -3;

		//Gregorian time to JDN
		double jdn = day + (153*m+2)/5 + 365*y + (y/4)-(y/100)+(y/400)-32045;*/

		double GREGORIAN_EPOCH = 1721425.5;


    return (GREGORIAN_EPOCH - 1) +
           (365 * (year - 1)) +
           floor((year - 1) / 4) +
           (-floor((year - 1) / 100)) +
           floor((year - 1) / 400) +
           floor((((367 * month) - 362) / 12) +
           ((month <= 2) ? 0 :
                               (isLeapYear(year) ? -1 : -2)
           ) +
           day);

	}

	void Gregorian::toDate(int &year, int &month, int &day) const
	{
		int Q = current_time + 0.5;
		int Z = Q;
		int W = (Z - 1867216.25) / 36524.25;
		int X = W / 4;
		int A = Z + 1 + W - X;
		int B = A + 1524;
		int C = (B - 122.1) / 365.25;
		int D = 365.25 * C;
		int E = (B - D) / 30.6001;
		int F = 30.6001 * E;

		day = B - D - F + (Q - Z);
		if(E > 13) {
			month = E-13;
		} else {
			month = E -1;
		}
		if(month < 3) {
			year = C - 4715;
		} else {
			year = C - 4716;
		}
	}

	bool Gregorian::validDate(int year, int month, int day) const
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

/*	int Gregorian::mod_julian_day() const{
  		return current_time - 2400000.5;
  	};*/

}	// end namespace lab2

