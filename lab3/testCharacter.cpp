#include "human.h"
#include "ghost.h"
#include "character.h"

#include <vector>
#include <string.h>
#include <iostream>

using namespace std;
using namespace haunted_house;
int main(){
	Human gunilla("Gunilla");
	Human juan;
	Ghost casper;
	Ghost laban("Laban");

	//Human bob(gunilla);


	std::vector<Character*> v; //TODO ERROR with vector of characters...
	v.push_back(&juan);
	v.push_back(&casper);

	for(unsigned int i = 0; i <v.size(); ++i){
		cout << v[i]->name() << endl;
	}

	return 0;
}