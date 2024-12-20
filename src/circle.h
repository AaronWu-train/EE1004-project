#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "base.h"
#include "bitmap.h"

class Circle : public Base {
protected:
    int radius;
public:
    Circle(const Point& _ref, int _radius, const RGB& _color) 
    : radius(_radius) {
        this->count = 1;
        this->ref = _ref;
        this->color = _color;
    }

    ~Circle(){}

    void operator*= (double scale) {
        this->radius *= scale;
    }

    Base* copy() const {
        Circle* ret = new Circle(ref, radius, color);
        return (Base *)ret;
    }

    void draw(Bitmap& map, int method) const {
        map.drawSolidCircle(ref, radius, color, method);
    }
};




#endif // _CIRCLE_H_
