#ifndef DATE_H_
#define DATE_H_

#include "kattistime.h"
#include <stdexcept>

namespace lab2 
{
  class Date {
  protected:
    //double current_time;

    public:
      double current_time;
      //Date() = 0;
      //Date(int year, int month, int day) = 0;
      //copy-contructor
      //copy-assignment
      //destructor
      //Date(){};

      /*Date(int year, int month, int day) : m_year(year), m_month(month), m_day(day)
      {
      }*/

      ~Date()
      {
      }

      virtual int year() const = 0;

      virtual int month() const = 0;

      virtual int day() const = 0;

      //virtual int week_day() const =0;

      //virtual int days_per_week() const { return m_daysPerWeek; }
    
      /*virtual int days_this_month() const =0;
    
    	virtual int months_per_year() const =0;

    	virtual std::string week_day_name() const =0;

    	virtual std::string month_name() const =0;

    	virtual Date& operator++() =0;

    	virtual Date& operator--() =0;

    	virtual Date& operator+=(int n) =0;

    	virtual Date& operator-=(int n) =0;

    	virtual void add_year(int n = 1) =0;

    	virtual void add_month(int n = 1) =0;

    	virtual bool operator==(const Date& d) const =0;

    	virtual bool operator!=(const Date& d) const =0;

    	virtual bool operator<(const Date& d) const =0;

    	virtual bool operator<=(const Date& d) const =0;

    	virtual bool operator>(const Date& d) const =0;

    	virtual bool operator>=(const Date& d) const =0;

    	virtual int operator-(const Date& d) const =0;

      virtual int mod_julian_day() const =0;

      virtual std::ostream & operator<<(const Date &) =0;*/

  };
}

#endif /* DATE_H_ */
