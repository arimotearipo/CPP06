SRCS = serialize.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++ -std=c++98

FLAGS = -Wall -Wextra -Werror

NAME = serialize

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:		
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all