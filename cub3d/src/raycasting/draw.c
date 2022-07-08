/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:55:33 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:55:35 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*get_pixel_tex(t_data *data, t_draw *draw, int diff_y, int side)
{
	char	*pixel_t;

	if (side == 0)
		pixel_t = data->mlx_attr->img_e->addr + (diff_y
				* data->mlx_attr->img_e->line_len + draw->diff
				* (data->mlx_attr->img_e->bpp / 8));
	else if (side == 1)
		pixel_t = data->mlx_attr->img_w->addr + (diff_y
				* data->mlx_attr->img_w->line_len + draw->diff
				* (data->mlx_attr->img_w->bpp / 8));
	else if (side == 2)
		pixel_t = data->mlx_attr->img_s->addr + (diff_y
				* data->mlx_attr->img_s->line_len + draw->diff
				* (data->mlx_attr->img_s->bpp / 8));
	else
		pixel_t = data->mlx_attr->img_n->addr + (diff_y
				* data->mlx_attr->img_n->line_len + draw->diff
				* (data->mlx_attr->img_n->bpp / 8));
	return (pixel_t);
}

/* Draws the vertical line with the texture */
void	draw_hline_tex(t_img *img, t_ray *ray, t_data *data, int diff)
{
	t_draw	draw;

	draw.count = 0;
	draw.dda_count = ray->dda->count;
	draw.diff = diff;
	img->perp_dis = ray->perp_wall_dist;
	draw.delta_x = 0;
	draw.delta_y = ray->draw_end - ray->draw_start;
	draw.delta_y_i = (int)draw.delta_y;
	draw.pixels = sqrt((draw.delta_x * draw.delta_x)
			+ (draw.delta_y * draw.delta_y));
	draw.delta_x /= draw.pixels;
	draw.delta_y /= draw.pixels;
	draw.pixel_y = ray->draw_start;
	while (draw.pixels)
	{
		if (ray->perp_wall_dist < 1)
			img_pix_put_tt(img, data, &draw, ray->dda->side);
		else
			img_pix_put_t(img, data, &draw, ray->dda->side);
		ray->dda->count += draw.delta_x;
		draw.pixel_y += draw.delta_y;
		--draw.pixels;
		draw.count++;
	}
}

/* Draws the ceiling and floor in first person vision */
void	draw_floor_ceiling(t_img *img, int x, t_data *data)
{
	t_draw	draw;

	draw.delta_x = 0;
	draw.delta_y = (double)SCREENWIDTH;
	draw.pixels = sqrt((draw.delta_x * draw.delta_x)
			+ (draw.delta_y * draw.delta_y));
	draw.delta_x /= draw.pixels;
	draw.delta_y /= draw.pixels;
	draw.pixel_x = x;
	draw.pixel_y = 0;
	while (draw.pixels)
	{
		if (draw.pixel_y < 768.0 / 2.0)
			img_pix_put(img, draw.pixel_x, draw.pixel_y, rgb_to_i(data, 0));
		else
			img_pix_put(img, draw.pixel_x, draw.pixel_y, rgb_to_i(data, 1));
		draw.pixel_x += draw.delta_x;
		draw.pixel_y += draw.delta_y;
		--draw.pixels;
	}
}

/* Put a pixel with color on x,y position */
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

/* Put a pixel with texture on x,y position */
void	img_pix_put_t(t_img *img, t_data *data, t_draw *draw, int side)
{
	char	*pixel;
	char	*pixel_t;
	int		diff_y;
	int		i;

	i = -1;
	pixel = img->addr + ((int)draw->pixel_y * img->line_len
			+ draw->dda_count * (img->bpp / 8));
	if (side == 0)
		diff_y = (draw->count * data->mlx_attr->img_e->width) / draw->delta_y_i;
	else if (side == 1)
		diff_y = (draw->count * data->mlx_attr->img_w->width) / draw->delta_y_i;
	else if (side == 2)
		diff_y = (draw->count * data->mlx_attr->img_s->width) / draw->delta_y_i;
	else
		diff_y = (draw->count * data->mlx_attr->img_n->width) / draw->delta_y_i;
	pixel_t = get_pixel_tex(data, draw, diff_y, side);
	while (++i < img->bpp / 8)
		pixel[i] = pixel_t[i];
}
