//This is the julian calendar!!
#include "kattistime.h"
#include "date.h"
#include <string>

namespace lab2
{
	class Julian : public Date {
		
		int j_year;
		int j_month;
		int j_day;

		//Help methods
   		void fromJDNtoJulianDate(long JDN);
		public:
			//double j_day_number;
			Julian();
			Julian(int year, int month, int day);
			Julian & operator= (const Date & date);
			virtual ~Julian(){};

			virtual int year() const;
			virtual int month() const;
      		virtual int day() const;
      		virtual std::string week_day() const;
      		virtual int days_per_week() const;
      		virtual int days_this_month() const;
      		virtual int months_per_year() const;
      		virtual std::string month_name() const;
      		//virtual Julian& operator++(); //Adds a day on the date


	};
}