#include "cgol.hpp"

cgol::cgol(size_t height, size_t width) {
  _height = height;
  _width = width;
  _board = std::vector<char>(height * width);
  for(auto & cell : _board) {
    cell = ' ';
  }
}

size_t cgol::height() { return _height; }
size_t cgol::width() { return _width; }
std::vector<char> cgol::board() { return _board; }

void cgol::set(int x, int y) {
  auto position = y * _width + x;
  _board[position] = '#';
}

cgol::~cgol() {}