/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_ra_rb_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:39:09 by cschwalm          #+#    #+#             */
/*   Updated: 2022/03/03 10:27:47 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	action_ra(t_stacks *stack)
{
	int	i;
	int	temp;

	i = stack->top_a;
	temp = stack->a[stack->top_a];
	while (i > 0)
	{	
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = temp;
	stack->count_moves++;
	ft_putstr_fd("ra\n", 1);
}

void	action_rb(t_stacks *stack)
{
	int	i;
	int	temp;

	i = stack->top_b;
	temp = stack->b[stack->top_b];
	while (i > 0)
	{	
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = temp;
	stack->count_moves++;
	ft_putstr_fd("rb\n", 1);
}

void	action_rr(t_stacks *stack)
{
	int	i;
	int	temp;

	i = stack->top_a;
	temp = stack->a[stack->top_a];
	while (i > 0)
	{	
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = temp;
	i = stack->top_b;
	temp = stack->b[stack->top_b];
	while (i > 0)
	{	
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = temp;
	stack->count_moves++;
	ft_putstr_fd("rr\n", 1);
}
