/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 07:59:13 by cschwalm          #+#    #+#             */
/*   Updated: 2021/11/25 08:02:30 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while (s[i] != '\0')
	{
		temp = s[i];
		write(fd, &temp, 1);
		i++;
	}
	write(fd, "\n", 1);
}
