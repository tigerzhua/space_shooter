#include "data_base.h"
//#include "machine_types.h"

Data_base::Data_base(){
    machine_list.clear();
    _machine_idx.clear();
    item_list.clear();
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
    machine_list.clear();
    _machine_idx.clear();
    item_list.clear();
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
    int idx = 0;//initial idx
    std::map<std::string, int>::iterator it;
    while (getline(infile, line)) {
        if (line.size() != 0){
            it = _machine_idx.find(line);
            if( it != _machine_idx.end() ){//check if already exist
                _machine_idx.insert( std::pair<std::string,int>(line,idx) );
                idx += 1;
            }
        }
        else { /* ignoring this line */ }
  }
  std::cout<<"Loading machine_idx complete"<<std::endl;
  infile.close();
}

void Data_base::initialize_item_idx(char* filename){
    std::ifstream infile(filename, std::ios::in);
    if (!infile) { std::cout<<"Cannot open item_idx "<<std::endl; return; }

    std::cout<<"Loading item_idx"<<std::endl;

    std::string line;
    int idx = 0;//initial idx
    std::map<std::string, int>::iterator it;
    while (getline(infile, line)) {
        if (line.size() != 0){
            it = _item_idx.find(line);
            if( it != _item_idx.end() ){//check if already exist
                _item_idx.insert( std::pair<std::string,int>(line,idx) );
                idx += 1;
            }
        }
        else { /* ignoring this line */ }
  }
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
    int idx = 0;//initial idx
    std::map<std::string, int>::iterator it;
    while (getline(infile, line)) {
        if (line.size() != 0){
            if (line.substr(0,2) != "##"){//not a comment
                if(line.substr(0,1) != "{"){//name of an item
                    it = _item_idx.find(line);
                    if( it == _item_idx.end() ){//doesn't exist
                        std::cout<<"missing item, suggest halt program immediately"<<std::endl;
                        break;
                    }

                    //everything goes on well
                    int idx = it->second;
                    make_item(item_list[idx], line);
                }
            }
        }
        else { /* ignoring this line */ }
  }
  std::cout<<"Loading item_list(data) complete"<<std::endl;
  infile.close();
}

void Data_base::make_item(Item& itm, std::string str){
    std::string data = str.substr(1, str.length()-2);

    std::istringstream input_stream(data);
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
    input_stream >> itm.special_effect;
    //TODO:read texture
}

int Data_base::get_machine_idx(char* name){
    std::string temp_name = std::string(name);
    std::map<std::string, int>::iterator it;
    it = _machine_idx.find(temp_name);
    if( it != _machine_idx.end() )
        return it->second;

    return -1;//not found
}

int Data_base::get_item_idx(char* name){
    std::string temp_name = std::string(name);
    std::map<std::string, int>::iterator it;
    it = _item_idx.find(temp_name);
    if( it != _item_idx.end() )
        return it->second;

    return -1;//not found
}
