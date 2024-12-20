#ifndef _DIAMOND_H_
#define _DIAMOND_H_

#include "base.h"
#include "bitmap.h"

class Diamond : public Base {
protected:
    double width;
    double height;

public:
    Diamond(const Point& _ref, double _width, double _height, const RGB& _color);
    ~Diamond();

    void operator*= (double scale);
    Base* copy() const;
    void draw(Bitmap& map, int method) const;
};

Diamond::Diamond(const Point& _ref, double _width, double _height, const RGB& _color)
    : width(_width), height(_height) {
    this->count = 1;
    this->ref = _ref;
    this->color = _color;
}

Diamond::~Diamond() {}

void Diamond::operator*= (double scale) {
    this->width *= scale;
    this->height *= scale;
}

Base* Diamond::copy() const {
    Diamond* ret = new Diamond(ref, width, height, color);
    return (Base*)ret;
}

void Diamond::draw(Bitmap& map, int method) const {
    map.drawDiamond(ref, width, height, color, method);
}

#endif // _DIAMOND_H_
