#include <iostream>
#include <vector>
#include <utility>
#include "../drawille.hpp"

using std::cout;
using std::vector;
using std::pair;
using Drawille::Canvas;

int main(int argc, char **argv) {
  using point = pair<int, int>;

  Canvas canvas(80, 24);
  
  const vector<point> points = {
    {1, 1},
    {(80*2) - 1, (24*4) - 1}
  };

  for(auto& p : points) {
    canvas.set(p.first, p.second);
  }

  canvas.draw(cout);
  
  return 0;
}
