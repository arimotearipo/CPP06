MAIN = main.cpp

SRCS = Base.cpp

HEADERS = A.hpp B.hpp C.hpp Base.hpp

OBJS = $(SRCS:.cpp=.o) main.o

CC = c++ -std=c++98

FLAGS = -Wall -Wextra -Werror

NAME = identify_type

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:		
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all