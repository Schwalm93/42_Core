/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:04:13 by cschwalm          #+#    #+#             */
/*   Updated: 2022/03/31 00:34:58 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t mutex;

void	*function(void *vargp)
{
	t_data *philo2;
	if (vargp)
		philo2 = vargp;


	pthread_mutex_lock(&mutex);
	sleep(3);
	pthread_mutex_unlock(&mutex);
	printf("Test2\n");
	sleep(1);
	printf("Test3\n");
	sleep(2);
	printf("Test4\n");
	sleep(3);
	printf("Test5\n");	
}

/*void	philo(t_data *philos)
{
	int i;

	i = 0;
	while (i <= philos->n_philos)
	{
		if (pthread_create(&philos->att[i].thread, NULL, function, &philos) != 0)
			exit(1);
		i++;
	}
	i = 1;
	while (i <= philos->n_philos)
	{
		if (pthread_join(philos->att[i].thread, NULL) != 0)
			exit(1);
		i++;
	}

}
*/
int	main(int argc, char *argv[])
{
	t_data philos;
	int i;

	i = 1;
	pthread_mutex_init(&mutex, NULL);
	error_input(argc, argv);
	printf("Test1\n");

	init_var(&philos, argc, argv);
	while (i <= philos.n_philos)
	{
		if (pthread_create(&philos.att[i].thread, NULL, function, &philos) != 0)
			exit(1);
		i++;
	}
	i = 1;
	while (i <= philos.n_philos)
	{
		if (pthread_join(philos.att[i].thread, NULL) != 0)
			exit(1);
		i++;
	}
//	philo(&philos);
	pthread_mutex_destroy(&mutex);
//	free_var();
	return 0;
}


// pthread_t t1;
// if (pthread_create(&t1, NULL, &function, NULL) != 0)
// { Error }
// if (pthread_join(t1, NULL) != 0)
// { Error }