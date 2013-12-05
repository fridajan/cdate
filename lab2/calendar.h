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
		 template <class T2=Date>
		Calendar(const Calendar<T2>& cal)
		{
			*this = cal;
		}

  		~Calendar()
  		{

  		}

  		template <class T2=Date>
		Calendar<T> & operator= (const Calendar<T2> & cal)
		{
			m_date = cal.get_date();
			m_cal.clear();
			std::map<T2, std::vector<std::string>> entries = cal.get_calender();
			typename std::map<T2, std::vector<std::string>>::iterator it;
			for(it=entries.begin(); it!=entries.end(); ++it) {
				//T date = it->first;
				T2 old = it->first;
				T date = T(old);
			//	std::cout << old << std::endl;
			//	std::cout << date << std::endl;
				std::vector<std::string> v = it->second;
				m_cal[date] = v;
			}
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

		bool add_event(std::string event){
			return add_event(event, m_date.day(), m_date.month(), m_date.year());
		}
		bool add_event(std::string event, int d){
			return add_event(event, d, m_date.month(), m_date.year());
		}
		bool add_event(std::string event, int d, int m){
			return add_event(event, d, m, m_date.year());
		}
		bool add_event(std::string event, int d, int m, int y)
		{
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

		bool remove_event(std::string event)
		{
			return remove_event(event, m_date.day(), m_date.month(), m_date.year());
		}
		bool remove_event(std::string event, int d)
		{
			return remove_event(event, d, m_date.month(), m_date.year());
		}
		bool remove_event(std::string event, int d, int m)
		{
			return remove_event(event, d, m, m_date.year());
		}
		bool remove_event(std::string event, int d, int m, int y)
		{
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
			//printf("%d-%d-%d\n", date.year(), date.month(), date.year());
			if(date > current_date) {
				std::vector<std::string> v = it->second;
				for(size_t i=0; i<v.size(); ++i) {
					oss << date << " : " << v[i] << std::endl;
				}
			}
		}
		std::string str = oss.str();
		os << str;
		return os;
	}

}

#endif /* CALENDAR_H_ */
