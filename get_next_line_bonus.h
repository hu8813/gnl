/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hu8813 <hu8813@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:53:21 by hu8813            #+#    #+#             */
/*   Updated: 2022/10/29 22:14:33 by hu8813           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef FD_SETSIZE
#  define FD_SETSIZE 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char		*get_next_line(int fd);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char *s1, const char *s2);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);

#endif
