/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:24:33 by huaydin           #+#    #+#             */
/*   Updated: 2022/10/26 18:44:36 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_mystrlen(const char *s);
char	*ft_mystrchr(const char *s, int c);
char	*ft_mystrdup(const char *s);
char	*ft_mystrjoin(char const *s1, char const *s2);
char	*ft_mysubstr(char const *s, unsigned int start, size_t len);

#endif
