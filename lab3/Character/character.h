#ifndef CHARACTER_H_
#define CHARACTER_H_

class Place;
#include <string>
#include <map>
#include <iostream>
#include "../place.h"
#include "../Items/item.h"
#include "../Items/pill.h"

using namespace std;
namespace haunted_house
{
	class Character{
		protected: //private?
			string m_name;
			int m_item_capacity;
			map<string, Item*> m_item_container;
			signed int m_life;
			string m_type;
			Place* m_location;

		public:
			~Character(){};

			string name() const;
						
			signed int life() const;
			void change_life(int change);
			
			string type() const;
			void change_type(string type);

			Place* location();
			void change_location(Place *location);
						
			int container_size() const;
			int container_capacity() const;
			bool pick_up(Item& item);
			bool drop(Item& item);

			bool go(int direction);
			bool eat(Pill& pill);

			virtual bool action() = 0; //aktörens tur att agera
			virtual bool fight(Character& c) = 0;
	};
}	
#endif