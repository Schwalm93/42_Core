/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:20:26 by cschwalm          #+#    #+#             */
/*   Updated: 2021/11/19 15:20:26 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	if (*s2 == 0)
	{
		return ((char *) s1);
	}
	if (ft_strlen((char *) s2) <= (ft_strlen((char *) s1)))
	{
		while ((char ) s1[i] != 0 && i < n)
		{
			while ((char ) s1[i] == (char ) s2[j]
				&& j < ft_strlen((char *) s2) && i < n)
			{
				i++;
				j++;
			}
			if (j == (ft_strlen((char *) s2)))
				return ((char *) &s1[i - j]);
			i++;
		}
	}
	return (NULL);
}
