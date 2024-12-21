#ifndef _HANDLE_H_
#define _HANDLE_H_

#include "base.h"
#include "bitmap.h"
#include "circle.h"
#include "diamond.h"
#include "oval.h"
#include "point.h"
#include "rect.h"
#include "rgb.h"
#include "tri.h"

class Handle {
protected:
    Base* content;

public:
    Handle();
    Handle(const Point&, int, const RGB&);                         // circle
    Handle(const Point&, int, int, const RGB&);                    // rect
    Handle(const Point&, int, int, int, const RGB&);               // tri
    Handle(const Point&, double, double, const RGB&, const RGB&);  // oval
    Handle(const Point&, double, double, const RGB&);              // diamond
    ~Handle();

    // Shallow copy
    Handle(const Handle&);                     // copy constructor
    const Handle& operator=(const Handle& h);  // copier

    // Copy on write
    void setColor(const RGB&);
    void operator+=(const Point&);
    void operator*=(const double&);
    Handle operator+(const Point&) const;
    Handle operator*(const double&) const;

    void draw(Bitmap& map, int method) const;
};

Handle::Handle() : content(nullptr) {}

Handle::Handle(const Point& ref, int radius, const RGB& c)
    : content(new Circle(ref, radius, c)) {}

Handle::Handle(const Point& ref, int width, int height, const RGB& c)
    : content(new Rect(ref, width, height, c)) {}

Handle::Handle(const Point& ref, int left, int right, int height, const RGB& c)
    : content(new Tri(ref, left, right, height, c)) {}

Handle::Handle(const Point& ref, double radiusX, double radiusY, const RGB& c, const RGB& c2)
    : content(new Oval(ref, radiusX, radiusY, c, c2)) {}

Handle::Handle(const Point& ref, double width, double height, const RGB& c)
    : content(new Diamond(ref, width, height, c)) {}

Handle::~Handle() {
    if (content) {
        if (content->count == 1) {
            delete content;
        } else {
            content->count--;
        }
    }
}

Handle::Handle(const Handle& h) : content(h.content) {
    if (content) {
        content->count++;
    }
}

const Handle& Handle::operator=(const Handle& h) {
    if (this == &h) return *this;
    if (content) {
        if (content->count == 1) {
            delete content;
        } else {
            content->count--;
        }
    }
    content = h.content;
    if (content) {
        content->count++;
    }
    return *this;
}

void Handle::setColor(const RGB& c) {
    if (!content) return;
    if (content->count > 1) {
        content->count--;
        content = content->copy();
    }
    content->setColor(c);
}

void Handle::operator+=(const Point& p) {
    if (!content) return;
    if (content->count > 1) {
        content->count--;
        content = content->copy();
    }
    content->operator+=(p);
}

void Handle::operator*=(const double& scale) {
    if (!content) return;
    if (content->count > 1) {
        content->count--;
        content = content->copy();
    }
    content->operator*=(scale);
}

Handle Handle::operator+(const Point& p) const {
    Handle ret = *this;
    ret += p;
    return ret;
}

Handle Handle::operator*(const double& scale) const {
    Handle ret = *this;
    ret *= scale;
    return ret;
}

void Handle::draw(Bitmap& map, int method) const {
    if (content) {
        content->draw(map, method);
    }
}

#endif  // _HANDLE_H_
