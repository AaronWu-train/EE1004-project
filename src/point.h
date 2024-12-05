#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>

class Point {
protected:
    int x, y;
    
public:
    Point();
    Point(int x, int y);
    Point(const Point& p);
    ~Point();
    
    Point& operator=(const Point& p);
    Point operator+(const Point& p) const ;
    Point& operator+=(const Point& p);
    friend std::ostream& operator << (std::ostream& os, const Point& p);

};

#ifndef _POINT_IMPL_
#define _POINT_IMPL_

Point::Point() : x(0), y(0) {}
Point::Point(int x, int y) : x(x), y(y) {}
Point::Point(const Point& p) : x(p.x), y(p.y) {}
Point::~Point() {}

Point& Point::operator=(const Point& p) {
    x = p.x;
    y = p.y;
    return *this;
}

Point Point::operator+(const Point& p) const {
    return Point(x + p.x, y + p.y);
}

Point& Point::operator+=(const Point& p) {
    x += p.x;
    y += p.y;
    return *this;
}

std::ostream& operator << (std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

#endif // _POINT_IMPL_
#endif  // _POINT_H_