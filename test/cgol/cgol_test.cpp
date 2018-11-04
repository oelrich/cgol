#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "cgol.hpp"

SCENARIO("a game can be started", "[cgol]") {
  GIVEN("A height and a width") {
    size_t height = 2;
    size_t width = 3;
    cgol cgol(height, width);
    REQUIRE(cgol.height() == height);
    REQUIRE(cgol.width() == width);
    WHEN("the board is requested") {
      auto board = cgol.board();
      THEN("the size of the board should be height x width") {
        REQUIRE(board.size() == (height * width));
      }
      AND_THEN("all cells should be dead") {
        for(auto const& cell : board) {
          REQUIRE(cell == ' ');
        }
      }
    }
  }
}