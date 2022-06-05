/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:12:55 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/02 06:51:55 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int	get_next_space(char *s, int start_index)
{
	while (s[start_index] != '\0' && is_white_space(s[start_index]) == 0)
	{
		start_index++;
		if (s[start_index] == '\0')
			return (start_index);
	}
	return (start_index);
}

int	get_last_c(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (is_white_space(s[i]))
		i--;
	return (i);
}

int	trim_strlen(char *s)
{
	int	i;

	i = (get_last_c(s) - get_first_c(s));
	return (i + 1);
}
