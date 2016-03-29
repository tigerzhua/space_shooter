#ifndef SCREEN_OBJECTS_H
#define SCREEN_OBJECTS_H

#include <time.h>
#include <SFML/Graphics.hpp>

#include "objects.h"
#include "camera.h"

class Screen_object: public Object
{
    public:

        Screen_object();
        Screen_object(float x, float y);
        Screen_object(Point3d pos);
        ~Screen_object();

        //basic functions
        Point3d* get_pos();
        Vector3d* get_velocity();
        Machine::Faction::faction get_faction();
        inline unsigned int get_texture_size_x();
        inline unsigned int get_texture_size_y();

        //moving functions
        void change_velocity(const float new_delta_x, const float new_delta_y);
        void change_velocity(const Vector3d new_v);
        void change_velocity(const Vector3d* new_v);

        void change_position(const float new_x, const float new_y);//Teleport
        void change_position(const Point3d pos);//Teleport
        void change_position(const Point3d* pos);//Teleport
        void move(Vector3d& vel);//displacement

        //game utilities
        void move();
        void draw();//TODO
        Point3d get_screen_pos();//TODO get the pos of the object on the screen
        void set_texture();//give the texture to the sprite
        void set_position();//give the position to sprite
        void set_screen_ptr(sf::RenderTexture* src);
        void set_camera_ptr(Camera* src);

        //Time object, unit in game cycle
        int entrance_time;

        //display
        void render();

    private:

        Machine::Faction::faction   _faction;
        int _group;

        Point3d            _pos;      //Position
        Vector3d           _velocity; //Speed

        //sprite components
        sf::Sprite         _sprite;
        unsigned int _texture_size_x, _texture_size_y;//TODO:take them down because they are fixed

        sf::RenderTexture* _screen;
        Camera* _camera;

};

inline unsigned int Screen_object::get_texture_size_x(){return _texture_size_x;}
inline unsigned int Screen_object::get_texture_size_y(){return _texture_size_y;}

#endif //SCREEN_OBJECT_H
