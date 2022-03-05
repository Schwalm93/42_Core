/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:47:26 by cschwalm          #+#    #+#             */
/*   Updated: 2022/03/05 03:07:51 by cschwalm         ###   ########.fr       */
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
			return (0);
		i++;
	}
	return (1);
}

void	sort_below_four(t_stacks *stack)
{
	if (stack->n_values < 3)
		action_sa(stack);
	else
	{
		if (stack->a[stack->top_a - 1] > stack->a[stack->bot]
			&& stack->a[stack->bot] > stack->a[stack->top_a])
		{
			action_rra(stack);
			action_sa(stack);
		}
		if (stack->a[stack->top_a] > stack->a[stack->top_a - 1]
			&& stack->a[stack->top_a] > stack->a[stack->bot])
			action_ra(stack);
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
	if (!check_ascending_small(stack))
		action_pb(stack);
	sort_below_four(stack);
	if (stack->b[stack->top_b] < stack->a[stack->top_a] && stack->top_b != -1)
		action_pa(stack);
	else if (stack->b[stack->top_b] > stack->a[stack->bot])
	{
		action_pa(stack);
		action_ra(stack);
	}
	else if (stack->b[stack->top_b] > stack->a[stack->top_a]
		&& stack->b[stack->top_b] != -1)
	{
		while (stack->b[stack->top_b] > stack->a[stack->top_a])
		{
			action_ra(stack);
			stack->rotate++;
		}
		action_pa(stack);
	}
}

void	sort_below_six(t_stacks *stack)
{
	while (stack->top_b != -1)
	{
		if (stack->b[stack->top_b] < stack->a[stack->top_a])
			action_pa(stack);
		else if (stack->b[stack->top_b] > stack->a[stack->top_a]
			&& stack->b[stack->top_b] < stack->a[stack->top_a - 1])
		{
			action_pa(stack);
			action_sa(stack);
		}
		else if (stack->b[stack->top_b] > stack->a[stack->bot])
		{
			action_pa(stack);
			action_ra(stack);
		}
		else if (stack->b[stack->top_b] > stack->a[stack->top_a])
		{
			action_ra(stack);
			stack->rotate++;
		}
	}
}

void	sort_small(t_stacks *stack)
{
	if (stack->n_values < 4)
		sort_below_four(stack);
	else if (stack->n_values < 5)
	{
		sort_below_five(stack);
		while (stack->rotate > 0)
		{
			action_rra(stack);
			stack->rotate--;
		}
	}
	else if (stack->n_values < 6)
	{
		action_pb(stack);
		action_pb(stack);
		sort_below_four(stack);
		sort_below_six(stack);
		while (stack->rotate > 0)
		{
			action_rra(stack);
			stack->rotate--;
		}
	}
}
