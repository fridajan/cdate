#include "pill.h"
#include <stdlib.h>     /* srand, rand */

using namespace std;
namespace haunted_house 
{
		//TODO Make this global for haunted_house
		const int RED = 0;
		const int BLUE = 1;
		const int GREEN = 2;
		const int YELLOW = 3;
		const int MAX_MAGIC = 100;
	Pill::Pill(){
		m_color = GREEN;
		m_name = "Green pill"; //TODO
		m_volume = 1;
		m_price = 0;
		m_weight = 1;
		m_magic_power = rand() % MAX_MAGIC + 1;
	};

	Pill::Pill(int col){
		m_color = col;
		m_name = "TODO pill"; //TODO
		m_volume = 1;
		m_price = 0;
		m_weight = 1;
		m_magic_power = rand() % MAX_MAGIC + 1;
	}

	string Pill::name(){
		return m_name;
	};

      string Pill::description(){
      		return string("This is a ")+ color() + string(" pill, eat it if you dare!");
      };
    int Pill::use(){
    	//Set everything to 0??
    	return magic_power();
    }
  	string Pill::color(){
	  	if(m_color == RED){
	  		return "red";
	  	}else if(m_color == BLUE){
	  		return "blue";
	  	}else if(m_color == GREEN){
	  		return "green";
	  	}else if(m_color == YELLOW){
	  		return "yellow";
	  	}
	  	return "error";
  	}

  	int Pill::magic_power() const{
  		return m_magic_power;
  	};

  	int Pill::weight() const{ 
  		return m_weight;
  	};

  	int Pill::volume() const{ 
  		return m_volume;
  	};

  	int Pill::price() const{ 
  		return m_price;
  	};

 }