#ifndef _RECT_H_
#define _RECT_H_

#include "base.h"
#include "bitmap.h"

class Rect : public Base {
protected:
    int width;
    int height;

public:
    Rect(const Point& _ref, int _width, int _height, const RGB& _color);
    ~Rect();

    void operator*= (double scale);
    Base* copy() const;
    void draw(Bitmap& map, int method) const;
};

Rect::Rect(const Point& _ref, int _width, int _height, const RGB& _color)
    : width(_width), height(_height) {
    this->count = 1;
    this->ref = _ref;
    this->color = _color;
}

Rect::~Rect() {}

void Rect::operator*= (double scale) {
    this->width *= scale;
    this->height *= scale;
}

Base* Rect::copy() const {
    Rect* ret = new Rect(ref, width, height, color);
    return (Base*)ret;
}

void Rect::draw(Bitmap& map, int method) const {
    map.drawSolidRect(ref, width, height, color, method);
}

#endif // _RECT_H_
