/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 08:18:13 by cschwalm          #+#    #+#             */
/*   Updated: 2022/01/11 09:49:34 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_uprintnbr(unsigned int n)
{
	unsigned int	value;
	int				store;

	store = 0;
	value = 0;
	if (n > 9)
		ft_uprintnbr(n / 10);
	value = n % 10 + 48;
	write(1, &value, 1);
	return (store);
}

int	ft_uputnbr(unsigned int n)
{
	unsigned int	temp;
	int				count;

	temp = n;
	count = 0;
	ft_uprintnbr(n);
	if (temp == 0)
	{
		count++;
		return (count);
	}
	while (temp > 0)
	{
		temp = temp / 10;
		count++;
	}
	return (count);
}
