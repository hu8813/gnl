/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:36:06 by hu8813            #+#    #+#             */
/*   Updated: 2022/10/26 18:23:12 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_free(char *buffer)
{
	free(buffer);
	buffer = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*buffer_read[1024] = {0};
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
		if (!buffer_read[fd])
			buffer_read[fd] = ft_mystrdup("");
		buffer_read[fd] = ft_join(buffer_read[fd], buffer, n);
		if (ft_mystrchr(buffer, '\n'))
			break ;
		n = read(fd, buffer, BUFFER_SIZE);
	}
	ft_free(buffer);
	if ((n < 0) || (!n && (!buffer_read[fd] || !*buffer_read[fd])))
		return (NULL);
	return (ft_get_first_line(&buffer_read[fd], n));
}
/*
#include <fcntl.h>
#include <stdio.h>
#include <stdio_ext.h>
int	main(void)
{
	int	fd1;
	int	fd2;

	fd1 = open("get_next_line.h", O_RDONLY);
	fd2 = open("get_next_line_bonus.h", O_RDONLY);
	printf("File1 Line1:%s\n", get_next_line(fd1));
	printf("File2 Line1:%s\n", get_next_line(fd2));
	printf("File1 Line2:%s\n", get_next_line(fd1));
	printf("File2 Line2:%s\n", get_next_line(fd2));
	printf("File1 Line3:%s\n", get_next_line(fd1));
	printf("File2 Line3:%s\n", get_next_line(fd2));
	printf("File1 Line4:%s\n", get_next_line(fd1));
	printf("File2 Line4:%s\n", get_next_line(fd2));
	close(fd1);
	close(fd2);
}
*/