#ifndef CALENDAR_H_
#define CALENDAR_H_

#include "date.h"
#include <string>
#include <stdexcept>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

namespace lab2 
{
template <class T=Date>
  class Calendar {

  	private:
  		T m_date;
	    std::map<T, std::vector<std::string>> m_cal;

  	public:
  		/**
		 * Default constructor
		 */
  		Calendar()
  		{
  			m_date = T();
  		}

		/**
		 * Copy constructor
		 */
		Calendar(const Calendar& cal)
		{
			m_date = cal.m_date;
			m_cal = cal.m_cal;
		}

  		~Calendar()
  		{

  		}

		Calendar & operator= (const Calendar & cal)
		{
			m_date = cal.m_date;
			m_cal = cal.m_cal;
			return *this;
		}

		bool set_date(int y, int m, int d)
		{
			try {
				m_date = T(y, m, d);
	        } catch(const std::out_of_range& oor) {
	        	return false;
			}
			return true;
		}

		bool add_event(std::string event, int d=0, int m=0, int y=0)
		{
			if(y == 0) {
				y = m_date.year();
			} if(m == 0) {
				m = m_date.month();
			} if(d == 0) {
				d = m_date.day();
			}
			try {
				T date = T(y, m, d);
				// check if date already in calender
				if(m_cal.count(date) > 0) {
					std::vector<std::string> v = m_cal[date];
					// check if event exist
					if(std::find(v.begin(), v.end(), event) != v.end()) {
						return false;
					} else {
						v.push_back(event);
						m_cal[date] = v;
						return true;
					}
				} else {
					std::vector<std::string> v;
					v.push_back(event);
					m_cal[date] = v;
					return true;
				}
	        } catch(const std::out_of_range& oor) {
	        	return false;
			}
		}

		bool remove_event(std::string event, int d=0, int m=0, int y=0)
		{
			if(y == 0) {
				y = m_date.year();
			} if(m == 0) {
				m = m_date.month();
			} if(d == 0) {
				d = m_date.day();
			}

			try {
				T date = T(y, m, d);
				// check if date is in calender
				if(m_cal.count(date) > 0) {
					std::vector<std::string> v = m_cal[date];
					// check if event exist
					std::vector<std::string>::iterator it = std::find(v.begin(), v.end(), event);
					if(it != v.end()) {
						if(v.size() > 1) {
							v.erase(it);
							m_cal[date] = v;
						} else {
							m_cal.erase(date);
						}
						return true;
					} else {
						return false;
					}
				} else {
					return false;
				}
	        } catch(const std::out_of_range& oor) {
	        	return false;
			}
		}

		T get_date() const
		{
			return m_date;
		}

		std::map<T, std::vector<std::string>> get_calender() const
		{
			return m_cal;
		}

  };

	template <typename T>
	std::ostream & operator<<(std::ostream & os, const Calendar<T> & cal)
	{
		std::ostringstream oss;
		std::map<T, std::vector<std::string>> entries = cal.get_calender();
		T current_date = cal.get_date();
		typename std::map<T, std::vector<std::string>>::iterator it;
		for(it=entries.begin(); it!=entries.end(); ++it) {
			T date = it->first;
			if(date >= current_date) {
				std::vector<std::string> v = it->second;
				for(size_t i=0; i<v.size(); ++i) {
					oss << date << ": " << v[i] << std::endl;
				}
			}
		}
		std::string str = oss.str();
		os << str;
		return os;
	}

}

#endif /* CALENDAR_H_ */
