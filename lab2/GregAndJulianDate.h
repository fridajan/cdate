#ifndef GREG_AND_JULIAN_DATE_H_
#define GREG_AND_JULIAN_DATE_H_

#include "kattistime.h"
#include "date.h"
#include <string>

#include <iostream>

namespace lab2
{
	class GregAndJulianDate : public Date {

	public:
        //virtual ~GregAndJulianDate() { };

    	virtual int year() const = 0;
        virtual int month() const = 0;
        virtual int day() const = 0;
        virtual int week_day() const = 0;
        virtual int days_this_month() const = 0;
        virtual std::string month_name() const = 0;
        virtual std::string week_day_name() const = 0;

        void add_year(int n = 1) =0;
        void add_month(int n = 1) =0;
        
        int days_per_week() const;
        int months_per_year() const;

    
        bool operator==(const Date& d) const;
        bool operator!=(const Date& d) const;
        bool operator<(const Date& d) const;
        bool operator<=(const Date& d) const;
        bool operator>(const Date& d) const;
        bool operator>=(const Date& d) const;
        int operator-(const Date& d) const;
        int mod_julian_day() const;
	};

    std::ostream & operator<<(std::ostream & os, const Date &);
}



#endif /* GREG_AND_JULIAN_DATE_H_ */