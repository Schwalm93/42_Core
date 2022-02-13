/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:49:15 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/01 11:11:08 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str != 0)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char			*dest;
	unsigned int	i;
	unsigned int	len_s;

	i = 0;
	len_s = ft_strlen(s);
	dest = malloc((ft_strlen(s) + 1));
	if (dest == NULL)
		return (NULL);
	while (i < len_s && s[i] != '\n')
	{
		dest[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		dest[i] = '\n';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		len_1;
	int		len_2;

	len_1 = -1;
	len_2 = 0;
	if (s1 == NULL)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL || s1 == NULL)
		return (NULL);
	while (s1[++len_1] != '\0' && s1)
		s3[len_1] = s1[len_1];
	while (s2[len_2] != '\0' && s2)
		s3[len_1++] = s2[len_2++];
	s3[len_1] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s != 0 && *s != c)
	{
		s++;
	}
	if (*s == c)
	{
		return ((char *) s);
	}
	return (0);
}
