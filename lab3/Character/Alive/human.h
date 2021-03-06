#ifndef HUMAN_H_
#define HUMAN_H_
#include "alive.h"
#include "../../Items/pill.h"
#include "../../Items/item.h"
#include <string>


#include <map>
#include <stdlib.h>     /* srand, rand */


using namespace std;
namespace haunted_house
{
	class Ghost;
	class Human: public Alive{
		public:
			Human();
			Human(string name);
			~Human(){};
			Human(const Character& d);	//TODO How to copy and assign??
			Human& operator=(const Character& h);

			virtual bool go(int direction){return false;};
			virtual bool eat(Pill& pill);
			//virtual bool fight(Character& c);
	};
}
#endif