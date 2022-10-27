/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hu8813 <hu8813@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:21:44 by hu8813            #+#    #+#             */
/*   Updated: 2022/10/26 23:24:16 by hu8813           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(const char *s)
{
	ssize_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*ft_strchr(const char *s, int c)
{
	ssize_t	i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	while (ptr[i] != (char)c && ptr[i] != '\0')
		i++;
	if (ptr[i] == (char)c)
		return ((char *)&ptr[i]);
	if (!c && ptr[i] == '\0')
		return ((char *)&ptr[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	ssize_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = s[i];
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
				+ 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, ssize_t len)
{
	char	*str;
	char	*result;
	ssize_t	strsize;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	strsize = ft_strlen(s + start);
	if (len > strsize)
		len = strsize;
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	str = result;
	s = s + start;
	while (*s && len--)
		*result++ = *s++;
	*result = '\0';
	return (str);
}
