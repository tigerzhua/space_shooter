#ifndef MACHINE_H
#define MACHINE_H

#include "objects.h"
#include "bullet.h"

class Machine_object: public Object
{
    public:
        Machine_object();
        ~Machine_object();

        void fire();
        bool being_hit(Bullet* b);
};

#endif //MACHINE_H
