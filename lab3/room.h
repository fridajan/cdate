#ifndef ROOM_H_
#define ROOM_H_

#include "place.h"
#include <stdexcept>
#include <string>
#include <vector>

namespace haunted_house 
{
  class Room : public Place {

  public:

    Room()
    {
      std::vector<int> directions = { Direction::north, Direction::south, Direction::east, Direction::west };
      //Place(description, directions);
    }

    ~Room() { };

  };
}


#endif /* ROOM_H_ */
