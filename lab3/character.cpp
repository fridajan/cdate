#include "character.h"
#include "item.h"

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
	
	bool Character::pick_up(Item& item){
		if(container_size() < container_capacity()){
			m_item_container.insert(pair<string, Item*>(item.name(), &item));
			return true;
		}
		return false;
	};
	
	bool Character::drop(Item& item){
		//Remove from container
		return false;
	};

	int Character::life(){
		return m_life;
	};
	void Character::change_life(int change){
		m_life += change;
	};
}