#include <vector>

class cgol
{
private:
  size_t _height;
  size_t _width;
  std::vector<char> _board;

public:
  cgol(size_t height, size_t width);
  ~cgol();
  size_t height();
  size_t width();
  void set(int x, int y);
  std::vector<char> board();
};
