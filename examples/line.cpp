#include <iostream>
#include "../drawille.hpp"

using namespace Drawille;
using std::cout;

int main(int argc, char **argv) {
	Canvas canvas(80, 24);

	for(int i = 0; i <= 10; ++i) {
		canvas.set(i, i);
	}

	canvas.draw(cout);

	return 0;
}
