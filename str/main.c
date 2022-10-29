#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int     fd;
	int     ret;
	char    *line;

	fd = open("get_next_line.c", O_RDONLY);
	line = get_next_line(fd);
	while ((*line) )
	{
		printf("%s\n", line);
		line = get_next_line(fd);
	}
	
	close(fd);
	return (0);
}
