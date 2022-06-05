/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 01:45:54 by cschwalm          #+#    #+#             */
/*   Updated: 2022/05/29 14:08:34 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_export(t_data *data)
{
	int	i;

	sort_exp_strings(data);
	i = 0;
	while (data->env_strings[i])
	{
		printf("declare -x %s\n", data->env_strings[i]);
		i++;
	}
}

int	check_is_arg_valid(t_data *data, char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[0])
			|| (!ft_isalnum(arg[i]) && arg[i] != '=' && arg[i] != '/'))
		{
			printf("minishell: export: '%s': not a valid identifier\n", arg);
			data->status_code = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

void	store_args(t_data *data, char *cmd, char *arg, int *print)
{
	int		i;
	int		j;
	int		len;

	i = 0;
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
			err_handler(data, 1, arg, "func export - allocation failed");
		while (j < len)
			arg[j++] = cmd[i++];
		if (check_is_arg_valid(data, arg))
			set_env(data, arg);
		else
			*print = 0;
		ft_free((void *) &arg, NULL, NULL);
	}
}

void	set_new_export_var(t_data *data, char *cmd, int *print)
{
	int		i;
	char	*tmp;
	char	*arg;

	i = 0;
	arg = NULL;
	while ((cmd[i]) && (cmd[i] != ' ' && cmd[i] != '"' && cmd[i] != '\''))
		i++;
	while (cmd[i] && !ft_isalnum(cmd[i]))
		i++;
	tmp = ft_strdup(cmd + i);
	store_args(data, tmp, arg, print);
	ft_free((void *) &tmp, NULL, NULL);
}

void	ft_export(t_data *data, int cmd_numb)
{
	int	print;

	print = 1;
	data->status_code = 0;
	if (check_for_variables(data->t_commands[cmd_numb]->command))
		set_new_export_var(data, data->t_commands[cmd_numb]->command, &print);
	if (print == 1)
		print_export(data);
}
