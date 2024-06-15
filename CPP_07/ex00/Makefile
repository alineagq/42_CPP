CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

all: main

main: main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp whatever.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f main main.o
