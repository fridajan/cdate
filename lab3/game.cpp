#include "game.h"
#include <string>
#include <climits>
#include <cmath>
namespace haunted_house
{
	Game::Game(){
		setup();
	};
	
	Game::~Game(){
		//tear down all rooms, characters and items!
		//TODO remove the items in the vectors, otherwise memory leakage
	};

	void Game::setup(){
		//Setup characters
		setup_characters();
		//Setup Board

		//Setup Items in room  
	};

	void Game::setup_characters(){
		Human *h = new Human("Meg");
		Ghost *g = new Ghost("Bono");
		Human *g2 = new Human("Bob");

		characters.push_back(h);
		characters.push_back(g);
		characters.push_back(g2);
		std::cout << characters[0]->name() << ": " << h  << std::endl;
		std::cout << characters[1]->name() << ": " << &g  << std::endl;
		std::cout << characters[2]->name() << ": " << &g2  << std::endl;
		printf("Setup complete\n");
	}
	
	bool Game::finished(){
		//Setup finish goals
		
		for(int i = 0; i < (int)characters.size(); ++i){
			std::cout << characters[i]->life() << std::endl;
			if(characters[i]->type() == "Human" && characters[i]->life() <= 0) return true;
			if(characters[i]->type() == "Ghost" && characters[i]->life() >= 0) return true;
		}
		return false;
	};

	void Game::play(){
		printf("In game loop\n");
		bool quit = false;
		while (!finished() || quit) {
       		/*Command command = parser.getCommand();
            quit = processCommand(command);*/
            for(int i = 0; i < (int)characters.size(); ++i){	
				characters[i]->fight(*characters[(i+1)%characters.size()]);
			}
		}
        printf("Play loop complete\n");
        std::cout << whoIsTheWinner() << std::endl;
	};

	bool Game::processCommand(){
		bool quit = false;
		//If command is quit, change to true
		return quit;
	};

	string Game::whoIsTheWinner(){
		int max = INT_MIN;
		string winner;
  		for(int i = 0; i < (int)characters.size(); ++i){	
			if(abs(characters[i]->life()) > max){
				max = abs(characters[i]->life());
				winner = characters[i]->name();
			} 
		}
		return winner;
	}
}