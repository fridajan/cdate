//This is the julian calendar!!
#include "kattistime.h"
#include "GregAndJulianDate.h"
#include <string>

namespace lab2
{
	class Julian : public GregAndJulianDate {
		
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

			virtual int year(); //should be const, TODO
			virtual int month(); //should be const, TODO
      		virtual int day(); //should be const, TODO
      		virtual int week_day() const;
      		virtual std::string week_day_name() const;

      		virtual int days_this_month() const;
      		virtual std::string month_name() const;
      		//virtual Julian& operator+=(int n);


	};
}