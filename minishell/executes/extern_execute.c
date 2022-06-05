/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extern_execute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:03:14 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/02 06:48:52 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_func(t_data *data, int cmd_numb)
{
	int		i;
	char	*tmp;
	char	*cmd;

	i = 0;
	cmd = data->t_commands[cmd_numb]->command;
	if (data->t_commands[cmd_numb]->command[0] == '\''
		&& data->t_commands[cmd_numb]->command
		[ft_strlen(data->t_commands[cmd_numb]->command) - 1] == '\'')
		return (ft_strdup(data->t_commands[cmd_numb]->command));
	while (cmd[i] != ' ' && cmd[i])
		i++;
	tmp = ft_calloc(i + 1, sizeof(char));
	if (!tmp)
		err_handler(data, 1, NULL, "Error can not allocate");
	i = 0;
	while (cmd[i] != ' ' && cmd[i])
	{
		tmp[i] = cmd[i];
		i++;
	}
	return (tmp);
}

void	ex_exe_supp(t_data *data, char *exe_path, char **argv, char **env)
{
	g_pid = fork();
	data->status_code = 0;
	if (g_pid == 0)
	{
		execve(exe_path, argv, env);
	}
}

char	*set_execute_paths(t_data *data, char *path, char *func, int *start)
{
	if (func[0] == '/')
	{
		*start = 1;
		return (copy_and_cut_str(data, func));
	}
	else
		return (extern_exe_support(start, path, func));
}

void	extern_execute(t_data *data, int cmd_numb, int start)
{
	char	*func;
	char	**paths;
	char	*exe_path;
	char	**argv;
	int		i;

	i = -1;
	exe_path = get_func(data, cmd_numb);
	func = copy_and_cut_str(data, exe_path);
	ft_free((void *) &exe_path, NULL, NULL);
	argv = ft_split(data->t_commands[cmd_numb]->command, ' ');
	if (check_path(data, data->path, func, 0) == 0 && start == 0)
		exe_path = extern_exe_support(&start, data->path, func);
	paths = get_path(data);
	while (paths[++i] && start == 0)
	{
		if (check_path(data, paths[i], func, 0) == 0)
			exe_path = set_execute_paths(data, paths[i], func, &start);
	}
	if (start == 1)
		ex_exe_supp(data, exe_path, argv, data->env_strings);
	ft_free((void *) &func, (void *) &argv, NULL);
	ft_free((void *) &exe_path, (void *) &paths, NULL);
}
