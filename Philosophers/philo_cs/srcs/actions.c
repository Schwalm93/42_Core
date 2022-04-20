/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 07:55:22 by cschwalm          #+#    #+#             */
/*   Updated: 2022/04/09 04:48:19 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	message(t_philo *philo, char *string)
{
	pthread_mutex_lock(&philo->data->message);
	if (philo->data->death == 0 && philo->data->all_eaten != 1)
	{
		printf("%lld - %d.  %s\n", (timenow() - philo->data->start_time),
			philo->philo_id, string);
	}
	pthread_mutex_unlock(&philo->data->message);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->fork_l]);
	message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->fork[philo->fork_r]);
	message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->eats);
	message(philo, "is eating");
	philo->start_last_meal = timenow();
	pthread_mutex_unlock(&philo->eats);
	usleep((philo->data->time_to_eat * 1000));
	philo->n_times_eat++;
	pthread_mutex_unlock(&philo->data->fork[philo->fork_l]);
	pthread_mutex_unlock(&philo->data->fork[philo->fork_r]);
}

void	sleeping(t_philo *philo)
{
	usleep((philo->data->time_to_sleep * 1000));
}
