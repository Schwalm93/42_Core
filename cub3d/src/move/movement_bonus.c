/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:54:20 by tguth             #+#    #+#             */
/*   Updated: 2022/07/07 03:27:21 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	move_up(t_data *data)
{
	data->player->y += (STEP_SIZE * data->player->diry);
	data->player->x += (STEP_SIZE * data->player->dirx);
}

void	move_down(t_data *data)
{
	data->player->y -= (STEP_SIZE * data->player->diry);
	data->player->x -= (STEP_SIZE * data->player->dirx);
}

void	move_left(t_data *data)
{
	data->player->x += (STEP_SIZE * ((data->player->diry) * (-1)));
	data->player->y += (STEP_SIZE * (data->player->dirx));
}

void	move_right(t_data *data)
{
	data->player->x += (STEP_SIZE * ((data->player->diry)));
	data->player->y += (STEP_SIZE * (data->player->dirx) * (-1));
}

void	look_right_left(t_data *data, int left)
{
	if (left == 0)
		left_vision(data);
	else
		right_vision(data);
}
