/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:23:42 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/24 13:51:49 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_stack_a(t_stacks *stack, int argc, char *argv[])
{
	int	i;

	i = 0;
	while (--argc > 0)
	{
		stack->a[i] = ft_atoi(argv[i + 1]);
		i++;
		stack->top_a++;
	}
	set_chunks(stack);
}
