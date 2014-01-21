#include "character.h"
#include "item.h"

using namespace std;

namespace haunted_house
{
	string Character::name() const{
		return m_name;
	}

	int Character::container_size() const{
		return m_item_container.size();
	};

	int Character::container_capacity() const{
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

	signed int Character::life() const{
		return m_life;
	};
	void Character::change_life(int change){
		m_life += change;
	};

	string Character::type() const{
		return m_type;
	};
	void Character::change_type(string type){
		m_type = type;
	};
}