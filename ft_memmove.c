/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwesche <nwesche@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:38:42 by nwesche           #+#    #+#             */
/*   Updated: 2021/05/20 10:38:42 by nwesche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*cdest;
	unsigned char		*csrc;

	i = 0;
	if (!src || !dest)
		return (NULL);
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	if (csrc < cdest)
	{
		while (n--)
		{
			cdest[n] = csrc[n];
		}
		return (dest);
	}
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
