#ifndef GHOST_H_
#define GHOST_H_
#include "dead.h"
#include "human.h"
#include "alive.h"
#include "pill.h"

namespace haunted_house
{
	class Human;
	class Ghost: public Dead{

		public:
			Ghost();
			Ghost(std::string name);
			~Ghost(){};
			Ghost(const Character &d);	//TODO How to copy and assign??

			virtual bool action(){return false;}; //aktörens tur att agera
			virtual bool go(int direction = 0){return false;}; //Can go through any walls
			bool steal();
			virtual bool eat(Pill& pill){ return false;};
			virtual bool fight(Character& c);
	};
}
#endif