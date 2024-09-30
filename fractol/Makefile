NAME = fractol
SRC = main.c complex_utils.c pow_complex.c fractal_utils.c mouse.c keyboard.c \
render.c mandelbrot.c julia.c multibrot.c phoenix.c inerror.c init.c input.c
HEADERS = fractol.h keys.h
OBJ = $(SRC:.c=.o)
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


all: $(NAME)

$(NAME): $(OBJ) $(LIBFTPRINTF)
	$(CC) $(OBJ) $(LIBFTPRINTF) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFTPRINTF):
	@$(MAKE) -C $(LIBFTPRINTF_DIR)
	@echo "\n$(GREEN)Compliation completed \n $(BLUE)To execute the fractal:$(COLOREND) \n\t \
	-Mandelbrot: $(RED)./fractol $(GREEN)mandel \n\t $(COLOREND)\
	-Julia: $(RED)./fractol $(GREEN)julia [(double)cR] [(double)cI] \n\t $(COLOREND)\
	-Multibrot: $(RED)./fractol $(GREEN)multi [(double)cR] [(double)cI] ([(int)pow])$(COLOREND) \n\t \
	-Phoenix: $(RED)./fractol $(GREEN)phoenix [(double)cR] [(double)cI] [(double)pR] [(double)pI] $(COLOREND)"\



%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJ)
	@$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	@echo "$(BLUE)Limpio$(COLOREND)"

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
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

.PHONY: all clean fclean re exec norma
