/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:51:13 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/25 09:40:48 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	set_smallest_n(t_stacks *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack->a[i];
	while (i < stack->n_values)
	{
		if (stack->a[i] < temp)
			temp = stack->a[i];
		i++;
	}
	return (temp);
}

int	set_biggest_n(t_stacks *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack->a[i];
	while (i < stack->n_values)
	{
		if (stack->a[i] > temp)
			temp = stack->a[i];
		i++;
	}
	return (temp);
}

void	set_n_chunks(t_stacks *stack)
{
	if (stack->n_values >= 25)
		stack->n_chunks = stack->n_values / 25;
	if ((stack->n_values % 25) > 0)
		stack->n_chunks++;
}

void	set_chunks_limit(t_stacks *stack, int k, int i, int temp)
{
	while (i < stack->n_values)
	{
		if (stack->chunks[k] > stack->a[i] && stack->a[i] > temp
			&& stack->a[i] != temp)
			stack->chunks[k] = stack->a[i];
		i++;
	}	
}

void	set_chunks(t_stacks *stack)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	stack->temp = set_smallest_n(stack);
	set_n_chunks(stack);
	stack->chunks[i] = stack->temp;
	while (k < stack->n_chunks)
	{
		while (j++ < 25)
		{
			set_chunks_limit(stack, k, i, stack->temp);
			stack->temp = stack->chunks[k];
			i = 0;
			stack->chunks[k] = set_biggest_n(stack);
		}
		j = 0;
		stack->chunks[k] = stack->temp;
		printf("chunk limit = %d\n", stack->chunks[k]);
		k++;
		stack->chunks[k] = set_biggest_n(stack);
	}
}
