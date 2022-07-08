/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:47:53 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:47:53 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*p_str1;
	unsigned char	*p_str2;
	unsigned int	i;

	i = 0;
	p_str1 = (unsigned char *) str1;
	p_str2 = (unsigned char *) str2;
	while (i < n)
	{
		if (*p_str1 != *p_str2)
		{
			return (*p_str1 - *p_str2);
		}
		p_str1++;
		p_str2++;
		i++;
	}
	return (0);
}
