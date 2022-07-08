/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:46:43 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:46:46 by tguth            ###   ########.fr       */
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
