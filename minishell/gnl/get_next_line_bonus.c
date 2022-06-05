/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:15:08 by tguth             #+#    #+#             */
/*   Updated: 2022/04/24 10:45:27 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*ft_get_line(char *overflow);
static	char	*ft_overflow(char *overflow);
static	char	*ft_read_and_overflow(int fd, char *overflow);
static	void	ft_supp_overflow(char *overflow, int i, char **s);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*overflow;

	if (fd < 0 || 10 <= 0)
		return (0);
	overflow = ft_read_and_overflow(fd, overflow);
	if (!overflow)
		return (NULL);
	line = ft_get_line(overflow);
	overflow = ft_overflow(overflow);
	return (line);
}

static	char	*ft_get_line(char *overflow)
{
	int		i;
	char	*s;

	i = 0;
	if (!overflow[i])
		return (NULL);
	while (overflow[i] && overflow[i] != '\n')
		i++;
	s = malloc((i + 2) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (overflow[i] && overflow[i] != '\n')
	{
		s[i] = overflow[i];
		i++;
	}
	if (overflow[i] == '\n')
	{
		s[i] = overflow[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static	char	*ft_overflow(char *overflow)
{
	int		i;
	char	*s;

	i = 0;
	while (overflow[i] && overflow[i] != '\n')
		i++;
	if (!overflow[i])
	{
		free(overflow);
		return (NULL);
	}
	s = malloc((ft_strlen(overflow) - i + 1) * sizeof(char *));
	if (!s)
		return (NULL);
	i++;
	ft_supp_overflow(overflow, i, &s);
	return (s);
}

static	void	ft_supp_overflow(char *overflow, int i, char **s)
{
	int		c;

	c = 0;
	while (overflow[i])
	{
		s[0][c] = overflow[i];
		c++;
		i++;
	}
	s[0][c] = '\0';
	free(overflow);
}

char	*ft_read_and_overflow(int fd, char *overflow)
{
	char	*buff;
	int		i;

	buff = malloc((10 + 1) * sizeof(char *));
	if (!buff)
		return (NULL);
	i = 1;
	while (!ft_strchr(overflow, '\n') && i != 0)
	{
		i = read(fd, buff, 10);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		overflow = ft_strjoin_gnl(overflow, buff);
	}
	free(buff);
	return (overflow);
}
