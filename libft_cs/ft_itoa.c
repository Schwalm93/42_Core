/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:04:30 by cschwalm          #+#    #+#             */
/*   Updated: 2021/12/01 18:13:39 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int in)
{
	int	size;

	size = 0;
	if (in <= 0)
		size ++;
	while (in != 0)
	{
		in = in / 10;
		size ++;
	}
	return (size);
}

char	*ft_itoa(int in)
{
	char		*sol;
	int			len;
	int long	n;

	n = in;
	len = ft_count(in);
	sol = ft_calloc(len + 1, 1);
	if (!sol)
		return (NULL);
	if (n < 0)
	{
		sol[0] = '-';
		n = n * -1;
	}
	while (n >= 10)
	{
		len--;
		sol[len] = (n % 10) + 48;
		n = n / 10;
	}
	sol[len - 1] = (n % 10) + 48;
	return (sol);
}
