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

class Data_base
{
    public:
        Data_base();
        ~Data_base();

        //utilities
        void initialize();
        int get_machine_idx(char* name);
        int get_item_idx(char* name);

        std::vector<Object> machine_list;//storing all the machine type data
        std::vector<Item> item_list;     //storing all the item data

    private:
        void initialize_machine_idx(char* filename);//generates an id for all machines and
                                                    //used until end of game
        void initialize_item_idx(char* filename);

        void initialize_machine_list(char* filename);
        void initialize_item_list(char* filename);

        void make_item(Item& itm, std::string str);

        std::map<std::string, int> _machine_idx;
        std::map<std::string, int> _item_idx;

};

#endif // DATA_BASE_H
