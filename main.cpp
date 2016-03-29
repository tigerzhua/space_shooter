#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//TEST ONLY
#define private public
#include "screen_object.h"
#include <iostream>

//types includes
#include "engine_types.h"

//local includes
#include "game_window.h"
#include "eposide.h"
#include "camera.h"
#include "script.h"

//these important components should be global
Data_base db;
Script_reader sr(&db);

int main(){
    //initialize state indicators, etc
    Engine::Cur_state state;
    state = Engine::BATTLE;

    sf::Event event;

    //initialize display coff: FPS, window width, height, etc.
    Engine::Screen_coff display_coff;
    display_coff.initialize();

    Game_window main_window;
    main_window.create_window(display_coff, "Space Shooter TEST");

    //load resources
    Camera test_camera;
    Eposide test_eposide;

    Screen_object* player = new Screen_object(100,100);

    player->change_velocity(1,1);
    player->load_set_texture("pics/player.png");

    test_eposide._level.machine_p.push_back(player);

    test_eposide.set_screen_ptr();
    test_eposide.set_camera_ptr(&test_camera);
    test_eposide._level._world.load_bg("pics/background.png");
    test_eposide._level._world.load_bg2("pics/bg_2.png");

    main_window.set_camera(test_camera);
    //load scripts

    //initialize a sf::clock for controlling game cycle
    //TODO: game cycle and graphics cycle should use separate clock
    sf::Clock game_cycle_clock;

    // The main loop
    while (main_window.is_open())
    {
        //check cycle time
        if(game_cycle_clock.getElapsedTime() >= display_coff.cycle_period)
        {
            //pull event from window
            while(main_window.poll_event(event))
            {
               if (event.type == sf::Event::Closed)
                   main_window.close_window();
            }

            main_window._window.setActive();
            //Then let eposide process everything
            test_eposide.process_game_cycle(state, event);

            main_window.display_window(test_eposide);

            //reset clock
            game_cycle_clock.restart();
        }
    }
    return 0;
}
