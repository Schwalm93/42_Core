/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:52:18 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/02 06:48:52 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_int_len(t_data *data)
{
	int	i;
	int	count;

	count = 0;
	i = data->status_code;
	if (i == 0)
	{
		data->status_len = 1;
		return (1);
	}
	while (i > 0)
	{
		i = i / 10;
		count++;
	}
	data->status_len = count;
	return (count);
}

int	count_status(t_data *data, char *str)
{
	int	i;
	int	count;
	int	len;
	int	minus_count;

	i = 0;
	count = 0;
	minus_count = 0;
	len = ft_strlen(str);
	while (str && i < (len - 1))
	{
		if (str[i] == '$' && str[i + 1] == '?')
		{
			count += get_int_len(data);
			minus_count++;
		}
		i++;
	}
	return (count - minus_count);
}
