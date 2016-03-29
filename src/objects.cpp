#include "objects.h"

Object::Object(){
    _texture = NULL;
    _u_id = NULL;
}

Object::~Object(){
    clear();
}

void Object::clear(){
    if(_u_id != NULL){
        delete _u_id;
        _u_id = NULL;
    }

    if(_texture != NULL){
        delete _texture;
        _texture = NULL;
    }
}

void Object::set_u_id(char* new_id){
    if (_u_id == NULL){
        _u_id = new char;
        _u_id = new_id;
    }
    else{
        delete _u_id;
        _u_id = new char;
        _u_id = new_id;
    }
}

char* Object::generate_u_id(){
    //assume char pointer is pre-generated
    return "gulujibasuai";
}

void Object::load_texture(char* filename){
    if(_texture != NULL){
        delete _texture;
    }
    _texture = new sf::Texture();
    _texture->loadFromFile(filename);
    //set_texture();
}

//bool Object::hit(){
//    //modifiy me later!
//    return false;
//}

bool Object::can_fire(){
    //TODO, should be checking type, or someting
    return false;
}
