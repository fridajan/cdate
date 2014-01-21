#include "human.h"
#include <iostream>
using namespace std;

namespace haunted_house
{
	Human::Human(){
		m_name = "Juan";
		m_life = 100;
		m_item_capacity = 5;
		m_type = "Human";
	}

	Human::Human(std::string nm){
		m_name = nm;
		m_life = 100;
		m_item_capacity = 5;
		m_type = "Human";
	}

	Human::Human(const Character& h){
		m_name = h.name();
		m_item_capacity = 5;
		m_life = h.life();
		//todo type
	}

	Human& Human::operator=(const Character& h){
		m_name = h.name();
		m_item_capacity = 5;
		return *this;
	}

	bool Human::eat(Pill& pill){
		Item* p = m_item_container[pill.name()];
		if((Pill*)p == &pill){
			int magic = pill.use();
			if(magic > 0)
			//Do something with magic!!
			m_item_container.erase(m_item_container.find(pill.name()));
			 return true;
		}
		return false;	
	};
}