#include <catch.hpp>

TEST_CASE( "The test suit runs", "[cgol]") {
  REQUIRE( true );
}

TEST_CASE( "The test suit doesn't", "[cgol]") {
  REQUIRE( false );
}