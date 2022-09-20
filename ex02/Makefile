MAIN = main.cpp

SRCS = Base.cpp

HEADERS = A.hpp B.hpp C.hpp Base.hpp

OBJS = $(SRCS:.cpp=.o) main.o

CC = c++ -std=c++98

FLAGS = -Wall -Wextra -Werror -fsanitize=address

NAME = identify_type

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS):	$(SRCS) $(MAIN)
			$(CC) $(FLAGS) $(SRCS) $(MAIN) -c

clean:		
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all