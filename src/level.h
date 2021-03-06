#ifndef LEVEL_H
#define LEVEL_H

//STL
#include <vector>

// local includes
#include "engine_types.h"
#include "screen_object.h"
#include "list.h"
#include "world.h"
#include "camera.h"

class Level
{
    public:
        //basic functions
        Level();
        ~Level();

        //init functions
        //screen ptr
        void set_screen_ptr_all(sf::RenderTexture* src);
            void set_screen_ptr(sf::RenderTexture* src);
            void set_screen_ptr_objs(sf::RenderTexture* src);

        //camera ptr
        void set_camera_ptr_all(Camera* src);
            void set_camera_ptr(Camera* src);
            void set_camera_ptr_objs(Camera* src);


        //display
        void render_world();
        void render_objects();
        void update_world_pos();//update the position of background

        //utilities
        void move_objects();//move everything
            //can be potentially changed to multi-thread implementation
            void move_machine();
            void move_machine_opp();
            void move_machine_p();
            void move_Objects_e();
            void move_items();
            void move_bullets();
            void move_bullets_e();
            void move_bullets_p();

       void change_player_dir(Engine::Key_type key);

    private:

        //The following ones contains objects that CURRENTLY shows on screen
        //All those things are displayed on the highest level
        std::vector<Screen_object*> machine_opp;//Enemies
        std::vector<Screen_object*> machine_p;//Friendlies
        std::vector<Screen_object*> Objects_elite;//Boss, etc
        //std::vector<Group*>         Objects_group;
        std::vector<Screen_object*> Items;//Items(e.g.dropped after killing enemy)
        std::vector<Screen_object*> Bullet;
        std::vector<Screen_object*> Bullet_p;

        bool game_over;

        World _world;//represent the entire map

        //The two lists store info about the entire level
        List<int>* _timeline;//indicate which time spot contains stuff
        List< List<Screen_object*>* >* _objectlist;

        sf::RenderTexture* _screen;
        Camera* _camera;
};

#endif // LEVEL_H
