#ifndef PLACE_H_
#define PLACE_H_

class Character;
#include "Character/character.h"
#include "Items/item.h"
#include <stdexcept>
#include <string>
#include <vector>
#include <map>

namespace haunted_house 
{
    class Character;
  class Place {
  private:
    std::string m_type;
    std::string m_description;
    std::vector<int> m_directions;
    std::vector<Character*> m_characters;
    std::map<std::string, Item*> m_items;
    std::map<int, Place*> m_neighbours;
    bool locked;

  public:
    friend class Room;
    friend class Garden;

    enum Direction { north, east, south, west, northeast, northwest, southeast, southwest, up, down };

    Place();

    ~Place();

    virtual std::vector<int> directions() const;

    virtual Place* getNeighbour(int direction);

    virtual void setNeighbour(int direction, Place* place);

    virtual std::string description();

    virtual std::string type();

    bool enter(Character* c);

    bool leave(Character* c);

    virtual std::vector<std::string> items();

    virtual bool pick_up(std::string it);

    virtual bool drop(Item& it);

  };
}


#endif /* PLACE_H_ */
