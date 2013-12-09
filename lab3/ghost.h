#ifndef GHOST_H_
#define GHOST_H_
#include "dead.h"
namespace haunted_house
{
	class Ghost: public Dead{

		public:
			Ghost();
			Ghost(std::string name);
			~Ghost(){};

			virtual bool action(){return false;}; //aktörens tur att agera
	};
}
#endif