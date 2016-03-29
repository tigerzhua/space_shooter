#include "world.h"

World::World(){
    clear();
    _width = 0;
    _height = 0;
    _camera = NULL;
    _screen = NULL;
    _background = new Screen_object();
    _bg_2nd_combined = new Screen_object();
}

World::~World(){
    //nothing
}

World::World(int w, int h){
    clear();
    _width = w;
    _height = h;
    _camera = NULL;
    _screen = NULL;
    _background = new Screen_object();
    _bg_2nd_combined = new Screen_object();
}

void World::clear(){
    _background = NULL;
    _bg_2nd_combined = NULL;
    _screen = NULL;
    _camera = NULL;
}

void World::change_size(int new_w, int new_h){
    _width = new_w;
    _height = new_h;
}

int World::get_width(){
    return _width;
}

int World::get_height(){
    return _height;
}

bool World::out_range(Point3d & p){
    if ( (p.get_x()<0)||(p.get_x()>_width)||
         (p.get_y()<0)||(p.get_y()>_height) )
            return true;

    return false;
}

void World::load_bg(char* file_name){
    if(_background == NULL)
        _background = new Screen_object();
    _background->load_texture(file_name);
}

void World::load_bg2(char* file_name){
    if(_bg_2nd_combined == NULL)
        _bg_2nd_combined = new Screen_object();
    _bg_2nd_combined->load_texture(file_name);
}

void World::set_screen_ptr(sf::RenderTexture* src){
    _screen = src;
    _bg_2nd_combined->set_screen_ptr(_screen);
    _background->set_screen_ptr(_screen);
}

void World::set_camera_ptr(Camera* src){
    _camera = src;
}

void World::render_world(){
    _background->render();
    _bg_2nd_combined->render();
}

void World::render_world_according_to_camera(){

}

void World::move_bg_2nd(const Vector3d& vel){//CHECK
    Vector3d displacement = vel*Engine::bg_2_spd_fac;
    _bg_2nd_combined->move(displacement);

    /*
    Point3d *ctr = camera.get_center_source();

    float x_ratio = ctr->get_x()/_width;
    float y_ratio = ctr->get_y()/_height;

    Point3d new_pos(x_ratio*_bg_2nd_combined->get_texture_size_x()-camera.get_size_x_src(),
                    y_ratio*_bg_2nd_combined->get_texture_size_y()-camera.get_size_y_src());
    _bg_2nd_combined->change_position(new_pos);
    */
}

void World::move_background(const Vector3d& vel){//CHECK
    Vector3d displacement = vel*Engine::bg_3_spd_fac;
    _background->move(displacement);
}

void World::update_bg_pos_all(const Vector3d& vel){
    move_background(vel);
    move_bg_2nd(vel);
}

//set_initial_pos_bg series
void World::set_initial_pos_bg_2(const Camera& camera){
    const Point3d *ctr = camera.get_center_source();

    float x_ratio = ctr->get_x()/_width;
    float y_ratio = ctr->get_y()/_height;

    Point3d new_pos(x_ratio*_bg_2nd_combined->get_texture_size_x()-camera.get_size_x_src(),
                    y_ratio*_bg_2nd_combined->get_texture_size_y()-camera.get_size_y_src());
    _bg_2nd_combined->change_position(new_pos);
}

void World::set_initial_pos_background(const Camera& camera){
    const Point3d *ctr = camera.get_center_source();

    float x_ratio = ctr->get_x()/_width;
    float y_ratio = ctr->get_y()/_height;

    Point3d new_pos(x_ratio*_background->get_texture_size_x()-camera.get_size_x_src(),
                    y_ratio*_background->get_texture_size_y()-camera.get_size_y_src());
    _background->change_position(new_pos);
}

void World::set_initial_bg_pos_all(const Camera& camera){
    set_initial_pos_background(camera);
    set_initial_pos_bg_2(camera);
}
