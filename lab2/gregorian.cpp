#include "gregorian.h"
#include "kattistime.h"
#include <stdexcept>
#include <iostream>

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
	    time(&mytime);

	    // För att få ut datum lokalt 
	    struct tm *t = gmtime(&mytime);
	    m_year  = t->tm_year + 1900;
	    m_month = t->tm_mon + 1;      // månaderna och dagarna
	    m_day   = t->tm_mday;         // indexerade från ETT
	}

	Gregorian::Gregorian(int year, int month, int day)
	{
	    m_year = year;
	    m_month = month;
	    m_day = day;
	}

	Gregorian::~Gregorian()
	{
	}

	int Gregorian::week_day() const
	{
		int d = day();
		int m = m_monthTable[month() - 1];
		if(isLeapYear() && (month() == 1 || month() == 2))
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

	int Gregorian::days_per_week() const
	{
		return 7;
	}

	int Gregorian::days_this_month() const
	{
		if(month() == 2 && isLeapYear()) {
			return 29;
		}
		return m_daysPerMonth[month()-1];
	}

	int Gregorian::months_per_year() const
	{
		return 12;
	}

    std::string Gregorian::week_day_name() const
    {
    	return m_weekDaysName[week_day()-1];
    }

	std::string Gregorian::month_name() const
	{
		return m_monthsName[month() - 1];
    }


	Date& Gregorian::operator++() 
	{ 
		if(day() < days_this_month()) {
			m_day++;
		} else {
			if(month() == months_per_year()) {
				m_year++;
				m_month = 1;
			} else {
				m_month++;
			}
			m_day = 1;
		}
		return *this; 
	}

	Date& Gregorian::operator--() 
	{ 
		if(day() > 1) {
			m_day--;
		} else {
			if(month() == 1) {
				m_year--;
				m_month = months_per_year();
			} else {
				m_month--;
			}
			m_day = days_this_month();
		}
		return *this; 
	}

	/*
	n = 20
	day 30
	days month 31
	
	*/
	Date& Gregorian::operator+=(int n) 
	{
		/*int newDay = n;
		int newMonth = 0;
		int newYear = 0;
		if(day() + n > days_this_month()) {
			day = n - (days_this_month() - day());
			newMonth = month + 1;
		}*/
		return *this; 
	}

	Date& Gregorian::operator-=(int n) 
	{ 
		m_day -= n;
		return *this; 
	}


	void Gregorian::add_year(int n = 1) 
	{  
		m_year += n;
	}

	void Gregorian::add_month(int n = 1) 
	{  
		//TODO
		int newMonth = month() + n;
		int newYear = 0;
		if(newMonth > months_per_year()) {
			newMonth = newMonth % months_per_year();
			newYear = m_year + newMonth / months_per_year();
		}
		if(day() > m_daysPerMonth[newMonth-1]) {
			std::cout << "error" << std::endl;
		} else {
			m_month = newMonth;
			m_year = newYear;
		}
	}


	bool Gregorian::isLeapYear() const
	{
		if( (year() % 4 == 0 && year() % 100 != 0) ||
			(year() % 100 == 0 && year() % 400 == 0) )
		{
			return true;
		}
		return false;
	}




}	// end namespace lab2


// Test
/*int main() {
	lab2::Gregorian g1;

	std::cout << g1.year() << "-" << g1.month() << "-" << g1.day() << std::endl;
	std::cout << "month name: " << g1.month_name() << std::endl;
	std::cout << "week day: " << g1.week_day_name() << std::endl;
	std::cout << std::endl;

	lab2::Gregorian g2(2013, 11, 9);
	std::cout << g2.year() << "-" << g2.month() << "-" << g2.day() << std::endl;
	std::cout << "month name: " << g2.month_name() << std::endl;
	std::cout << "week day: " << g2.week_day_name() << std::endl;
	std::cout << std::endl;

	lab2::Gregorian g3(2000, 2, 13);
	std::cout << g3.year() << "-" << g3.month() << "-" << g3.day() << std::endl;
	std::cout << "month name: " << g3.month_name() << std::endl;
	std::cout << "week day: " << g3.week_day_name() << std::endl;
	std::cout << std::endl;

	lab2::Gregorian g4(1900, 2, 13);
	std::cout << g4.year() << "-" << g4.month() << "-" << g4.day() << std::endl;
	std::cout << "month name: " << g4.month_name() << std::endl;
	std::cout << "week day: " << g4.week_day_name() << std::endl;


	return 0;
}*/