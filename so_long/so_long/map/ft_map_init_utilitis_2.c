/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init_utilitis_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:05:00 by tguth             #+#    #+#             */
/*   Updated: 2022/02/05 11:09:10 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_file_to_pntr_1(t_pointer *t_pntr)
{
	(*t_pntr).t_win_p-> wall = mlx_xpm_file_to_image(
			(*t_pntr).t_win_p-> mlx, "./img/top.xpm",
			&(*t_pntr).t_win_p-> wall_width,
			&(*t_pntr).t_win_p-> wall_height);
	(*t_pntr).t_win_p-> player = mlx_xpm_file_to_image(
			(*t_pntr).t_win_p-> mlx, "./img/character.xpm",
			&(*t_pntr).t_win_p-> player_width,
			&(*t_pntr).t_win_p-> player_height);
	(*t_pntr).t_win_p-> coin = mlx_xpm_file_to_image(
			(*t_pntr).t_win_p-> mlx, "./img/coin.xpm",
			&(*t_pntr).t_win_p-> coin_width,
			&(*t_pntr).t_win_p-> coin_height);
	(*t_pntr).t_win_p-> exit = mlx_xpm_file_to_image(
			(*t_pntr).t_win_p-> mlx, "./img/exit.xpm",
			&(*t_pntr).t_win_p-> exit_width,
			&(*t_pntr).t_win_p-> exit_height);
	(*t_pntr).t_win_p-> empty = mlx_xpm_file_to_image(
			(*t_pntr).t_win_p-> mlx, "./img/free.xpm",
			&(*t_pntr).t_win_p-> empty_width,
			&(*t_pntr).t_win_p-> empty_height);
}

void	ft_file_to_pntr_2(t_pointer *t_pntr)
{
	(*t_pntr).t_win_p-> exit_closed = mlx_xpm_file_to_image(
			(*t_pntr).t_win_p-> mlx, "./img/exit_closed.xpm",
			&(*t_pntr).t_win_p-> exit_closed_width,
			&(*t_pntr).t_win_p-> exit_closed_height);
	if ((*t_pntr).t_win_p-> wall == NULL
		|| (*t_pntr).t_win_p-> player == NULL
		|| (*t_pntr).t_win_p-> coin == NULL
		|| (*t_pntr).t_win_p-> exit == NULL
		|| (*t_pntr).t_win_p-> empty == NULL
		|| (*t_pntr).t_win_p-> exit_closed == NULL)
	{
		printf("Error! Can not load all images!\n");
		ft_clear_lists(t_pntr);
		ft_free_lists(t_pntr);
		exit(0);
	}
}
