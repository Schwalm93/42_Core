/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilitis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:59:49 by tguth             #+#    #+#             */
/*   Updated: 2022/02/04 13:19:15 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_close_all(t_pointer *t_pntr)
{
	mlx_loop_end((*t_pntr).t_win_p);
	ft_clear_lists(t_pntr);
	ft_free_lists(t_pntr);
	return (0);
}

void	ft_clear_lists(t_pointer *t_pntr)
{
	mlx_destroy_image((*t_pntr).t_win_p->mlx, (*t_pntr).t_win_p->wall);
	mlx_destroy_image((*t_pntr).t_win_p->mlx, (*t_pntr).t_win_p->coin);
	mlx_destroy_image((*t_pntr).t_win_p->mlx, (*t_pntr).t_win_p->player);
	mlx_destroy_image((*t_pntr).t_win_p->mlx, (*t_pntr).t_win_p->empty);
	mlx_destroy_image((*t_pntr).t_win_p->mlx, (*t_pntr).t_win_p->exit);
	mlx_destroy_image((*t_pntr).t_win_p->mlx, (*t_pntr).t_win_p->exit_closed);
	mlx_destroy_window((*t_pntr).t_win_p->mlx, (*t_pntr).t_win_p->win);
	mlx_destroy_display((*t_pntr).t_win_p->mlx);
	free((*t_pntr).t_win_p->mlx);
}

void	ft_free_lists(t_pointer *t_pntr)
{
	t_xy	*iter;
	t_xy	*del;

	iter = (*t_pntr).t_map_p->head_wall;
	while (iter != NULL)
	{
		del = iter;
		iter = (*t_pntr).t_map_p->head_wall->list_next;
		free(del);
	}
	iter = (*t_pntr).t_map_p->head_coin;
	while (iter != NULL)
	{
		del = iter;
		iter = (*t_pntr).t_map_p->head_coin->list_next;
		free(del);
	}
	iter = (*t_pntr).t_map_p->head_empty;
	while (iter != NULL)
	{
		del = iter;
		iter = (*t_pntr).t_map_p->head_empty->list_next;
		free(del);
	}
}

void	ft_free(void *string)
{
	free(string);
	string = NULL;
}

void	ft_error_input(int error, char **overflow, char *line)
{
	if (error == 1)
		printf("Error! not allowed sign in map!\n");
	else if (error == 2)
		printf("Error! Map must be surrounded by walls\n");
	ft_free(overflow);
	ft_free(line);
	exit(0);
}
