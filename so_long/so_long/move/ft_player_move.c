/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:32:59 by kali              #+#    #+#             */
/*   Updated: 2022/02/07 07:31:50 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	keyhook(int keycode, t_pointer *t_pntr);
static void	ft_move_player(t_pointer *t_pntr, int x, int y);
static int	ft_check_move(t_xy *iter, int x, int y, t_pointer *t_pntr);

void	ft_playermove(t_pointer *t_pntr)
{
	int	keycode;

	keycode = 0;
	mlx_key_hook((*t_pntr).t_win_p->win, keyhook, t_pntr);
	mlx_hook((*t_pntr).t_win_p->win, 17, 0, ft_close_all, t_pntr);
}

static int	keyhook(int keycode, t_pointer *t_pntr)
{
	if (keycode == 65307)
		ft_close_all(t_pntr);
	if ((*t_pntr).t_map_p->finish == 0)
	{
		if (keycode == 119 || keycode == 65362)
			ft_move_player(t_pntr, 0, -1);
		else if (keycode == 115 || keycode == 65364)
			ft_move_player(t_pntr, 0, 1);
		else if (keycode == 100 || keycode == 65363)
			ft_move_player(t_pntr, 1, 0);
		else if (keycode == 97 || keycode == 65361)
			ft_move_player(t_pntr, -1, 0);
	}
	return (0);
}

static void	ft_move_player(t_pointer *t_pntr, int x, int y)
{
	int	new_x;
	int	new_y;
	int	check;

	new_x = 0;
	new_y = 0;
	check = 0;
	check = ft_check_y(y, &new_x, &new_y, t_pntr);
	if (check == 0)
		check = ft_check_x(x, &new_x, &new_y, t_pntr);
	if (check == 1)
		ft_change_image_1(t_pntr, new_x, new_y);
	else if (check == 2)
		ft_change_image_2(t_pntr, new_x, new_y);
	else if (check == 3)
		ft_change_image_3(t_pntr, new_x, new_y);
	else if (check == 0)
	{
		printf("Error! move player\n");
		ft_close_all(t_pntr);
	}
}

int	ft_check(int x, int y, t_pointer *t_pntr)
{
	t_xy	*iter;

	iter = (*t_pntr).t_map_p->head_wall;
	while (iter != NULL)
	{
		if (x == iter-> list_x && y == iter->list_y)
			return (0);
		iter = iter-> list_next;
	}
	iter = (*t_pntr).t_map_p->head_empty;
	while (iter != NULL)
	{
		if (x == iter->list_x && y == iter->list_y)
			return (3);
		iter = iter-> list_next;
	}
	iter = (*t_pntr).t_map_p->head_coin;
	return (ft_check_move(iter, x, y, t_pntr));
}

static int	ft_check_move(t_xy *iter, int x, int y, t_pointer *t_pntr)
{
	while (iter != NULL)
	{
		if (x == iter->list_x && y == iter->list_y)
			return (1);
		iter = iter-> list_next;
	}
	if (x == (*t_pntr).t_map_p->exit_x && y == (*t_pntr).t_map_p->exit_y)
		return (2);
	return (-1);
}
