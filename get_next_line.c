/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:24:49 by huaydin           #+#    #+#             */
/*   Updated: 2022/10/26 19:15:28 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer)
{
	free(buffer);
	buffer = NULL;
	return (NULL);
}

static char	*ft_get_first_line(char **buffer_read, ssize_t n)
{
	char	*first_line;
	char	*tmp;
	size_t	i;

	(void)n;
	i = 0;
	first_line = NULL;
	while ((*buffer_read)[i] != '\n' && (*buffer_read)[i])
		i++;
	if ((*buffer_read)[i] == '\n')
	{
		first_line = ft_mysubstr(*buffer_read, 0, i + 1);
		tmp = ft_mystrdup(*buffer_read + i + 1);
		free(*buffer_read);
		*buffer_read = tmp;
		if (!**buffer_read)
		{
			free(*buffer_read);
			*buffer_read = NULL;
		}
		return (first_line);
	}
	first_line = ft_mystrdup(*buffer_read);
	free(*buffer_read);
	*buffer_read = NULL;
	return (first_line);
}

static char	*ft_join(char *buffer_read, char *buffer, ssize_t n)
{
	char	*tmp;

	buffer[n] = '\0';
	tmp = ft_mystrjoin(buffer_read, buffer);
	free(buffer_read);
	buffer_read = tmp;
	return (buffer_read);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*buffer_read = {0};
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer || read(fd, buffer, 0) == -1)
		return (ft_free(buffer));
	//if (ft_mystrchr(buffer_read, '\n'))
	//	return (ft_get_first_line(&buffer_read, 0));
	n = read(fd, buffer, BUFFER_SIZE);
	while (n > 0)
	{
		if (!buffer_read)
			buffer_read = ft_mystrdup("");
		buffer_read = ft_join(buffer_read, buffer, n);
		if (ft_mystrchr(buffer, '\n') || n == 0 || n == -1)
			break ;
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1 || n == 0)
			break ;
	}
	//if (*buffer_read)
	free(buffer);
	//if ((n < 0) || (!n && (!buffer_read || !*buffer_read)))
	if ((!n && (!buffer_read || !*buffer_read)))
			return (ft_free(buffer_read));
	return (ft_get_first_line(&buffer_read, n));
}
/*
#include <fcntl.h>
#include <stdio_ext.h>
int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("open_close_open.txt", O_RDONLY);
	//fd = 0;
	//buffer = malloc(BUFFER_SIZE + 1);
	//printf("res=%zd", read(fd, buffer, 0) );
	//return (0);
	printf("Line1:%s", get_next_line(fd));
	printf("Line2:%s", get_next_line(fd));
	printf("Line3:%s", get_next_line(fd));
	printf("Line4:%s", get_next_line(fd));
	printf("Line5:%s", get_next_line(fd));
	printf("Line6:%s", get_next_line(fd));
	printf("Line7:%s", get_next_line(fd));
	printf("Line8:%s", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
	//close(fd);
}
*/