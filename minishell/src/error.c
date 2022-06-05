/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:58:59 by tguth             #+#    #+#             */
/*   Updated: 2022/06/02 08:41:18 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	err_handler(t_data *data, int fatal_err, void *mem, char *err_str)
{
	if (data->redirect_stat[1] == 1)
	{
		if (dup2(data->stdin_cpy, STDIN_FILENO) < 0)
			exit(1);
		close(data->stdin_cpy);
	}
	if (data->redirect_stat[0] == 1)
	{
		if (dup2(data->stdout_cpy, STDOUT_FILENO) < 0)
			exit(1);
		close(data->stdout_cpy);
	}
	printf("%s", err_str);
	ft_free((void *) &mem, NULL, NULL);
	re_init(data);
	if (fatal_err == 0)
	{
		close(data->stdin_cpy);
		close(data->stdout_cpy);
		exit(1);
	}
	else
		printf("\b\b\n");
	run(data);
}
