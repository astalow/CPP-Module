NAME		= ClapTrap03

SRCS		= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -I. -Wno-shadow
OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
