/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:57:19 by tguth             #+#    #+#             */
/*   Updated: 2022/07/07 03:27:59 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_img(t_data *data)
{
	data->mlx_attr->img_n->mlx_img = NULL;
	data->mlx_attr->img_s->mlx_img = NULL;
	data->mlx_attr->img_e->mlx_img = NULL;
	data->mlx_attr->img_w->mlx_img = NULL;
}

static void	init_pictures(t_data *data)
{
	init_pictures_n_s(data);
	init_pictures_w_e(data);
	check_pictures(data);
}

static void	run(t_data *data)
{
	t_img	img_n;
	t_img	img_s;
	t_img	img_w;
	t_img	img_e;

	data->mlx_attr->img_n = &img_n;
	data->mlx_attr->img_s = &img_s;
	data->mlx_attr->img_w = &img_w;
	data->mlx_attr->img_e = &img_e;
	init_img(data);
	data->mlx_attr->mlx_win = mlx_new_window(data->mlx_attr->mlx,
			SCREENWIDTH, SCREENWIDTH, "cub3D");
	init_pictures(data);
	keyhooks(data);
	ray_cast(data);
	mlx_loop(data->mlx_attr->mlx);
}

int	main(int args, char *argv[])
{
	t_data		data;
	t_mlx		mlx;
	t_map		map;
	t_player	player;

	check_input_argv(args, argv);
	init_struct(&data, &map, &mlx, &player);
	get_map(&data, argv[1]);
	init_player_view(&data);
	run(&data);
	return (0);
}
