#include <iostream>
#include <locale>
#include "../drawille.hpp"

using namespace Drawille;
using std::wcout;
using std::locale;

int main() {
  locale::global(locale(""));
  Canvas canvas(80, 24);

  for(int i = 0; i <= 10; ++i) {
    canvas.set(i, i);
  }

  canvas.draw(wcout);

  return 0;
}
