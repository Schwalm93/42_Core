/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 07:54:05 by cschwalm          #+#    #+#             */
/*   Updated: 2022/01/21 01:49:09 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	len;
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	len = ft_strlen(s);
	while (i < len)
	{
		write (fd, &s[i], 1);
		i++;
	}
}
