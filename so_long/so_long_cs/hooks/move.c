/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 05:00:10 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/05 06:25:30 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_print(t_program *pro, int keycode)
{
	if (keycode == 119)
	{
		pro->player_pos_x -= 32;
		pro->pl -= pro->check;
		pro->steps += 1;
	}
	if (keycode == 100)
	{
		pro->player_pos_y += 32;
		pro->pl++;
		pro->steps += 1;
	}
	if (keycode == 115)
	{
		pro->player_pos_x += 32;
		pro->pl += pro->check;
		pro->steps += 1;
	}
	if (keycode == 97)
	{
		pro->player_pos_y -= 32;
		pro->pl--;
		pro->steps += 1;
	}
}

void	print_empty(t_program *pro, int keycode)
{
	if (keycode == 119 && pro->gnl[pro->pl - pro->check] != '1')
		if (pro->gnl[pro->pl - pro->check] != 'E' || pro->finish == 1)
			mlx_put_image_to_window(pro->mlx, pro->win, pro->empty,
				pro->player_pos_y, pro->player_pos_x);
	if (keycode == 100 && pro->gnl[pro->pl + 1] != '1')
		if (pro->gnl[pro->pl + 1] != 'E' || pro->finish == 1)
			mlx_put_image_to_window(pro->mlx, pro->win, pro->empty,
				pro->player_pos_y, pro->player_pos_x);
	if (keycode == 115 && pro->gnl[pro->pl + pro->check] != '1')
		if (pro->gnl[pro->pl + pro->check] != 'E' || pro->finish == 1)
			mlx_put_image_to_window(pro->mlx, pro->win, pro->empty,
				pro->player_pos_y, pro->player_pos_x);
	if (keycode == 97 && pro->gnl[pro->pl - 1] != '1')
		if (pro->gnl[pro->pl - 1] != 'E' || pro->finish == 1)
			mlx_put_image_to_window(pro->mlx, pro->win, pro->empty,
				pro->player_pos_y, pro->player_pos_x);
}

void	move(t_program *pro, int keycode)
{
	print_empty(pro, keycode);
	if (keycode == 119 && pro->gnl[pro->pl - pro->check] != '1')
		if (pro->gnl[pro->pl - pro->check] != 'E' || pro->finish == 1)
			ft_print(pro, keycode);
	if (keycode == 100 && pro->gnl[pro->pl + 1] != '1')
		if (pro->gnl[pro->pl + 1] != 'E' || pro->finish == 1)
			ft_print(pro, keycode);
	if (keycode == 115 && pro->gnl[pro->pl + pro->check] != '1')
		if (pro->gnl[pro->pl + pro->check] != 'E' || pro->finish == 1)
			ft_print(pro, keycode);
	if (keycode == 97 && pro->gnl[pro->pl - 1] != '1')
		if (pro->gnl[pro->pl - 1] != 'E' || pro->finish == 1)
			ft_print(pro, keycode);
}
