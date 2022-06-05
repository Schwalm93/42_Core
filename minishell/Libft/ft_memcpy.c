/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:20:14 by tguth             #+#    #+#             */
/*   Updated: 2021/05/26 10:20:14 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	if (src == NULL && dest == NULL)
		return (NULL);
	i = 0;
	p_dest = (unsigned char *) dest;
	p_src = (unsigned char *) src;
	while (i < n)
	{
		*p_dest = *p_src;
		p_dest++;
		p_src++;
		i++;
	}
	return (dest);
}
