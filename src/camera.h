#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>

#include "point3d.h"

class Camera//based on the sf::View object
{
    public:

        Camera();
        ~Camera();

        //initialiation function
        void set_source(float x, float y, float s_x, float s_y);//replace the old view
        void set_source(Point3d& p, float s_x, float s_y);      //replace the old view
        void set_target(float x, float y, float s_x, float s_y);//replace the old view
        void set_target(Point3d& p, float s_x, float s_y);      //replace the old view

        //movement function
        void change_source_pos(float off_x, float off_y);
        void change_source_pos(Point3d& off_p);
        void change_target_pos(float off_x, float off_y);
        void change_target_pos(Point3d& off_p);

        //return member functions
        const Point3d* get_center_source() const;
        const Point3d* get_center_target() const;
        float get_size_x_src() const;
        float get_size_y_src() const;
        const sf::View* get_view_ptr() const;

        //helpers
        void calculate_ctr_src();
        void calculate_ctr_tar();
        void update_view_src();
        void update_view_tar();

    private:

        //source
        Point3d _coord_src;    //coord of camera, top left
        float _size_x, _size_y;//size of the view
        Point3d _center_src;   //center of the source view

        //target
        Point3d _coord_tar;//coord of camera, top left
        float _fac_x, _fac_y;//size of the view
        Point3d _center_tar;

        sf::View _view;//includes a source view and a target view
};

inline const Point3d* Camera::get_center_source() const{return &_center_src;}
inline const Point3d* Camera::get_center_target() const{return &_center_tar;}
inline const sf::View* Camera::get_view_ptr() const{return &_view;}
inline float Camera::get_size_x_src() const{return _size_x;}
inline float Camera::get_size_y_src() const{return _size_y;}

#endif // CAMERA_H
