//This is the julian calendar!!
#include "kattistime.h"
#include "GregAndJulianDate.h"
#include <string>
#include <tuple>


namespace lab2
{
	class Julian : public GregAndJulianDate {

   		std::tuple<int,int,int> fromJDNtoJulianDate(double JDN) const;
   		double add_one_month(double time);
   		double sub_one_month(double time);
		public:
			//double j_day_number;
			Julian();
			Julian(int year, int month, int day);
			Julian(const Date& date);
			Julian & operator= (const Date & date);
			virtual ~Julian() { };

			virtual int year() const;
			virtual int month() const;
      		virtual int day() const;
      		virtual int week_day() const;
      		virtual std::string week_day_name() const;

      		virtual void add_year(int n);
      		virtual void add_month(int n);

      		virtual int days_this_month() const;
      		virtual std::string month_name() const;
      		//virtual Julian& operator+=(int n);
	};	
}