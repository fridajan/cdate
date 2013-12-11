#include "ghost.h"
#include <iostream>
using namespace std;
namespace haunted_house
{
	Ghost::Ghost(){
		m_name = "Casper";
		m_item_capacity = 1;
		m_life = -100;
	}
	Ghost::Ghost(std::string nm){
		m_name = nm;
		m_item_capacity = 1;
		m_life = -100;
	}

	Ghost::Ghost(const Character& h):Dead(h){
		m_name = h.name();
		m_item_capacity = 1;
		m_life = h.life();
	}

	bool Ghost::fight(Character& c){
		srand(time(NULL)); //Generate random
		if(c.life() < 0){ //Dead
			//No fight needed we can talk!
			return true;
		}else{
			int i = 0;
			while(i < 10){ //change to fight until win or loose
				int rate = rand() % 100 + 1;
				cout << rate << " Ghost" << endl;
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
				c.fight(*this);
			}
			return true;
		}
	};
}