CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: identify_test

identify_test: main.cpp Base.cpp A.cpp B.cpp C.cpp
    $(CXX) $(CXXFLAGS) $^ -o $@

clean:
    rm -f identify_test
