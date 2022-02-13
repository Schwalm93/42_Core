/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:47:46 by cschwalm          #+#    #+#             */
/*   Updated: 2022/01/31 12:56:41 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

// reads from the filedescriptor and stores it as string
char	*ft_read(int fd, char *s_buffer)
{
	char	*buf_read;
	ssize_t	b_read;

	b_read = 1;
	buf_read = malloc(BUFFER_SIZE + 1);
	if (buf_read == NULL)
		return (NULL);
	while (b_read != 0 && !(ft_strchr(s_buffer, '\n')))
	{
		b_read = read(fd, buf_read, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(buf_read);
			return (NULL);
		}
		buf_read[b_read] = '\0';
		s_buffer = ft_strjoin(s_buffer, buf_read);
	}
	free(buf_read);
	return (s_buffer);
}

// extract the line from the string it got from the fd
char	*ft_get_line(char *s_buffer)
{
	char	*buf_line;

	if (s_buffer[0] == '\0')
		return (NULL);
	buf_line = ft_strdup(s_buffer);
	return (buf_line);
}

// stores the rest from the static variable for the next call
char	*ft_next_call(char *s_buffer)
{
	char	*buf_next;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s_buffer[i] != '\n' && s_buffer[i] != '\0')
		i++;
	if (s_buffer[i] == '\0')
	{
		free(s_buffer);
		return (NULL);
	}
	buf_next = malloc(ft_strlen(s_buffer) + 1);
	if (buf_next == NULL)
		return (NULL);
	i++;
	while (s_buffer[i] != '\0')
		buf_next[j++] = s_buffer[i++];
	buf_next[j] = '\0';
	free(s_buffer);
	return (buf_next);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s_buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	s_buffer = ft_read(fd, s_buffer);
	if (s_buffer == NULL)
		return (NULL);
	line = ft_get_line(s_buffer);
	s_buffer = ft_next_call(s_buffer);
	return (line);
}
