#include "house.h"
#include <iostream>

namespace haunted_house 
{
  House::House() {
  	Room *p1 = new Room("This is a hallway");
  	Room *p2 = new Room("This is a room");
  	p1->setNeighbour(Place::north, p2);
  	p2->setNeighbour(Place::south, p1);
  	
  	places.push_back(p1);
  	places.push_back(p2);
  }

  House::~House() {

  }

  void House::printHouse() {
  	std::cout << "House:" << std::endl;

  	for(int i=0; i<places.size(); ++i) {
  		std::cout << places[i]->type() << " : " << places[i]->description() << std::endl;

  		std::vector<int> dir = places[i]->directions();
  		for(int j=0; j<dir.size(); ++j) {
  			std::cout << places[i]->getNeighbour(dir[j]).description() << std::endl;
  		}
  	}
  }

} /*end namespace*/

  int main() {
  	haunted_house::House h;
  	h.printHouse();
  	return 0;
  }


