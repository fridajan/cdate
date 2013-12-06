#ifndef TEST_PERSON_H_
#define TEST_PERSON_H_

#include <string.h>
#include <iostream>
#include <map>
#include <Item.h>
#include <Character.h>


using namespace std;
namespace haunted_house
{
	class test_person : Character
	{
		virtual int item_capacity;
		virtual string name;
		virtual string type;
		virtual map<string, Item> item_container;

	public:
		virtual string type(); //returnerar namnet på arten, t.ex. trollkarl eller drake
		virtual string name(); //returnerar namnet på varelsen, t.ex. Merlin
		virtual bool action(); //aktörens tur att agera
		virtual bool go(int direction); //gå åt håll
		virtual bool fight(Character c); //slåss med
		virtual bool pick_up(Item item); //ta upp sak
		virtual bool drop(Item item); //släpp sak på marken
		virtual string talk_to(Character c); //konversera med
	};
}
#endif TEST_PERSON_H_
