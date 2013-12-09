#ifndef ALIVE_H_
#define ALIVE_H_

#include <string>
#include <map>
#include "item.h"
#include "character.h"

using namespace std;
namespace haunted_house
{
	class Alive : public Character{
		protected:
			int life;
		public:
			virtual bool action() = 0; //aktörens tur att agera
	};
}	
#endif