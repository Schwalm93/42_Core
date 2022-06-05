/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_supp_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 07:41:46 by tguth             #+#    #+#             */
/*   Updated: 2022/06/02 06:48:52 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*check_cd_name(t_data *data, char ***temp)
{
	char	*name;

	name = get_sec_last_str(*temp);
	if (name == NULL)
	{
		chdir("/");
		set_env_var(data, ft_strdup("/"), "PWD");
		ft_free(NULL, (void *) temp, NULL);
		return (NULL);
	}
	else
		return (name);
}

void	ft_set_cd(t_data *data, char *path, char **cmd, char **tmp)
{
	char	*temp;
	int		index;

	ft_free((void *) cmd, NULL, NULL);
	ft_free((void *) tmp, NULL, NULL);
	if (path[ft_strlen(path) - 1] == '/')
	{
		temp = ft_substr(path, 0, ft_strlen(path) - 1);
		ft_free((void *) &path, NULL, NULL);
	}
	else
		temp = path;
	if (access(temp, F_OK) != 0)
	{
		data->status_code = 1;
		free(temp);
		err_handler(data, 1, NULL, "No such file or directory");
	}
	chdir(temp);
	index = find_var_index(data, "PWD");
	if (index != -1)
		set_env_var(data, temp, "PWD");
	else
		free(temp);
}

void	ft_create_cd(t_data *data, char *str, char **cmd)
{
	char	*tmp;

	if (str[1] != '\0')
		tmp = ft_strjoin(str, "/");
	else
		tmp = ft_strdup(str);
	ft_set_cd(data, ft_strjoin(tmp, *cmd), cmd, &tmp);
}

int	ft_check_cd_helper(char **sol, char **temp, int i, int index)
{
	if (i == 0)
	{
		ft_free((void *) sol, NULL, NULL);
		*sol = ft_strdup(*temp + index);
	}
	else if (i == 1)
	{
		free(*sol);
		*sol = ft_strdup(*temp + index + 1);
	}
	else
	{
		free(*sol);
		*sol = ft_strdup(*temp + index + 2);
	}
	return (3);
}
