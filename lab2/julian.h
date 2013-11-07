//This is the julian calendar!!
#include "kattistime.h"
#include "date.h"

namespace lab2
{
	class Julian : public Date {
		int m_year;
		public:
			Julian();
			virtual int year();
			virtual ~Julian(){};
	};
}