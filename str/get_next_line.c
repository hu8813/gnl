/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdittric <cdittric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:16:23 by cdittric          #+#    #+#             */
/*   Updated: 2022/10/29 00:11:35 by hu8813           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(const int fd)
{
	static t_f	*openfiles;
	t_f			*f;
	char			*line;
	int			i;
	t_f	*tmp;

	//*line= "";
	(void) tmp;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024 || read(fd, 0, 0) == -1)
		return (NULL);

	if (read(fd, 0, 0) == 0 && !openfiles)
		return(NULL);
	f = openfiles;
	while (!(i = 0) && f && f->d != fd)
		f = f->n;
	if (fd < 0 || (!f && (!(f = malloc(sizeof(*f))) || ((f->n = openfiles) && 0)
				|| (f->d *= 0) || (f->d += fd) < 0 || !(openfiles = f)
				|| (f->i *= 0) || (f->j *= 0))) || (f->s *= 0))
		return (NULL);
	while (!(f->k *= 0) && (f->i < f->j || (!(f->i *= 0) && (f->j = read(fd,
						f->r, BUFFER_SIZE)) > 0)) && (f->s == 0
			|| f->r[f->i] != 10 || !(++f->i)))
	{
		if (i + BUFFER_SIZE >= f->s && (f->k -= 1) && ((f->t = f->b) || 1)
			&& (f->b = (char *)malloc(sizeof(char) * (i + BUFFER_SIZE + 1))))
			while (++(f->k) < i && (f->k) < f->s)
				free(((f->b[f->k] = f->t[f->k]) && (f->k + 1 < i) ? 0 : f->t));
		if (i + BUFFER_SIZE >= f->s && ((!f->b && ((f->b = f->t) || 1))
				|| !(f->s = i + BUFFER_SIZE + 1)))
			return (NULL);
		while (f->i < f->j && f->r[f->i] != '\n')
			f->b[i++] = f->r[f->i++];
	}
	line = f->b;
	return (line);
	//return ((i || f->j > 0) && (*line = f->b) && !(f->b[i] *= 0) ? 1 : f->j);
}
