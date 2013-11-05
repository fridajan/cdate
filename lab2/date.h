#include <stdexcept>

class Date {
  public:
  	
    //Date() = 0;
    //Date(int year, int month, int day) = 0;
    //copy-contructor
    //copy-assignment
    //destructor

    virtual int year() const =0;

    virtual int month() const =0;

    virtual int day() const =0;

    virtual int week_day() const =0;

    virtual int days_per_week() const =0;
  
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

/*private:
	int year;*/
};