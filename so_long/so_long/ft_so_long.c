/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 06:39:01 by kali              #+#    #+#             */
/*   Updated: 2022/02/05 11:37:23 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_so_long(char *input);
static void	ft_read_map(int fp, t_pointer *t_pntr);
static void	ft_check_input(t_pointer *t_pntr);

int	main(int numb, char *arg[])
{
	if (numb != 2)
	{
		printf("Error! Please check your Input --> ./so_long map.ber\n");
		exit(0);
	}
	if (ft_strnstr(arg[1], ".ber", ft_strlen(arg[1])) == NULL)
	{
		printf("Error! The map file need an ending with .ber --> map.ber\n");
		exit(0);
	}
	ft_so_long(arg[1]);
	return (0);
}

static void	ft_so_long(char *input)
{
	t_pointer	t_pntr;
	int			fp;

	fp = open(input, O_RDONLY);
	if (fp < 1)
	{
		printf("Error! Can not read the map!\n");
		exit(0);
	}
	ft_init(&t_pntr);
	ft_init_win(&t_pntr);
	ft_read_map(fp, &t_pntr);
	ft_check_input(&t_pntr);
	ft_map_init(&t_pntr);
}

static void	ft_read_map(int fp, t_pointer *t_pntr)
{
	char		*line;
	int			last_line;
	int			i;
	int			walls;
	static char	*overflow;

	ft_init_read_map(&last_line, &i, &walls);
	while (last_line < 2)
	{
		ft_check_line(&line, t_pntr, &overflow, fp);
		while (line[++i] != '\n' && line[++i] != '\0')
		{
			ft_check_wall(line, i, &overflow);
			if (ft_set_walls(line, i, t_pntr, &walls) == 0
				&& ft_set_player_coin(line, i, t_pntr, &overflow) == 0
				&& ft_set_exit(line, i, t_pntr, &overflow) == 0)
				ft_error_input(1, &overflow, line);
		}
		ft_check_wall_2(&i, t_pntr, &last_line, walls);
		ft_check_wall_3(last_line, &overflow, line, t_pntr);
	}
	ft_free(overflow);
}

static void	ft_check_input(t_pointer *t_pntr)
{
	if ((*t_pntr).t_map_p->numb_coin < 1)
	{
		printf("Error! at least 1 collectible on the map!\n");
		exit(0);
	}
	if ((*t_pntr).t_map_p->exit_x == 0 || (*t_pntr).t_map_p->exit_y == 0)
	{
		printf("Error! no exit on the map!\n");
		exit(0);
	}
	if ((*t_pntr).t_map_p->player_x == 0 || (*t_pntr).t_map_p->player_y == 0)
	{
		printf("Es gibt keine Startposition für den Spieler auf der Map!\n");
		exit(0);
	}
}
