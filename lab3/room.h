#ifndef ROOM_H_
#define ROOM_H_

#include "item.h"
#include <stdexcept>
#include <string>

//TODO: makefile

namespace haunted_house 
{
  class Room {
  private:
    std::string m_description;
  	std:vector<int> m_directions;
    std::std::vector<Character*> m_characters;
  	std:map<std::string, Item*> m_items;
    std:map<int, Room> m_neighbours;

  public:
    enum Direction {
      north, east, south, west, northeast, northwest, southeast, southwest;
    };

    virtual ~Rooms() { };

    virtual std::vector<int> directions() const {
      return m_directions;
    };

    virtual Room& getNeighbour(int direction) const {
      if(m_neighbours.find(direction) == m_neighbours.end()) {
        return *m_neighbours[direction];
      } else {
        return NULL;
      }
    };

    virtual std::string description() {
      return m_description;
    };

    virtual bool enter(Character& c) =0;

    virtual bool leave(Character& c) =0;

    virtual bool pick_up(std::string it) {
      if(m_items.find(direction) == m_neighbours.end()) {
        return true;
      } else {
        return false;
      }
    };

    virtual bool drop(Item& it) =0;

  };
}


#endif /* ROOM_H_ */
