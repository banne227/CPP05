############################################################
#                                                          #
#   ██████╗ ██████╗ ███╗   ██╗                             #
#   ██╔══██╗╚════██╗████╗  ██║                             #
#   ██████╔╝ █████╔╝██╔██╗ ██║                             #
#   ██╔══██╗██╔═══╝ ██║╚██╗██║                             #
#   ██████╔╝███████╗██║ ╚████║                             #
#   ╚═════╝ ╚══════╝╚═╝  ╚═══╝                             #
#                                                          #
#   File    : Makefile                                     #
#   Created : 2026-01-16 17:12                             #
#   Updated : 2026-01-16 17:12                             #
#                                                          #
############################################################

NAME		= bureaucrat

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp \
			  srcs/Bureaucrat.cpp \
			  srcs/Form.cpp \

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

c:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

r: fclean all c

.PHONY: all clean fclean re r