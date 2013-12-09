#include "ghost.h"
namespace haunted_house
{
	Ghost::Ghost(){
		m_name = "Casper";
		m_item_capacity = 1;
	}
	Ghost::Ghost(std::string nm){
		m_name = nm;
		m_item_capacity = 1;
	}
}