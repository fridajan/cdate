#include "kattistime.h"
#include "date.h"
#include <string>

#include <iostream>

namespace lab2
{
	class GregAndJulianDate : public Date{

	public:
		virtual int year() = 0;
      	virtual int month() = 0;
      	virtual int day() = 0;
      	virtual int week_day() const = 0;
      	virtual int days_this_month() const = 0;
    	virtual std::string month_name() const = 0;
      	virtual std::string week_day_name() const = 0;

      	virtual int days_per_week() const;
      	virtual int months_per_year() const;

      	virtual void add_year(int n = 1) =0;
      	virtual void add_month(int n = 1) =0;

    	bool operator==(const Date& d) const;
    	bool operator!=(const Date& d) const;
    	bool operator<(const Date& d) const;
    	bool operator<=(const Date& d) const;
    	bool operator>(const Date& d) const;
    	bool operator>=(const Date& d) const;
    	int operator-(const Date& d) const;
      	int mod_julian_day() const;

      	//virtual std::ostream & operator<<(const Date &) =0;

	};
}