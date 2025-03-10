NAME = server
CLIN = client
SRC = ./server_src/server.c ./server_src/ser_handlers.c
OBJ = $(SRC:.c=.o)
CLI = ./client_src/client.c ./client_src/cli_handlers.c
CLIOBJ = $(CLI:.c=.o)
LIB_DIR = ./libimp
LIB = $(LIB_DIR)/libft.a
HEADERS = ./inc/server.h ./inc/client.h ./inc/global.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
RM = rm -f

NBONUS := server_bonus
CBONUS := client_bonus

# COLORES
COLOREND = \033[0m
GREEN = \033[1;32m
RED = \e[1;31m
YELLOW = \e[1;33m
BLUE = \033[0;34m
CIAN = \e[7;36m


all: $(NAME) $(CLIN)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(OBJ) $(LIB) -o $(NAME)


$(CLIN): $(CLIOBJ) $(LIB)
	$(CC) $(CLIOBJ) $(LIB) -o $(CLIN)
	@clear
	@echo "\n$(GREEN)Compliation completed $(COLOREND)"


$(LIB):
	@$(MAKE) -C $(LIB_DIR)

bonus: $(NBONUS) $(CBONUS)

$(NBONUS): $(OBJ) $(LIB)
	$(CC) $(OBJ) $(LIB) -o $(NBONUS)

$(CBONUS): $(CLIOBJ) $(LIB)
	$(CC) $(CLIOBJ) $(LIB) -o $(CBONUS)
	@clear
	@echo "\n$(GREEN)Bonus compilation completed $(COLOREND)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(CLIOBJ)
	@$(MAKE) clean -C $(LIB_DIR)
	@clear
	@echo "$(BLUE)Limpio$(COLOREND)"

fclean: clean
	$(RM) $(NAME) $(CLIN) $(NBONUS) $(CBONUS)
	@$(MAKE) fclean -C $(LIB_DIR)
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
	@for file in $(CLI); do \
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
