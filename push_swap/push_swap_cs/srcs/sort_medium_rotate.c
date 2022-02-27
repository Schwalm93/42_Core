/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 05:53:25 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/27 06:24:43 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_back(t_stacks *stack)
{
	while (stack->rotate > 0)
	{
		action_rrb(stack);
		stack->rotate--;
	}
}

void	rotate_b(t_stacks *stack)
{
	while (stack->rotate > 0)
	{
		action_rrb(stack);
		stack->rotate--;
	}
}

void	rotate_and_decrease(t_stacks *stack)
{
	action_rrb(stack);
	stack->rotate--;
}

void	rotate_and_increase(t_stacks *stack)
{
	action_rb(stack);
	stack->rotate++;
}
