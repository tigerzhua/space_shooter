#include "game_window.h"

#include <string>

Game_window::Game_window(){
    _width = 0;
    _height = 0;
    _fps = 0;
}

Game_window::~Game_window(){
    //nothing
}

void Game_window::create_window(int w, int h){
    _width = w;
    _height = h;
    _window.create(sf::VideoMode(w, h), "Untitled");
}

void Game_window::create_window(int w, int h, char* name){
    _width = w;
    _height = h;
    std::string str(name);
    _window.create(sf::VideoMode(w, h), str);
}

void Game_window::create_window(Engine::Screen_coff& s, char* name){
    _height = s.window_height;
    _width = s.window_width;
    std::string str(name);
    _window.create(sf::VideoMode(_width, _height), str);
}

void Game_window::adjust_size(int new_w, int new_h){
    _width = new_w;
    _height = new_h;
    sf::Vector2u dim(_width, _height);
    _window.setSize(dim);
}

int Game_window::get_width(){
    return _width;
}

int Game_window::get_height(){
    return _height;
}

unsigned int Game_window::get_fps(){
    return _fps;
}

void Game_window::set_window_title(char* name){
    std::string str(name);
    _window.setTitle(str);
}

void Game_window::set_max_fps(unsigned int fps){
    _window.setFramerateLimit(fps);
    _fps = fps;
}

void Game_window::set_camera(const Camera& camera){
    _window.setView( *(camera.get_view_ptr()) );
}

bool Game_window::is_open(){
    return _window.isOpen();
}

bool Game_window::poll_event(sf::Event& e){
    return _window.pollEvent(e);
}

void Game_window::close_window(){
    _window.close();
}

void Game_window::display_window(const Eposide& epo){
    _window.clear();
    _window.setActive();
    sf::Sprite frame(epo.get_screen());
    _window.draw(frame);
    _window.display();
}
