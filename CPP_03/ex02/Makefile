# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = robotgame

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

# Phony targets
.PHONY: all clean fclean re
