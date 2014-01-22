#ifndef HOUSE_H_
#define HOUSE_H_

#include "place.h"
#include "room.h"
#include "garden.h"
#include "Items/item.h"
#include <stdexcept>
#include <string>
#include <vector>
#include <map>


namespace haunted_house 
{
  class House {
  private:
    std::vector<Place*> places;

  public:

    House();

    ~House();

    void printHouse();

    static const std::string directions[];

  };
}


#endif /* HOUSE_H_ */

