/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:24:49 by huaydin           #+#    #+#             */
/*   Updated: 2022/10/27 18:08:52 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free(char *buffer)
{
	free(buffer);
	buffer = NULL;
}

static char	*ft_line_with_nl(char **cache)
{
	size_t	n;
	char	*tmp;
	char	*line;

	n = 0;
	while (cache[n] != '\0' && cache[n] != '\n')
		n++;
	tmp = *cache;
	line = ft_substr(tmp, 0, n + 1);
	*cache = ft_strdup(&cache[n + 1]);
	ft_free(tmp);
	return (line);
}

static size_t	ft_read_from_file(int fd, char *buffer, char **cache)
{
	size_t	n;
	char	*tmp;

	n = 1;
	while (n && (!ft_strchr(*cache, '\n')))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
			return (n);
		*cache[n] = '\0';
		printf("%s\n",*cache);
		printf("%s\n",buffer);
		tmp = *cache;
		*cache = ft_strjoin(tmp, *cache);
		ft_free(tmp);
	}
	return (n);
}

static char	*ft_getline(int fd, char **buffer, char **cache)
{
	size_t	n;
	char	*tmp;

	if (ft_strchr(*cache, '\n'))
		ft_line_with_nl(*cache);
	n = ft_read_from_file(fd, buffer, cache);
	if ((n == 0 || n == -1) && !**cache)
	{
		ft_free(*cache);
		return (NULL);
	}
	if (ft_strchr(*cache, '\n'))
		ft_line_with_nl(*cache);
	if (!ft_strchr(*cache, '\n') && *cache)
	{
		tmp = ft_strdup(*cache);
		ft_free(*cache);
		return (tmp);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*cache[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = ft_getline(fd, buffer, &cache[fd]);
	ft_free(buffer);
	return (line);
}
