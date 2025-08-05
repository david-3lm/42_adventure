NAME = ex03

# Archivos fuente
SRC_DIR = src
OBJ_DIR = obj

SRC = $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/AMateria.cpp \
      $(SRC_DIR)/ICharacter.cpp

OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

HEADERS =

CC = c++
CPPFLAGS = -Wall -Werror -Wextra -Iinclude -std=c++98
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
	$(CC) $(CPPFLAGS) -o $@ $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

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

debug: CPPFLAGS += -g3 -O0
debug: re

.PHONY: all clean fclean re exec norma debug bonus
