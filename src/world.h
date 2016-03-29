#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "engine_types.h"
#include "vector3d.h"
#include "point3d.h"
#include "screen_object.h"
#include "camera.h"

/*
This class represent the entire game map
The window shows only part of the world.
the Level class includes a World object
*/

class World
{
    public:
        World();
        ~World();

        World(int w, int h);

        //basic
        void change_size(int new_w, int new_h);
        int get_width();
        int get_height();

        //setting
        void load_bg(char* file_name);//last level
        void load_bg2(char* file_name);
        void set_screen_ptr(sf::RenderTexture* src);
        void set_camera_ptr(Camera* src);
        void set_initial_bg_pos_all(const Camera& camera);
            void set_initial_pos_bg_2(const Camera& camera);
            void set_initial_pos_background(const Camera& camera);

        //utilities
        bool out_range(Point3d & p);//check if a point is outrange
        void render_world();
        void update_bg_pos_all(const Vector3d& vel);
            void move_bg_2nd(const Vector3d& vel);
            void move_background(const Vector3d& vel);

    private:
        int _width, _height;//The size of the world

        //TODO:all vectors are not properly initialized at this point
        //TODO:so it is almost certain to have seg fault if you try to use it.

        std::vector<Screen_object*> _bg_1st_lv;//highest ones
        //std::vector<Screen_object*> _bg_moving_obj;//suplement moving objects?
        std::vector<Screen_object*> _bg_2nd_lv;//2nd one, don't used in final rendering
        Screen_object* _bg_2nd_combined;//2nd level bg cimbined to a single picture
        Screen_object* _background;//the lowest level BG, fixed

        //Notes
        sf::RenderTexture* _screen;
        Camera* _camera;

        //helpers
        void render_world_according_to_camera();//CHECK
        void clear();
};

#endif // WORLD_H
