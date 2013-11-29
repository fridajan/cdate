#include "date.h"
#include <math.h>       /* floor */
#include "GregAndJulianDate.h" 

namespace lab2{
    int GregAndJulianDate::days_per_week() const{
        return 7;
    };

    int GregAndJulianDate::months_per_year() const{
        return 12;
    };

    Date& GregAndJulianDate::operator++(){ 
        current_time++; 
        return *this;
    }; //Add a day on the date

    Date& GregAndJulianDate::operator--(){ 
        current_time--; 
        return *this;
    };

    Date& GregAndJulianDate::operator+=(int n){
        current_time+=n; 
        return *this;
    };

    Date& GregAndJulianDate::operator-=(int n){
        current_time-=n; 
        return *this;
    };

    bool GregAndJulianDate::operator==(const Date& d) const {
		if(this->current_time == d.current_time){
			return true;
		}else{
			return false;
		}
	};

	bool GregAndJulianDate::operator!=(const Date& d) const{
		if(this->current_time != d.current_time){
			return true;
		}else{
			return false;
		}
	};

	bool GregAndJulianDate::operator<(const Date& d) const{
		if(this->current_time < d.current_time){
			return true;
		}else{
			return false;
		}
	};

	bool GregAndJulianDate::operator<=(const Date& d) const{
		if(this->current_time <= d.current_time){
			return true;
		}else{
			return false;
		}
	};

	bool GregAndJulianDate::operator>(const Date& d) const {
		if(this->current_time > d.current_time){
			return true;
		}else{
			return false;
		}
	};

	bool GregAndJulianDate::operator>=(const Date& d) const{
		if(this->current_time >= d.current_time){
			return true;
		}else{
			return false;
		}
	};

	int GregAndJulianDate::operator-(const Date& d) const{
		//TODO
		return -1;
	};

  	int GregAndJulianDate::mod_julian_day() const{
  		return round(current_time - 2400000.5);
  	};
}