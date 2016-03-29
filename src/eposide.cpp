#include "eposide.h"
#include <sstream>
#include <fstream>
#include <string>

Eposide::Eposide(){
    _cur_file = 0;
    _screen.create(800,600);//TODO change this
}

Eposide::~Eposide(){
    //nothing
}

void Eposide::goto_next_file(){
    _cur_file += 1;
}

int Eposide::get_cur_file(){
    return _cur_file;
}

void Eposide::load_file_list(const char* filename){
    std::ifstream infile(filename, std::ios::in);
    if (!infile) { std::cout<<"Cannot open script list "<<filename<<std::endl; return; }

    std::cout<<"Loading script list: "<<filename<<std::endl;
    std::string line;
    int cur_line = 0;
    while (getline(infile, line)) {
        _file_list[0] = line;
        cur_line += 1;
    }
}

void Eposide::load_file(const char* filename){
    _script.read_script(filename, &_level);
}

void Eposide::move_level_entities(){
    _level.move_objects();
}

void Eposide::set_screen_ptr(){
    _level.set_screen_ptr_all(&_screen);
}

void Eposide::set_camera_ptr_self(Camera* src){
    _camera = src;
}

void Eposide::set_camera_ptr(Camera* src){
    set_camera_ptr_self(src);
}

void Eposide::render_all(){
    _level.render_world();
    _level.render_objects();
    _screen.display();
}

Engine::Key_type Eposide::process_event(const Engine::Cur_state& state, const sf::Event& event){
    if (event.type == sf::Event::KeyPressed){
        if(state == Engine::BATTLE){//decide according to Engine::Cur_state
            return process_keys_battle(event);
        }
        else if(state == Engine::PREPARE){}{
            return process_keys_prepare(event);
        }
    }
    return Engine::NONE;
}

void Eposide::player_action(const Engine::Key_type key){
    _level.change_player_dir(key);
    _level.move_machine_p();
}

void Eposide::update_world_info(){
    _level.update_world_pos();
}

void Eposide::process_game_cycle(const Engine::Cur_state& state, const sf::Event& event){
    Engine::Key_type key = process_event(state, event);
    player_action(key);
    update_world_info();
    render_all();
}
