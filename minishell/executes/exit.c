/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:41:55 by tguth             #+#    #+#             */
/*   Updated: 2022/05/28 12:42:10 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	re_init(t_data *data)
{
	int	i;

	i = -1;
	if (data->t_commands != NULL)
	{
		while (data->t_commands[++i] != NULL)
		{
			if (data->t_commands[i]->command != NULL)
				ft_free((void *) &data->t_commands[i]->command, NULL, NULL);
			ft_free((void *) &data->t_commands[i], NULL, NULL);
		}
	}
	i = -1;
	if (data->pipes_fd != NULL)
	{
		while (data->pipes_fd[++i])
			free(data->pipes_fd[i]);
		free(data->pipes_fd);
		data->pipes_fd = NULL;
	}
	ft_free((void *) &data->t_commands, NULL, NULL);
	ft_free((void *) &data->line, NULL, NULL);
	data->count_pipe = 0;
}

void	ft_exit(t_data *data)
{
	re_init(data);
	ft_free(NULL, (void *) &data->env_strings, NULL);
	rl_clear_history();
	exit(0);
}
