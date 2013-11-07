#include "kattistime.h"
#include "date.h"
#include "julian.h"

namespace lab2{
	Julian::Julian()
	{


		time_t mytime;
		time(&mytime);    
    	set_k_time(mytime);
    	
    	struct tm *t = gmtime(&mytime);
    	m_year  = t->tm_year + 1900;
	};

	int Julian::year() {
		return m_year;
	};

}