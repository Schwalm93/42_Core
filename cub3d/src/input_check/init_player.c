/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:53:22 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:53:26 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_player_plane(t_data *data)
{
	if (data->map_attr->player_dir == 78
		|| data->map_attr->player_dir == 83)
	{
		data->player->planex = 0.66;
		data->player->planey = 0;
	}
	else
	{
		data->player->planex = 0;
		data->player->planey = 0.66;
	}
}

void	init_player_view(t_data *data)
{
	if (data->map_attr->player_dir == 78)
	{
		data->player->dirx = 0;
		data->player->diry = -1;
	}
	else if (data->map_attr->player_dir == 83)
	{
		data->player->dirx = 0;
		data->player->diry = 1;
	}
	else if (data->map_attr->player_dir == 87)
	{
		data->player->dirx = -1;
		data->player->diry = 0;
	}
	else
	{
		data->player->dirx = 1;
		data->player->diry = 0;
	}
	init_player_plane(data);
}
