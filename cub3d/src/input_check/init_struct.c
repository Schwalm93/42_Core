/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:53:37 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:53:42 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/* Initialize all mlx_attr to NULL + Init mlx */
void	init_mlx_struct(t_data *data)
{
	data->mlx_attr->mlx = mlx_init();
	data->mlx_attr->mlx_win = NULL;
	data->mlx_attr->img_n = NULL;
	data->mlx_attr->img_s = NULL;
	data->mlx_attr->img_e = NULL;
	data->mlx_attr->img_w = NULL;
}

/* Initialize the player struct to initial value */
void	init_player_struct(t_data *data)
{
	data->player->x = 0;
	data->player->y = 0;
	data->player->move_up = 0;
	data->player->move_down = 0;
	data->player->move_left = 0;
	data->player->move_right = 0;
	data->player->look_left = 0;
	data->player->look_right = 0;
}

/* Initialize all struct values to zero */
void	init_struct(t_data *data, t_map *map, t_mlx *mlx, t_player *player)
{
	data->mlx_attr = mlx;
	data->map_attr = map;
	data->map_attr->map_char = NULL;
	data->player = player;
	data->map_attr->map = NULL;
	data->map_attr->n_texture = NULL;
	data->map_attr->s_texture = NULL;
	data->map_attr->w_texture = NULL;
	data->map_attr->e_texture = NULL;
	data->map_attr->n_ok = 0;
	data->map_attr->s_ok = 0;
	data->map_attr->w_ok = 0;
	data->map_attr->e_ok = 0;
	data->map_attr->counter = 0;
	data->map_attr->count_j = 0;
	data->map_attr->count_str = 0;
	data->map_attr->map_width = 0;
	data->map_attr->map_height = 0;
	data->map_attr->player_dir = 0;
	ft_memset(data->map_attr->rgb_floor, 0, 3);
	ft_memset(data->map_attr->rgb_ceiling, 0, 3);
	init_mlx_struct(data);
	init_player_struct(data);
}

void	init_pictures_w_e(t_data *data)
{
	t_mlx	*tmp;

	tmp = data->mlx_attr;
	tmp->img_e->path = data->map_attr->e_texture;
	tmp->img_w->path = data->map_attr->w_texture;
	tmp->img_e->mlx_img = mlx_xpm_file_to_image(tmp->mlx,
			data->map_attr->e_texture, &(tmp->img_e->width),
			&(tmp->img_e->height));
	tmp->img_w->mlx_img = mlx_xpm_file_to_image(tmp->mlx,
			data->map_attr->w_texture, &(tmp->img_w->width),
			&(tmp->img_w->height));
	if (tmp->img_e->mlx_img == NULL || tmp->img_w->mlx_img == NULL)
		ft_exit(data, 1, "Error - can not load all pictures (west, east)");
	tmp->img_e->addr = mlx_get_data_addr(tmp->img_e->mlx_img,
			&tmp->img_e->bpp, &tmp->img_e->line_len, &tmp->img_e->endian);
	tmp->img_w->addr = mlx_get_data_addr(tmp->img_w->mlx_img,
			&tmp->img_w->bpp, &tmp->img_w->line_len, &tmp->img_w->endian);
	if (tmp->img_e->addr == NULL || tmp->img_w->addr == NULL)
		ft_exit(data, 1,
			"Error - can not get all addresses from the pictures (west, east)");
}

void	init_pictures_n_s(t_data *data)
{
	t_mlx	*tmp;

	tmp = data->mlx_attr;
	tmp->img_n->path = data->map_attr->n_texture;
	tmp->img_s->path = data->map_attr->s_texture;
	tmp->img_n->mlx_img = mlx_xpm_file_to_image(tmp->mlx,
			data->map_attr->n_texture, &(tmp->img_n->width),
			&(tmp->img_n->height));
	tmp->img_s->mlx_img = mlx_xpm_file_to_image(tmp->mlx,
			data->map_attr->s_texture, &(tmp->img_s->width),
			&(tmp->img_s->height));
	if (tmp->img_n->mlx_img == NULL || tmp->img_s->mlx_img == NULL)
		ft_exit(data, 1, "Error - can't load all pictures (north, south)");
	tmp->img_n->addr = mlx_get_data_addr(tmp->img_n->mlx_img,
			&tmp->img_n->bpp, &tmp->img_n->line_len,
			&tmp->img_n->endian);
	tmp->img_s->addr = mlx_get_data_addr(tmp->img_s->mlx_img,
			&tmp->img_s->bpp, &tmp->img_s->line_len,
			&tmp->img_s->endian);
	if (tmp->img_n->addr == NULL || tmp->img_s->addr == NULL)
		ft_exit(data, 1,
			"Error - can't get all addresses from the pictures (north, south)");
}
