#include "alive.h"
#include <iostream>
using namespace std;
namespace haunted_house
{
	bool Alive::fight(Character& c){
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

	bool Alive::action(){
		Place *locat = this->location();
		vector<std::string> items = locat->items();
		if(items.size() > 0) this->change_life(10000);
		this->go(1);
		std::cout << this->name() << ", " << this->life() <<", " <<  this->location()->description()<< std::endl;
		return true;
	};
}