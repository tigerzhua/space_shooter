//Types utilized in game engines
#ifndef MACHINE_TYPES_H
#define MACHINE_TYPES_H

#include <stdlib.h>

enum class Faction {
            NETURAL,
            PLAYER,
            OPPONENT
};

namespace Machine
{
    namespace Type{
        enum type {
            INVALID,
            //driveable by players
            AIRSHIP,
            AIRSHIP_L,
            PLANE,
            HELI,
            CARRIER_S,
            //
            //carried by carriers
            FIGHTER_C,
            BOMBER_C,
            GUARD_C,
            //
            //other types
            CARRIER,
            BATTLESHIP,
            BATTLECRUISER,
            CRUISER,
            DESTROYER,
            FRIGATE,
            BOMB_L,

            BULLET
        };
    };

    //state
    namespace Cur_state{
        enum cur_state {
            INVALILD,
            GOOD,
            DAMAGE_S,
            DAMAGE_M,
            DAMAGE_L,
            DEAD
        };
    };

    namespace Fire_type{
        enum fire_type {
            DISABLED,//cannot fire
            NORMAL,//normal pattern
            SPECIAL
        };
    };

    namespace Flag{
        enum flag {
            //TODO
            CAN_FIRE
        };
    };

    namespace Bullet_type{
        enum bullet_type {
            NORMAL
        };
    };

    //modules
    namespace Module_type{
        enum module_type{
            INVALID,
            GUN,
            ENGINE,
            ARMOR,
            TRANSPORT,
            POTION,
            ITEM,
            OTHER
        };
    };

    namespace Module_size{
        enum module_size{
            INVALID,
            TINY,
            SMALL,
            MEDIAM,
            LARGE,
            HUGE
        };
    };
};

#endif // MACHINE_TYPES_H
