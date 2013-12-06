#ifndef ROOM_H_
#define ROOM_H_

#include "item.h"
#include <stdexcept>
#include <string>

namespace haunted_house 
{
  class Room {
  private:
  	std:vector<int> m_directions;
  	std:map<std::string, Item> m_items;

  public:
    virtual ~Rooms() { };

    virtual std::vector<int> directions() const =0;

    virtual Room& neighbour(int direction) const =0;

    virtual std::string description() =0;

    virtual bool enter(Character& c) =0;

    virtual bool leave(Character& c) =0;

    virtual bool pick_up(Item& it) =0;

    virtual bool drop(Item& it) =0;

  };
}


#endif /* ROOM_H_ */
