#ifndef _TRI_H_
#define _TRI_H_

#include "base.h"
#include "bitmap.h"

class Tri : public Base {
protected:
    int left;
    int right;
    int height;

public:
    Tri(const Point& _ref, int _left, int _right, int _height, const RGB& _color) 
    : left(_left), right(_right), height(_height) {
        this->count = 1;
        this->ref = _ref;
        this->color = _color;
    }

    ~Tri(){}

    void operator*= (double scale) {
        this->left *= scale;
        this->right *= scale;
        this->height *= scale;
    }

    Base* copy() const {
        Tri* ret = new Tri(ref, left, right, height, color);
        return (Base *)ret;
    }

    void draw(Bitmap& map, int method) const {
        map.drawSolidTriangle(ref, left, right, height, color, method);
    }
};

#endif // _TRI_H_
