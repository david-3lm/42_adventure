CC=gcc
CFLAGS=-Wall -Werror -Wextra -D BUFFER_SIZE=10
DEPS = get_next_line.c get_next_line_utils.c main.c

all: get_next_line

get_next_line:
	@$(CC) $(CFLAGS) $(DEPS)
	@./a.out

clean:
	$(RM) $(OBJ) $(OBJBONUS)
	@echo "$(BLUE)Limpio$(COLOREND)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(BLUE)Limpio$(COLOREND)"

re: fclean all


.PHONY: all clean fclean re bonus get_next_line

