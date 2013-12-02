#include "GregAndJulianDate.h" 
#include <sstream>
#include <math.h>

namespace lab2{

	const std::string GregAndJulianDate::m_weekDays[] = { "monday", "tuesday", "wednesday", 
											"thursday", "friday", "saturday", "sunday"};
	const std::string GregAndJulianDate::m_months[] = { "january", "february", "march",
													"april", "may", "june", "july",
													"august", "september", "october",
													"november", "december" };


    int GregAndJulianDate::days_per_week() const{
        return 7;
    };

    int GregAndJulianDate::months_per_year() const{
        return  12;
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

  	/*int GregAndJulianDate::mod_julian_day() const{
  		return current_time - 2400001;
  		//return current_time - 2400000.5;
  	};*/

	std::ostream & operator<<(std::ostream & os, const Date & date)
	{
		int y = date.year();
		int m = date.month();
		int d = date.day();

		std::ostringstream oss;
		oss << y << "-";
		if(m < 10) {
			oss << "0" << m << "-";
		} else {
			oss << m << "-";
		}

		if(d < 10) {
			oss << "0" << d;
		} else {
			oss << d;
		}
		std::string str = oss.str();
		os << str;
		return os;
	}

}