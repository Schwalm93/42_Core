/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:33:21 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/09 11:43:27 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_forbiden_chars(t_program *pro)
{
	printf("Map Error - The Map has forbidden chars.");
	ft_error_map(pro);
}

void	check_map_forbidden_chars(t_program *pro, char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'P' || map[i] == 'C' || map[i] == '1'
			|| map[i] == '0' || map[i] == 'E' || map[i] == '\n' )
			i++;
		else
			error_forbiden_chars(pro);
	}
}
