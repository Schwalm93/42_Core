/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:20:03 by tguth             #+#    #+#             */
/*   Updated: 2021/05/26 10:20:03 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int			i;
	const unsigned char		*p_src;
	unsigned char			*p_dest;

	if (src == NULL)
		return (NULL);
	i = 0;
	p_dest = (unsigned char *) dest;
	p_src = (unsigned char *) src;
	while (i < n)
	{
		*p_dest = *p_src;
		if (*p_src == c)
		{
			p_dest++;
			return (p_dest);
		}
		p_src++;
		p_dest++;
		i++;
	}
	return (NULL);
}
