/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 08:18:13 by cschwalm          #+#    #+#             */
/*   Updated: 2021/11/25 08:24:27 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	value;

	value = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n >= 9)
		ft_putnbr_fd(n / 10, fd);
	value = n % 10 + 48;
	write(fd, &value, 1);
}
