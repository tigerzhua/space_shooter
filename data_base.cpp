#include "data_base.h"
//#include "machine_types.h"

Data_base::Data_base(){
    _machine_list.clear();
    _machine_idx.clear();
    _item_list.clear();
    _item_idx.clear();
    //load item first
    initialize_item_idx("assets/data/item_idx.txt");
    initialize_item_list("assets/data/item_data.txt");
    initialize_machine_idx("assets/data/machine_idx.txt");
    initialize_machine_list("assets/data/machine_data.txt");
}

Data_base::~Data_base(){

}

void Data_base::initialize(){
    _machine_list.clear();
    _machine_idx.clear();
    _item_list.clear();
    _item_idx.clear();
    //load item first
    initialize_item_idx("assets/data/item_idx.txt");
    initialize_item_list("assets/data/item_data.txt");
    initialize_machine_idx("assets/data/machine_idx.txt");
    initialize_machine_list("assets/data/machine_data.txt");
}

void Data_base::initialize_machine_idx(char* filename){
    std::ifstream infile(filename, std::ios::in);
    if (!infile) { std::cout<<"Cannot open machine_idx "<<std::endl; return; }

    std::cout<<"Loading machine_idx"<<std::endl;

    std::string line;
    int idx = 1;//initial idx
    std::map<std::string, int>::iterator it;
    while (getline(infile, line)) {
        if (line.size() != 0){
            it = _machine_idx.find(line);
            if( it == _machine_idx.end() ){//check if already exist
                _machine_idx.insert( std::pair<std::string,int>(line,idx) );
                idx += 1;
            }
        }
        else { /* ignoring this line */ }
  }
  _machine_list.resize(idx);
  std::cout<<"Loading machine_idx complete"<<std::endl;
  infile.close();
}

void Data_base::initialize_item_idx(char* filename){
    std::ifstream infile(filename, std::ios::in);
    if (!infile) { std::cout<<"Cannot open item_idx "<<std::endl; return; }

    std::cout<<"Loading item_idx"<<std::endl;

    std::string line;
    int idx = 1;//initial idx
    std::map<std::string, int>::iterator it;
    while (getline(infile, line)) {
        if (line.size() != 0){
            it = _item_idx.find(line);
            if( it == _item_idx.end() ){//check if already exist
                _item_idx.insert( std::pair<std::string,int>(line,idx) );
                idx += 1;
            }
        }
        else { /* ignoring this line */ }
  }
  _item_list.resize(idx);
  std::cout<<"Loading item_idx complete"<<std::endl;
  infile.close();
}

void Data_base::initialize_machine_list(char* filename){

}

void Data_base::initialize_item_list(char* filename){
    std::ifstream infile(filename, std::ios::in);
    if (!infile) { std::cout<<"Cannot open item_list "<<std::endl; return; }

    std::cout<<"Loading item_list"<<std::endl;

    std::string line;
    std::string contents;
    int idx = 0;//initial idx
    std::map<std::string, int>::iterator it;
    while (getline(infile, line)) {
        int line_size = line.size();
        if (line_size != 0){
            if ( (line_size >= 2)&&(line.substr(0,2) != "##") ){//not a comment
                if ( (line.substr(0,1) == "{")&&(line.substr(line_size-1,line_size) != "}") ){
                    if(contents.size() > 0){//we got a name
                        it = _item_idx.find(contents);
                        if( it == _item_idx.end() ){//doesn't exist
                            std::cout<<"missing item"<<std::endl;
                            break;
                        }
                        idx = it->second;
                        contents.clear();
                    }
                    contents.append(line.substr(2,line_size-1));
                }
                else if ( (line.substr(0,1) != "{")&&(line.substr(line_size-1,line_size) == "}") ){
                    contents.append(line.substr(0,line_size-1));
                    make_item(_item_list[idx], contents);
                    contents.clear();
                }
                else if ( (line.substr(0,1) == "{")&&(line.substr(line_size-1,line_size) == "}") ){
                    if(contents.size() > 0){//we got a name
                        it = _item_idx.find(contents);
                        if( it == _item_idx.end() ){//doesn't exist
                            std::cout<<"missing item"<<std::endl;
                            break;
                        }
                        idx = it->second;
                        contents.clear();
                    }
                    contents.append(line.substr(1,line_size-1));
                    make_item(_item_list[idx], contents);
                    contents.clear();

                } else
                    contents.append(line);
            }
        }
        else { /* ignoring this line */ }
  }
  std::cout<<"Loading item_list(data) complete"<<std::endl;
  infile.close();
}

void Data_base::make_item(Item& itm, std::string str){
    std::istringstream input_stream(str);
    input_stream >> itm.hp;
    input_stream >> itm.armor;
    input_stream >> itm.fire_power;
    std::string size_temp;
    input_stream >> size_temp;
        if (size_temp == "TINY")
            itm.size = Machine::Module_size::TINY;
        else if (size_temp == "SMALL")
            itm.size = Machine::Module_size::SMALL;
        else if (size_temp == "MEDIAM")
            itm.size = Machine::Module_size::MEDIAM;
        else if (size_temp == "LARGE")
            itm.size = Machine::Module_size::LARGE;
        else if (size_temp == "HUGE")
            itm.size = Machine::Module_size::HUGE;
        else
            itm.size = Machine::Module_size::INVALID;
    input_stream >> itm.heal_pts;
    input_stream >> itm.mass;
    //type
    std::string type_temp;
    input_stream >> type_temp;
        if (type_temp == "GUN")
            itm.type = Machine::Module_type::GUN;
        else if (type_temp == "ENGINE")
            itm.type = Machine::Module_type::ENGINE;
        else if (type_temp == "ARMOR")
            itm.type = Machine::Module_type::ARMOR;
        else if (type_temp == "TRANSPORT")
            itm.type = Machine::Module_type::TRANSPORT;
        else if (type_temp == "POTION")
            itm.type = Machine::Module_type::POTION;
        else if (type_temp == "ITEM")
            itm.type = Machine::Module_type::ITEM;
        else if (type_temp == "OTHER")
            itm.type = Machine::Module_type::OTHER;
        else
            itm.type = Machine::Module_type::INVALID;
    input_stream >> itm.special_effect;
    //TODO:read texture
}

int Data_base::get_machine_idx(std::string name){
    std::map<std::string, int>::iterator it;
    it = _machine_idx.find(name);
    if( it != _machine_idx.end() )
        return it->second;

    return -1;//not found
}

int Data_base::get_item_idx(std::string name){
    std::map<std::string, int>::iterator it;
    it = _item_idx.find(name);
    if( it != _item_idx.end() )
        return it->second;

    return -1;//not found
}
