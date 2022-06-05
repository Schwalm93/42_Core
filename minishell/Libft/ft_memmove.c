/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:20:17 by tguth             #+#    #+#             */
/*   Updated: 2021/05/26 10:20:17 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove( void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*p_src;
	char		*p_dest;

	i = 0;
	if (src == NULL || dest == NULL)
		return (NULL);
	p_dest = (char *) dest;
	p_src = (char *) src;
	if (p_src < p_dest)
	{
		while (n > 0)
		{
			n--;
			p_dest[n] = p_src[n];
		}
		return (dest);
	}
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}
