#ifndef GAME_H_
#define GAME_H_

#include "Character/character.h"
#include "Character/Alive/human.h"
#include "Character/Dead/ghost.h"
#include "place.h"
#include "room.h"
#include "garden.h"

//#include "room.h"
#include <iostream>
#include <vector>
namespace haunted_house
{
	class Game{
		void setup();
		bool finished();
		bool processCommand();

		std::vector<Character*> characters;
		std::vector<Place*> places;

		public:
			Game();
			~Game();

			void play();
			string whoIsTheWinner();
			
			void setup_characters();
			void setup_game_board();
			void setup_characters_in_room();

	};
}
#endif