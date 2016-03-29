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

        //member access
        int get_hp();
        sf::Texture* get_texture_ptr();
        void set_u_id(char* new_id);//set up new_id before calling this function
                                    //delete old char* if already have content
        inline Faction get_faction();

        //utilities
        char* generate_u_id();//automatically generate an u_id
        void load_texture(char* filename);//overwrite the old one
        void set_hp(int hp);

        //inqueries

        //TODO (may need to move to private) public storage
        sf::Time obj_timer;//TODO for, say, fire?

        //virtual functions
        void set_texture();

    private:

        int _hp;       //hit point
        float _mass;    //used to calculate speed, etc.
        int _special_effect;//idx
        char* _u_id;
        Faction _faction;

        sf::Texture* _texture;//appearance

        //a member describing damage model

        //TODO:Animation components
        //TODO:Modules

        void clear();

};

inline Faction      Object::get_faction()    {return _faction;}
inline sf::Texture* Object::get_texture_ptr(){return _texture;}
inline int          Object::get_hp()         {return _hp;}

#endif // OBJECTS_H
