MAIN = main.cpp

SRCS = serialize.cpp

OBJS = $(SRCS:.cpp=.o) main.o

HEADERS = serialize.hpp

CC = c++ -std=c++98

FLAGS = -Wall -Wextra -Werror

NAME = serialize

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:		
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all