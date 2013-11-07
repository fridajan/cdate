#ifndef DATE_H_
#define DATE_H_

#include "kattistime.h"
#include <stdexcept>

namespace lab2 
{
  class Date {

    protected:
      int m_year;
      int m_month;
      int m_day;
      int m_daysPerWeek;

    public:
      //Date() = 0;
      //Date(int year, int month, int day) = 0;
      //copy-contructor
      //copy-assignment
      //destructor

      Date()
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

      Date(int year, int month, int day) : m_year(year), m_month(month), m_day(day)
      {
      }

      ~Date()
      {
      }

      virtual int year() const { return m_year; }

      virtual int month() const { return m_month; }

      virtual int day() const  { return m_day; }

      //virtual int week_day() const =0;

      virtual int days_per_week() const { return m_daysPerWeek; }
    
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
