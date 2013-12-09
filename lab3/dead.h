#ifndef DEAD_H_
#define DEAD_H_

#include <string>
#include <map>
#include "item.h"
#include "character.h"

using namespace std;
namespace haunted_house
{
	class Dead : public Character{
		protected:
			int death;
		public:
			virtual bool action() = 0; //aktörens tur att agera
	};
}	
#endif