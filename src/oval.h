#ifndef _OVAL_H_
#define _OVAL_H_

#include "base.h"
#include "bitmap.h"

class Oval : public Base {
protected:
    double radiusX;
    double radiusY;

    RGB color2;

public:
    Oval(const Point& _ref, double _radiusX, double _radiusY, const RGB& _color, const RGB& _color2);
    ~Oval();

    void operator*= (double scale);
    Base* copy() const;
    void draw(Bitmap& map, int method) const;
    
};

Oval::Oval(const Point& _ref, double _radiusX, double _radiusY, const RGB& _color, const RGB& _color2): 
radiusX(_radiusX), radiusY(_radiusY), color2(_color2) {
    this->count = 1;
    this->ref = _ref;
    this->color = _color;
}

Oval::~Oval(){}

void Oval::operator*= (double scale) {
    this->radiusX *= scale;
    this->radiusY *= scale;
}

Base* Oval::copy() const {
    Oval* ret = new Oval(ref, radiusX, radiusY, color, color2);
    return (Base *)ret;
}

void Oval::draw(Bitmap& map, int method) const {
    map.drawGradientOval(ref, radiusX, radiusY, color, color2, method);
}


#endif // _OVAL_H_
