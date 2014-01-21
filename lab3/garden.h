#ifndef GARDEN_H_
#define GARDEN_H_

#include "place.h"
#include <stdexcept>
#include <string>
#include <vector>

namespace haunted_house 
{
  class Garden : public Place {

  public:

    Garden(std::string description)
    {
      m_type = "Garden";
      m_description = description;
    }

    Garden()
    {
    }

    ~Garden() { };

  };
}


#endif /* GARDEN_H_ */
