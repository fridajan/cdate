#include "character.h"
using namespace std;
namespace haunted_house
{
	string Character::name(){
		return m_name;
	}

	int Character::container_size(){
		return m_item_container.size();
	};

	int Character::container_capacity(){
		return m_item_capacity;
	};
	
}