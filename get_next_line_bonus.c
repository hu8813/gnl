/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:36:06 by hu8813            #+#    #+#             */
/*   Updated: 2022/10/24 14:05:08 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_first_line(char **all_lines)
{
	char	*first_line;
	char	*tmp;
	size_t	i;

	i = 0;
	first_line = NULL;
	while ((*all_lines)[i] != '\n' && (*all_lines)[i])
		i++;
	if ((*all_lines)[i] == '\n')
	{
		first_line = ft_substr(*all_lines, 0, i + 1);
		tmp = ft_strdup(*all_lines + i + 1);
		free(*all_lines);
		*all_lines = tmp;
		if (!**all_lines)
		{
			free(*all_lines);
			*all_lines = NULL;
		}
		return (first_line);
	}
	first_line = ft_strdup(*all_lines);
	free(*all_lines);
	*all_lines = NULL;
	return (first_line);
}

static char	*ft_join(char *all_lines, char *buffer, ssize_t n)
{
	char	*tmp;

	buffer[n] = '\0';
	tmp = ft_strjoin(all_lines, buffer);
	free(all_lines);
	all_lines = tmp;
	return (all_lines);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*all_lines[FD_SIZE];
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!all_lines[fd])
		all_lines[fd] = ft_strdup("");
	n = read(fd, buffer, BUFFER_SIZE);
	while (n > 0)
	{
		buffer[n] = '\0';
		all_lines[fd] = ft_join(all_lines[fd], buffer, n);
		if (ft_strchr(buffer, '\n'))
			break ;
		n = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	buffer = NULL;
	if ((n < 0) || (!n && (!all_lines[fd] || !*all_lines[fd])))
		return (NULL);
	return (ft_get_first_line(&all_lines[fd]));
}
/*
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
	char		*tmp;
	char		*buf;
	static char	*s[FD_SIZE];
	ssize_t		n;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	n = read(fd, buf, BUFFER_SIZE);
	while (n > 0)
	{
		buf[n] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup("");
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
		n = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if ((n < 0) || (!n && (!s[fd] || !*s[fd])))
		return (NULL);
	return (return_next_line(&s[fd]));
}
*/
