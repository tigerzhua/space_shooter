#ifndef MACHINE_H
#define MACHINE_H

#include "objects.h"
#include "bullet.h"
#include "item.h"

class Machine_object: public Object
{
    public:
        Machine_object();
        ~Machine_object();

        //member access
        inline Machine::Cur_state::cur_state  get_state() {return _state;}
        inline Machine::Type::type            get_type()  {return _type;}
        inline Machine::Flag::flag            get_flag()  {return _f;}

        //utilities
        void fire();

        //inquery
        bool can_fire();
        bool being_hit(Bullet* b);

    private:

        std::vector<Item*> _items;   //all default items&modules the machine is carrying
        Machine::Type::type            _type;
        Machine::Cur_state::cur_state  _state;
        Machine::Flag::flag            _f;
        Vector3d           _max_v;
        Vector3d           _min_v;
};

#endif //MACHINE_H
