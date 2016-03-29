#ifndef OBJECTS_H
#define OBJECTS_H

// c-style includes
#include <stdio.h>
#include <stdlib.h>

// c++ style includes
#include <string>
#include <iostream>

// local includes
#include "vector3d.h"
#include "point3d.h"
#include "machine_types.h"
#include "item.h"

//main
#include <SFML/Graphics.hpp>
#include <math.h>

/*
For player and enemies on the screen
*/

class Object
{
    public:

        //basic functions
        Object();
        ~Object();

        inline Machine::Cur_state::cur_state  get_state();
        inline Machine::Type::type            get_type();
        inline Machine::Flag::flag            get_flag();
        inline Machine::Faction::faction      get_faction();

        int get_hp();
        void set_u_id(char* new_id);//set up new_id before calling this function
                                    //delete old char* if already have content
        char* generate_u_id();//automatically generate an u_id
        void load_texture(char* filename);//overwrite the old one
        sf::Texture* get_texture_ptr();

        //damage functions
        bool can_fire();

        //public storage
        sf::Time obj_timer;//TODO for, say, fire?

        //virtual functions
        void set_texture();

    private:

        int                _hp;       //hit point
        int                _cur_hp;
        Machine::Type::type            _type;
        Machine::Cur_state::cur_state  _state;
        Machine::Flag::flag            _f;
        Vector3d           _max_v;
        Vector3d           _min_v;
        float              _mass;    //used to calculate speed, etc.
        std::vector<Item*> _items;   //all default items&modules the machine is carrying

        char* _u_id;
        sf::Texture* _texture;//appearance

        //a member describing damage model

        //TODO:Animation components
        //TODO:Modules

        void clear();

};

inline sf::Texture*                   Object::get_texture_ptr(){return _texture;}
inline Machine::Cur_state::cur_state  Object::get_state(){return _state;}
inline Machine::Type::type            Object::get_type(){return _type;}
inline Machine::Flag::flag            Object::get_flag(){return _f;}
inline int                            Object::get_hp(){return _hp;}

#endif // OBJECTS_H
