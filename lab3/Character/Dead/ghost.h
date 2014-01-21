#ifndef GHOST_H_
#define GHOST_H_
#include "dead.h"
#include "../../Items/pill.h"

namespace haunted_house
{
	class Human;
	class Ghost: public Dead{

		public:
			Ghost();
			Ghost(std::string name);
			~Ghost(){};
			Ghost(const Character &d);	//TODO How to copy and assign??

			virtual bool action(); //aktörens tur att agera
			virtual bool go(int direction = 0){return false;}; //Can go through any walls
			virtual bool eat(Pill& pill){ return false;};

			bool steal();
	};
}
#endif