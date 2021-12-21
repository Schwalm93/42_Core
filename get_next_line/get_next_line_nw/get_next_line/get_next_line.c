/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwesche <nwesche@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:04:59 by nwesche           #+#    #+#             */
/*   Updated: 2021/12/21 18:06:44 by nwesche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buf[4096];
	char			*line;
	size_t			old_len;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (gnl_strchr_i(buf[fd], '\n') == -1)
	{
		old_len = gnl_strlen(buf[fd]);
		buf[fd] = gnl_expand_buffer(buf[fd], fd);
		if (old_len == gnl_strlen(buf[fd]) && buf[fd])
			line = gnl_substr(buf[fd], 0, gnl_strlen(buf[fd]));
	}
	if (!buf[fd])
		return (NULL);
	if (!line && gnl_strchr_i(buf[fd], '\n') != -1)
		line = gnl_substr(buf[fd], 0, gnl_strchr_i(buf[fd], '\n') + 1);
	if (line)
	{
		buf[fd] = gnl_shrink_buffer(buf[fd], line);
		return (line);
	}
	return (get_next_line(fd));
}

char	*gnl_shrink_buffer(char *buf, char *line)
{
	char	*newbuf;
	int		line_len;

	if (!buf || !line)
		return (buf);
	line_len = gnl_strlen(line);
	if ((int)gnl_strlen(buf) == line_len)
	{
		free(buf);
		return (NULL);
	}
	newbuf = gnl_substr(buf, line_len, gnl_strlen(buf) - line_len);
	free(buf);
	return (newbuf);
} 

char	*gnl_expand_buffer(char *buf, int fd)
{
	char	*newbuf;
	int		newlen;
	char	*alpha;

	alpha = gnl_newread(fd);
	if (!alpha)
		return (NULL);
	if (!alpha[0])
	{
		free(alpha);
		return (buf);
	}
	if (!buf)
		return (alpha);
	newlen = gnl_strlen(buf) + gnl_strlen(alpha);
	newbuf = malloc(newlen + 1);
	if (!newbuf)
		return (NULL);
	gnl_strlcpy(newbuf, buf, newlen + 1);
	gnl_strlcat(newbuf, alpha, newlen + 1);
	free(buf);
	free(alpha);
	return (newbuf);
}

char	*gnl_newread(int fd)
{
	char	*alpha;
	int		nbytes;

	alpha = malloc(BUFFER_SIZE + 1);
	if (!alpha)
		return (NULL);
	nbytes = read(fd, alpha, BUFFER_SIZE);
	if (nbytes < 0)
	{
		free(alpha);
		return (NULL);
	}
	alpha[nbytes] = '\0';
	return (alpha);
}
