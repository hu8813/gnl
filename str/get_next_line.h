/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdittric <cdittric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:16:19 by cdittric          #+#    #+#             */
/*   Updated: 2022/10/29 00:11:43 by hu8813           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
/*
** t_f: Chained file info list element
** d	File descriptor
** s	Line buffer size
** b	Line buffer
** t	Pointer to temporary buffer used when reallocating line buffer
** r	Read buffer
** i	Index of next character to read in read buffer
** j 	Number of characters in read buffer
** k	Line buffer iterator
** n	Next element in chained list
*/

typedef struct s_f
{
	int			d;
	int			s;
	char		*b;
	char		*t;
	char		r[BUFFER_SIZE];
	int			i;
	int			j;
	int			k;
	struct s_f	*n;
}				t_f;

char				*get_next_line(const int fd);

#endif
