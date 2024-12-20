#include <iostream>
#include "bitmap.h"
#include "point.h"
#include "rgb.h"
#include "circle.h"
#include "rect.h"
#include "tri.h"
#include "diamond.h"

using namespace std;

void testBitmap() {
    Bitmap map(400, 400);
    RGB red(255, 0, 0);
    Point center(0, 0);
    map.setPixel(center, red, 0);
    map.save("output/foo.bmp");
    map.clear();

}

void testCircle() {
    Bitmap map(400, 400);
    Circle red_circle(Point(0, 0), 100, RGB(255, 0, 0));
    Base* green_circle;
    green_circle = red_circle.copy();
    green_circle->setColor(RGB(0, 255, 0));
    *green_circle *= 0.5;
    red_circle.draw(map, 0);
    green_circle->draw(map, 0);
    map.save("output/circle.bmp");
}

void testRect() {
    Bitmap map(400, 400);
    Rect red_rect(Point(0, 0), 120, 160, RGB(255, 0, 0));
    Base* green_rect;
    green_rect = red_rect.copy();
    green_rect->setColor(RGB(0, 255, 0));
    *green_rect *= 0.5;
    red_rect.draw(map, 0);
    green_rect->draw(map, 0);
    map.save("output/rect.bmp");
}

void testTri() {
    Bitmap map(400, 400);
    Tri red_tri(Point(0, 0), 50, 100, 150, RGB(255, 0, 0));
    Base* green_tri;
    green_tri = red_tri.copy();
    green_tri->setColor(RGB(0, 255, 0));
    *green_tri *= 0.5;
    red_tri.draw(map, 0);
    green_tri->draw(map, 0);
    map.save("output/tri.bmp");
}

void testDiamond() {
    Bitmap map(400, 400);
    Diamond red_diamond(Point(0, 0), 50.0, 70.0, RGB(255,0,0));
    Base* green_diamond;
    green_diamond = red_diamond.copy();
    green_diamond->setColor(RGB(0, 255, 0));
    *green_diamond *= 0.5;
    red_diamond.draw(map, 0);
    green_diamond->draw(map, 0);
    map.save("output/diamond.bmp");
}

int main() {
    testDiamond();
}
