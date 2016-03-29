#ifndef ITEM_H
#define ITEM_H

//stl include
#include <stdlib.h>

//SFML
#include <SFML/Graphics.hpp>

//Local include
#include "machine_types.h"
#include "objects.h"

/*
The class not only for items,
but equipments, modules, etc
*/

class Item : public Object
{
    public:
        Item();
        ~Item();

        //member access
        inline int get_armor()                             {return _armor;}
        inline int get_fire_power()                        {return _fire_power;}
        inline int get_heal_pts()                          {return _heal_pts;}
        inline Machine::Module_type::module_type get_type(){return _type;}
        inline Machine::Module_size::module_size get_size(){return _size;}

        //utilities
        void set_armor(int armor)                            {_armor = armor;}
        void set_fire_power(int fire_power)                  {_fire_power = fire_power;}
        void set_heal_pts(int heal_pts)                      {_heal_pts = heal_pts;}
        void set_type(Machine::Module_type::module_type type){_type = type;}
        void set_size(Machine::Module_size::module_size size){_size = size;}

    private:
        int _armor, _fire_power, _heal_pts;
        Machine::Module_type::module_type _type;
        Machine::Module_size::module_size _size;
};

#endif // ITEM_H
