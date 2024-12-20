#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>

class Point {
friend class BitmapBase;
protected:
    int x, y;
    
public:
    Point();
    Point(int x, int y);
    Point(const Point& p);
    ~Point();
    
    int getX() const;
    int getY() const;

    void setX(int _x);
    void setY(int _y);

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

int Point::getX() const {
    return this->x;
}

int Point::getY() const {
    return this->y;
}

void Point::setX(int _x) {
    x = _x;
}

void Point::setY(int _y) {
    y = _y;
}

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
