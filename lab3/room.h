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

    Room(std::string description)
    {
      m_type = "Room";
      m_description = description;
    }

    Room()
    {
    }

    ~Room() { };

  };
}


#endif /* ROOM_H_ */
