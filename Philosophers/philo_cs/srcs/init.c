/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:04:11 by cschwalm          #+#    #+#             */
/*   Updated: 2022/04/09 04:49:19 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i++ <= data->n_philos)
	{
		data->philo[i].philo_id = i;
		if (i == 1)
			data->philo[i].fork_r = data->n_philos;
		else
			data->philo[i].fork_r = (i - 1);
		data->philo[i].fork_l = i;
		data->philo[i].n_times_eat = 0;
		data->philo[i].start_last_meal = timenow();
		data->philo[i].data = data;
	}
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i++ <= data->n_philos)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
			return (error_init());
		if (pthread_mutex_init(&data->philo[i].eats, NULL) != 0)
			return (error_init());
	}
	if (pthread_mutex_init(&data->message, NULL) != 0)
		return (error_init());
	return (0);
}

int	init(t_data *data, int argc, char *argv[])
{
	data->n_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_eat = ft_atoi(argv[5]);
	else
		data->max_eat = -1;
	data->death = 0;
	data->all_eaten = 0;
	data->start_time = timenow();
	if (error_values(data) == 1)
		return (1);
	init_philo(data);
	if (init_mutex(data) == 1)
		return (1);
	return (0);
}
