/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:56:27 by cschwalm          #+#    #+#             */
/*   Updated: 2022/04/09 04:31:18 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(int argc, char *argv[])
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
				return (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	error_input(int argc, char *argv[])
{
	if (argc < 5)
	{
		printf("Error - to less arguments.\n");
		return (1);
	}
	else if (argc > 6)
	{
		printf("Error - to many arguments.\n");
		return (1);
	}
	if (atoi(argv[1]) < 1 || atoi(argv[1]) > 250)
	{
		printf("Error - to few or to many philosophers.\n");
		return (1);
	}
	if (check_args(argc, argv) == 1)
		return (1);
	else
		return (0);
}

int	error_values_print(void)
{
	printf("Error - Time parameters to low (<60ms)");
	return (1);
}

int	error_values(t_data *data)
{
	if (data->n_philos > 250)
		return (error_values_print());
	if (data->time_to_die < 60)
		return (error_values_print());
	if (data->time_to_eat < 60)
		return (error_values_print());
	if (data->time_to_sleep < 60)
		return (error_values_print());
	return (0);
}
