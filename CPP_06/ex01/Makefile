CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: serializer_test

serializer_test: main.cpp Serializer.cpp Data.cpp
    $(CXX) $(CXXFLAGS) $^ -o $@

clean:
    rm -f serializer_test
