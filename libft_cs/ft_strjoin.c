/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:56:34 by cschwalm          #+#    #+#             */
/*   Updated: 2021/11/23 20:37:44 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	n;
	unsigned int	k;

	i = 0;
	n = ft_strlen(s1);
	k = ft_strlen(s2);
	str = malloc(sizeof(char [n + k]));
	if (str == NULL)
	{
		return (NULL);
	}
	while (i < n)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < (n + k))
	{
		str[i] = s2[i - n];
		i++;
	}
	str[i] = 0;
	return (str);
}
