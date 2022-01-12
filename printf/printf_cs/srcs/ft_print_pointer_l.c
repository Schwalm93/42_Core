/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_l.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 05:18:45 by cschwalm          #+#    #+#             */
/*   Updated: 2022/01/11 09:48:32 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printnbr_hex_l(unsigned int n)
{
	int		value;
	long	store;

	store = 0;
	if (n > 15)
		ft_printnbr_hex_l(n / 16);
	value = n % 16;
	if (value == 10)
		value = 'a';
	else if (value == 11)
		value = 'b';
	else if (value == 12)
		value = 'c';
	else if (value == 13)
		value = 'd';
	else if (value == 14)
		value = 'e';
	else if (value == 15)
		value = 'f';
	else
		value += 48;
	write(1, &value, 1);
	return (store);
}

int	ft_print_pointer_l(unsigned int n)
{
	int				count;
	unsigned int	temp;

	temp = n;
	count = 0;
	if (n == 0)
	{
		ft_putstr("0");
		return (1);
	}
	ft_printnbr_hex_l(n);
	while (temp > 0)
	{
		temp = temp / 16;
		count++;
	}
	return (count);
}
