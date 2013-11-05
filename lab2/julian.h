//This is the julian calendar!!
#include "kattistime.h"
#include "date.h"

class Julian : Date {
	time_t currentTime;
	public:
		Julian();
		int year() const;
};