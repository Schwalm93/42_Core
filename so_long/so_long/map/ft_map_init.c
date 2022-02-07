/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 08:17:42 by kali              #+#    #+#             */
/*   Updated: 2022/02/05 11:29:16 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_create_map(t_pointer *t_pntr);
static void	ft_img_pointer(int x_in, int y_in, t_pointer *t_pntr);

void	ft_map_init(t_pointer *t_pntr)
{
	(*t_pntr).t_win_p->mlx = mlx_init();
	if ((*t_pntr).t_win_p->mlx == NULL)
	{
		printf("Fehler bei mlx!\n");
		exit(0);
	}
	(*t_pntr).t_win_p->win = mlx_new_window(
			(*t_pntr).t_win_p->mlx, (*t_pntr).t_map_p->map_x * 32,
			(*t_pntr).t_map_p->map_y * 32, "so_long");
	if ((*t_pntr).t_win_p->mlx == NULL)
	{
		printf("Fehler beim Fenster erstellen!\n");
		exit(0);
	}
	ft_file_to_pntr_1(t_pntr);
	ft_file_to_pntr_2(t_pntr);
	ft_create_map(t_pntr);
	(*t_pntr).t_win_p->count_steps = 1;
	ft_playermove(t_pntr);
	mlx_loop((*t_pntr).t_win_p-> mlx);
}

static void	ft_create_map(t_pointer *t_pntr)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < (*t_pntr).t_map_p->map_y)
	{
		while (x < (*t_pntr).t_map_p->map_x)
		{
			ft_img_pointer(x, y, t_pntr);
			x++;
		}
		y++;
		x = 0;
	}
}

static void	ft_img_pointer(int x_in, int y_in, t_pointer *t_pntr)
{
	if (ft_init_image_1(t_pntr, x_in, y_in) == 1)
		return ;
	if (ft_init_image_2(t_pntr, x_in, y_in) == 1)
		return ;
	if (ft_init_image_3(t_pntr, x_in, y_in) == 1)
		return ;
	if (ft_init_image_4(t_pntr, x_in, y_in) == 1)
		return ;
	if (ft_init_image_5(t_pntr, x_in, y_in) == 1)
		return ;
	printf("Error! Put image to Window\n");
	ft_clear_lists(t_pntr);
	ft_free_lists(t_pntr);
	exit(0);
}
