/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:45:33 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:45:33 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
