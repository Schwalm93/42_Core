/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 07:54:05 by cschwalm          #+#    #+#             */
/*   Updated: 2022/01/11 09:49:23 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strlen(s);
	while (i < len)
	{
		write (1, &s[i], 1);
		i++;
	}
	return (len);
}
