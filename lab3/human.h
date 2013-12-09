#ifndef HUMAN_H_
#define HUMAN_H_
#include "alive.h"
#include "pill.h"
#include "item.h"
#include <string>

#include <iostream>
#include <map>
#include <stdlib.h>     /* srand, rand */

using namespace std;
namespace haunted_house
{
	class Human: public Alive{
		public:
			Human();
			Human(string name);
			~Human(){};
			Human(const Human &h);	//TODO How to copy and assign??
			Human& operator=(const Human &h);

			virtual bool action(){return false;}; //aktörens tur att agera
			virtual bool go(int direction){return false;};
			virtual bool eat(Pill& pill);
			virtual bool fight(Character& c);
	};
}
#endif