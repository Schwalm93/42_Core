/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:16:50 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/09 12:12:58 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_program	program;
	t_map		map;

	if (argc != 2)
	{
		ft_putstr_fd("Error. Right Format = ./so_long [Map]", 1);
		return (0);
	}
	program.mlx = mlx_init();
	if (!program.mlx)
		return (0);
	// Img init + Map_W & Map_H from GNL
	img_init(&program, &map);
	read_map(&program, argv[1]);
		// Close on "x" Button.
	mlx_hook(program.win, 17, 0, ft_close, &program);
		// Keybinding Move(w,s,a,d + ↑,↓,←,→) + Esc
	mlx_key_hook(program.win, ft_pressbutton, &program);
	mlx_loop(program.mlx);
	ft_exit(&program);
}
