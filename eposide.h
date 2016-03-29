#ifndef EPOSIDE_H
#define EPOSIDE_H

//SFML
#include <SFML/Graphics.hpp>

//STL
#include <vector>
#include <string>

// local includes
#include "level.h"
#include "script.h"
#include "camera.h"

class Eposide
{
    public:
        //basic functions
        Eposide();
        ~Eposide();

        //get member
        const sf::Texture& get_screen() const;
        bool is_last_file();
        int get_cur_file();
        std::string get_cur_filename_inc();
        std::string get_cur_filename();
        std::string get_next_filename();

        //display
        void render_all();

        //utilities
        Engine::Key_type process_event(const Engine::Cur_state& state, const sf::Event& event);
        void update_status_info();//e.g. hp, skill cool-downs, etc.
        void move_level_entities();
        void update_pos_accoding_to_camera();//TODO
        void player_action(const Engine::Key_type key);//everythin about player is finished after this call
        void update_world_info();//evey other stuff is done here
        void goto_next_file();
        void load_file_list(const char* filename);

        void set_camera_ptr(Camera* src);//pass camera ptr to all lower levels
        void set_camera_ptr_self(Camera* src);//only set camera ptr for Eposide
        void set_screen_ptr();//pass screen ptr to all lower levels

        //"main" function
        void process_game_cycle(const Engine::Cur_state& state, const sf::Event& event);

    private:

        Level _level;//CURRENT level
        std::vector<std::string> _file_list;
        sf::RenderTexture _screen;//everything is drawn to this
                                  //also this pointer is passed down
        Camera* _camera;
        int _cur_file;

        //helper
        //those three are inline
        Engine::Key_type process_keys_all(const sf::Event& event);
        Engine::Key_type process_keys_battle(const sf::Event& event);//So key is pressed here
        Engine::Key_type process_keys_prepare(const sf::Event& event);
};

inline const sf::Texture& Eposide::get_screen() const {return _screen.getTexture();}
inline Engine::Key_type Eposide::process_keys_battle(const sf::Event& event){
    //big switch case stuff
    Engine::Key_type key;

    //moving or not is decided by if/elseif
    bool left  = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    bool up    = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool down  = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

    if      (left&&up)   {key = Engine::UP_LEFT;}
    else if (left&&down) {key = Engine::DOWN_LEFT;}
    else if (right&&up)  {key = Engine::UP_RIGHT;}
    else if (right&&down){key = Engine::DOWN_RIGHT;}
    else if (left)       {key = Engine::LEFT;}
    else if (right)      {key = Engine::RIGHT;}
    else if (up)         {key = Engine::UP;}
    else if (down)       {key = Engine::DOWN;}
    else{}

    //special action is decided using sf::event
    return key;
}

inline Engine::Key_type Eposide::process_keys_prepare(const sf::Event& event){
    return Engine::NONE;
}

inline Engine::Key_type Eposide::process_keys_all(const sf::Event& event){
    return Engine::NONE;
}

#endif // LEVEL_H
