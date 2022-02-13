/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:35:16 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/04 04:44:21 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_init(t_program *program)
{
	program->map_h = 0;
	program->map_w = 0;
	program->print_x = 0;
	program->print_y = 0;
	program->count_coin = 0;
	program->finish = 0;
	program->move = 1;
	program->steps = 0;
}
