/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:56:27 by cschwalm          #+#    #+#             */
/*   Updated: 2022/03/31 01:01:15 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < (argc))
	{
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
			{
				printf("Error - wrong arguments.\n");
				exit(0);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	error_input(int argc, char *argv[])
{
	if (argc < 5)
	{
		printf("Error - to less arguments.\n");
		exit(0);
	}
	else if (argc > 6)
	{
		printf("Error - to many arguments.\n");
		exit(0);
	}
	if (atoi(argv[1]) < 1 || atoi(argv[1]) > 250)
	{
		printf("Error - to few or to many philosophers.\n");
		exit(0);
	}
	
	check_args(argc, argv);
}
