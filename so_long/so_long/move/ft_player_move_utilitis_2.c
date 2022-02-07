/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move_utilitis_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:44:55 by tguth             #+#    #+#             */
/*   Updated: 2022/02/07 07:29:48 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_change_image_1(t_pointer *t_pntr, int new_x, int new_y)
{
	printf("%d\n", (*t_pntr).t_win_p->count_steps++);
	mlx_put_image_to_window((*t_pntr).t_win_p->mlx, (*t_pntr).t_win_p->win,
		(*t_pntr).t_win_p->empty, (*t_pntr).t_map_p->player_x * 32,
		(*t_pntr).t_map_p->player_y * 32);
	mlx_put_image_to_window((*t_pntr).t_win_p->mlx, (*t_pntr).t_win_p->win,
		(*t_pntr).t_win_p->player, new_x * 32, new_y * 32);
	(*t_pntr).t_map_p->player_x = new_x;
	(*t_pntr).t_map_p->player_y = new_y;
	(*t_pntr).t_map_p->numb_coin--;
	ft_lstadd_back_xy(&(*t_pntr).t_map_p->head_empty,
		ft_lstnew_xy((*t_pntr).t_map_p->player_y,
			(*t_pntr).t_map_p->player_x));
	if ((*t_pntr).t_map_p->numb_coin == 0)
		mlx_put_image_to_window((*t_pntr).t_win_p->mlx,
			(*t_pntr).t_win_p->win,
			(*t_pntr).t_win_p->exit, (*t_pntr).t_map_p->exit_x * 32,
			(*t_pntr).t_map_p->exit_y * 32);
}

void	ft_change_image_2(t_pointer *t_pntr, int new_x, int new_y)
{
	printf("%d\n", (*t_pntr).t_win_p->count_steps++);
	printf("Exit gefunden\n");
	if ((*t_pntr).t_map_p->numb_coin != 0)
		printf("You need first all coins!\n");
	mlx_put_image_to_window((*t_pntr).t_win_p->mlx, (*t_pntr).t_win_p->win,
		(*t_pntr).t_win_p->empty, (*t_pntr).t_map_p->player_x * 32,
		(*t_pntr).t_map_p->player_y * 32);
	mlx_put_image_to_window((*t_pntr).t_win_p->mlx, (*t_pntr).t_win_p->win,
		(*t_pntr).t_win_p->player, new_x * 32, new_y * 32);
	(*t_pntr).t_map_p->player_x = new_x;
	(*t_pntr).t_map_p->player_y = new_y;
	(*t_pntr).t_map_p->finish = 1;
	printf("You win the game XD \n");
}

void	ft_change_image_3(t_pointer *t_pntr, int new_x, int new_y)
{
	printf("%d\n", (*t_pntr).t_win_p->count_steps++);
	mlx_put_image_to_window((*t_pntr).t_win_p->mlx, (*t_pntr).t_win_p->win,
		(*t_pntr).t_win_p->empty, (*t_pntr).t_map_p->player_x * 32,
		(*t_pntr).t_map_p->player_y * 32);
	mlx_put_image_to_window((*t_pntr).t_win_p->mlx, (*t_pntr).t_win_p->win,
		(*t_pntr).t_win_p->player, new_x * 32, new_y * 32);
	(*t_pntr).t_map_p->player_x = new_x;
	(*t_pntr).t_map_p->player_y = new_y;
}
