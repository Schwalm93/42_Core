/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:20:10 by tguth             #+#    #+#             */
/*   Updated: 2021/05/26 10:20:10 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p_str1;
	const unsigned char	*p_str2;
	unsigned int		i;

	p_str1 = (const unsigned char *) s1;
	p_str2 = (const unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (*p_str1 != *p_str2)
			return (*p_str1 - *p_str2);
		p_str1++;
		p_str2++;
		i++;
	}
	return (0);
}
