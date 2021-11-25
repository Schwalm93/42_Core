/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:04:30 by cschwalm          #+#    #+#             */
/*   Updated: 2021/11/25 12:53:21 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(int n)
{
	int	length;

	length = 0;
	if (n < 0)
	{
		n = n * -1;
	}
	while (n > 0)
	{
		if (n < 10)
		{
			n = 0;
		}
		n = n / 10;
		length++;
	}
	return (length);
}

static void	ft_convert(char *p, int i, int len, int n)
{
	while (len >= 0)
	{
		p[len + i] = (n % 10 + 48);
		n = n / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*p;
	int		length;
	int		i;

	i = 0;
	length = ft_length(n);
	if (n < 0)
		i++;
	p = malloc(sizeof(char [length + (i + 1)]));
	if (n < 0)
	{
		p[0] = '-';
		n = n * -1;
	}
	if (n == 0)
	{
		p[0] = 48;
		return (p);
	}
	p[length] = 0;
	length = length - 1;
	ft_convert(p, i, length, n);
	return (p);
}
