#ifndef DEAD_H_
#define DEAD_H_

#include <string>
#include <map>
#include "../../Items/item.h"
#include "../character.h"
#include "../../Items/pill.h"

using namespace std;
namespace haunted_house
{
	class Dead : public Character{
		public:
			~Dead(){};
			
			bool fight(Character& c);
			bool action(); //aktörens tur att agera
	};
}	
#endif