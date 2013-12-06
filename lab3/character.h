#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string.h>
#include <iostream>
#include <map>
#include <Item.h>


using namespace std;
namespace haunted_house
{
	class Character{
		virtual int item_capacity = 0;
		virtual string name = 0;
		virtual string type = 0;
		virtual map<string, Item> item_container = 0;

	public:
		virtual string type() = 0; //returnerar namnet på arten, t.ex. trollkarl eller drake
		virtual string name() = 0; //returnerar namnet på varelsen, t.ex. Merlin
		virtual bool action() = 0; //aktörens tur att agera
		virtual bool go(int direction) = 0; //gå åt håll
		virtual bool fight(Character c) = 0; //slåss med
		virtual bool pick_up(Item item) = 0; //ta upp sak
		virtual bool drop(Item item) = 0; //släpp sak på marken
		virtual string talk_to(Character c) = 0; //konversera med
	};
}
#endif