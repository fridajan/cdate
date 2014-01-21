#include "house.h"
#include <string>
#include <iostream>

namespace haunted_house 
{
  const std::string House::directions[] = { "north", "east", "south", "west", "northeast", "northwest", "southeast", "southwest", "up", "down" };

  House::House() {
  	//Create rooms
  	Room *p1 = new Room("This is a hallway. It leads to many exiting rooms. ");
  	Room *p2 = new Room("This is a kitchen. You can eat some things here, but look out for poison!");
  	Garden *p3 = new Garden("This is a rose garden. There may be something buried here");
  	Room *p4 = new Room("This is an ordinary room.");
  	Room *p5 = new Room("This is an ordinary room.");

  	// Create items
  	Item *it1 = new Pill();
  	p4->drop(*it1);

  	// Drop items in rooms

  	// Connect rooms
  	p1->setNeighbour(Place::north, p2);
  	p1->setNeighbour(Place::east, p3);
  	p1->setNeighbour(Place::south, p4);
  	p1->setNeighbour(Place::west, p5);

  	p2->setNeighbour(Place::south, p1);
  	p3->setNeighbour(Place::west, p1);
  	p4->setNeighbour(Place::north, p1);
  	p5->setNeighbour(Place::east, p1);
  	
  	// Add rooms to list
  	places.push_back(p1);
  	places.push_back(p2);
  	places.push_back(p3);
  	places.push_back(p4);
  	places.push_back(p5);
  }

  House::~House() {

  }

  void House::printHouse() {
  	for(int i=0; i<places.size(); ++i) {
  		std::cout << places[i]->type() << " : " << places[i]->description() << std::endl;

  		std::vector<int> dir = places[i]->directions();
  		std::cout << "Directions: ";
  		for(int j=0; j<dir.size(); ++j) {
  			std::cout << directions[dir[j]] << ", ";
  		}
  		std::cout << std::endl;

		std::vector<std::string> it = places[i]->items();
  		std::cout << "Items: ";
		for(int j=0; j<it.size(); ++j) {
  			std::cout << it[j] << ", ";
  		}

  		std::cout << std::endl;
  		std::cout << "-------" << std::endl;
  	}
  }

} /*end namespace*/

  int main() {
  	haunted_house::House h;
  	h.printHouse();
  	return 0;
  }


