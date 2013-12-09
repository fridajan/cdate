#include "human.h"
namespace haunted_house
{
	Human::Human(){
		m_name = "Juan";
		m_item_capacity = 5;
	}

	Human::Human(std::string nm){
		m_name = nm;
		m_item_capacity = 5;
	}

	Human::Human(const Human &h){
		m_name = h.m_name;
		m_item_capacity = h.m_item_capacity;
	}
	Human& Human::operator=(const Human &h){
		m_name = h.m_name;
		m_item_capacity = h.m_item_capacity;
		return *this;
	}
}