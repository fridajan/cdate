#include "ghost.h"
#include <iostream>
using namespace std;
namespace haunted_house
{
	Ghost::Ghost(){
		m_name = "Casper";
		m_item_capacity = 1;
		m_life = -100;
		m_type = "Ghost";
	}
	Ghost::Ghost(std::string nm){
		m_name = nm;
		m_item_capacity = 1;
		m_life = -100;
		m_type = "Ghost";
	}

	Ghost::Ghost(const Character& h){
		m_name = h.name();
		m_item_capacity = 1;
		m_life = h.life();
		//Todo type
	}

	bool Ghost::action(){
		cout << name() << endl;
		return true;
	}

	bool Ghost::steal(){
		return false;
	}
}