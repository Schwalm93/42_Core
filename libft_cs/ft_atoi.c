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

int	ft_atoi(const char *str)
{
	int	v;

	v = 0;
	while (*str != 0)
	{
		if (*str < 48 || *str > 57)
		{
			return (0);
		}
		v = (v * 10) + (*str - 48);
		str++;
	}
	return (v);
}
