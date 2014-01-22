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

			bool steal();
	};
}
#endif