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