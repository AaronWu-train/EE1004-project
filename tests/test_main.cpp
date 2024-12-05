#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include "point.h"

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
