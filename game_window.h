#ifndef GAME_WINDOW
#define GAME_WINDOW

#include <SFML/Graphics.hpp>

#include "engine_types.h"
#include "camera.h"
#include "eposide.h"

class Game_window
{
    public:

        Game_window();
        ~Game_window();

        //Create new window kills the old one
        void create_window(int w, int h);
        void create_window(int w, int h, char* name);
        void create_window(Engine::Screen_coff& s, char* name);

        //basic function
        int get_width();
        int get_height();
        unsigned int get_fps();

        //setting functions
        void set_window_title(char* name);
        void set_max_fps(unsigned int fps);
        void set_camera(const Camera& camera);//At this point, taking down the pointer only slow thins down
                                        //but we'll see whats now in the future

        //utilities
        void adjust_size(int new_w, int new_h);//when the change_resolution function is used
        bool is_open();
        bool poll_event(sf::Event& e);
        void close_window();

        //"main" function
        void display_window(const Eposide& epo);

    private:

        sf::RenderWindow _window;//where everything is shown
        int _width, _height;
        unsigned int _fps;

        //helpers
};

#endif // GAME_WINDOW
