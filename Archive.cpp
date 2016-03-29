    //machine type
    if(s->mach_type == "INVALID")           {scp.mach_type = Machine::Type::INVALID;}
    else if(s->mach_type == "AIRSHIP")      {scp.mach_type = Machine::Type::AIRSHIP;}
    else if(s->mach_type == "AIRSHIP_L")    {scp.mach_type = Machine::Type::AIRSHIP_L;}
    else if(s->mach_type == "PLANE")        {scp.mach_type = Machine::Type::PLANE;}
    else if(s->mach_type == "HELI")         {scp.mach_type = Machine::Type::HELI;}
    else if(s->mach_type == "CARRIER_S")    {scp.mach_type = Machine::Type::CARRIER_S;}
    else if(s->mach_type == "FIGHTER_C")    {scp.mach_type = Machine::Type::FIGHTER_C;}
    else if(s->mach_type == "BOMBER_C")     {scp.mach_type = Machine::Type::BOMBER_C;}
    else if(s->mach_type == "GUARD_C")      {scp.mach_type = Machine::Type::GUARD_C;}
    else if(s->mach_type == "CARRIER")      {scp.mach_type = Machine::Type::CARRIER;}
    else if(s->mach_type == "BATTLESHIP")   {scp.mach_type = Machine::Type::BATTLESHIP;}
    else if(s->mach_type == "BATTLECRUISER"){scp.mach_type = Machine::Type::BATTLECRUISER;}
    else if(s->mach_type == "CRUISER")      {scp.mach_type = Machine::Type::CRUISER;}
    else if(s->mach_type == "DESTROYER")    {scp.mach_type = Machine::Type::DESTROYER;}
    else if(s->mach_type == "FRIGATE")      {scp.mach_type = Machine::Type::FRIGATE;}
    else if(s->mach_type == "BOMB_L")       {scp.mach_type = Machine::Type::BOMB_L;}
    else if(s->mach_type == "BULLET")       {scp.mach_type = Machine::Type::BULLET;}
    else{}
