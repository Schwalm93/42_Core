/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:58:33 by cschwalm          #+#    #+#             */
/*   Updated: 2021/11/23 20:36:08 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	unsigned int	i;
	int				counter;

	counter = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			counter++;
		}
		i++;
	}
	return (counter + 1);
}

char	**ft_split(char const *s, char c)
{
	char			**p;
	unsigned int	i;
	unsigned int	row;
	unsigned int	n;
	unsigned int	counter;

	n = 0;
	row = 0;
	counter = 0;
	i = 0;
	p = malloc(sizeof(char *[ft_count_words(s, c)]));
	if (p == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		if (s[i] == c || s[i + 1] == 0)
		{
			if (s[i + 1] == 0)
				i++;
			p[row] = malloc(sizeof(char [counter]));
			counter = 0;
			while (n < i)
			{
				p[row][counter] = s[n];
				n++;
				counter++;
			}
			n++;
			row++;
			counter = 0;
		}
		i++;
		counter++;
	}
	return (p);
}
