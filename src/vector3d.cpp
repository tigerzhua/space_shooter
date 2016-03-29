#include "vector3d.h"
#include <math.h>

Vector3d::Vector3d()
{
    _x = 0;
    _y = 0;
    _z = 0;
    _length = 0;
}

Vector3d::~Vector3d()
{
    //nothing
}

Vector3d::Vector3d(const float ox, const float oy, const float oz,
                   const float dx, const float dy, const float dz)
{
    _x = dx - ox;
    _y = dy - oy;
    _z = dz - oz;
    calculate_length();
}

Vector3d::Vector3d(const float x, const float y, const float z)
{
    _x = x;
    _y = y;
    _z = z;
    calculate_length();
}

Vector3d::Vector3d(const float x, const float y)
{
    _x = x;
    _y = y;
    _z = 0;
    calculate_length();
}

Vector3d::Vector3d(const Point3d a, const Point3d b)
{
    _x = b.get_x()-a.get_x();
    _y = b.get_y()-a.get_y();
    _z = b.get_z()-a.get_z();
    calculate_length();
}

Vector3d::Vector3d(const Point3d* a, const Point3d* b)
{
    //No NULL check here
    _x = b->get_x()-a->get_x();
    _y = b->get_y()-a->get_y();
    _z = b->get_z()-a->get_z();
    calculate_length();
}

Point3d Vector3d::operator+ (const Point3d& rhs) const{
    Point3d result( _x+rhs.get_x(), _y+rhs.get_y(), _z+rhs.get_z() );
    return result;
}

Vector3d& Vector3d::operator= (const Vector3d& rhs)
{
    if(&rhs != this)
    {
        _x = rhs._x;
        _y = rhs._y;
        _z = rhs._z;

        _length = rhs.get_len();
    }
}

Vector3d Vector3d::operator- (const Vector3d& rhs)
{
    Vector3d result;

    result._x = this->_x - rhs._x;
    result._y = this->_y - rhs._y;
    result._z = this->_z - rhs._z;
    result.calculate_length();

    return result;
}

float Vector3d::operator* (const Vector3d& rhs)
{
    //dot product
    float result;
    result = this->_x*rhs._x +
             this->_y*rhs._y +
             this->_z*rhs._z;

    return result;
}

Vector3d Vector3d::operator* (const float rhs) const
{
    //scale
    Vector3d result;
    result = Vector3d(rhs*this->_x, rhs*this->_y, rhs*this->_z);
    result.calculate_length();

    return result;
}

Vector3d Vector3d::operator^ (const Vector3d& rhs)
{
    //cross product
    Vector3d result;
    result._x = this->_y*rhs._z - this->_z*rhs._y;
    result._y = this->_z*rhs._x - this->_x*rhs._z;
    result._z = this->_x*rhs._y - this->_y*rhs._x;
    result.calculate_length();

    return result;
}

void Vector3d::normalize()
{
    float len = sqrt( _x*_x+_y*_y+_z*_z );
    _x /= len;
    _y /= len;
    _z /= len;
    _length = 1;
}

void Vector3d::change_vector(const float x, const float y, const float z)
{
    _x = x;
    _y = y;
    _z = z;
    calculate_length();
}

void Vector3d::change_vector(const float x, const float y)
{
    _x = x;
    _y = y;
    calculate_length();
}

void Vector3d::change_x(const float x)
{
    _x = x;
    calculate_length();
}

void Vector3d::change_y(const float y)
{
    _y = y;
    calculate_length();
}

void Vector3d::change_z(const float z)
{
    _z = z;
    calculate_length();
}

void Vector3d::calculate_length()
{
    _length = sqrt( _x*_x+_y*_y+_z*_z );
}

void Vector3d::change_dir(const Engine::Key_type& key)
{
    //(0,0) is the upper left corner
    //(max_x-1, max_y-1) is the lower right
    //be careful

    float old_length = _length;

    switch(key){
    case Engine::UP:
        change_vector(0,-1);
        break;
    case Engine::DOWN:
        change_vector(0,1);
        break;
    case Engine::LEFT:
        change_vector(-1,0);
        break;
    case Engine::RIGHT:
        change_vector(1,0);
        break;
    case Engine::UP_LEFT:
        change_vector(-sqrt(2),-sqrt(2));
        break;
    case Engine::UP_RIGHT:
        change_vector(sqrt(2),-sqrt(2));
        break;
    case Engine::DOWN_LEFT:
        change_vector(-sqrt(2),sqrt(2));
        break;
    case Engine::DOWN_RIGHT:
        change_vector(sqrt(2),sqrt(2));
        break;
    case Engine::NONE:
    default://NONE
        return;
        break;
    }

    _x = _x*old_length;
    _y = _y*old_length;
    _length = old_length;
}

