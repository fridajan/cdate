#ifndef ITEM_H_
#define ITEM_H_

#include <stdexcept>
#include <string>

namespace haunted_house 
{
  class Item {

    protected:
      std::string m_name;
      int m_magic_power;
      int m_weight;
      int m_volume;
      int m_price;
  
    public:
      //~Item(){};
      virtual std::string name() =0;
      virtual std::string description() =0;
      virtual int magic_power() const =0;
      virtual int weight() const =0;
      virtual int volume() const =0;
      virtual int price() const =0;

      //Some kind of use function

  };
}



#endif /* ITEM_H_ */
