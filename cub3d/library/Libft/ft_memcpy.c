/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:47:59 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:47:59 by tguth            ###   ########.fr       */
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
