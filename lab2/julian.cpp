#include "kattistime.h"
#include "date.h"
#include "julian.h"

	Julian::Julian() : 
	{
		time_t mytime;
    	currentTime = k_time(&mytime);
	};

	int Julian::year() : {
		if(currentTime) return 1;
		return 0;
	};