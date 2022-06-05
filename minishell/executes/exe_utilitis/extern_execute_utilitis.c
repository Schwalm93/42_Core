/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extern_execute_utilitis.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 02:04:14 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/02 06:45:20 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**get_path(t_data *data)
{
	char	**paths;
	char	*val;

	val = get_var(data, "PATH");
	paths = ft_split(val, ':');
	return (paths);
}

void	pre_check_path(t_data *data, char *path, char *func, char **tmp_2)
{
	char	*tmp;

	if (func[0] != '/' && func[0] != '\\')
	{
		tmp = ft_strjoin(path, "/");
		*tmp_2 = ft_strjoin(tmp, func);
		ft_free((void *) &tmp, NULL, NULL);
	}
	else
		*tmp_2 = copy_and_cut_str(data, func);
}

int	check_path(t_data *data, char *path, char *func, int exce_file)
{
	char	*tmp_2;
	int		check_stat;

	pre_check_path(data, path, func, &tmp_2);
	if (exce_file == 0)
		check_stat = X_OK;
	else
		check_stat = F_OK;
	if (access(tmp_2, check_stat) == 0)
	{
		ft_free((void *) &tmp_2, NULL, NULL);
		return (0);
	}
	else
	{
		ft_free((void *) &tmp_2, NULL, NULL);
		return (-1);
	}
}

char	*copy_and_cut_str(t_data *data, char *func)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = ft_strlen(func);
	tmp = (char *) ft_calloc(i + 1, sizeof(char));
	if (!tmp)
		err_handler(data, 1, tmp, "Allocation failed\n");
	i = 0;
	while (func[i])
	{
		if (func[i] != '"' && func[i] != '\'')
		{
			if (func[i] == '/' && ft_isalpha(func[i + 1]))
				tmp[j++] = func[i];
			else if (func[i] != '/')
				tmp[j++] = func[i];
		}
		i++;
	}
	return (tmp);
}
