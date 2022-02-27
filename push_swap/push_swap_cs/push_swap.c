/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 04:46:15 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/27 05:52:19 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stacks *stack)
{
	if (stack->n_values < 6)
		sort_small(stack);
	else if (stack->n_values <= 5000)
		sort_medium(stack);
}

int	main(int argc, char *argv[])
{
	t_stacks	stack;

	error_input(argc, argv);
	init_stacks(&stack, argc);
	fill_stack_a(&stack, argc, argv);
	push_swap(&stack);
	free_stacks(&stack);
	return (0);
}
