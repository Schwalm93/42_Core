/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rra_rrb_rrr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:43:17 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/25 11:07:58 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	action_rra(t_stacks *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack->a[i];
	while (i < stack->top_a)
	{	
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = temp;
	stack->count_moves++;
	stack->count_2 += 1;
	ft_putstr_fd("rra\n", 1);
}

void	action_rrb(t_stacks *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack->b[i];
	while (i < stack->top_b)
	{	
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = temp;
	stack->count_moves++;
	stack->count_2 += 1;
	ft_putstr_fd("rrb\n", 1);
}

void	action_rrr(t_stacks *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack->a[i];
	while (i < stack->top_a)
	{	
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = temp;
	temp = stack->b[i];
	while (i < stack->top_b)
	{	
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = temp;
	stack->count_moves++;
}
