/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 01:11:50 by huaydin           #+#    #+#             */
/*   Updated: 2023/01/18 21:26:36 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_first_and_remaining_lines(char *str, char **remaining)
{
	size_t	i;
	char	*first;

	if (str == NULL)
		return (NULL);
	i = 0;
	while ((str)[i] != '\n' && (str)[i])
		i++;
	first = ft_substr(str, 0, i + 1);
	if ((str)[i] == '\n' && (str)[i + 1])
		*remaining = ft_substr(str, i + 1, ft_strlen(str) - i - 1);
	else
		*remaining = NULL;
	free(str);
	return (first);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*cache[1025];
	size_t		n;

	if (BUFFER_SIZE <= 0 || fd < 0 || 1025 < fd)
		return (NULL);
	else if (read(fd, 0, 0) < 0)
	{
		if (cache[fd])
			free(cache[fd]);
		return (cache[fd] = NULL, NULL);
	}
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	n = 1;
	while ((ft_strchr(cache[fd], '\n') == NULL) && n != 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0 || n == 0)
			break ;
		buffer[n] = '\0';
		cache[fd] = ft_strjoin(cache[fd], buffer);
	}
	return (free(buffer), get_first_and_remaining_lines(cache[fd], &cache[fd]));
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	//int fd = 0;
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
}
*/
