NAME = account

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

INC = inc

SRC =	Account.cpp \
		tests.cpp

OBJDIR = obj/

OBJ := $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -I $(INC) -o $(NAME) $(OBJ)

$(OBJDIR)%.o : %.cpp | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INC) -o $@ -c $<

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

re : fclean all