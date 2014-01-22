#ifndef ALIVE_H_
#define ALIVE_H_

#include <string>
#include <map>
#include "../../item.h"
#include "../character.h"
#include "../../pill.h"
#include "../../place.h"

using namespace std;
namespace haunted_house
{
	class Alive : public Character{
		public:
			virtual bool go(int direction = 0) = 0;
			virtual bool eat(Pill& pill) = 0;
			
			bool fight(Character& c);
			bool action(); //aktörens tur att agera
	};
}	
#endif