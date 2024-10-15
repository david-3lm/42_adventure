NAME = server
CLIN = client
SRC = server.c
OBJ = $(SRC:.c=.o)
CLI = client.c
CLIOBJ = $(CLI:.c=.o)
LIBFTPRINTF_DIR = ./ft_printf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
RM = rm -f

# COLORES
COLOREND = \033[0m
GREEN = \033[1;32m
RED = \e[1;31m
YELLOW = \e[1;33m
BLUE = \033[0;34m
CIAN = \e[7;36m


all: $(NAME) $(CLIN)

$(NAME): $(OBJ) $(LIBFTPRINTF)
	$(CC) $(OBJ) $(LIBFTPRINTF) -o $(NAME)


$(CLIN): $(CLIOBJ) $(LIBFTPRINTF)
	$(CC) $(CLIOBJ) $(LIBFTPRINTF) -o $(CLIN)
	@clear
	@echo "\n$(GREEN)Compliation completed $(COLOREND)"


$(LIBFTPRINTF):
	@$(MAKE) -C $(LIBFTPRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(CLIOBJ)
	@$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	@clear
	@echo "$(BLUE)Limpio$(COLOREND)"

fclean: clean
	$(RM) $(NAME) $(CLIN)
	@$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	@clear
	@echo "$(BLUE)Limpio$(COLOREND)"

re: fclean all

exec:
	./$(NAME)


debug: CFLAGS += -g3 -O0
debug: re
# gdb 


.PHONY: all clean fclean re exec norma debug
