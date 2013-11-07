//This is the julian calendar!!
#include "kattistime.h"
#include "date.h"

namespace lab2
{
	class Julian : public Date {
		
		int j_year;
		int j_month;
		int j_day;

		public:
			//double j_day_number;
			Julian();
			Julian(int year, int month, int day);
			Julian & operator= (const Date & date);
			virtual ~Julian(){};

			virtual int year() const;
			virtual int month() const;
      		virtual int day() const;

	};
}