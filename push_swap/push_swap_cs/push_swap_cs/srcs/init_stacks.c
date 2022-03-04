/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 05:24:48 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/25 10:56:09 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stacks(t_stacks *stack, int argc)
{
	stack->top_a = -1;
	stack->top_b = -1;
	stack->bot = 0;
	stack->n_values = (argc - 1);
	stack->hold_first = 0;
	stack->hold_second = 0;
	stack->position_n = 0;
	stack->count_moves = 0;
	stack->rotate = 0;
	stack->chunk_count = 0;
	stack->a = malloc(sizeof(int) * (argc - 1));
	if (!stack->a)
		exit(0);
	stack->b = malloc(sizeof(int) * (argc - 1));
	if (!stack->b)
		exit(0);
	stack->chunks = malloc(sizeof(int) * (argc - 1));
	if (!stack->chunks)
		exit(0);
}
