#ifndef SCRIPT_H
#define SCRIPT_H

// c-style includes
#include <stdio.h>
#include <stdlib.h>

// c++ style includes
#include <string>
#include <iostream>

// local includes
#include "machine_types.h"
#include "script_types.h"
#include "objects.h"
#include "level.h"
#include "data_base.h"

//main
#include <SFML/Graphics.hpp>
#include <math.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

/*
For player and enemies on the screen
*/

class Script
{
    public:
        Script();
        Script(const char* file_name, Level* level, Data_base* db);
        ~Script();

        void read_script(const char* filename, Level* level, Data_base* db); //read a script and load the level

    private:

        void process_element(Script_type::One_script* s, Script_type::Real_script& scp);
        void add_to_level(Script_type::Real_script& scp, Level* level, Data_base* db);
};

class Script_reader
{
    public:
        Script_reader(Data_base* db);
        ~Script_reader();

        void read(const char* file_name, Level* level, Data_base* db);

    private:
        Data_base* _db;
};

#endif // OBJECTS_H
