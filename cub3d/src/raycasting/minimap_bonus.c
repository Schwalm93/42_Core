/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:55:38 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:55:41 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

/* Sets the player on minimap */
void	set_player(t_data *data, t_img *img)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = (int)(data->player->x * 6.0);
	y = (int)(data->player->y * 6.0);
	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			img_pix_put(img, (x - 3 + i), (y - 3 + j), 5289296);
			j++;
		}
		i++;
	}
}

/* Draws one field of the minimap */
void	draw_map_field(t_img *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			if (color == 1)
				img_pix_put(img, x * 6 + j, y * 6 + i, 16777215);
			else
				img_pix_put(img, x * 6 + j, y * 6 + i, 0);
			j++;
		}
		i++;
	}
}

/* Draws the minimap */
void	draw_minimap(t_data *data, t_img *img)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->map_attr->map_height)
	{
		j = 0;
		while (j < data->map_attr->map_width)
		{
			if (data->map_attr->map[i][j] == 0
				|| data->map_attr->map[i][j] == 78
				|| data->map_attr->map[i][j] == 79
				|| data->map_attr->map[i][j] == 83
				|| data->map_attr->map[i][j] == 87)
				draw_map_field(img, j, i, 1);
			else if (data->map_attr->map[i][j] == 1)
				draw_map_field(img, j, i, 0);
			j++;
		}
		i++;
	}
	set_player(data, img);
}
