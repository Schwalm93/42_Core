/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_pa_pb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:33:12 by cschwalm          #+#    #+#             */
/*   Updated: 2022/03/03 10:27:44 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	action_pa(t_stacks *stack)
{
	stack->top_a++;
	stack->a[stack->top_a] = stack->b[stack->top_b];
	stack->b[stack->top_b] = 0;
	stack->top_b--;
	stack->count_moves++;
	ft_putstr_fd("pa\n", 1);
}

void	action_pb(t_stacks *stack)
{
	stack->top_b++;
	stack->b[stack->top_b] = stack->a[stack->top_a];
	stack->a[stack->top_a] = 0;
	stack->top_a--;
	stack->count_moves++;
	ft_putstr_fd("pb\n", 1);
}
