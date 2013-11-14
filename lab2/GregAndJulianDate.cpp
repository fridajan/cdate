#include "date.h"
#include "GregAndJulianDate.h" 

namespace lab2{
    int GregAndJulianDate::days_per_week() const{
        return 7;
    };

    int GregAndJulianDate::months_per_year() const{
        return 12;
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
  		return current_time - 2400000.5;
  	};
}