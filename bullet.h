#ifndef BULLET_H
#define BULLET_H

#include "objects.h"
#include "screen_object.h"

class Bullet: public Screen_object
{
    public:
        Bullet();
        ~Bullet();

        inline Machine::Bullet_type::bullet_type get_type();
        float get_damage();
        bool hit();

    private:
        float _damage;
        Machine::Bullet_type::bullet_type _type;
};

inline float                              Bullet::get_damage(){return _damage;}
inline Machine::Bullet_type::bullet_type  Bullet::get_type(){return _type;}

#endif // EBULLET_H
