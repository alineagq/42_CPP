CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: convert

convert: main.cpp ScalarConverter.cpp
    $(CXX) $(CXXFLAGS) $^ -o $@

clean:
    rm -f convert
