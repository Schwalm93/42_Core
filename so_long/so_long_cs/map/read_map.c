/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 08:05:45 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/06 08:07:31 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	printmap(t_program *program, char type)
{
	if (type == 48)
		mlx_put_image_to_window(program->mlx, program->win,
			program->empty, program->print_x, program->print_y);
	if (type == 49)
		mlx_put_image_to_window(program->mlx, program->win,
			program->wall, program->print_x, program->print_y);
	if (type == 67)
	{
		mlx_put_image_to_window(program->mlx, program->win,
			program->coin, program->print_x, program->print_y);
		program->count_coin++;
	}
	if (type == 69)
		mlx_put_image_to_window(program->mlx, program->win,
			program->exit, program->print_x, program->print_y);
	if (type == 80)
	{
		mlx_put_image_to_window(program->mlx, program->win,
			program->player, program->print_x, program->print_y);
		program->player_pos_x = program->print_y;
		program->player_pos_y = program->print_x;
	}
	program->print_x += 32;
}

void	read_line(t_program *program)
{
	int	i;

	i = -1;
	if (program->map_w == 0)
	{
		while (program->gnl[++i] != '\n')
			program->map_w += 1;
		program->map_w *= 32;
		program->win = mlx_new_window(program->mlx, (program->map_w),
				(program->map_h), "Takeshis Castle");
	}
	i = -1;
	while (program->gnl[++i] != 0)
	{
		if (program->gnl[i] == '\n')
		{
			program->print_y += 32;
			program->print_x = 0;
			i++;
		}
		printmap(program, program->gnl[i]);
	}
	player_startlocation(program);
}

void	read_map(t_program *program, char *argv)
{
	int		fd;
	int		i;
	char	*mem;

	i = 0;
	map_init(program);
	fd = open(argv, O_RDONLY);
	program->gnl = malloc(sizeof(char) * 1);
	program->gnl[0] = '\0';
	while (mem != 0)
	{
		mem = get_next_line(fd);
		if (i < 1)
			program->check = (ft_strlen(mem));
		if (mem != 0)
			program->gnl = ft_strjoin(program->gnl, mem);
		i++;
		free(mem);
	}
	check_map(program, program->gnl);
	program->map_h = ((i - 1) * 32);
	printf("%s\n", program->gnl);
	read_line(program);
}
