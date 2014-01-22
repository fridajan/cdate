#include "dead.h"
#include <iostream>
using namespace std;
namespace haunted_house
{
	bool Dead::fight(Character& c){
		int rounds = 10;
		srand(time(NULL)); //Generate random
		if(c.life() < 0){ //Dead
			//No fight needed we can talk! TODO
			return true;
		}else{
			int i = 0;
			while(i < rounds){ //Fight certain rounds
				int rate = rand() % 100 + 1;
				if(rate > 50){ //Loose round
					this->change_life(rate % 50);
					c.change_life(rate % 50);
				}else{ //Win round
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

	bool Dead::action(){
		Place *locat = this->location();
		vector<std::string> items = locat->items();
		if(items.size() > 0) this->change_life(-10000);
		std::cout << this->name() << ", " << this->life() <<", " <<  locat->description()<< std::endl;
		return true;
	};
}