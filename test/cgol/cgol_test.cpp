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
    AND_WHEN("the board is given some state") {
      cgol.set(2,1);
      THEN("that and only that cell should be alive") {
        auto board = cgol.board();
        for(int iy = 0; iy < height; iy++) {
          for(int ix = 0; ix < width; ix++) {
            auto position = iy * width + ix;
            if(ix == 2 && iy == 1) {
              REQUIRE(board[position] == '#');
            } else {
              REQUIRE(board[position] == ' ');
            }
          }
        }
      }
      AND_THEN("more state should give more livning cells") {
        cgol.set(1,1);
        auto board = cgol.board();
        for(int iy = 0; iy < height; iy++) {
          for(int ix = 0; ix < width; ix++) {
            auto position = iy * width + ix;
            if((ix == 2 || ix == 1) && iy == 1) {
              REQUIRE(board[position] == '#');
            } else {
              REQUIRE(board[position] == ' ');
            }
          }
        }
      }
    }
  }
}

SCENARIO("a game can run", "[cgol]") {
  GIVEN("A board with some state") {
    size_t height = 2;
    size_t width = 3;
    cgol cgol(height, width);

    auto board = std::vector<char>(
      {' ', '#', ' ',
       '#', ' ', ' '});
    for(int pos = 0; pos < board.size(); pos++) {
      if(board[pos] == '#') {
        int x = pos % width;
        int y = static_cast<int>(pos / width);
        cgol.set(x,y);
      }
    }

    WHEN("nothing happens") {
      auto game_board = cgol.board();
      THEN("the board should be the same") {
        for(int pos = 0; pos < game_board.size(); pos++) {
          REQUIRE(board[pos] == game_board[pos]);
        }
      }
    }
  }
}