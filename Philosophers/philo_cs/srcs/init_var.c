/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:04:11 by cschwalm          #+#    #+#             */
/*   Updated: 2022/03/31 01:02:08 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void init_var(t_data *philos, int argc, char *argv[])
{
	int i;

	i = 0;
	philos->n_philos = ft_atoi(argv[1]);
	philos->time_to_die = ft_atoi(argv[2]);
	philos->time_to_eat = ft_atoi(argv[3]);
	philos->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philos->max_eat = ft_atoi(argv[5]);
	philos->death = 0;
	philos->start_time = timestemp();
	while (i < philos->n_philos)
	{
		philos->att[i].philo_id = (i + 1);
		if (i == 0)
			philos->att[i].fork_l = philos->n_philos;
		else
			philos->att[i].fork_l = i;
		philos->att[i].fork_r = (i + 1);
		philos->att[i].n_times_eat = 0;
		i++;
	}
	// alle werte über 0 + Anzahl Philos absichern (0 oder >250 = gefehler)
}
