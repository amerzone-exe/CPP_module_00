NAME = phonebook

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors

INC = inc

SRC =	main.cpp \
		Contact.cpp \
		PhoneBook.cpp \
		utils.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -I $(INC) -o $(NAME) $(OBJ)

%.o : %.cpp
	$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

clean :
	rm $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
