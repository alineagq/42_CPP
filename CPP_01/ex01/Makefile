CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = ex01
SRCS = Zombie.cpp main.cpp zombieHorde.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

re: clean all

.PHONY: all clean re