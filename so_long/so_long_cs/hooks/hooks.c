/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 03:39:29 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/05 06:35:43 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_exit(t_program *pro)
{
	if (pro->count_coin == 0)
		pro->finish = 1;
	if (pro->gnl[pro->pl] == 'E' && pro->finish == 1)
	{
		ft_putstr_fd("Hurray!! You did it in ", 1);
		ft_putnbr_fd(pro->steps, 1);
		ft_putstr_fd(" Steps!!", 1);
		ft_putstr_fd("\nEnd the game with ESC or Close the Window!", 1);
		pro->move = 0;
	}
}

void	check_coin(t_program *pro)
{
	pro->gnl[pro->pl] = '0';
	pro->count_coin--;
}

int	ft_pressbutton(int keycode, t_program *pro)
{
	if (keycode == 65307)
		ft_close(pro);
	if (pro->move == 1)
	{
		pro->check_step = pro->steps;
		move(pro, keycode);
		if (pro->check_step != pro->steps)
		{
			ft_putstr_fd("Steps = ", 1);
			ft_putnbr_fd(pro->steps, 1);
			ft_putstr_fd("\n", 1);
		}
		check_exit(pro);
	}
	if (pro->gnl[pro->pl] == 'C')
		check_coin(pro);
	mlx_put_image_to_window(pro->mlx, pro->win, pro->player,
		pro->player_pos_y, pro->player_pos_x);
	return (0);
}

int	ft_close(t_program *pro)
{
	mlx_loop_end(pro->mlx);
	return (0);
}

void	player_startlocation(t_program *pro)
{
	pro->pl = 0;
	while (pro->gnl && pro->gnl[pro->pl] != 'P')
		pro->pl++;
}
