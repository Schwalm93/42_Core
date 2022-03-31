/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 04:46:26 by cschwalm          #+#    #+#             */
/*   Updated: 2022/03/29 11:26:14 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_attribute
{
	int	philo_id;
	int	fork_l;
	int	fork_r;
	int	n_times_eat;
	pthread_t	thread;
//	t_data	*data;
} t_attribute;

typedef struct s_data
{
	int	philo;
	int n_philos;
	int death;
	int	time_to_eat;
	int	time_to_die;
	int	time_to_sleep;
	int	max_eat;
	long long	start_time;
	t_attribute	att[301];
//	pthread_mutex_t	fork[301];
//	pthread_mutex_t	message;
//	int	all_eaten;
} t_data;

void	error_input(int argc, char *argv[]);
void init_var(t_data *philos, int argc, char *argv[]);
int	ft_atoi(const char *nptr);
long long	timestemp();

#endif
