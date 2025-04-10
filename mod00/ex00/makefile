# Compiler and Flag
CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = megaphone

# Sources and objects
SRCS = megaphone.cpp
OBJDIR = obj
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

# Default rule
all: $(OBJDIR) $(NAME)

# Linking
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation
$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean rule
clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean