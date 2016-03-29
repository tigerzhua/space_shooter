#ifndef POINT3D_H
#define POINT3D_H

class Point3d
{
    public:

        Point3d();

        ~Point3d();

        Point3d(const float x, const float y, const float z);
        Point3d(const float x, const float y);

        Point3d& operator= (const Point3d& rhs);
        Point3d operator+ (const Point3d& rhs);
        Point3d operator* (const float rhs);

        float get_x() const;
        float get_y() const;
        float get_z() const;

        void set_x(const float x);
        void set_y(const float y);
        void set_z(const float z);

        void add_x(const float x);
        void add_y(const float y);
        void add_z(const float z);
        void add_point(const Point3d& rhs);

    private:

        float _x, _y, _z;

        void set_point(const float x, const float y, const float z);
};

inline float Point3d::get_z() const{return _z;}
inline float Point3d::get_x() const{return _x;}
inline float Point3d::get_y() const{return _y;}
inline void Point3d::set_x(const float x){_x = x;}
inline void Point3d::set_y(const float y){_y = y;}
inline void Point3d::set_z(const float z){_z = z;}
inline void Point3d::add_x(const float x){_x += x;}
inline void Point3d::add_y(const float y){_y += y;}
inline void Point3d::add_z(const float z){_z += z;}


#endif // POINT3D_H
