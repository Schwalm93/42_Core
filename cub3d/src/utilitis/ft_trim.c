/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:56:53 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:56:57 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

int	get_first_c(char *s)
{
	int	i;

	i = 0;
	while (is_white_space(s[i]))
	{
		i++;
		if (s[i] == '\0')
			return (-1);
	}
	return (i);
}

int	get_next_c(char *s, int index)
{
	while (is_white_space(s[index]))
	{
		index++;
		if (s[index] == '\0')
			return (-1);
	}
	return (index);
}
