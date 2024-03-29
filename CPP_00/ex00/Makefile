CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = megaphone
SRCS = megaphone.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

re: clean all

.PHONY: all clean re
