/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:21:45 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/02 06:48:52 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_existing(t_data *data, char *var_value, int index)
{
	int		length;
	int		i;
	char	*new_var;

	i = 0;
	length = ft_strlen(var_value);
	new_var = ft_calloc(length + 1, sizeof(char));
	if (!new_var)
		err_handler(data, 1, NULL, "Error can not allocate");
	ft_free((void *) &data->env_strings[index], NULL, NULL);
	while (var_value[i] != '\0')
	{
		new_var[i] = var_value[i];
		i++;
	}
	data->env_strings[index] = new_var;
}

void	set_not_existing(t_data *data, char *var_value)
{
	int		i;
	char	**env;

	i = 0;
	while (data->env_strings[i])
		i++;
	env = (char **)ft_calloc((i + 2), sizeof(char *));
	if (!env)
		err_handler(data, 1, NULL, "Env - Allocation Failed");
	i = 0;
	while (data->env_strings[i] != NULL)
	{
		env[i] = data->env_strings[i];
		i++;
	}
	ft_free(NULL, NULL, (void *) &data->env_strings);
	env[i] = ft_strdup(var_value);
	i++;
	env[i] = NULL;
	data->env_strings = env;
}

char	*find_var_set(t_data *data, char *var_value)
{
	int		i;
	char	*var;

	i = 0;
	while (var_value[i] != '=' && var_value[i] != '\0')
		i++;
	var = (char *)ft_calloc((i + 1), sizeof(char));
	if (!var)
		err_handler(data, 1, NULL, "Error can not allocate");
	i = 0;
	while (var_value[i] != '=' && var_value[i] != '\0')
	{
		var[i] = var_value[i];
		i++;
	}
	return (var);
}

void	set_env(t_data *data, char *var_value)
{
	int		index;
	char	*var;

	var = find_var_set(data, var_value);
	index = find_var_index(data, var);
	if (index == -1)
		set_not_existing(data, var_value);
	else
		set_existing(data, var_value, index);
	ft_free((void *) &var, NULL, NULL);
	data->status_code = 0;
}
