/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 04:46:26 by cschwalm          #+#    #+#             */
/*   Updated: 2022/04/09 04:46:37 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				philo_id;
	int				fork_l;
	int				fork_r;
	int				n_times_eat;
	long long		start_last_meal;
	pthread_t		thread;
	pthread_mutex_t	eats;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				n_philos;
	int				death;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				max_eat;
	int				all_eaten;
	long long		start_time;
	pthread_mutex_t	message;
	pthread_mutex_t	fork[250];
	t_philo			philo[250];
}	t_data;

int			error_input(int argc, char *argv[]);
int			error_init(void);
int			init(t_data *philos, int argc, char *argv[]);
int			error_values(t_data *data);
int			ft_atoi(const char *nptr);
long long	timenow(void);
void		message(t_philo *philo, char *string);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
int			free_var(t_data *data);

#endif
