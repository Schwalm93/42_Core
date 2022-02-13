/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:10:45 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/04 05:24:33 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_exit(t_program *pro)
{
	mlx_destroy_image(pro->mlx, pro->player);
	mlx_destroy_image(pro->mlx, pro->coin);
	mlx_destroy_image(pro->mlx, pro->exit);
	mlx_destroy_image(pro->mlx, pro->wall);
	mlx_destroy_image(pro->mlx, pro->empty);
	mlx_destroy_window(pro->mlx, pro->win);
	mlx_destroy_display(pro->mlx);
	free(pro->mlx);
	free(pro->gnl);
}
