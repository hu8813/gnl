/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:24:55 by huaydin           #+#    #+#             */
/*   Updated: 2022/10/25 13:50:38 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_mystrlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*ft_mystrchr(const char *s, int c)
{
	size_t	i;
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

char	*ft_mystrdup(const char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_mystrlen(s) + 1));
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

char	*ft_mystrjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_mystrlen(s1) + ft_mystrlen(s2)
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

char	*ft_mysubstr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*result;
	size_t	strsize;

	if (!s)
		return (0);
	if (start > ft_mystrlen(s))
		start = ft_mystrlen(s);
	strsize = ft_mystrlen(s + start);
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
