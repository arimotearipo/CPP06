SRCS = Conversion.cpp

OBJS = $(SRCS:.cpp=.o) main.o

HEADERS = $(SRCS:.cpp=.hpp)

CC = c++ -std=c++98

FLAGS = -Wall -Wextra -Werror

NAME = convert

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:	
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all