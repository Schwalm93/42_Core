/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_helper_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:53:59 by tguth             #+#    #+#             */
/*   Updated: 2022/07/07 03:27:32 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	pressbutton_w(int keycode, t_data *data)
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
int	releasebutton_w(int keycode, t_data *data)
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
