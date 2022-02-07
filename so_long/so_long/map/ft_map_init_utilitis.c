/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init_utilitis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:52:06 by tguth             #+#    #+#             */
/*   Updated: 2022/02/05 10:59:46 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_init_image_1(t_pointer *t_pntr, int x_in, int y_in)
{
	t_xy	*iter;

	iter = (*t_pntr).t_map_p->head_wall;
	while (iter != NULL)
	{
		if (iter -> list_x == x_in && iter -> list_y == y_in)
		{
			mlx_put_image_to_window((*t_pntr).t_win_p->mlx,
				(*t_pntr).t_win_p->win, (*t_pntr).t_win_p->wall,
				(x_in * 32), (y_in * 32));
			return (1);
		}
		iter = iter->list_next;
	}
}

int	ft_init_image_2(t_pointer *t_pntr, int x_in, int y_in)
{
	t_xy	*iter;

	iter = (*t_pntr).t_map_p->head_empty;
	while (iter != NULL)
	{
		if (iter -> list_x == x_in && iter -> list_y == y_in)
		{
			mlx_put_image_to_window((*t_pntr).t_win_p-> mlx,
				(*t_pntr).t_win_p-> win, (*t_pntr).t_win_p-> empty,
				(x_in * 32), (y_in * 32));
			return (1);
		}
		iter = iter->list_next;
	}
}

int	ft_init_image_3(t_pointer *t_pntr, int x_in, int y_in)
{
	t_xy	*iter;

	iter = (*t_pntr).t_map_p->head_coin;
	while (iter != NULL)
	{
		if (iter -> list_x == x_in && iter -> list_y == y_in)
		{
			mlx_put_image_to_window((*t_pntr).t_win_p-> mlx,
				(*t_pntr).t_win_p-> win, (*t_pntr).t_win_p-> coin,
				(x_in * 32), (y_in * 32));
			return (1);
		}
		iter = iter->list_next;
	}
}

int	ft_init_image_4(t_pointer *t_pntr, int x_in, int y_in)
{
	t_xy	*iter;

	if (x_in == (*t_pntr).t_map_p->player_x
		&& y_in == (*t_pntr).t_map_p->player_y)
	{
		mlx_put_image_to_window((*t_pntr).t_win_p-> mlx,
			(*t_pntr).t_win_p-> win, (*t_pntr).t_win_p-> player,
			(x_in * 32), (y_in * 32));
		ft_lstadd_back_xy(&(*t_pntr).t_map_p->head_empty,
			ft_lstnew_xy((*t_pntr).t_map_p->player_y,
				(*t_pntr).t_map_p->player_x));
		return (1);
	}
}

int	ft_init_image_5(t_pointer *t_pntr, int x_in, int y_in)
{
	t_xy	*iter;

	if (x_in == (*t_pntr).t_map_p->exit_x && y_in == (*t_pntr).t_map_p->exit_y)
	{
		mlx_put_image_to_window((*t_pntr).t_win_p-> mlx,
			(*t_pntr).t_win_p-> win, (*t_pntr).t_win_p-> exit_closed,
			(x_in * 32), (y_in * 32));
		return (1);
	}
}
