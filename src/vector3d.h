#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "point3d.h"
#include "engine_types.h"

//vector that indicates direction
class Vector3d
{
    public:

        Vector3d();
        ~Vector3d();

        //basic functions
        Vector3d(const float ox, const float oy, const float oz,
                 const float dx, const float dy, const float dz);
        Vector3d(const float x, const float y, const float z);
        Vector3d(const float x, const float y);
        Vector3d(const Point3d a, const Point3d b);
        Vector3d(const Point3d* a, const Point3d* b);//no NULL check here

        //inlines
        float get_x() const;
        float get_y() const;
        float get_z() const;
        float get_len() const;

        //operators
        Point3d operator+ (const Point3d& rhs) const;
		Vector3d& operator= (const Vector3d& rhs);
		Vector3d operator- (const Vector3d& rhs);
		float operator* (const Vector3d& rhs);//dot product
		Vector3d operator^ (const Vector3d& rhs);//cross product
		Vector3d operator* (const float rhs) const;//scale

        //utilities
        void normalize();
        void change_vector(const float x, const float y, const float z);//change x, y and z values
        void change_vector(const float x, const float y);//change x and y values
        void change_x(const float x);
        void change_y(const float y);
        void change_z(const float z);
        //other files dependent
        void change_dir(const Engine::Key_type& key);

    private:

        float _x, _y, _z;
        float _length;

        void calculate_length();
};

inline float Vector3d::get_x() const{return _x;}
inline float Vector3d::get_y() const{return _y;}
inline float Vector3d::get_z() const{return _z;}
inline float Vector3d::get_len() const{return _length;}
#endif // VECTOR3D_H
