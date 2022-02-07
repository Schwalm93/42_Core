/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move_utilitis.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:26:41 by tguth             #+#    #+#             */
/*   Updated: 2022/02/05 10:44:18 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_y(int y, int *new_x, int *new_y, t_pointer *t_pntr)
{
	int	check;

	check = 0;
	if (y == 1)
	{
		check = ft_check((*t_pntr).t_map_p->player_x,
				(*t_pntr).t_map_p->player_y + 1, t_pntr);
		*new_x = (*t_pntr).t_map_p->player_x;
		*new_y = (*t_pntr).t_map_p->player_y + 1;
	}
	else if (y == -1)
	{
		check = ft_check((*t_pntr).t_map_p->player_x,
				(*t_pntr).t_map_p->player_y - 1, t_pntr);
		*new_x = (*t_pntr).t_map_p->player_x;
		*new_y = (*t_pntr).t_map_p->player_y -1;
	}
	return (check);
}

int	ft_check_x(int x, int *new_x, int *new_y, t_pointer *t_pntr)
{
	int	check;

	check = 0;
	if (x == 1)
	{
		check = ft_check((*t_pntr).t_map_p->player_x + 1,
				(*t_pntr).t_map_p->player_y, t_pntr);
		*new_x = (*t_pntr).t_map_p->player_x + 1;
		*new_y = (*t_pntr).t_map_p->player_y;
	}
	else if (x == -1)
	{
		check = ft_check((*t_pntr).t_map_p->player_x - 1,
				(*t_pntr).t_map_p->player_y, t_pntr);
		*new_x = (*t_pntr).t_map_p->player_x - 1;
		*new_y = (*t_pntr).t_map_p->player_y;
	}
	return (check);
}
