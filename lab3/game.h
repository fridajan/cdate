#ifndef GAME_H_
#define GAME_H_

#include "character.h"

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
		//std::vector<Room*> board;

		public:
			Game();
			~Game();

			void play();
			string whoIsTheWinner();
			void setup_characters();

	};
}
#endif