/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:46:17 by tguth             #+#    #+#             */
/*   Updated: 2022/05/17 11:59:24 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	before_exe_re(t_data *data, int cmd_numb)
{
	if (data->t_commands[cmd_numb]->input_fd != STDIN_FILENO)
	{
		if (dup2(data->t_commands[cmd_numb]->input_fd, STDIN_FILENO) < 0)
			err_handler(data, 1, NULL, "Error dup2, redirecting STDIN");
		close(data->t_commands[cmd_numb]->input_fd);
		data->redirect_stat[1] = 1;
	}
	if (data->t_commands[cmd_numb]->output_fd != STDOUT_FILENO)
	{
		if (dup2(data->t_commands[cmd_numb]->output_fd, STDOUT_FILENO) < 0)
			err_handler(data, 1, NULL, "Error dup2, redirecting STDOUT");
		close(data->t_commands[cmd_numb]->output_fd);
		data->redirect_stat[0] = 1;
	}
}

void	before_exe_pipe(t_data *data, int cmd_numb)
{
	if (data->count_pipe < 1)
		return ;
	if (data->t_commands[cmd_numb]->output_fd == STDOUT_FILENO)
	{
		if (cmd_numb < data->count_pipe - 1)
		{
			if (dup2(data->pipes_fd[cmd_numb][1], STDOUT_FILENO) < 0)
				err_handler(data, 1, NULL,
					"Error dup2, redirecting pipes STDOUT");
			close(data->pipes_fd[cmd_numb][1]);
			data->redirect_stat[0] = 1;
		}
	}
	if (data->t_commands[cmd_numb]->input_fd == STDIN_FILENO)
	{
		if (cmd_numb > 0)
		{
			if (dup2(data->pipes_fd[cmd_numb - 1][0], STDIN_FILENO) < 0)
				err_handler(data, 1, NULL,
					"Error dup2, redirecting pipes STDOUT");
			close(data->pipes_fd[cmd_numb - 1][1]);
			data->redirect_stat[1] = 1;
		}
	}
}

void	after_exe(t_data *data)
{
	if (data->redirect_stat[1] == 1)
	{
		if (dup2(data->stdin_cpy, STDIN_FILENO) < 0)
			err_handler(data, 1, NULL, "Error dup2, redirecting STDIN");
		data->redirect_stat[1] = 0;
	}
	if (data->redirect_stat[0] == 1)
	{
		if (dup2(data->stdout_cpy, STDOUT_FILENO) < 0)
			err_handler(data, 1, NULL, "Error dup2, redirecting STDOUT");
		data->redirect_stat[0] = 0;
	}
}
