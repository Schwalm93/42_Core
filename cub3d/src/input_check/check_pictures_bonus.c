/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pictures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:53:01 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:53:04 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	check_pictures(t_data *data)
{
	if (data->mlx_attr->img_n->height != data->mlx_attr->img_n->width
		|| data->mlx_attr->img_s->height != data->mlx_attr->img_s->width
		|| data->mlx_attr->img_e->height != data->mlx_attr->img_e->width
		|| data->mlx_attr->img_w->height != data->mlx_attr->img_w->width)
		ft_exit(data, 1, "Error - the images are not square");
}
