#ifndef _BITMAP_H_
#define _BITMAP_H_

#include "bitmapbase.h"
#include "point.h"
#include "rgb.h"

#include <cmath>

class Bitmap : public BitmapBase {

public:
    Bitmap(int x, int y);
    ~Bitmap();

    void drawSolidRect(const Point& base, int width, int height, const RGB& c, int m);
    void drawSolidTriangle(const Point& ref, int left, int right, int height, const RGB& c, int m);
    void drawSolidCircle(const Point& center, int radius, const RGB& c, int m);
    void drawDiamond(const Point& center, double width, double height, const RGB& c, int m);
    void drawGradientOval(const Point& center, double radiusX, double radiusY, 
                          const RGB& c, const RGB& c2, int m);

};


Bitmap::Bitmap(int x, int y) {
    xSize = x;
    ySize = y;
    image = new unsigned char[xSize * ySize * 3];
    this->clear();
}

Bitmap::~Bitmap() {
    if (image) delete []image;
}

void Bitmap::drawSolidRect(const Point& base, int width, int height, const RGB& c, int m) {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            int x = i + base.getX();
            int y = j + base.getY();
            this->setPixel(x, y, c, m);
        }
    }
}

void Bitmap::drawSolidTriangle (const Point& ref, int left, int right,
                                int height, const RGB& c, int m) {
    for (int j = 0; j < height; ++j) {
        int y = j + ref.getX();
        for (int i = 0; i < left*(1 - (double)j / height); ++i) {
            int x = ref.getY() - i;
            this->setPixel(x, y, c, m);
        }
        for (int i = 0; i < right*(1 - (double)j / height); i++) {
            int x = ref.getY() + i;
            this->setPixel(x, y, c, m);
        }
    }
}

void Bitmap::drawSolidCircle (const Point& center, int radius, const RGB& c, int m) {
    for (long long i = 0; i < radius; ++i) {
        for (long long j = 0; j < radius; ++j) {
            if (i * i + j * j <= (long long)radius * radius) {
                this->setPixel(center.getX() + i, center.getY() + j, c, m);
                this->setPixel(center.getX() + i, center.getY() - j, c, m);
                this->setPixel(center.getX() - i, center.getY() + j, c, m);
                this->setPixel(center.getX() - i, center.getY() - j, c, m);
            }
        }
    }
}

void Bitmap::drawDiamond(const Point& center, double width, double height, const RGB& c, int m){
    for (int i = 0; i < height/2; ++i) {
        for (int j = 0; j < (width / 2) * (1 - (double)i / (height / 2) ); j++) {
            this->setPixel(center.getX() + j, center.getY() + i, c, m);
            this->setPixel(center.getX() + j, center.getY() - i, c, m);
            this->setPixel(center.getX() - j, center.getY() + i, c, m);
            this->setPixel(center.getX() - j, center.getY() - i, c, m);
        }
    }
}

void Bitmap::drawGradientOval(const Point& center, double radiusX, double radiusY, 
                              const RGB& c, const RGB& c2, int m) {

    for (long long i = 0; i < radiusX; ++i) {
        for (long long j = 0; j < radiusY; ++j) {
            double ratio = sqrt(( i * i ) / ( radiusX * radiusX ) + ( j * j ) / ( radiusY * radiusY ));
            if (ratio <= 1.0) {
                RGB color = c + ((c2 - c) * ratio);
                if(ratio<0.1)std::cerr << color << c<<c2<< c2-c << (c2-c)* ratio << " " << ratio << "\n";


                this->setPixel(center.getX() + i, center.getY() + j, color, m);
                this->setPixel(center.getX() + i, center.getY() - j, color, m);
                this->setPixel(center.getX() - i, center.getY() + j, color, m);
                this->setPixel(center.getX() - i, center.getY() - j, color, m);
            }
        }
    }
}

#endif // _BITMAP_H_
