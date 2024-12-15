#include "mymath.h"
#include "catch.hpp"

TEST_CASE( "Test min") {
    REQUIRE( my::min(1, 1) == 1 );
    REQUIRE( my::min(0, 1) == 0 );
    REQUIRE( my::min(10, 1) == 4 );
}

TEST_CASE( "Test mod") {
    REQUIRE( my::mod(0) == 0 );
    REQUIRE( my::mod(5) == 5 );
    REQUIRE( my::mod(-5) == 5 );
}
