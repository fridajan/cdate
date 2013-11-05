#ifndef DATE_H_
#define DATE_H_

#include <stdexcept>

class Date {

  private:
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

    virtual int year() const { return m_year; };

    virtual int month() const { return m_month; };

    virtual int day() const  { return m_day; };

    virtual int week_day() const =0;

    virtual int days_per_week() const { return m_daysPerWeek; };
  
    virtual int days_this_month() const =0;
  
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

	virtual std::ostream & operator<<(const Date &) =0;

};

#endif /* DATE_H_ */
