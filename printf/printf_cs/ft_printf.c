/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 04:07:59 by cschwalm          #+#    #+#             */
/*   Updated: 2022/01/12 02:56:15 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_variable(void *arg, const char format, int *total )
{
	if (format == 'd' || format == 'i')
		*total += ft_putnbr(*(int *) &arg);
	else if (format == 'u')
		*total += ft_uputnbr(*(unsigned int *) &arg);
	else if (format == 'c')
		*total += ft_putchar(*(char *) &arg);
	else if (format == 's')
		*total += ft_putstr((char *) arg);
	else if (format == 'p')
		*total += ft_print_pointer((unsigned long) arg);
	else if (format == 'x')
		*total += ft_print_pointer_l(*(unsigned int *) &arg);
	else if (format == 'X')
		*total += ft_print_pointer_u(*(unsigned int *) &arg);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		total;
	va_list	args;

	i = -1;
	total = 0;
	va_start(args, format);
	while (format[++i] != 0)
	{
		if (format[i] != '%')
			total += write(1, &format[i], 1);
		else if (format[i + 1] == '%')
			total += ft_print_percent(&i);
		else
		{
			ft_put_variable(va_arg(args, void *), format[i + 1], &total);
			i++;
		}
	}
	va_end(args);
	return (total);
}
