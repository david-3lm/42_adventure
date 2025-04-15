NAME = philo
SRC = ./src/main.c ./src/forks.c ./src/death.c ./src/philo.c ./src/table.c ./src/meals.c ./utils/ft_atoi.c ./utils/timing.c ./utils/console.c ./utils/cleaner.c ./actions/eat.c ./actions/sleep.c 
OBJ = $(SRC:.c=.o)
HEADERS = ./inc/philo.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra -O0 #-fsanitize=thread -fPIE -pie -g
RM = rm -f

# COLORES
COLOREND = \033[0m
GREEN = \033[1;32m
RED = \e[1;31m
YELLOW = \e[1;33m
BLUE = \033[0;34m
CIAN = \e[7;36m


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@clear
	@echo "$(BLUE)Limpio$(COLOREND)"

fclean: clean
	$(RM) $(NAME)
	@clear
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

.PHONY: all clean fclean re exec norma debug bonus
