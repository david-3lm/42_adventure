NAME = libftprintf.a
SRC = ft_printf.c
OBJ = $(SRC:.c=.o)
#SRCBONUS =
#OBJBONUS = $(SRCBONUS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	gcc main.c -L. -l ftprintf -o main
	./main
clean:
	$(RM) $(OBJ) $(OBJBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJBONUS)
	ar rcs $(NAME) $(OBJBONUS)

.PHONY: all clean fclean re bonus
