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

$(OBJS):	$(MAIN) $(SRCS)
			$(CC) $(FLAGS) $(MAIN) $(SRCS) -c

clean:		
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all