#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>

void printHello() {
    std::cout << "Hello, World!" << std::endl;
}

TEST_CASE("OutputTest") {
    std::ostringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    printHello();
    std::cout.rdbuf(old);

    REQUIRE(buffer.str() == "Hello, World!\n");
}
