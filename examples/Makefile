CXX?=g++
CXXFLAGS=-Wall -Werror -pedantic -std=c++14
LDFLAGS=-licuuc -licuio
all:
	for f in *.cpp ; do \
		echo "Compiling $$f..."; \
		$(CXX) $$f -o `basename $$f .cpp`".out" $(CXXFLAGS) $(LDFLAGS); \
	done;

clean:
	rm *.out
