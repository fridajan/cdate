#include "place.h"

namespace haunted_house 
{

  Place::Place() 
  {
  }

  Place::~Place() 
  { 
  }

  std::vector<int> Place::directions() const 
  {
    return m_directions;
  }

  Place& Place::getNeighbour(int direction) 
  {
    if(m_neighbours.find(direction) == m_neighbours.end()) {
      return *m_neighbours[direction];
    } else {
      return *this;
    }
  }

  void Place::setNeighbour(int direction, Place* place)
  {
    m_neighbours[direction] = place;
  }

  std::string Place::description() 
  {
    return m_description;
  }

  std::string Place::type() 
  {
    return m_type;
  }

  bool Place::enter(Character& c) 
  {
    if(locked) {
      //TODO key?
      return false;
    } else {
      m_characters.push_back(&c);
      return true;
    }
  }

  bool Place::leave(Character& c) 
  {
    return true;
  }

  bool Place::pick_up(std::string it) 
  {
    if(m_items.find(it) == m_items.end()) {
      return true;
    } else {
      return false;
    }
  }

  bool Place::drop(Item& it) 
  {
    m_items[it.name()] = &it;
  }

} /*end namespace*/

