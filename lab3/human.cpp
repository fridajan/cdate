#include "human.h"

namespace haunted_house
{
	Human::Human(){
		m_name = "Juan";
		m_life = 100;
		m_item_capacity = 5;
	}

	Human::Human(std::string nm){
		m_name = nm;
		m_life = 100;
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

	bool Human::fight(Character& c){
		if(c.life() > 0){ //Human or Wizard
			//No fight needed we can talk!
			return true;
		}else{
			int i = 0;
			while(i < 100){ //change to fight until win or loose
				int rate = rand() % 100 + 1;
				cout << rate << " rate" << endl;
				if(rate > 50){
					this->change_life(rate % 50);
					c.change_life(rate % 50);
				}else{
					this->change_life(-(rate % 50));
					c.change_life(-(rate % 50));
				}
				if(c.life() > 0){
					//Todo transform object to human
					return true;
				}else if(this->life() < 0){
					//Transform you to dead
					return false;
				}
				++i;
			}
			return true;
		}
	};
}