/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:31:00 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/02 06:48:20 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_pid = 0;

int	run_helper(t_data *data, int i)
{
	data->cmd_numb = i;
	check_all_paths(data);
	redirect(data, i);
	before_exe_re(data, i);
	before_exe_pipe(data, i);
	select_exe(data, i);
	after_exe(data);
	return (i);
}

void	init_data(t_data *data, char **environ)
{
	printf("\n---------------------------------------------\n");
	printf("---------- Minishell Callback Cats ----------\n");
	printf("---------------------------------------------\n\n");
	signal_check(data);
	get_env_len(data, environ);
	data->env_strings = init_env(environ, data);
	data->t_commands = NULL;
	data->count_pipe = 0;
	data->stdin_cpy = dup(STDIN_FILENO);
	data->stdout_cpy = dup (STDOUT_FILENO);
	data->redirect_stat[0] = 0;
	data->redirect_stat[1] = 0;
	if (data->stdin_cpy == -1 || data->stdout_cpy == -1)
		err_handler(data, 0, NULL, "can not dup STDIN or STDOUT");
	data->line = NULL;
	data->status_code = 0;
	data->status_len = 1;
}

void	set_status(int *status, t_data *data)
{
	if (*status == 256)
		data->status_code = 127;
	else if (*status == 512)
		data->status_code = 2;
	else if (*status != 0)
		data->status_code = 1;
	else
		data->status_code = 0;
	*status = 0;
}

void	run(t_data *data)
{
	int	i;
	int	y;
	int	status;

	i = -1;
	y = 0;
	status = 0;
	while (1)
	{
		read_input(data);
		parse_input(data);
		ft_pipe(data);
		if (data->line[0] != '\0' && is_all_white_space(data->line) != 1)
			add_history(data->line);
		while (data->t_commands[++i] != NULL && data->line[0] != '\0'
			&& is_all_white_space(data->line) != 1)
			i = run_helper(data, i);
		y = waitpid(-1, &status, 0);
		while (y > 0)
			y = waitpid(-1, &status, 0);
		set_status(&status, data);
		g_pid = 0;
		re_init(data);
		i = -1;
	}
}

int	main(void)
{
	t_data		data;
	extern char	**environ;

	data.pipes_fd = NULL;
	init_data(&data, environ);
	getcwd(data.path, PATH_MAX);
	run(&data);
	return (0);
}
