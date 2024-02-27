CC=gcc
CFLAGS=-Wall -Werror -Wextra -D BUFFER_SIZE=64
DEPS = get_next_line.c get_next_line_utils.c main.c

all: get_next_line

get_next_line:
	@$(CC) $(CFLAGS) $(DEPS)
	@./a.exe

.PHONY: all get_next_line