/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:24:49 by huaydin           #+#    #+#             */
/*   Updated: 2022/10/24 13:42:49 by huaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

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
	static char	*all_lines;
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!all_lines)
		all_lines = ft_strdup("");
	n = read(fd, buffer, BUFFER_SIZE);
	while (n > 0)
	{
		buffer[n] = '\0';
		all_lines = ft_join(all_lines, buffer, n);
		if (ft_strchr(buffer, '\n'))
			break ;
		n = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	buffer = NULL;
	if ((n < 0) || (!n && (!all_lines || !*all_lines)))
		return (NULL);
	return (ft_get_first_line(&all_lines));
}



/*
int main()
{
  int fd;
  
  fd = open("text.txt", O_RDONLY);
  printf("Line1:%s\n", get_next_line(fd));
  printf("Line2:%s\n", get_next_line(fd));
  printf("Line3:%s\n", get_next_line(fd));
  //printf("%s\n", get_next_line(fd));
  //close(fd);
}
*/

/*
int	main(int argc, char **argv)
{
	char *line;
	int f;
	size_t read;
	size_t len;
	FILE *fd;	
	
	printf("fd=%d\n", BUFFER_SIZE);
	(void)argc;
	(void)argv;

	f = open("text.txt", O_RDONLY);
	//f = (int) fd;
	printf("fd=%d\n", f);
	//read = getline(&line, &len, fd);
	printf("fd=%zu\n", read);

	//printf("fd=%d\n", fd);
		
	while ((read = getline(&line, &len, fd)) != -1) {
		printf("Retrieved line of length %zu :\n", read);
		printf("%s", line);
	}
	

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
	//	fd = open(argv[1], O_RDONLY);
		fd = open("text.txt", O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);

}
*/