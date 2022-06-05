/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:22:00 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/02 06:48:52 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_var_index(t_data *data, char *var)
{
	int	i;

	i = 0;
	while (data->env_strings[i] != NULL)
	{
		if (ft_strncmp(data->env_strings[i], var, ft_strlen(var)) == 0
			&& (data->env_strings[i][ft_strlen(var)] == '\0'
			|| data->env_strings[i][ft_strlen(var)] == '='))
			return (i);
		i++;
	}
	return (-1);
}

void	unset_delete_var(t_data *data, int index)
{
	int	start;

	start = 1;
	if (index != -1)
	{
		ft_free((void *) &data->env_strings[index], NULL, NULL);
		while (data->env_strings[index] != NULL || start == 1)
		{
			start = 0;
			data->env_strings[index] = data->env_strings[index + 1];
			index++;
		}
		ft_free((void *) &data->env_strings[index], NULL, NULL);
	}
	data->status_code = 0;
}

void	search_args_and_destroy(t_data *data, char *cmd, char *arg)
{
	int		i;
	int		j;
	int		index;
	int		len;

	i = 0;
	j = 0;
	while (cmd[i] != '\0')
	{
		len = 0;
		while (cmd[i] && cmd[i] == ' ')
			i++;
		j = (i - 1);
		while (cmd[++j] && cmd[j] != ' ')
			len++;
		j = 0;
		arg = (char *)ft_calloc((len + 1), sizeof(char));
		if (!arg)
			err_handler(data, 1, arg, "func unset - allocation failed");
		while (j < len)
			arg[j++] = cmd[i++];
		index = find_var_index(data, arg);
		unset_delete_var(data, index);
		ft_free((void *) &arg, NULL, NULL);
	}
}

void	unset_var(t_data *data, char *cmd)
{
	int		i;
	char	*tmp;
	char	*arg;

	i = 0;
	arg = NULL;
	while ((cmd[i]) && (cmd[i] != ' ' && cmd[i] != '"' && cmd[i] != '\''))
		i++;
	while (cmd[i] && !ft_isalpha(cmd[i]))
		i++;
	tmp = ft_strdup(cmd + i);
	search_args_and_destroy(data, tmp, arg);
	ft_free((void *) &tmp, NULL, NULL);
}

void	ft_unset(t_data *data, int cmd_numb)
{
	if (check_for_variables(data->t_commands[cmd_numb]->command))
		unset_var(data, data->t_commands[cmd_numb]->command);
}
