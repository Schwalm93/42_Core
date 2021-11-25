/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:33:46 by cschwalm          #+#    #+#             */
/*   Updated: 2021/11/17 20:33:46 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	i = 0;
	p_dest = dest;
	p_src = src;
	while (i < n)
	{
		*p_dest = *p_src;
		p_dest++;
		p_src++;
		i++;
	}
	return (dest);
}
