/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:52:14 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:52:17 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	get_color_texture_helper(t_data *data, char *temp)
{
	if (temp[0] == 'N' && temp[1] == 'O' && data->map_attr->n_ok == 0)
		data->map_attr->n_ok = get_texture(data, temp, temp[0]);
	else if (temp[0] == 'S' && temp[1] == 'O' && data->map_attr->s_ok == 0)
		data->map_attr->s_ok = get_texture(data, temp, temp[0]);
	else if (temp[0] == 'W' && temp[1] == 'E' && data->map_attr->w_ok == 0)
		data->map_attr->w_ok = get_texture(data, temp, temp[0]);
	else if (temp[0] == 'E' && temp[1] == 'A' && data->map_attr->e_ok == 0)
		data->map_attr->e_ok = get_texture(data, temp, temp[0]);
	else if (temp[0] == 'F' || temp[0] == 'C')
	{
		if (get_color(data, temp, temp[0]) == -1)
			return (-1);
	}
	else
		return (-1);
	return (1);
}
