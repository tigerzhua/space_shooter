#include "script.h"

Script::Script(){}

Script::Script(const char* filename, Level* level, Data_base* db){
    read_script(filename, level, db);
}

Script::~Script(){}

void Script::read_script(const char* filename, Level* level, Data_base* db){
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
                input_stream >> this_one.msg;
            }
        }
        else { /* ignoring this line */ }

        //now build screen object
        Script_type::Real_script scp;
        process_element(&this_one, scp);
        add_to_level(scp, level, db);
  }
  std::cout<<"Loading script "<<filename<<" successful!"<<std::endl;
  infile.close();
}

void Script::process_element(Script_type::One_script* s, Script_type::Real_script& scp){
    //operator
    if((s->oprt == "Add")||(s->oprt == "A")){
        scp.oprt = Script_type::ADD;
    }
    else if((s->oprt == "Move")||(s->oprt == "Mov")||(s->oprt == "M")){
        scp.oprt = Script_type::MOVE;
    }
    else if((s->oprt == "Teleport")||(s->oprt == "Tele")||(s->oprt == "Tel")){
        scp.oprt = Script_type::TELEPORT;
    }
    else{}

    scp.obj_type = s->mach_type;
    scp.u_id   = s->u_id;
    scp.from_x = s->from_x;
    scp.from_y = s->from_y;
    scp.to_x   = s->to_x;
    scp.to_y   = s->to_y;
    scp.delta  = s->delta;
    scp.period = s->period;

    //machine faction
    if (s->faction == "NETURAL")      {scp.faction = Machine::Faction::NETURAL;}
    else if (s->faction == "PLAYER")  {scp.faction = Machine::Faction::PLAYER;}
    else if (s->faction == "OPPONENT"){scp.faction = Machine::Faction::OPPONENT;}
    else{}

    scp.group      = s->group;
    scp.time_s     = s->time_s;
    scp.time_cycle = s->time_cycle;
    scp.AI         = s->AI;
    scp.msg        = s->msg;
}

void Script::add_to_level(Script_type::Real_script& scp, Level* level, Data_base* db){
    //setup
    bool obj_exist = false;
    Screen_object* so = new Screen_object();

    if (scp.msg == "m")
        so->set_obj_ptr( db->get_machine(scp.obj_type) );

    if (scp.msg == "i")
        so->set_obj_ptr( db->get_item(scp.obj_type) );
    //level->add_screen_object();
}

Script_reader::Script_reader(Data_base* db){
    _db = db;
}

Script_reader::~Script_reader(){
    _db = nullptr;
}

void Script_reader::read(const char* file_name, Level* level, Data_base* db){
    Script temp;
    temp.read_script(file_name, level, db);
}
