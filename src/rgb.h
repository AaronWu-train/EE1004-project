#ifndef _RGB_H_
#define _RGB_H_

class RGB {
friend class BitmapBase;
protected:
    uint8_t r, g, b;

public:
    RGB();
    RGB(uint8_t r, uint8_t g, uint8_t b);
    RGB(const RGB& rgb);
    RGB& operator=(const RGB& rgb);
    RGB operator+(const RGB& rgb) const;
    RGB operator-(const RGB& rgb) const;
    RGB operator*(double ratio) const;
    RGB& operator+=(const RGB& rgb);
    RGB& operator-=(const RGB& rgb);
    friend std::ostream& operator<<(std::ostream& os, const RGB& rgb);

}; // class RGB

#ifndef _RGB_IMPL_
#define _RGB_IMPL_

RGB::RGB() : r(0), g(0), b(0) {}
RGB::RGB(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}
RGB::RGB(const RGB& rgb) : r(rgb.r), g(rgb.g), b(rgb.b) {}

RGB& RGB::operator=(const RGB& rgb) {
    r = rgb.r;
    g = rgb.g;
    b = rgb.b;
    return *this;
}

RGB RGB::operator+(const RGB& rgb) const {
    return RGB(r + rgb.r, g + rgb.g, b + rgb.b);
}

RGB RGB::operator-(const RGB& rgb) const {
    return RGB(r - rgb.r, g - rgb.g, b - rgb.b);
}

RGB RGB::operator*(double ratio) const {
    return RGB(r * ratio, g * ratio, b * ratio);
}

RGB& RGB::operator+=(const RGB& rgb) {
    r += rgb.r;
    g += rgb.g;
    b += rgb.b;
    return *this;
}

RGB& RGB::operator-=(const RGB& rgb) {
    r -= rgb.r;
    g -= rgb.g;
    b -= rgb.b;
    return *this;
}

std::ostream& operator<< (std::ostream& os, const RGB& rgb) {
    os << "(" << (int)rgb.r << ", " << (int)rgb.g << ", " << (int)rgb.b << ")";
    return os;
}

#endif // _RGB_IMPL_
#endif // _RGB_H_
