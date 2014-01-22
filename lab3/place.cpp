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

  Place* Place::getNeighbour(int direction) 
  {
    if(m_neighbours.find(direction) != m_neighbours.end()) {
      return m_neighbours[direction];
    } else {

      printf("%p\n", &*this);
      return this;
    }
  }

  void Place::setNeighbour(int direction, Place* place)
  {
    m_neighbours[direction] = place;
    m_directions.push_back(direction);
  }

  std::string Place::description() 
  {
    return m_description;
  }

  std::string Place::type() 
  {
    return m_type;
  }

  bool Place::enter(Character* c) 
  {
    if(locked) {
      //TODO key?
      return false;
    } else {
      m_characters.push_back(c);
      return true;
    }
  }

  bool Place::leave(Character* c) 
  {
    return true;
  }

 vector<std::string> Place::items()
 {
    vector<std::string> v;
    for(std::map<std::string, Item*>::iterator it = m_items.begin(); it != m_items.end(); ++it) {
      v.push_back(it->first);
    }
    return v;
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

