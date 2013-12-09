#ifndef PILL_H_
#define PILL_H_

#include <stdexcept>
#include <string>
#include "item.h"

using namespace std;

namespace haunted_house 
{
  class Pill : public Item {
    int m_color;
    public:
      Pill();
      Pill(int col);

      string color();
      int use();

      virtual string name();
      virtual string description();
      virtual int magic_power() const;
      virtual int weight() const;
      virtual int volume() const;
      virtual int price() const;

  };
}

#endif