//Types utilized in game engines
#ifndef ENGINE_TYPES_H
#define ENGINE_TYPES_H

#include <stdlib.h>

#include <SFML/Graphics.hpp>

namespace Engine
{
    enum Mode {
        STORY,
        FREE_BATTLE
    };

    enum Cur_state {
        INVALILD,
        BUSY,//reading script, or others
        BATTLE,
        PREPARE
    };

    enum Flag {
        //TODO
        dummy
    };

    enum Key_type{
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        W,
        A,
        S,
        D,
        //combined
        UP_LEFT,
        UP_RIGHT,
        DOWN_LEFT,
        DOWN_RIGHT,
    };

    typedef struct{
        float max_x;
        float min_x;
        float max_y;
        float min_y;
        int CPS;//cycle per second
    }Game_coff;

    typedef struct{
        int window_height;
        int window_width;
        unsigned int FPS;//Frame per second
        sf::Time cycle_period;

        void initialize(){
            window_height = 600;
            window_width = 800;
            FPS = 30;
            calculate_cycle_time();
        }

        void calculate_cycle_time(){
            cycle_period = sf::seconds( (float)1/FPS );
        }

        void change_fps(unsigned int new_fps){
            FPS = new_fps;
            calculate_cycle_time();
        }

    }Screen_coff;

    const int player_idx = 0;

    //The factors of how backgrounds should move
    const float bg_3_spd_fac = 0.1;
    const float bg_2_spd_fac = 0.3;
    const float bg_1_spd_fac = 1.f;
}

#endif
