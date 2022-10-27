#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int	main(void)
{
	int	fd;

	fd = open("get_next_line.h", O_RDONLY);
	printf("a=%s", get_next_line(fd));
	close(fd);
/*
	fd = open("get_next_line.c", O_RDONLY);
	close(fd);
	fd = open("get_next_line.h", O_RDONLY);
	printf("a=%s", get_next_line(fd));
	close(fd);
	fd = open("get_next_line.h", O_RDONLY);
	printf("a=%s", get_next_line(fd));
	close(fd);
	fd = open("get_next_line.h", O_RDONLY);
	printf("a=%s", get_next_line(fd));
*/
	return (0);
}
