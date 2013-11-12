#ifndef GREGORIAN_H_
#define GREGORIAN_H_

#include "date.h"

namespace lab2 
{
	class Gregorian: public Date {

	public:
		Gregorian();

		Gregorian(int year, int month, int day);

		~Gregorian();

		int year() const { return m_year; };

		int month() const { return m_month; };

		int day() const { return m_day; };

		int week_day() const;

		int days_per_week() const;

		int days_this_month() const;

		int months_per_year() const;

    	std::string week_day_name() const;

    	std::string month_name() const;

    	Date& operator++() { return *this; };

    	Date& operator--() { return *this; };

    	Date& operator+=(int n) { return *this; };

    	Date& operator-=(int n) { return *this; };

    	void add_year(int n = 1) {  };

    	void add_month(int n = 1) {  };

    	bool operator==(const Date& d) const { return true; };

    	bool operator!=(const Date& d) const { return true; };

    	bool operator<(const Date& d) const { return true; };

    	bool operator<=(const Date& d) const { return true; };

    	bool operator>(const Date& d) const { return true; };

    	bool operator>=(const Date& d) const { return true; };

    	int operator-(const Date& d) const { return 0; };

      	int mod_julian_day() const { return 0; };

      	std::ostream & operator<<(const Date &) { };


	private:
		bool isLeapYear() const;


		int m_year;
		int m_month;
		int m_day;

		static const int m_daysPerMonth[];
		static const int m_monthTable[];
		static const int m_yearTable[][15];
		static const int m_centuriesTable[];
		
	};
}

#endif /* GREGORIAN_H_ */