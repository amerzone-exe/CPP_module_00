NAME = megaphone

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o : %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean all
