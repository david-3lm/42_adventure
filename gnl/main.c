#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("prueba", O_RDONLY);

	printf("%s", get_next_line(fd));
}
