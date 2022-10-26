/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:35:38 by hu8813            #+#    #+#             */
/*   Updated: 2022/10/26 15:18:39 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_mystrlen(const char *s);
char	*ft_mystrchr(const char *s, int c);
char	*ft_mystrdup(const char *s);
char	*ft_mystrjoin(char const *s1, char const *s2);
char	*ft_mysubstr(char const *s, unsigned int start, size_t len);

#endif
