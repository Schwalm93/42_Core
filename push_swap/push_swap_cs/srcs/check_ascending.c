/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ascending.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 05:37:26 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/27 05:38:58 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_ascending(t_stacks *stack)
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
