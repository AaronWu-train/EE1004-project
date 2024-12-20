#include <iostream>
#include "bitmap.h"
#include "point.h"
#include "rgb.h"
#include "circle.h"
#include "rect.h"
#include "tri.h"
#include "diamond.h"
#include "oval.h"
#include "handle.h"
#include "desktop.h"

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

void testOval() {
    Bitmap map(400, 400);
    Oval red_grad_oval(Point(0, 0), 100.0, 150.0, RGB(255,0,0), RGB(255,128,0));
    Base* green_grad_oval;
    green_grad_oval = red_grad_oval.copy();
    green_grad_oval->setColor(RGB(0, 255, 0));
    *green_grad_oval *= 0.5;
    red_grad_oval.draw(map, 0);
    green_grad_oval->draw(map, 0);
    map.save("output/oval.bmp");
}

void testHandle() {
    // Circle
    Handle a(Point(-50,-50), 100, RGB(128,0,0));
    // Rect
    Handle b(Point(0, 0), 150, 100, RGB(0,128,0));
    // Triangle
    Handle c(Point(-30,-30), 50, 150, 100, RGB(0,0,128));
    // Oval
    Handle d(Point(-40,-40), 25.0, 75.0, RGB(255,0,0), RGB(255,128,0));
    // Diamond
    Handle e(Point(-100,-30), 50.0, 70.0, RGB(255,255,0));
    Desktop desk(400,400);
    desk << a << b << c << d << e;
    desk.save("output/1.bmp");
    desk.clear();
    desk + a + b + c + d + e;
    desk.save("output/2.bmp");

    // shallow copy
    b = a;
    // copy-on-write
    b += Point(50,0);
    b *= 1.2;
    d *= 0.5;
    d.setColor(RGB(255,0,0));
    desk.clear();
    desk + a + b - d;
    desk.save("output/3.bmp");

    // No problem with using array
    desk.clear();
    int num = 30;
    Handle *list = new Handle[num];
    list[0] = Handle(Point(0,0), 300.0, 300.0, RGB(255,0,0));
    double u = 255.0;
    for (int i=1; i<num; ++i) {
    list[i] = list[i-1] * 0.9;
    u *= 0.9;
    list[i].setColor(RGB(int(u),0,0));
    }
    for (int i=0; i<num; ++i)
    desk + list[i] - (list[i]*0.95);
    desk.save("output/tunnel.bmp");
    delete []list;
}

int main() {
    testRect();
    testCircle();
    testTri();
    testDiamond();
    testOval();
    testHandle();
}

