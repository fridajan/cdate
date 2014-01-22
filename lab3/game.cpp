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
		setup_game_board();

		srand(time(NULL)); //Generate random
		for(int i = 0; i < (int)characters.size(); ++i){
			int random_room = rand() % (int)places.size(); 
			characters[i]->change_location(places[random_room]);
			//places[random_room]->enter(characters[i]); //TODO add the characters to the room too!
		}
		printf("Setup complete\n");
	};

	void Game::setup_game_board(){
		//Create rooms
	  	Room *p1 = new Room("This is a hallway. It leads to many exiting rooms. ");
	  	Room *p2 = new Room("This is a kitchen. You can eat some things here, but look out for poison!");
	  	Garden *p3 = new Garden("This is a rose garden. There may be something buried here");
	  	Room *p4 = new Room("This is an ordinary room 1.");
	  	Room *p5 = new Room("This is an ordinary room 2.");

	  	// Create items
	  	Item *it1 = new Pill();
	  	p4->drop(*it1);

	  	// Drop items in rooms

	  	// Connect rooms
	  	p1->setNeighbour(Place::north, p2);
	  	p1->setNeighbour(Place::east, p3);
	  	p1->setNeighbour(Place::south, p4);
	  	p1->setNeighbour(Place::west, p5);

	  	p2->setNeighbour(Place::south, p1);
	  	p3->setNeighbour(Place::west, p1);
	  	p4->setNeighbour(Place::north, p1);
	  	p5->setNeighbour(Place::east, p1);
	  	
	  	// Add rooms to list
	  	places.push_back(p1);
	  	places.push_back(p2);
	  	places.push_back(p3);
	  	places.push_back(p4);
	  	places.push_back(p5);

	};

	void Game::setup_characters(){
		Human *h = new Human("Meg", NULL);
		Ghost *g = new Ghost("Bono");
		Human *g2 = new Human("Bob", NULL);

		characters.push_back(h);
		characters.push_back(g);
		characters.push_back(g2);
	};
	
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
		//while (!finished() || quit) {
       		/*Command command = parser.getCommand();
            quit = processCommand(command);*/
            for(int i = 0; i < (int)characters.size(); ++i){	
				//characters[i]->fight(*characters[(i+1)%characters.size()]);
				characters[i]->action();
				std::cout << i<<characters[i]->name() << std::endl;
			}
		//}
        std::cout << whoIsTheWinner() << " is the winner!" << std::endl;
                printf("Play loop complete\n");
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