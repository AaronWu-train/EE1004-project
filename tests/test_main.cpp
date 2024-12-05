#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include "point.h"
#include "rgb.h"

using namespace std;

void pointTest() {
    Point p1(1, 2), p2(3, 4);
    // Overload <<
    cout << "p1=" << p1 << " p2=" << p2 << endl;
    Point p3(p1);
    cout << "p3=" << p3 << endl;
    p3 = Point(5, 6);
    cout << "p3=" << p3 << endl;
    // Overload +
    cout << "p1+p2=" << p1 + p2 << endl;
    // Overload +=
    p1 += p3;
    cout << "p1=" << p1 << endl;
}

TEST_CASE("PointTest") {
    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    pointTest();
    std::cout.rdbuf(old);

    REQUIRE(buffer.str() == "p1=(1, 2) p2=(3, 4)\np3=(1, 2)\np3=(5, 6)\np1+p2=(4, 6)\np1=(6, 8)\n");
}

TEST_CASE("RGBTest") {
    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    RGB a(155, 165, 175);
    cout << a << endl;
    cout << a + RGB(10, 10, 10) << endl;
    cout << a - RGB(10, 10, 10) << endl;
    RGB c(a);
    cout << c << endl;

    std::cout.rdbuf(old);
    REQUIRE(buffer.str() == "(155, 165, 175)\n(165, 175, 185)\n(145, 155, 165)\n(155, 165, 175)\n");
}