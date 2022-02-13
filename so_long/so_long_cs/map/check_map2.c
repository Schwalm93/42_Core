/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:07:40 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/07 12:34:47 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_wall3(t_program *pro, char *map, int l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (j == l)
		{
			if (map[i] != '1')
			{
				printf("Map Error - The Map has to be closed with \"1\".");
				ft_error_map(pro);
			}
		}
		if (map[i] == '\n')
			j++;
		i++;
	}	
}

void	check_map_wall2(t_program *pro, char *map)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (map[i - 1] != '1' || map[i + 1] != '1')
			{
				printf("Map Error - The Map has to be closed with \"1\".");
				ft_error_map(pro);
			}
			l++;
		}
		i++;
	}
	check_map_wall3(pro, map, l);
}

void	check_map_wall(t_program *pro, char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n' && map[i])
	{
		if (map[i] != '1')
		{
			printf("Map Error - The Map has to be closed with \"1\".");
			ft_error_map(pro);
		}
		i++;
	}
	check_map_wall2(pro, map);
}

void	check_map_rect_error(t_program *pro)
{
	printf("Map Error - The Map isn't rectangular");
	ft_error_map(pro);
}

void	check_map_rect2(t_program *pro, char *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (map[j] != '\n' && map[j])
		j++;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (k != j)
				check_map_rect_error(pro);
			k = -1;
		}
		k++;
		i++;
	}
}
