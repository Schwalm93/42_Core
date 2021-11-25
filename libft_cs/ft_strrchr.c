/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:45:55 by cschwalm          #+#    #+#             */
/*   Updated: 2021/11/17 12:45:55 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	mark;
	char			*p_str;
	char			*p_result;

	mark = c;
	p_str = (char *) str;
	p_result = NULL;
	while (*p_str != 0)
	{
		if (*p_str == mark)
		{
			p_result = p_str;
		}
		p_str++;
	}
	return (p_result);
}
