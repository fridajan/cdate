#ifndef DEAD_H_
#define DEAD_H_

#include <string>
#include <map>
#include "item.h"
#include "character.h"
#include "alive.h"
#include "pill.h"

using namespace std;
namespace haunted_house
{
	class Dead : public Character{
		public:
			~Dead(){};
			
			virtual bool action() = 0; //aktörens tur att agera
			virtual bool go(int direction = 0) = 0;
			virtual bool eat(Pill& pill) = 0;
			bool fight(Character& c);
	};
}	
#endif