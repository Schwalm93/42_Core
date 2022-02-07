/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utilitis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:12:47 by tguth             #+#    #+#             */
/*   Updated: 2022/02/07 07:32:17 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init(t_pointer *t_pntr)
{
	t_mlx		t_win;
	t_world		t_map;

	(*t_pntr).t_map_p = &t_map;
	(*t_pntr).t_win_p = &t_win;
	(*t_pntr).t_map_p->head_wall = NULL;
	(*t_pntr).t_map_p->head_empty = NULL;
	(*t_pntr).t_map_p->head_coin = NULL;
	(*t_pntr).t_map_p->numb_coin = 0;
	(*t_pntr).t_map_p->exit_x = 0;
	(*t_pntr).t_map_p->exit_y = 0;
	(*t_pntr).t_map_p->player_x = 0;
	(*t_pntr).t_map_p->player_y = 0;
	(*t_pntr).t_map_p->map_x = 0;
	(*t_pntr).t_map_p->map_y = 0;
	(*t_pntr).t_map_p->finish = 0;
	printf("1. %d\n", (*t_pntr).t_map_p->map_x);
}

void	ft_init_win(t_pointer *t_pntr)
{
	(*t_pntr).t_win_p->mlx = NULL;
	(*t_pntr).t_win_p->win = NULL;
	(*t_pntr).t_win_p->wall = NULL;
	(*t_pntr).t_win_p->player = NULL;
	(*t_pntr).t_win_p->exit = NULL;
	(*t_pntr).t_win_p->exit_closed = NULL;
	(*t_pntr).t_win_p->coin = NULL;
	(*t_pntr).t_win_p->empty = NULL;
	(*t_pntr).t_win_p->wall_height = 0;
	(*t_pntr).t_win_p->wall_width = 0;
	(*t_pntr).t_win_p->player_height = 0;
	(*t_pntr).t_win_p->player_width = 0;
	(*t_pntr).t_win_p->exit_height = 0;
	(*t_pntr).t_win_p->exit_width = 0;
	(*t_pntr).t_win_p->coin_height = 0;
	(*t_pntr).t_win_p->coin_width = 0;
	(*t_pntr).t_win_p->empty_height = 0;
	(*t_pntr).t_win_p->empty_width = 0;
	(*t_pntr).t_win_p->exit_closed_height = 0;
	(*t_pntr).t_win_p->exit_closed_width = 0;
	(*t_pntr).t_win_p->count_steps = 0;
}

void	ft_init_read_map(int *last_line, int *i, int *walls)
{
	*last_line = 0;
	*i = -1;
	*walls = 0;
}

t_xy	*ft_lstnew_xy(int row, int coloum)
{
	t_xy		*head;

	head = NULL;
	head = (t_xy *) malloc(sizeof(t_xy));
	if (head == NULL)
		return (NULL);
	head -> list_y = row;
	head -> list_x = coloum;
	head -> list_next = NULL;
	return (head);
}

void	ft_lstadd_back_xy(t_xy **lst, t_xy *new)
{
	if (!new || !lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while ((*lst)-> list_next != NULL)
			*lst = (*lst)-> list_next;
		(*lst)->list_next = new;
	}
}
