/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 05:56:46 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/27 06:25:10 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_all_to_a(t_stacks *stack)
{
	while (stack->top_b > -1)
		action_pa(stack);
}

void	move_n_to_b_and_swap_b(t_stacks *stack)
{
	action_pb(stack);
	action_sb(stack);
}

void	move_smallest_n_to_b(t_stacks *stack)
{
	action_pb(stack);
	action_rb(stack);
}

void	move_n_to_b(t_stacks *st, int n)
{
	while (st->a[st->top_a] == n)
	{
		if (st->top_b == -1)
			action_pb(st);
		else if (st->a[st->top_a] < st->b[st->top_b]
			&& st->a[st->top_a] > st->b[st->top_b - 1])
			move_n_to_b_and_swap_b(st);
		else if (st->a[st->top_a] > st->b[st->top_b]
			&& st->rotate == 0)
			action_pb(st);
		else if (st->a[st->top_a] > st->b[st->top_b]
			&& st->a[st->top_a] < st->b[st->bot])
			action_pb(st);
		else if (st->a[st->top_a] > st->b[st->top_b]
			&& st->a[st->top_a] > st->b[st->bot] && st->rotate > 0)
			rotate_and_decrease(st);
		else if (st->a[st->top_a] < st->b[st->bot]
			&& st->rotate == 0)
			move_smallest_n_to_b(st);
		else if (st->a[st->top_a] < st->b[st->bot + st->rotate]
			&& st->rotate > 0)
			rotate_back(st);
		else if (st->a[st->top_a] < st->b[st->top_b])
			rotate_and_increase(st);
	}
}

void	move_n_to_top_a(t_stacks *stack, int pos, int n)
{
	while (stack->a[stack->top_a] != n)
	{
		if (pos >= stack->top_a / 2)
			action_ra(stack);
		else
			action_rra(stack);
	}
}
