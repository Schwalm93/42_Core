/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 07:02:10 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/06 11:40:43 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error_image(t_program *pro)
{
	if (pro->player)
		mlx_destroy_image(pro->mlx, pro->player);
	if (pro->coin)
		mlx_destroy_image(pro->mlx, pro->coin);
	if (pro->exit)
		mlx_destroy_image(pro->mlx, pro->exit);
	if (pro->wall)
		mlx_destroy_image(pro->mlx, pro->wall);
	if (pro->empty)
		mlx_destroy_image(pro->mlx, pro->empty);
	free(pro->mlx);
	exit(0);
}

void	ft_error_map(t_program *pro)
{
	if (pro->player)
		mlx_destroy_image(pro->mlx, pro->player);
	if (pro->coin)
		mlx_destroy_image(pro->mlx, pro->coin);
	if (pro->exit)
		mlx_destroy_image(pro->mlx, pro->exit);
	if (pro->wall)
		mlx_destroy_image(pro->mlx, pro->wall);
	if (pro->empty)
		mlx_destroy_image(pro->mlx, pro->empty);
	mlx_destroy_display(pro->mlx);
	free(pro->mlx);
	free(pro->gnl);
	exit(0);
}
