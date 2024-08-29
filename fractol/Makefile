NAME = fractol
SRC = main.c complex_utils.c fractal_utils.c mouse.c view.c render.c

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
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@


clean:
	$(RM) $(OBJ) $(OBJBONUS)
	@echo "$(BLUE)Limpio$(COLOREND)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(BLUE)Limpio$(COLOREND)"

re: fclean all

#bonus: $(OBJBONUS)
#	ar rcs $(NAME) $(OBJBONUS)

.PHONY: all clean fclean re bonus
