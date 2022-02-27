/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 06:35:40 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/27 06:02:32 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_who_is_near(t_stacks *stack)
{
	int	temp;
	int	temp2;

	temp = stack->position_n;
	temp2 = stack->position_n_s;
	if (stack->position_n + 1 > stack->top_a / 2)
		temp = stack->top_a - stack->position_n;
	if (stack->position_n_s + 1 > stack->top_a / 2)
		temp2 = stack->top_a - stack->position_n_s;
	if (temp < temp2)
		return (1);
	else
		return (0);
}

int	check_chunk(t_stacks *stack)
{
	int	temp;
	int	k;

	k = 0;
	stack->chunk_count++;
	temp = stack->chunk_count;
	while (temp > (stack->n_values / stack->n_chunks))
	{
		k++;
		temp = temp - (stack->n_values / stack->n_chunks);
	}
	return (k);
}

void	check_next_n(t_stacks *stack)
{
	int	i;
	int	k;

	i = 0;
	stack->position_n = 0;
	stack->position_n_s = 0;
	k = check_chunk(stack);
	stack->hold_second = stack->hold_first;
	while (i < stack->top_a)
	{
		if (stack->a[i] <= stack->chunks[k] && stack->position_n == 0)
		{
			stack->hold_first = stack->a[i];
			stack->position_n = i;
		}
		if (stack->a[i] <= stack->chunks[k])
		{
			stack->hold_second = stack->a[i];
			stack->position_n_s = i;
		}
		i++;
	}
	printf("Hold 1 = %d\n", stack->hold_first);
	printf("Hold 2 = %d\n", stack->hold_second);
}
