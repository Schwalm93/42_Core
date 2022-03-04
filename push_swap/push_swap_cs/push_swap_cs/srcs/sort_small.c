/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:47:26 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/20 06:41:57 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_ascending_small(t_stacks *stack)
{
	int	i;

	i = 0;
	while (stack->a[i])
	{
		if (stack->a[i] < stack->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	sort_below_four(t_stacks *stack)
{
	if (stack->n_values < 3 && check_ascending_small(stack))
		action_sa(stack);
	else
	{
		if (stack->a[stack->top_a - 1] > stack->a[stack->bot]
			&& stack->a[stack->bot] > stack->a[stack->top_a])
		{
			action_rra(stack);
			action_sa(stack);
		}
		if (stack->a[stack->top_a] > stack->a[stack->top_a - 1])
			action_sa(stack);
		if (stack->a[stack->top_a - 1] > stack->a[stack->bot])
			action_rra(stack);
		if (stack->a[stack->top_a - 1] > stack->a[stack->bot]
			&& stack->a[stack->bot] > stack->a[stack->top_a])
		{
			action_rra(stack);
			action_sa(stack);
		}
	}
}

void	sort_below_five(t_stacks *stack)
{
	action_pb(stack);
	sort_below_four(stack);
	if (stack->b[stack->bot] > stack->a[stack->bot + 1]
		&& stack->b[stack->bot] < stack->a[stack->bot])
	{
		action_rra(stack);
		action_pa(stack);
		action_rra(stack);
		action_rra(stack);
	}
	else
		action_pa(stack);
	if (stack->a[stack->top_a] > stack->a[stack->bot])
		action_ra(stack);
	if (stack->a[stack->top_a] > stack->a[stack->top_a - 1])
		action_sa(stack);
}

void	sort_below_six(t_stacks *stack)
{
	int	i;

	i = 0;
	action_pb(stack);
	action_pb(stack);
	sort_below_four(stack);
	while (i < 2)
	{
		if (stack->b[stack->top_b] > stack->a[stack->bot + 1]
			&& stack->b[stack->top_b] < stack->a[stack->bot])
		{
			action_rra(stack);
			action_pa(stack);
			action_ra(stack);
			action_ra(stack);
		}
		else
			action_pa(stack);
		if (stack->a[stack->top_a] > stack->a[stack->bot])
			action_ra(stack);
		if (stack->a[stack->top_a] > stack->a[stack->top_a - 1])
			action_sa(stack);
		i++;
	}
}

void	sort_small(t_stacks *stack)
{
	printf("stack a[4] = %d\n", stack->a[4]);
	printf("stack a[3] = %d\n", stack->a[3]);
	printf("stack a[2] = %d\n", stack->a[2]);
	printf("stack a[1] = %d\n", stack->a[1]);
	printf("stack a[0] = %d\n\n", stack->a[0]);
	ft_putstr_fd("-----------actions------------\n", 1);
	if (stack->n_values < 4)
		sort_below_four(stack);
	else if (stack->n_values < 5)
		sort_below_five(stack);
	else if (stack->n_values < 6)
		sort_below_six(stack);
	ft_putstr_fd("------------------------------\n", 1);
	printf("stack a[4] = %d\n", stack->a[4]);
	printf("stack a[3] = %d\n", stack->a[3]);
	printf("stack a[2] = %d\n", stack->a[2]);
	printf("stack a[1] = %d\n", stack->a[1]);
	printf("stack a[0] = %d\n", stack->a[0]);
}
