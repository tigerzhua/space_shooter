#ifndef CARRIER_BASED_H
#define CARRIER_BASED_H

#include "machine.h"

#include "machine_types.h"

class Carrier_based: public Machine_object
{
    public:
        Carrier_based();
        ~Carrier_based();

        Object* get_base();
        inline Machine::Type::type get_base_type();


    private:
        Object* _base;
        Machine::Type::type _base_type;
};

inline Machine::Type::type Carrier_based::get_base_type() {return _base_type;}

#endif //CARRIER_BASED_H
