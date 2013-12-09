#ifndef HUMAN_H_
#define HUMAN_H_
#include "alive.h"
#include <string>
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
	};
}
#endif