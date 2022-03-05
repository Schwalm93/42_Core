/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 09:44:11 by cschwalm          #+#    #+#             */
/*   Updated: 2022/03/05 02:53:04 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algorithm(t_stacks *stack)
{
	int	n;
	int	pos;

	n = stack->hold_second;
	pos = stack->position_n_s;
	if ((stack->top_a / 25) == 0)
	{
		if (stack->a[stack->top_a] > stack->a[stack->bot])
		{
			n = stack->a[stack->bot];
			pos = 0;
		}
		else
		{
			n = stack->a[stack->top_a];
			pos = stack->top_a;
		}
	}
	else if (check_who_is_near(stack))
	{
		n = stack->hold_first;
		pos = stack->position_n;
	}
	move_n_to_top_a(stack, pos, n);
	move_n_to_b(stack, n);
}

void	sort_medium(t_stacks *stack)
{
	while (stack->top_a > 0)
	{
		check_next_n(stack);
		if (stack->top_a != 0)
			algorithm(stack);
	}
	rotate_back(stack);
	move_all_to_a(stack);
}
