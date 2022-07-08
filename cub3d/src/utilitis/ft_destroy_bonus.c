/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:56:03 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:56:05 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	ft_desetroy_north_south(t_data *data)
{
	if (data->mlx_attr->img_n)
	{
		if (data->mlx_attr->img_n->mlx_img != NULL)
		{
			mlx_destroy_image(data->mlx_attr->mlx,
				data->mlx_attr->img_n->mlx_img);
			data->mlx_attr->img_n->mlx_img = NULL;
		}
	}
	if (data->mlx_attr->img_s)
	{
		if (data->mlx_attr->img_s->mlx_img != NULL)
		{
			mlx_destroy_image(data->mlx_attr->mlx,
				data->mlx_attr->img_s->mlx_img);
			data->mlx_attr->img_s->mlx_img = NULL;
		}
	}
}

void	ft_desetroy_west_east(t_data *data)
{
	if (data->mlx_attr->img_w)
	{
		if (data->mlx_attr->img_w->mlx_img != NULL)
		{
			mlx_destroy_image(data->mlx_attr->mlx,
				data->mlx_attr->img_w->mlx_img);
			data->mlx_attr->img_w->mlx_img = NULL;
		}
	}
	if (data->mlx_attr->img_e)
	{
		if (data->mlx_attr->img_e->mlx_img != NULL)
		{
			mlx_destroy_image(data->mlx_attr->mlx,
				data->mlx_attr->img_e->mlx_img);
			data->mlx_attr->img_e->mlx_img = NULL;
		}
	}
}
