NAME = libftprintf.a
SRC = ft_printf.c ft_print_string.c ft_print_nbr_dec.c ft_print_unsigned.c ft_print_hex.c ft_print_ptr.c

OBJ = $(SRC:.c=.o)
#SRCBONUS =
#OBJBONUS = $(SRCBONUS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

#COLORES
COLOREND = \033[0m
GREEN = \033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)
#	@echo "$(GREEN)ft_printf compilado!$(COLOREND)"
#	gcc main.c -L. -l ftprintf -o main
#	./main

clean:
	$(RM) $(OBJ) $(OBJBONUS)
	@make clean -C libft
#	@echo "$(BLUE)Limpio$(COLOREND)"

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft
#	@echo "$(BLUE)Limpio$(COLOREND)"

re: fclean all

#bonus: $(OBJBONUS)
#	ar rcs $(NAME) $(OBJBONUS)

.PHONY: all clean fclean re bonus
