/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:39:58 by cschwalm          #+#    #+#             */
/*   Updated: 2021/11/19 18:39:58 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(const char *nptr)
{
	long	nbr;
	int		isnegative;

	nbr = 0;
	isnegative = 1;
	while (nptr[0] == ' ' || nptr[0] == '\t' || nptr[0] == '\f'
		|| nptr[0] == '\v' || nptr[0] == '\r' || nptr[0] == '\n')
				nptr++;
	if (nptr[0] == '-')
	{
		isnegative = -1;
		nptr++;
	}
	else if (nptr[0] == '+')
		nptr++;
	while (nptr[0] >= '0' && nptr[0] <= '9')
	{
		nbr = (nbr * 10) + nptr[0] - 48;
		nptr++;
	}
	nbr = nbr * isnegative;
	return ((int)nbr);
}
