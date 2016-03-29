#ifndef SCRIPT_H
#define SCRIPT_H

// c-style includes
#include <stdio.h>
#include <stdlib.h>

// c++ style includes
#include <string>
#include <iostream>

// local includes
#include "vector3d.h"
#include "point3d.h"
#include "bullet.h"
#include "machine_types.h"
#include "script_types.h"
#include "objects.h"
#include "level.h"

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
        Script(const char* file_name, Level* level);
        ~Script();

        void read_script(const char* filename, Level* level);

    private:

        void process_element(Script_type::One_script* s, Level* level);
};
#endif // OBJECTS_H
