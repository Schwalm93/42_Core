/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:20:37 by tguth             #+#    #+#             */
/*   Updated: 2021/05/26 10:20:37 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	temp;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		temp = s[i];
		write(fd, &temp, 1);
		i++;
	}
}
