/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestemp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:22:31 by cschwalm          #+#    #+#             */
/*   Updated: 2022/03/31 00:56:26 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	timestemp()
{
	struct	timeval time;
	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
