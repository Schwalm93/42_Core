/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:55:03 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:55:05 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

/* Calculate draw-start and draw-end in y-direction */
void	calc_draw_points(t_ray *ray)
{
	int	lineheight;

	lineheight = (int)(SCREENWIDTH / ray->perp_wall_dist);
	ray->draw_start = -lineheight / 2 + SCREENWIDTH / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = lineheight / 2 + SCREENWIDTH / 2;
	if (ray->draw_end >= SCREENWIDTH)
		ray->draw_end = SCREENWIDTH - 1;
}

/* Calculate distance to pixel in x-direction */
int	calc_tex_diff(t_data *data, t_ray *ray, int side)
{
	float	diff;

	ray->end_x = ray->pos_x + ray->raydir_x * ray->perp_wall_dist;
	ray->end_y = ray->pos_y + ray->raydir_y * ray->perp_wall_dist;
	if (side == 0 || side == 1)
		diff = ((float)ray->map_y + 1) - ray->end_y;
	else
		diff = ((float)ray->map_x + 1) - ray->end_x;
	diff *= 100.0;
	if (side == 0)
		diff = (diff * data->mlx_attr->img_e->width) / 100;
	else if (side == 1)
		diff = (diff * data->mlx_attr->img_w->width) / 100;
	else if (side == 2)
		diff = (diff * data->mlx_attr->img_s->width) / 100;
	else
		diff = (diff * data->mlx_attr->img_n->width) / 100;
	return ((int)diff);
}

/* Calculate perpendicular distance */
void	calc_perdis(t_ray *ray, int side)
{
	if (side == 0 || side == 1)
		ray->perp_wall_dist = (ray->side_dis_x - ray->step_len_x);
	else
		ray->perp_wall_dist = (ray->side_dis_y - ray->step_len_y);
}

/* Calculates step direction and initail ray length */
void	calc_step_init_dist(t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dis_x = (ray->pos_x - ray->map_x) * ray->step_len_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dis_x = (ray->map_x + 1.0 - ray->pos_x) * ray->step_len_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dis_y = (ray->pos_y - ray->map_y) * ray->step_len_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dis_y = (ray->map_y + 1.0 - ray->pos_y) * ray->step_len_y;
	}
}
