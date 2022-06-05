/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:00:52 by tguth             #+#    #+#             */
/*   Updated: 2022/06/02 06:48:52 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pipe(t_data *data)
{
	int	i;

	i = -1;
	if (data->count_pipe == 1)
		return ;
	data->pipes_fd = ft_calloc(data->count_pipe, sizeof(int *));
	if (!data->pipes_fd)
		err_handler(data, 0, data->pipes_fd, "Can not create 2d Arry pipe");
	while (++i < data->count_pipe - 1)
	{
		data->pipes_fd[i] = ft_calloc(2, sizeof(int));
		if (!data->pipes_fd[i])
			err_handler(data, 0, data->pipes_fd[i], "Can not create Arr_pipe");
		if (pipe(data->pipes_fd[i]) == -1)
			err_handler(data, 0, data->pipes_fd[i], "Can not create pipes");
	}
	data->pipes_fd[i] = NULL;
}
