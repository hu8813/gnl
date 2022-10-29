/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hu8813 <hu8813@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:54:10 by hu8813            #+#    #+#             */
/*   Updated: 2022/10/29 22:03:49 by hu8813           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	int		len;
	int		i;

	len = (int)ft_strlen(s);
	new = malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*new_string;
	size_t	i;
	size_t	j;

	new_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (new_string == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("\0");
	if (s1)
		while (s1[i])
			new_string[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_string[j++] = s2[i++];
	new_string[j] = '\0';
	free(s1);
	return (new_string);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*first_occurence;

	i = 0;
	first_occurence = NULL;
	if (!s)
		return (NULL);
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			first_occurence = (char *)&s[i];
			break ;
		}
		i++;
	}
	return (first_occurence);
}
