/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:45:08 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:45:13 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlengnl(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strchrgnl(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*(str + i))
	{
		if (*(str + i) == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoingnl(char *string1, char *string2)
{
	char	*str;
	int		i;
	int		j;

	if (!string1)
	{
		string1 = (char *)malloc(1 * sizeof(char));
		*(string1 + 0) = '\0';
	}
	if (!string1 || !string2)
		return (NULL);
	str = malloc(ft_strlengnl(string1) + ft_strlengnl(string2) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (string1)
		while (*(string1 + ++i))
			*(str + i) = *(string1 + i);
	while (*(string2 + j))
		*(str + i++) = *(string2 + j++);
	*(str + i) = '\0';
	free(string1);
	return (str);
}

char	*output(char *string1)
{
	int		i;
	char	*str;

	i = 0;
	if (!*(string1 + i))
		return (NULL);
	while (*(string1 + i) && *(string1 + i) != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (*(string1 + i) && *(string1 + i) != '\n')
	{
		*(str + i) = *(string1 + i);
		i++;
	}
	if (*(string1 + i) == '\n')
	{
		*(str + i) = *(string1 + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*new_string(char *string1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (*(string1 + i) && *(string1 + i) != '\n')
		i++;
	if (!*(string1 + i))
	{
		free(string1);
		return (NULL);
	}
	str = malloc((ft_strlengnl(string1) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (*(string1 + i))
		*(str + j++) = *(string1 + i++);
	*(str + j) = '\0';
	free(string1);
	return (str);
}
