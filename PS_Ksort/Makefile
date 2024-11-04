NAME = push_swap
SRC = push_swap.c mem_utils.c init.c pushes.c r_rotates.c rotates.c stack_utils.c swaps.c \
	order.c check_order.c data_utils.c idx_utils.c math_utils.c algo.c
HEADERS = push_swap.h
OBJ = $(SRC:.c=.o)
LIB_DIR = ./libimp
LIB = $(LIB_DIR)/libft.a

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

TEST_FILE = tests

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(OBJ) $(LIB) -o $(NAME) -lm

$(LIB):
	@$(MAKE) -C $(LIB_DIR)
	@echo "\n$(GREEN)Compliation completed $(COLOREND)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@$(MAKE) clean -C $(LIB_DIR)
	@echo "$(BLUE)Limpio$(COLOREND)"

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIB_DIR)
	@echo "$(BLUE)Limpio$(COLOREND)"

re: fclean all

exec:
	./$(NAME)

norma:
	@echo "$(CIAN)SCRIPTS\n$(COLOREND)"
	@for file in $(SRC); do \
		norminette $$file | grep "OK!" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "$(GREEN)$$file: OK!$(COLOREND)"; \
		else \
			echo "$(RED)"; \
			norminette $$file; \
			echo "$(COLOREND)"; \
		fi \
	done
	@echo "$(CIAN)\nHEADERS\n$(COLOREND)"
	@for header in $(HEADERS); do \
		norminette $$header | grep "OK!" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "$(GREEN)$$header: OK!$(COLOREND)"; \
		else \
			echo "$(RED)"; \
			norminette $$header; \
			echo "$(COLOREND)"; \
		fi \
	done

debug: CFLAGS += -g3 -O0
debug: re
# gdb 

test:
	while read line; do \
		echo "\nTesting with: $$line"; \
		./$(NAME) "$$line" | ./checker_linux "$$line"; \
	done < $(TEST_FILE)


.PHONY: all clean fclean re exec norma debug
