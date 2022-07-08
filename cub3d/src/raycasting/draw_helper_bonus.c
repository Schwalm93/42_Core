/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:55:20 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:55:23 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

int	calc_diff_y(t_data *data, t_draw *draw, t_img *img, int side)
{
	int	width;
	int	diff_y;

	if (side == 0)
		width = data->mlx_attr->img_e->width;
	else if (side == 1)
		width = data->mlx_attr->img_w->width;
	else if (side == 2)
		width = data->mlx_attr->img_s->width;
	else
		width = data->mlx_attr->img_n->width;
	diff_y = ((draw->count * (width
					* img->perp_dis)) / draw->delta_y_i)
		+ ((width - (width
					* img->perp_dis)) / 2);
	return (diff_y);
}

void	img_pix_put_tt(t_img *img, t_data *data, t_draw *draw, int side)
{
	char	*pixel;
	char	*pixel_t;
	int		diff_y;
	int		i;

	i = -1;
	pixel = img->addr + ((int)draw->pixel_y * img->line_len
			+ draw->dda_count * (img->bpp / 8));
	diff_y = calc_diff_y(data, draw, img, side);
	pixel_t = get_pixel_tex(data, draw, diff_y, side);
	while (++i < img->bpp / 8)
		pixel[i] = pixel_t[i];
}

int	rgb_to_i(t_data *data, int floor)
{
	int	color;

	if (floor)
		color = 65536 * data->map_attr->rgb_floor[0]
			+ 256 * data->map_attr->rgb_floor[1]
			+ data->map_attr->rgb_floor[2];
	else
		color = 65536 * data->map_attr->rgb_ceiling[0]
			+ 256 * data->map_attr->rgb_ceiling[1]
			+ data->map_attr->rgb_ceiling[2];
	return (color);
}
