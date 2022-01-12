/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 08:18:13 by cschwalm          #+#    #+#             */
/*   Updated: 2022/01/11 09:49:17 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printnbr(int n)
{
	int	value;
	int	store;

	store = 0;
	value = 0;
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	if (n < 0 && n != -2147483648)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	if (n > 9)
		ft_printnbr(n / 10);
	if (n != -2147483648)
	{
		value = n % 10 + 48;
		write(1, &value, 1);
	}
	return (store);
}

int	ft_putnbr(int n)
{
	int	count;
	int	temp;

	temp = n;
	count = 0;
	ft_printnbr(n);
	if (n == -2147483648)
		return (count + 11);
	if (temp == 0)
	{
		count++;
		return (count);
	}
	else if (temp < 0)
	{
		temp = temp * -1;
		count++;
	}
	while (temp > 0)
	{
		temp = temp / 10;
		count++;
	}
	return (count);
}
