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
	
	//Century mod 7
	const int Gregorian::m_centuriesTable[] = {0, 5, 3, 1, 0};



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
		int c = m_centuriesTable[(year() / 100) % 7 -1];

		int weekDay = (d + m + y + (y / 4) + c) % 7;
		if(weekDay == 0) {
			return 7;
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

    }

	std::string Gregorian::month_name() const
	{

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
int main() {
	lab2::Gregorian g1;

	std::cout << g1.year() << "-" << g1.month() << "-" << g1.day() << std::endl;
	std::cout << "days this month: " << g1.days_this_month() << std::endl;
	std::cout << "week day: " << g1.week_day() << std::endl;

	lab2::Gregorian g2(2012, 2, 1);
	std::cout << g2.year() << "-" << g2.month() << "-" << g2.day() << std::endl;
	std::cout << "days this month: " << g2.days_this_month() << std::endl;
	std::cout << "week day: " << g2.week_day() << std::endl;

	lab2::Gregorian g3(2000, 2, 13);
	std::cout << g3.year() << "-" << g3.month() << "-" << g3.day() << std::endl;
	std::cout << "days this month: " << g3.days_this_month() << std::endl;
	std::cout << "week day: " << g3.week_day() << std::endl;

	lab2::Gregorian g4(1900, 2, 13);
	std::cout << g4.year() << "-" << g4.month() << "-" << g4.day() << std::endl;
	std::cout << "days this month: " << g4.days_this_month() << std::endl;
	std::cout << "week day: " << g4.week_day() << std::endl;


	return 0;
}