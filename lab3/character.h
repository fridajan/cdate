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
		protected:
			string m_name;
			int m_item_capacity;
			map<string, Item*> m_item_container;
			int m_life;

		public:
/*			Character(const Character& c){

			}*/
			~Character(){};

			string name();
			int container_size();
			int container_capacity();
			bool pick_up(Item& item);
			bool drop(Item& item);
			int life();
			void change_life(int change);

			virtual bool action() = 0; //aktörens tur att agera
			virtual bool go(int direction = 0) = 0;
			virtual bool eat(Pill& pill) = 0;
			virtual bool fight(Character& c) = 0;
	};
}	
#endif