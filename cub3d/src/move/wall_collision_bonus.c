/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:54:43 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:54:45 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static void	get_xy(t_data *data, float *x, float *y, int directing)
{
	if (directing == 1)
	{
		*y = data->player->y + STEP_SIZE * data->player->diry;
		*x = data->player->x + STEP_SIZE * data->player->dirx;
	}
	else if (directing == 2)
	{
		*y = data->player->y - STEP_SIZE * data->player->diry;
		*x = data->player->x - STEP_SIZE * data->player->dirx;
	}
	else if (directing == 3)
	{
		*x = data->player->x + STEP_SIZE * data->player->diry * -1;
		*y = data->player->y + STEP_SIZE * data->player->dirx;
	}
	else if (directing == 4)
	{
		*x = data->player->x + STEP_SIZE * data->player->diry;
		*y = data->player->y + STEP_SIZE * data->player->dirx * -1;
	}
}

int	check_hitbox(t_data *data, float x, float y)
{
	float	x_pos;
	float	y_pos;
	float	x_neg;
	float	y_neg;

	x_pos = x + HITBOX_SIDE;
	y_pos = y + HITBOX_SIDE;
	x_neg = x - HITBOX_SIDE;
	y_neg = y - HITBOX_SIDE;
	if (data->map_attr->map[(int) floor(y_pos)][(int)floor(x_pos)] == 1)
		return (-1);
	else if (data->map_attr->map[(int) floor(y_pos)][(int) floor(x_neg)] == 1)
		return (-1);
	else if (data->map_attr->map[(int) floor(y_neg)][(int) floor(x_pos)] == 1)
		return (-1);
	else if (data->map_attr->map[(int) floor(y_neg)][(int) floor(x_neg)] == 1)
		return (-1);
	return (1);
}

void	wall_collision(t_data *data, int directing)
{
	float	x;
	float	y;

	get_xy(data, &x, &y, directing);
	if (check_hitbox(data, x, y) == 1)
	{
		if (directing == 1)
			move_up(data);
		else if (directing == 2)
			move_down(data);
		else if (directing == 3)
			move_left(data);
		else if (directing == 4)
			move_right(data);
	}
}
