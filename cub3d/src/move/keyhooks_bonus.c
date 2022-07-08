/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:53:47 by tguth             #+#    #+#             */
/*   Updated: 2022/07/07 03:27:05 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

/* manages the close window button */
int	ft_close(t_data *data)
{
	ft_exit(data, 0, NULL);
	return (0);
}

/* manages the pressed keys by their key code */
int	pressbutton_s(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		ft_close(data);
	if (keycode == W_KEY)
		data->player->move_up = 1;
	if (keycode == D_KEY)
		data->player->move_right = 1;
	if (keycode == S_KEY)
		data->player->move_down = 1;
	if (keycode == A_KEY)
		data->player->move_left = 1;
	if (keycode == ARROW_L_KEY)
		data->player->look_left = 1;
	if (keycode == ARROW_R_KEY)
		data->player->look_right = 1;
	return (0);
}

/* manages the released keys by their key code */
int	releasebutton_s(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->player->move_up = 0;
	if (keycode == D_KEY)
		data->player->move_right = 0;
	if (keycode == S_KEY)
		data->player->move_down = 0;
	if (keycode == A_KEY)
		data->player->move_left = 0;
	if (keycode == ARROW_L_KEY)
		data->player->look_left = 0;
	if (keycode == ARROW_R_KEY)
		data->player->look_right = 0;
	return (0);
}

/* main loop, checks for Player movement */
int	main_loop(t_data *data)
{
	if (data->player->move_up == 1 && data->player->move_down != 1)
		wall_collision(data, 1);
	if (data->player->move_down == 1 && data->player->move_up != 1)
		wall_collision(data, 2);
	if (data->player->move_left == 1 && data->player->move_right != 1)
		wall_collision(data, 3);
	if (data->player->move_right == 1 && data->player->move_left != 1)
		wall_collision(data, 4);
	if (data->player->look_left == 1)
		look_right_left(data, 1);
	if (data->player->look_right == 1)
		look_right_left(data, 0);
	ray_cast(data);
	return (0);
}

/* initialize mlx hooks */
void	keyhooks(t_data *data)
{
	mlx_hook(data->mlx_attr->mlx_win, 17, 0, ft_close, data);
	if (data->map_attr->player_dir == 69)
	{
		mlx_hook(data->mlx_attr->mlx_win, 2, 1L << 0, pressbutton_e, data);
		mlx_hook(data->mlx_attr->mlx_win, 3, 1L << 1, releasebutton_e, data);
	}
	else if (data->map_attr->player_dir == 78)
	{
		mlx_hook(data->mlx_attr->mlx_win, 2, 1L << 0, pressbutton_n, data);
		mlx_hook(data->mlx_attr->mlx_win, 3, 1L << 1, releasebutton_n, data);
	}
	else if (data->map_attr->player_dir == 87)
	{
		mlx_hook(data->mlx_attr->mlx_win, 2, 1L << 0, pressbutton_w, data);
		mlx_hook(data->mlx_attr->mlx_win, 3, 1L << 1, releasebutton_w, data);
	}
	else
	{
		mlx_hook(data->mlx_attr->mlx_win, 2, 1L << 0, pressbutton_s, data);
		mlx_hook(data->mlx_attr->mlx_win, 3, 1L << 1, releasebutton_s, data);
	}
	mlx_loop_hook(data->mlx_attr->mlx, main_loop, data);
}
