/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 01:12:13 by huaydin           #+#    #+#             */
/*   Updated: 2022/12/25 09:53:12 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_free(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (NULL);
}

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
	static char	*cache[FD_SETSIZE + 1];
	size_t		n;

	if (BUFFER_SIZE <= 0 || fd < 0 || FD_SETSIZE < fd)
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
	return (get_first_and_remaining_lines(cache[fd], &cache[fd]));
}
