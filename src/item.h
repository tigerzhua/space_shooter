#ifndef ITEM_H
#define ITEM_H

//stl include
#include <stdlib.h>

//SFML
#include <SFML/Graphics.hpp>

//Local include
#include "machine_types.h"

/*
The class not only for items,
but equipments, modules, etc
*/
class Item{
    public:
        Item();
        ~Item();

        float mass;
        int hp, armor, fire_power, heal_pts;
        int special_effect;//idx
        int cur_hp;

        //textures
        sf::Texture* texture;

        Machine::Module_type::module_type type;
        Machine::Module_size::module_size size;

};

#endif // ITEM_H
