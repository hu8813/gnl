/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 01:11:50 by huaydin           #+#    #+#             */
/*   Updated: 2022/10/30 13:49:40 by huaydin          ###   ########.fr       */
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

static char	*get_first_line(char *str)
{
	size_t	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while ((str)[i] != '\n' && (str)[i])
		i++;
	if ((str)[i] == '\n')
		return (ft_substr(str, 0, i + 1));
	else
		return (ft_strdup(str));
}

static char	*remaining_lines(char *str)
{
	char	*result;
	size_t	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
		return (ft_free(&str));
	if (str[i])
		i++;
	result = (ft_substr(str, i, ft_strlen(str) - i));
	free(str);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*first_line;
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
	first_line = get_first_line(cache[fd]);
	cache[fd] = remaining_lines(cache[fd]);
	return (first_line);
}
