/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:59:35 by cschwalm          #+#    #+#             */
/*   Updated: 2021/11/17 19:59:35 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	mark;
	char			*p_str;
	char			*p_result;

	mark = c;
	p_str = (char *) str;
	p_result = NULL;
	while (*p_str != 0 && n != 0)
	{
		if (*p_str == mark)
		{
			p_result = p_str;
			return (p_result);
		}
		p_str++;
		n--;
	}
	return (p_result);
}
