#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
#include <map>
#include "item.h"

using namespace std;
namespace haunted_house
{
	class Character{
		protected:
			string m_name;
			int m_item_capacity;
			map<string, Item&> m_item_container;


		public:
			~Character(){};

			string name();
			int container_size();
			int container_capacity();

			virtual bool action() = 0; //aktörens tur att agera
	};
}	
#endif