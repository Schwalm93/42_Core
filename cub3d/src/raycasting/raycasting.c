/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:55:53 by tguth             #+#    #+#             */
/*   Updated: 2022/07/07 03:48:03 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*Init the current ray */
void	init_ray(t_ray *ray, t_data *data, t_dda *dda)
{
	ray->pos_x = data->player->x;
	ray->pos_y = data->player->y;
	ray->dir_x = data->player->dirx;
	ray->dir_y = data->player->diry;
	ray->plane_x = data->player->planex;
	ray->plane_y = data->player->planey;
	ray->dda = dda;
	dda->x = -1;
	dda->count = 0;
	dda->hit = 0;
	dda->side = 0;
}

/*Init the current ray */
void	set_ray_value(t_ray *ray, float x)
{
	ray->camera_x = x;
	ray->raydir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->raydir_y = ray->dir_y + ray->plane_y * ray->camera_x;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	if (ray->raydir_x == 0)
		ray->step_len_x = 1e30;
	else
		ray->step_len_x = fabs(1 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->step_len_y = 1e30;
	else
		ray->step_len_y = fabs(1 / ray->raydir_y);
}

/* Performs DDA to determine raylength */
void	perform_dda(t_ray *ray, t_data *data, int *side, int *hit)
{
	while (*hit == 0)
	{
		if (ray->side_dis_x < ray->side_dis_y)
		{
			ray->side_dis_x += ray->step_len_x;
			ray->map_x += ray->step_x;
			if ((float)ray->map_x > (float)ray->pos_x)
				*side = 0;
			else
				*side = 1;
		}
		else
		{
			ray->side_dis_y += ray->step_len_y;
			ray->map_y += ray->step_y;
			if ((float)ray->map_y < (float)ray->pos_y)
				*side = 3;
			else
				*side = 2;
		}
		if (data->map_attr->map[ray->map_y][ray->map_x] == 1)
			*hit = 1;
	}
}

/* Casts the ray and calculates the distance to wall */
void	ray_cast(t_data *data)
{
	t_ray	ray;
	t_img	img;
	t_dda	dda;

	init_ray(&ray, data, &dda);
	img.mlx_img = mlx_new_image(data->mlx_attr->mlx, SCREENWIDTH, SCREENWIDTH);
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp,
			&img.line_len, &img.endian);
	while (dda.x <= 1)
	{
		dda.hit = 0;
		draw_floor_ceiling(&img, dda.count, data);
		set_ray_value(&ray, dda.x);
		calc_step_init_dist(&ray);
		perform_dda(&ray, data, &dda.side, &dda.hit);
		calc_perdis(&ray, dda.side);
		calc_draw_points(&ray);
		draw_hline_tex(&img, &ray, data, calc_tex_diff(data, &ray, dda.side));
		dda.x += 2.00 / (double)SCREENWIDTH;
		dda.count++;
	}
	mlx_put_image_to_window(data->mlx_attr->mlx,
		data->mlx_attr->mlx_win, img.mlx_img, 0, 0);
	mlx_destroy_image(data->mlx_attr->mlx, img.mlx_img);
}
