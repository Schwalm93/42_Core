/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwesche <nwesche@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:38:37 by nwesche           #+#    #+#             */
/*   Updated: 2021/05/20 10:38:37 by nwesche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*abc;
	size_t	i;

	i = 0;
	abc = (char *)s;
	while (i < n)
	{
		if ((unsigned char)abc[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
