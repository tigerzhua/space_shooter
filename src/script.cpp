#include "script.h"

Script::Script(){}

Script::Script(const char* filename, Level* level){
    read_script(filename, level);
}

Script::~Script(){}

void Script::read_script(const char* filename, Level* level){
    //assume level ptr valid
    std::ifstream infile(filename, std::ios::in);
    if (!infile) { std::cout<<"Cannot open script file "<<filename<<std::endl; return; }

    std::cout<<"Loading script: "<<filename<<std::endl;
    //real loading start
    //separate with white space
    std::string line;
    Script_type::One_script this_one;
    while (getline(infile, line)) {
        if (line.size() != 0){
            if (line.substr(0,2) != "##"){//not a comment
                std::istringstream input_stream(line);
                //Build necessary storages

                input_stream >> this_one.oprt;
                input_stream >> this_one.mach_type;
                input_stream >> this_one.u_id;
                input_stream >> this_one.from_x; input_stream >> this_one.from_y;
                input_stream >> this_one.to_x; input_stream >> this_one.to_y;
                input_stream >> this_one.delta;
                input_stream >> this_one.period;
                input_stream >> this_one.faction;
                input_stream >> this_one.group;
                input_stream >> this_one.time_s; input_stream >> this_one.time_cycle;
                input_stream >> this_one.AI;
            }
        }
        else { /* ignoring this line */ }

        //now build screen object
        process_element(&this_one, level);

  }
  std::cout<<"Loading script "<<filename<<" successful!"<<std::endl;
  infile.close();
}

void Script::process_element(Script_type::One_script* s, Level* level){
    //setup
    bool obj_exist = false;
    Script_type::Real_script scp;//record everything into this

    //psudocode:
    //if (search(s->u_id))
    //    obj_exist = true;

    //operator

    if((s->oprt == "Add")||
       (s->oprt == "A")){
        //if (!obj_exist){}
        }
    else if((s->oprt == "Move")||
            (s->oprt == "Mov")||
            (s->oprt == "M")){
            }
    else if((s->oprt == "Teleport")||
            (s->oprt == "Tele")||
            (s->oprt == "Tel")){
            }
    else{}

    //machine type
    /*
    switch(s->mach_type){
        case "INVALID":{
            scp.mach_type = Machine::Type::INVALID;
            }break;
        case "AIRSHIP":
            break;
        case "AIRSHIP_L":
            break;
        case "PLANE":
            break;
        case "HELI":
            break;
        case "CARRIER_S":
            break;
        case "FIGHTER_C":
            break;
        case "BOMBER_C":
            break;
        case "GUARD_C":
            break;
        case "CARRIER":
            break;
        case "BATTLESHIP":
            break;
        case "BATTLECRUISER":
            break;
        case "CRUISER":
            break;
        case "DESTROYER":
            break;
        case "FRIGATE":
            break;
        case "BOMB_L":
            break;
        case "BULLET":
            break;
        default:
            break;
    }

    //machine type
    switch(s->faction){
        case "NETURAL":
            break;
        case "PLAYER":
            break;
        case "OPPONENT":
            break;
        default:
            break;
    }
    */
}
