/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_sa_sb_ss.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:06:14 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/25 11:08:09 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	action_sa(t_stacks *stack)
{
	int	temp;

	temp = stack->a[stack->top_a - 1];
	stack->a[stack->top_a - 1] = stack->a[stack->top_a];
	stack->a[stack->top_a] = temp;
	stack->count_moves++;
	stack->count_2 += 1;
	ft_putstr_fd("sa\n", 1);
}

void	action_sb(t_stacks *stack)
{
	int	temp;

	temp = stack->b[stack->top_b - 1];
	stack->b[stack->top_b - 1] = stack->b[stack->top_b];
	stack->b[stack->top_b] = temp;
	stack->count_moves++;
	stack->count_2 += 1;
	ft_putstr_fd("sb\n", 1);
}

void	action_ss(t_stacks *stack)
{
	int	temp;

	temp = stack->a[stack->top_a - 1];
	stack->a[stack->top_a - 1] = stack->a[stack->top_a];
	stack->a[stack->top_a] = temp;
	temp = stack->b[stack->top_b - 1];
	stack->b[stack->top_b - 1] = stack->b[stack->top_b];
	stack->b[stack->top_b] = temp;
	stack->count_moves++;
	ft_putstr_fd("ss\n", 1);
}
