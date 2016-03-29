#include"screen_object.h"

Screen_object::Screen_object(){_pos = Point3d(); _screen = nullptr; _camera = nullptr; _obj = nullptr;}
Screen_object::~Screen_object(){_screen = nullptr; _camera = nullptr; _obj = nullptr;}
Screen_object::Screen_object(float x, float y){_pos = Point3d(x,y); _screen = nullptr; _camera = nullptr; _obj = nullptr;}
Screen_object::Screen_object(Point3d pos){_pos = pos; _screen = nullptr; _camera = nullptr; _obj = nullptr;}

void Screen_object::set_screen_ptr(sf::RenderTexture* src){_screen = src;}
void Screen_object::set_camera_ptr(Camera* src){_camera = src;}

void Screen_object::change_velocity(const float new_delta_x, const float new_delta_y){_velocity = Vector3d(new_delta_x, new_delta_y);}
void Screen_object::change_velocity(const Vector3d new_v){_velocity = new_v;}
void Screen_object::change_velocity(const Vector3d* new_v){_velocity = *new_v;}

void Screen_object::change_position(const float new_x, const float new_y){
    _pos = Point3d(new_x, new_y);
    set_sprite_position();
}

void Screen_object::change_position(const Point3d pos){
    _pos = pos;
    set_sprite_position();
}

void Screen_object::change_position(const Point3d* pos){
    //assume a valid pointer
    _pos = *pos;
    set_sprite_position();
}

Point3d* Screen_object::get_pos(){
    return &_pos;
}

Vector3d* Screen_object::get_velocity(){
    return &_velocity;
}

Machine::Faction::faction Screen_object::get_faction(){
    return _faction;
}

void Screen_object::move(){
    _pos.add_x( _velocity.get_x() );
    _pos.add_y( _velocity.get_y() );
    _pos.add_z( _velocity.get_z() );
    set_sprite_position();
}

void Screen_object::move(Vector3d& vel){
    _pos = vel+_pos;
    set_sprite_position();
}

void Screen_object::draw(){

}

void Screen_object::load_set_texture(char* filename){
    _obj->load_texture(filename);
    _sprite.setTexture(*(_obj->get_texture_ptr()));
}

void Screen_object::set_texture(){
    _sprite.setTexture(*(_obj->get_texture_ptr()));
}

void Screen_object::set_sprite_position(){
    _sprite.setPosition(_pos.get_x(), _pos.get_y());
}

void Screen_object::render(){
    _screen->draw(_sprite);
}
