/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hu8813 <hu8813@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:53:40 by hu8813            #+#    #+#             */
/*   Updated: 2022/10/29 22:12:00 by hu8813           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (NULL);
}

static char	*first_line(char *str)
{
	char	*result;
	size_t	i;

	if (str == NULL)
		return (NULL);
	result = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	result[i] = '\0';
	return (result);
}

static char	*remaining_lines(char *str)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
		return (free(str), NULL);
	if (str[i])
		i++;
	result = malloc(sizeof(char) * ft_strlen(str + i) + 1);
	if (result == NULL)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*out;
	static char	*cache[1025];
	size_t		n;

	if (BUFFER_SIZE <= 0 || fd < 0 || 1024 < fd)
		return (NULL);
	else if (read(fd, 0, 0) < 0)
		return (ft_free(&cache[fd]));
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	n = 1;
	while ((ft_strchr(cache[fd], '\n') == NULL) && n != 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buffer[n] = '\0';
		cache[fd] = ft_strjoin(cache[fd], buffer);
	}
	free(buffer);
	out = first_line(cache[fd]);
	cache[fd] = remaining_lines(cache[fd]);
	return (out);
}
