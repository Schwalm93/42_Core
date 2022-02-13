/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 08:07:05 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/05 07:12:08 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	img_check_init(t_program *program)
{
	if (!program->wall)
	{
		ft_putstr_fd("Error - wall image cannot be loaded\n", 1);
		ft_error_image(program);
	}
	if (!program->player)
	{
		ft_putstr_fd("Error - player image cannot be loaded\n", 1);
		ft_error_image(program);
	}
	if (!program->empty)
	{
		ft_putstr_fd("Error - empty image cannot be loaded\n", 1);
		ft_error_image(program);
	}
	if (!program->exit)
	{
		ft_putstr_fd("Error - exit image cannot be loaded\n", 1);
		ft_error_image(program);
	}
	if (!program->coin)
	{
		ft_putstr_fd("Error - coin image cannot be loaded\n", 1);
		ft_error_image(program);
	}
}

void	img_init(t_program *program, t_map *map)
{
	program->wall = mlx_xpm_file_to_image(program->mlx,
			"./images/wall.xpm", &map->wall_l, &map->wall_h);
	program->player = mlx_xpm_file_to_image(program->mlx,
			"./images/player.xpm", &map->player_l, &map->player_h);
	program->empty = mlx_xpm_file_to_image(program->mlx,
			"./images/empty.xpm", &map->empty_l, &map->empty_h);
	program->exit = mlx_xpm_file_to_image(program->mlx,
			"./images/exit.xpm", &map->exit_l, &map->exit_h);
	program->coin = mlx_xpm_file_to_image(program->mlx,
			"./images/coin.xpm", &map->coin_l, &map->coin_h);
	img_check_init(program);
}
