CXX?=g++
CXXFLAGS=-Wall -Werror -pedantic -std=c++14
all:
	for f in *.cpp ; do \
		echo "Compiling $$f..."; \
		$(CXX) $$f -o `basename $$f .cpp`".out" $(CXXFLAGS); \
	done;

clean:
	rm *.out
