/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:04:13 by cschwalm          #+#    #+#             */
/*   Updated: 2022/04/20 01:13:55 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*function(void *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	if (data)
		philo = data;
	if (philo->philo_id % 2 == 0)
		usleep(15000);
	if (philo->data->n_philos == 1)
	{
		usleep(philo->data->time_to_die * 1000);
		message(philo, "died");
		philo->data->death = 1;
	}
	while (philo->data->death == 0 && philo->data->all_eaten != 1)
	{
		eating(philo);
		message(philo, "is sleeping");
		sleeping(philo);
		message(philo, "is thinking");
		i++;
	}
	return (NULL);
}

void	check_max_eat(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->n_philos && data->max_eat != -1
		&& data->death == 0
		&& data->philo[i].n_times_eat >= data->max_eat)
		i++;
	if (data->death == 0 && data->max_eat != -1 && i == data->n_philos)
	{
		pthread_mutex_lock(&data->message);
		data->all_eaten = 1;
		usleep(15000);
		pthread_mutex_unlock(&data->message);
	}
}

void	check_status(t_data *data)
{
	int	i;

	while (data->death == 0 && data->all_eaten != 1)
	{
		i = 1;
		while (i < data->n_philos && data->death == 0)
		{
			pthread_mutex_lock(&data->philo[i].eats);
			if (timenow() - data->philo[i].start_last_meal >= data->time_to_die)
			{
				message(data->philo + i, "is died");
				data->death = 1;
			}
			pthread_mutex_unlock(&data->philo[i].eats);
			i++;
			usleep(100);
		}
		check_max_eat(data);
	}
}

int	main(int argc, char *argv[])
{
	t_data			data;
	int				i;

	i = 1;
	if (error_input(argc, argv) == 1 || init(&data, argc, argv) == 1)
		return (1);
	while (i <= data.n_philos)
	{
		if (pthread_create(&data.philo[i].thread,
				NULL, function, &data.philo[i]) != 0)
			error_init();
		i++;
	}
	check_status(&data);
	if (free_var(&data) == 1)
		return (1);
	return (0);
}
