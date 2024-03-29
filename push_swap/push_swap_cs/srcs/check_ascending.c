/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ascending.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 05:37:26 by cschwalm          #+#    #+#             */
/*   Updated: 2022/03/04 02:19:15 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#include <stdio.h>

int	check_ascending(t_stacks *stack)
{
	int	i;

	i = 0;
	while (i < stack->n_values - 1)
	{
		if (stack->a[i] < stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
