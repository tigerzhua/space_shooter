//Types utilized in game engines
#ifndef SCRIPT_TYPES_H
#define SCRIPT_TYPES_H

#include <stdlib.h>
#include <string>
#include "machine_types.h"
#include "engine_types.h"
#include "screen_object.h"

namespace Script_type
{
    enum Obj_action_pattern{
        INVALID,
        RANDOM,
        HOLD,//not moving
        FOLLOW,
        MANUAL,//script give specific instructions
        AI_BASIC,
        AI_IMPROVED,
        AI_ADVANCED,
        AI_MASTER
    };

    enum Time_stamp_type{
        IMMEDIATE,
        DELAY
    };

    enum Operator{
        MOVE,
        ADD,
        TELEPORT
    };

    typedef struct{
        std::string oprt;
        std::string mach_type;
        std::string u_id;
        float from_x, from_y, to_x, to_y;
        float delta, period;
        std::string faction;
        int group, time_s, time_cycle;
        std::string AI;
    }One_script;

    typedef struct{
        Operator oprt;
        Machine::Type::type mach_type;
        std::string u_id;
        float from_x, from_y, to_x, to_y;
        float delta, period;
        Machine::Faction::faction faction;
        int group, time_s, time_cycle;
        std::string AI;
    }Real_script;
}

#endif
