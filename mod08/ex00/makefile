# Compiler and Flag
CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -Wno-conversion -std=c++98 -I$(INC)
NAME = easyfind

#Directories
INC = inc/
SRC_DIR = srcs/
OBJ_DIR = obj/

#Sources and objects
SRCS = 	$(SRC_DIR)main.cpp \

OBJS = $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRCS))

# Default rule
all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Linking
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Assembler
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re