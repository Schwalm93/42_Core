/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   -ft_strtrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:44:26 by cschwalm          #+#    #+#             */
/*   Updated: 2021/11/23 20:36:22 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	l;
	i = 0;
	j = 0;
	k = ft_strlen(s1);
	l = ft_strlen(set);

	if (s1[0] == set[0])
	{
		i++;
	}
	if (s1[k - 1] == set[0])
	{
		k--;
	}
	j = k - i;
	k = 0;
	str = malloc(sizeof(char[j]));
	if (str == NULL)
	{
		return (NULL);
	}
	while (j > 0)
	{
		str[k] = s1[i];
		j--;
		i++;
		k++;
	}
	return (str);
}

int	main(void)
{
	char *p;

	p = ft_strtrim("TesTT", "T");

	printf("Der String ist: %s \n", p);

	return (0);
}