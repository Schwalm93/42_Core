/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 07:43:20 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/09 11:34:18 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_p(t_program *pro, char *map)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			p++;
		i++;
	}
	if (p != 1)
	{
		printf("Map Error - There must be 1 \"P\" in the Map.");
		ft_error_map(pro);
	}
}

void	check_map_c(t_program *pro, char *map)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			c++;
		i++;
	}
	if (c == 0)
	{
		printf("Map Error - There must be atleast 1 \"C\" in the Map.");
		ft_error_map(pro);
	}
}

void	check_map_e(t_program *pro, char *map)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (map[i])
	{
		if (map[i] == 'E')
			e++;
		i++;
	}
	if (e == 0)
	{
		printf("Map Error - There must be at least 1 \"E\" in the Map.");
		ft_error_map(pro);
	}	
}

void	check_map_rect(t_program *pro, char *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			j++;
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (k == j)
				check_map_rect_error(pro);
			k = -1;
		}
		k++;
		i++;
	}
}

void	check_map(t_program *pro, char *map)
{
	check_map_p(pro, map);
	check_map_c(pro, map);
	check_map_e(pro, map);
	check_map_wall(pro, map);
	check_map_rect(pro, map);
	check_map_rect2(pro, map);
	check_map_forbidden_chars(pro, map);
}
