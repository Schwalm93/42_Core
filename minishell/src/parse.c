/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:18:21 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/02 06:48:52 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**init_cmd(char *str, t_data *data)
{
	char	**cmd;
	int		i;
	int		temp;

	i = 0;
	cmd = ft_calloc(data->count_pipe, sizeof (char *));
	if (!cmd)
		err_handler(data, 1, cmd, "Error can not create struct");
	while (i < data->count_pipe)
	{
		temp = ft_strlen(str);
		cmd[i] = ft_calloc(temp + 1, sizeof(char));
		if (!cmd[i])
			err_handler(data, 1, cmd, "Error can not create struct");
		i++;
	}
	return (cmd);
}

t_command	**save_command_structs(t_data *data, char **cmd, int count)
{
	int			i;
	t_command	*temp_command;
	t_command	**commands;

	i = 0;
	commands = (t_command **) ft_calloc(count + 1, sizeof(t_command *));
	if (!commands)
		err_handler(data, 1, commands, "Error malloc command struct");
	while (i < count)
	{
		temp_command = (t_command *) ft_calloc(1, sizeof(t_command));
		if (!temp_command)
		{
			err_handler(data, 1, commands, "Error malloc command struct");
			break ;
		}
		temp_command->command = cmd[i];
		temp_command->input_fd = STDIN_FILENO;
		temp_command->output_fd = STDOUT_FILENO;
		commands[i] = temp_command;
		i++;
	}
	ft_free((void *) &cmd, NULL, NULL);
	return (commands);
}

t_command	**save_commands(char *str, t_data *data)
{
	int		j;
	char	**cmd;

	cmd = ft_init_cmd(data, str, &j);
	ft_helper(data, str, j, &cmd);
	return (save_command_structs(data, cmd, data->count_pipe));
}

int	set_id(char *command)
{
	if (!ft_input_strncmp(command, "echo", ft_strlen("echo")))
		return (1);
	else if (!ft_input_strncmp(command, "cd", ft_strlen("cd")))
		return (2);
	else if (!ft_input_strncmp(command, "pwd", ft_strlen("pwd")))
		return (3);
	else if (!ft_input_strncmp(command, "unset", ft_strlen("unset")))
		return (4);
	else if (!ft_input_strncmp(command, "env", ft_strlen("env")))
		return (5);
	else if (!ft_input_strncmp(command, "exit", ft_strlen("exit")))
		return (6);
	else if (!ft_input_strncmp(command, "export", ft_strlen("export")))
		return (7);
	else
		return (-1);
}

void	parse_input(t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	num_pipes(data);
	data->t_commands = save_commands(data->line, data);
	while (i < data->count_pipe)
	{
		command_trim(data, i);
		data->t_commands[i]->id = set_id(data->t_commands[i]->command);
		if (data->t_commands[i]->id != 1 && data->t_commands[i]->id != -1)
		{
			tmp = ft_strtrim(data->t_commands[i]->command, "\'");
			free(data->t_commands[i]->command);
			data->t_commands[i]->command = tmp;
		}
		i++;
	}
}
