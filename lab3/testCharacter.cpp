#include "human.h"
#include "ghost.h"
#include "character.h"
#include "item.h"
#include "pill.h"

#include <vector>
#include <string.h>
#include <iostream>
#include <assert.h>

using namespace std;
using namespace haunted_house;
int main(){
	Human gunilla("Gunilla");
	Human juan;
	Ghost casper;
	Ghost laban("Laban");

	//Test, Juan pick up pill, eat it, and removes it from its backpack
	cout << "############################TEST####################" << endl;
	cout << "Juan pick up pill, eat it, and removes it from its backpack" << endl;
	Pill p;
	//Human bob(gunilla);
	assert(juan.container_size()==0);
	juan.pick_up(p);
	assert(juan.container_size()==1);
	bool b = juan.eat(p);
	if(b){
	 	cout << "Juan ate the pill! now the size of backpack is: " << juan.container_size()<< endl;
		assert(juan.container_size()==0);
	}else{
		assert(juan.container_size()==1);
	}
	cout << "_______________END_OF_TEST____________________" << endl;


	//Test Put different characters in a character vector
	cout << "############################TEST####################" << endl;
	cout << "Put different characters in a character vector" << endl;
	std::vector<Character*> v; //TODO ERROR with vector of characters...
	v.push_back(&juan);
	v.push_back(&casper);
	assert(v[0]->name() == "Juan");
	assert(v[1]->name() == "Casper");
	cout << "_______________END_OF_TEST____________________" << endl;

	cout << "############################TEST####################" << endl;
	cout << "_______________FIGHT__________" << endl;
	cout << "Juan has life: " << juan.life()<< " before fight against Casper buuuuuuh"<<endl;
	b = juan.fight(casper);
	if(b){
		cout << "Juan Won! and gained life: " << juan.life()<< endl;
	}else{
		cout << "Juan Lost!" << endl;
	}
	return 0;
}