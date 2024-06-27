CC=gcc
CFLAGS=-Wall -Werror -Wextra -D BUFFER_SIZE=2048
DEBUGFLAGS=-g -O0
DEPS = get_next_line.c get_next_line_utils.c main.c
OBJ = $(DEPS:.c=.o)

all: get_next_line

get_next_line:
	@$(CC) $(CFLAGS) $(DEPS)
#	@./a.out

debug: CFLAGS += $(DEBUGFLAGS)
debug: clean get_next_line
	@echo "Compilado en modo debug con información de depuración"

run_debug: debug
	@gdb ./a.out

clean:
	$(RM) a.out $(OBJ)
	@echo "Limpiando archivos objeto y ejecutable"

fclean: clean
	$(RM) $(NAME)
	@echo "Limpiando todo"

re: fclean all

.PHONY: all clean fclean re debug run_debug
