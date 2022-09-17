SRCS = Conversion.cpp

MAIN = main.cpp

OBJS = $(SRCS:.cpp=.o) main.o

HEADERS = $(SRCS:.cpp=.hpp)

CC = c++ -std=c++98

FLAGS = -Wall -Wextra -Werror -Werror=implicit-fallthrough=0

NAME = convert

all:		$(NAME)

$(OBJS):	$(SRCS) $(MAIN)
			$(CC) $(FLAGS) $(SRCS) $(MAIN) -c

$(NAME):	$(OBJS) $(HEADERS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:	
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all