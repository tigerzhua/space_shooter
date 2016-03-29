#ifndef DATA_BASE_H
#define DATA_BASE_H

//stl include
#include <stdlib.h>
#include <vector>
#include <map>

#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

//local include
#include "objects.h"
#include "item.h"
#include "machine.h"

class Data_base
{
    //generates an id for all machines and items
    //used until end of game
    //everytime when a specific item/machine is required,
    //return a reference to it

    public:
        Data_base();
        ~Data_base();

        //utilities
        void initialize();
        inline Item* get_item(std::string name);
        inline Machine_object* get_machine(std::string name);
        int get_machine_idx(std::string name);
        int get_item_idx(std::string name);

    private:
        void initialize_machine_idx(char* filename);
        void initialize_item_idx(char* filename);

        void initialize_machine_list(char* filename);
        void initialize_item_list(char* filename);

        void make_item(Item& itm, std::string str);
        void make_machine(Machine_object& mac, std::string str);

        std::map<std::string, int> _machine_idx;
        std::map<std::string, int> _item_idx;
        std::vector<Machine_object> _machine_list;//storing all the machine type data
        std::vector<Item> _item_list;     //storing all the item data

};
inline Item* Data_base::get_item(std::string name){
    std::map<std::string, int>::iterator it;
    it = _item_idx.find(name);
    if( it == _item_idx.end() )//check if already exist
        return &_item_list[0];

    return &_item_list[it->second];
}

inline Machine_object* Data_base::get_machine(std::string name){
    std::map<std::string, int>::iterator it;
    it = _machine_idx.find(name);
    if( it == _machine_idx.end() )//check if already exist
        return &_machine_list[0];

    return &_machine_list[it->second];
}

#endif // DATA_BASE_H
