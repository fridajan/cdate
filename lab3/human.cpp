#include "human.h"
#include <iostream>
using namespace std;

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

	Human::Human(const Character& h){
		m_name = h.name();
		m_item_capacity = 5;
		m_life = h.life();
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

	bool Human::fight(Character& c){
		srand(time(NULL)); //Generate random
		if(c.life() > 0){ //Human or Wizard
			//No fight needed we can talk!
			return true;
		}else{
			int i = 0;
			while(i < 10){ //change to fight until win or loose
				int rate = rand() % 100 + 1;
				cout << rate << " Human" << endl;
				if(rate > 50){
					this->change_life(rate % 50);
					c.change_life(rate % 50);
				}else{
					this->change_life(-(rate % 50));
					c.change_life(-(rate % 50));
				}
				if(c.life() > 0){
					//Todo transform object to human
					//c = new Human();
					return true;
				}else if(this->life() < 0){
					//Transform you to dead
					return false;
				}
				++i;
				c.fight(*this);
			}
			return true;
		}

	};
}