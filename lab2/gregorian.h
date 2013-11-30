#ifndef GREGORIAN_H_
#define GREGORIAN_H_

#include "GregAndJulianDate.h" 

namespace lab2 
{
	class Gregorian: public GregAndJulianDate {

	public:
		Gregorian();
		Gregorian(int year, int month, int day);
		Gregorian(const Date& date);
		~Gregorian();

		Gregorian & operator= (const Date & date);

		int year() const;
		int month() const;
		int day() const;
		int week_day() const;
		int days_this_month() const;

    	std::string week_day_name() const;
    	std::string month_name() const;

    	void add_year(int n = 1);
    	void add_month(int n = 1);

	private:
		void sub_month(int n);
		bool isLeapYear(int year) const;
		int daysAMonth(int month, int year) const;
		double toJDN(int year, int month, int day) const;
		void toDate(int &year, int &month, int &day) const;
		bool validDate(int year, int month, int d) const;

		static const int m_daysPerMonth[];
		static const int m_monthTable[];
		static const int m_centuriesTable[];
		static const std::string m_weekDaysName[];
		static const std::string m_monthsName[];
	};

    //std::ostream & operator<<(std::ostream & os, const Date &);
}

#endif /* GREGORIAN_H_ */