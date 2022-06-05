/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:29:10 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/02 06:48:52 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_var(t_data *data, char *var)
{
	char	*value;
	int		index;

	index = find_var_index(data, var);
	if (index == -1)
		return (NULL);
	value = &data->env_strings[index][ft_strlen(var) + 1];
	return (value);
}

void	set_env_var(t_data *data, char *var, char *name)
{
	int		index;
	char	*temp;

	index = find_var_index(data, name);
	ft_free((void *) &data->env_strings[index], NULL, NULL);
	temp = ft_strjoin(name, "=");
	data->env_strings[index] = ft_strjoin(temp, var);
	ft_memset(data->path, '\0', PATH_MAX);
	ft_strlcpy(data->path, var, ft_strlen(var) + 1);
	ft_free((void *) &temp, NULL, NULL);
	ft_free((void *) &var, NULL, NULL);
}

void	get_env_len(t_data *data, char **environ)
{
	int	len;

	len = 0;
	while (environ[len])
		len++;
	data->env_len = len;
}

char	**init_env(char **environ, t_data *data)
{
	int		i;
	char	**env;

	i = -1;
	env = (char **)malloc((data->env_len + 1) * sizeof(char *));
	if (!env)
		err_handler(data, 1, (void *)env, "env - Allocation failed");
	while (environ[++i])
		env[i] = ft_strdup(environ[i]);
	env[i] = NULL;
	return (env);
}

void	print_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env_strings[i])
		printf("%s\n", data->env_strings[i++]);
	data->status_code = 0;
}
