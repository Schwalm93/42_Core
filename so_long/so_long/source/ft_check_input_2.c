/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:31:31 by tguth             #+#    #+#             */
/*   Updated: 2022/02/04 13:12:17 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_wall_2(int *i, t_pointer *t_pntr, int *last_line, int walls)
{
	i = 0;
	if (walls == (*t_pntr).t_map_p->map_x)
		last_line++;
	walls = 0;
}

void	ft_check_wall_3(int last_line, char **overflow,
	char *line, t_pointer *t_pntr)
{
	if ((*t_pntr).t_map_p->map_y == 0 && last_line != 1)
		ft_error_input(2, overflow, line);
	(*t_pntr).t_map_p->map_y++;
	ft_free(line);
}
