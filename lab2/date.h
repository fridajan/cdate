#ifndef DATE_H_
#define DATE_H_

#include <stdexcept>
#include <string>

namespace lab2 
{
  class Date {
  protected:
    //double current_time;

    public:
      double current_time;
      //Date() = 0;
      //Date(int year, int month, int day) = 0;

    public:
      //Date() 
      //Date(int year, int month, int day)

      virtual int year() = 0;

      virtual int month() = 0;

      virtual int day() = 0;

      virtual int week_day() const = 0;

      virtual int days_per_week() const = 0; //TODO No need for virtual because it is always seven??
    
      virtual int days_this_month() const = 0;
    
    	virtual int months_per_year() const = 0; //TODO No need for virtual because it is always 12??

    	virtual std::string month_name() const = 0;

      virtual std::string week_day_name() const = 0;

      virtual void add_year(int n = 1) =0;

      virtual void add_month(int n = 1) =0;

      //VirtuaL??
      Date& operator++(){ 
          current_time++; 
          return *this;
      }; //Add a day on the date

      Date& operator--(){ 
          current_time--; 
          return *this;
      };

      Date& operator+=(int n){
          current_time+=n; 
          return *this;
      };

    	Date& operator-=(int n){
          current_time-=n; 
          return *this;
      };

    	virtual bool operator==(const Date& d) const =0;

    	virtual bool operator!=(const Date& d) const =0;

    	virtual bool operator<(const Date& d) const =0;

    	virtual bool operator<=(const Date& d) const =0;

    	virtual bool operator>(const Date& d) const =0;

    	virtual bool operator>=(const Date& d) const =0;

    	virtual int operator-(const Date& d) const =0;

      virtual int mod_julian_day() const =0;

    //  virtual std::ostream & operator<<(const Date &) =0;

  };
}

#endif /* DATE_H_ */
