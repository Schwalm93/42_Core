/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keshav <keshav@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 22:03:41 by keshav            #+#    #+#             */
/*   Updated: 2021/12/05 22:12:43 by keshav           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool	checklinebreak(char const *buffer)
{
	while (buffer && *buffer)
	{
		if (*buffer == '\n')
			return (true);
		buffer++;
	}
	return (false);
}

void	concatenate(char **remainder, char *buffer)
{
	size_t	i;
	size_t	total;
	char	*new;

	total = ft_strlen(*remainder) + ft_strlen(buffer);
	new = (char *)ft_calloc(total + 1, sizeof(char));
	i = 0;
	while (*remainder && *(*remainder + i) && new)
	{
		*(new + i) = *(*remainder + i);
		i++;
	}
	while (*buffer)
	{
		*(new + i) = *buffer;
		buffer++;
		i++;
	}
	free(*remainder);
	*remainder = new;
}

char	*get_line(char	**remainder)
{
	char	*line;
	char	*leftovers;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(*remainder + i) && *(*remainder + i) != '\n')
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	while (j < i)
	{
		*(line + j) = *(*remainder + j);
		j++;
	}
	*(line + j) = '\n';
	leftovers = ft_strdup(*remainder + j + 1);
	free(*remainder);
	*remainder = leftovers;
	return (line);
}

void	read_and_concatenate(int *bytes, int fd, char **remainder)
{
	char		*buffer;
	int			i;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return ;
	*bytes = read(fd, buffer, BUFFER_SIZE);
	if (*bytes == -1)
	{
		free(buffer);
		return ;
	}
	while (*bytes && !checklinebreak(buffer))
	{
		concatenate(&remainder[fd], buffer);
		i = 0;
		while (i <= BUFFER_SIZE)
		{
			buffer[i] = '\0';
			i++;
		}
		*bytes = read(fd, buffer, BUFFER_SIZE);
	}
	concatenate(&remainder[fd], buffer);
	free(buffer);
}

char	*get_next_line(int fd)
{
	static char	*remainder[OPEN_MAX_F];
	char		*result;
	int			bytes;

	if (fd < 0 || fd > OPEN_MAX_F || BUFFER_SIZE < 1)
		return (NULL);
	if (remainder[fd] && checklinebreak(remainder[fd]))
		return (get_line(&remainder[fd]));
	read_and_concatenate(&bytes, fd, remainder);
	result = NULL;
	if (bytes < 0)
		return (NULL);
	if (bytes)
		result = get_line(&remainder[fd]);
	else if (remainder[fd])
	{
		if (ft_strlen(remainder[fd]))
			result = ft_strdup(remainder[fd]);
		free(remainder[fd]);
		remainder[fd] = NULL;
	}
	return (result);
}
