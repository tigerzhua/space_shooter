#include "camera.h"

Camera::Camera(){
    _coord_src = Point3d();
    _size_x = 800;
    _size_y = 600;
    _coord_tar = Point3d();
    _fac_x = 1;
    _fac_y = 1;
}

Camera::~Camera(){

}

void Camera::set_source(float x, float y, float s_x, float s_y){
    _coord_src.set_x(x);
    _coord_src.set_y(y);
    _size_x = s_x;
    _size_y = s_y;
    _view.reset( sf::Rect<float>(x,y,_size_x,_size_y) );
}

void Camera::set_source(Point3d& p, float s_x, float s_y){
    _coord_src = p;
    _size_x = s_x;
    _size_y = s_y;
    _view.reset( sf::Rect<float>(p.get_x(),p.get_y(),_size_x,_size_y) );
}

void Camera::set_target(float x, float y, float s_x, float s_y){
    _coord_tar.set_x(x);
    _coord_tar.set_y(y);
    _fac_x = s_x;
    _fac_y = s_y;
    _view.setViewport( sf::Rect<float>(x,y,_fac_x,_fac_y) );
}

void Camera::set_target(Point3d& p, float s_x, float s_y){
    _coord_tar = p;
    _fac_x = s_x;
    _fac_y = s_y;
    _view.setViewport( sf::Rect<float>(p.get_x(),p.get_y(),_fac_x,_fac_y) );
}

void Camera::update_view_src(){
    _view.setViewport( sf::Rect<float>(_coord_src.get_x(),_coord_src.get_y(),_size_x,_size_y) );
}

void Camera::update_view_tar(){
    _view.setViewport( sf::Rect<float>(_coord_tar.get_x(),_coord_tar.get_y(),_fac_x,_fac_y) );
}

void Camera::calculate_ctr_src(){
    _center_src.set_x(_coord_src.get_x()+_size_x*0.5);
    _center_src.set_y(_coord_src.get_y()+_size_y*0.5);
}

void Camera::calculate_ctr_tar(){
    _center_tar.set_x(_coord_tar.get_x()+_size_x*0.5);
    _center_tar.set_y(_coord_tar.get_y()+_size_y*0.5);
}

void Camera::change_source_pos(float off_x, float off_y){
    _coord_src.add_x(off_x);
    _coord_src.add_y(off_y);
    calculate_ctr_src();
    update_view_src();
}
void Camera::change_source_pos(Point3d& off_p){
    _coord_src.add_point(off_p);
    calculate_ctr_src();
    update_view_src();
}

void Camera::change_target_pos(float off_x, float off_y){
    _coord_tar.add_x(off_x);
    _coord_tar.add_y(off_y);
    calculate_ctr_tar();
    update_view_tar();
}
void Camera::change_target_pos(Point3d& off_p){
    _coord_tar.add_point(off_p);
    calculate_ctr_tar();
    update_view_tar();
}
