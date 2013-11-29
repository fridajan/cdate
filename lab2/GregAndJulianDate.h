#include "kattistime.h"
#include "date.h"
#include <string>

#include <iostream>

#define YEAR 1
#define MONTH 2
#define DAY 3

namespace lab2
{
	const std::string WEEKDAYS[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
	const std::string MONTHS[12] = {"january", "february", "mars", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
  
	class GregAndJulianDate : public Date{

	public:
		  virtual int year() const = 0;
      virtual int month() const = 0;
      virtual int day() const = 0;
      virtual int week_day() const = 0;
      virtual int days_this_month() const = 0;
    	virtual std::string month_name() const = 0;
      virtual std::string week_day_name() const = 0;

      virtual int days_per_week() const;
      virtual int months_per_year() const;

      virtual void add_year(int n = 1) =0;
      virtual void add_month(int n = 1) =0;
      
      virtual Date& operator++(); //Add a day on the date
      virtual Date& operator--();
     	virtual Date& operator+=(int n);
      virtual Date& operator-=(int n);

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