#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
#include <map>
#include "item.h"
#include "pill.h"

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

		public:
/*			Character(const Character& c){

			}*/
			~Character(){};

			string name() const;
						
			signed int life() const;
			void change_life(int change);
			
			string type() const;
			void change_type(string type);
						
			int container_size() const;
			int container_capacity() const;
			bool pick_up(Item& item);
			bool drop(Item& item);

			virtual bool action() = 0; //aktörens tur att agera
			virtual bool go(int direction = 0) = 0;
			virtual bool eat(Pill& pill) = 0;
			virtual bool fight(Character& c) = 0;
	};
}	
#endif