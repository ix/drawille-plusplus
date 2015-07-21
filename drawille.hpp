#ifndef DRAWILLE_HPP
#define DRAWILLE_HPP

#include <vector>
#include <ostream>
#include <unicode/ustream.h>
#include <unicode/unistr.h>

namespace Drawille {
	using std::vector;
	using std::ostream;

	const size_t pixmap[4][2] = {
		{0x01, 0x08},
		{0x02, 0x10},
		{0x04, 0x20},
		{0x40, 0x80}
	};

	const size_t braille = 0x2800;

	class Canvas {
	public:
		Canvas(size_t width, size_t height) {
			this->canvas.resize(height);
			for(auto& v: this->canvas)
				v.resize(width);
		}

		void set(size_t x, size_t y) {
			if(x > this->canvas[0].size() or x < 1) x = 0;
			if(y > this->canvas.size() or y < 1)    y = 0;
			this->canvas[y / 4][x / 2] |= pixmap[y % 4][x % 2];
		}

		void unset(size_t x, size_t y) {
			if(x > this->canvas[0].size() or x < 1) x = 0;
			if(y > this->canvas.size() or y < 1)    y = 0;
			this->canvas[y / 4][x / 2] &= ~pixmap[y % 4][x % 2];
		}

		void draw(ostream& strm) {
			for(auto& v: this->canvas) {
				for(auto& c: v) {
					if(c == 0) strm << " ";
					else strm << UnicodeString((UChar32)(braille+c));
				}
				strm << std::endl;
			}
		}

	protected:
		vector<vector<int>> canvas;
	};
};

#endif
