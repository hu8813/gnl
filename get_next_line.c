/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hu8813 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:35:47 by hu8813            #+#    #+#             */
/*   Updated: 2022/10/23 23:31:50 by hu8813           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*return_next_line(char **s)
{
	char	*out;
	char	*tmp;
	size_t	len;

	len = 0;
	out = NULL;
	while ((*s)[len] != '\n' && (*s)[len])
		len++;
	if ((*s)[len] == '\n')
	{
		out = ft_substr(*s, 0, len + 1);
		tmp = ft_strdup(*s + len + 1);
		free(*s);
		*s = tmp;
		if (!**s)
		{
			free(*s);
			*s = NULL;
		}
		return (out);
	}
	out = ft_strdup(*s);
	free(*s);
	*s = NULL;
	return (out);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*tmp;
	static char	*s;
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	s = ft_strdup("");
	if (!buf || !s)
		return (NULL);
	n = read(fd, buf, BUFFER_SIZE);
	while (n > 0)
	{
		buf[n] = '\0';
		tmp = ft_strjoin(s, buf);
		free(s);
		s = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
		n = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if ((n < 0) || (!n && (!s || !*s)))
		return (NULL);
	return (return_next_line(&s));
}
