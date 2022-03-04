/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 04:59:12 by cschwalm          #+#    #+#             */
/*   Updated: 2022/02/27 06:45:19 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_dup(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
			{
				ft_putstr_fd("Error - Duplicated variables", 1);
				exit(0);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	error_wrong_arg(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
			{
				if (argv[j][i] != '-')
				{
					ft_putstr_fd("Error - Wrong Arguments", 1);
					exit(0);
				}
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	error_input(int argc, char *argv[])
{
	if (argc < 3)
	{
		ft_putstr_fd("Error - Too few Arguments ", 1);
		exit(0);
	}
	error_wrong_arg(argv);
	error_dup(argv);
}
