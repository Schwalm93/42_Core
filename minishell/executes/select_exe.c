/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_exe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:17:02 by tguth             #+#    #+#             */
/*   Updated: 2022/06/02 06:44:13 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	err_err_handler(t_data *data, int i)
{
	char	*func;
	char	*temp;

	func = get_func(data, i);
	temp = ft_strjoin(func, ": command not found");
	free(func);
	data->status_code = 127;
	err_handler(data, 1, temp, temp);
}

void	check_all_paths_helper(char **paths, t_data *data, int i)
{
	int		j;
	int		found;
	char	*temp;
	char	*name;

	j = -1;
	found = 0;
	name = get_func(data, i);
	temp = copy_and_cut_str(data, name);
	ft_free((void *) &name, NULL, NULL);
	if (paths != NULL)
	{
		while (paths[++j])
			if (!(check_path(data, paths[j], temp, 0)))
				found = 1;
	}
	if (!(check_path(data, data->path, temp, 0)))
		found = 1;
	ft_free((void *) &temp, NULL, NULL);
	if (!found)
	{
		ft_free(NULL, (void *) &paths, NULL);
		err_err_handler(data, i);
	}
}

void	check_all_paths(t_data *data)
{
	int		i;
	char	**paths;

	i = -1;
	paths = get_path(data);
	while (data->t_commands[++i])
	{
		if (data->t_commands[i]->id == -1)
			check_all_paths_helper(paths, data, i);
	}
	ft_free(NULL, (void *) &paths, NULL);
}

void	select_exe(t_data *data, int cmd_numb)
{
	int	id;

	id = data->t_commands[cmd_numb]->id;
	if (id == 0)
		err_handler(data, 1, NULL, "can not select execute!");
	else if (id == -1)
		extern_execute(data, cmd_numb, 0);
	else if (id == 1)
		ft_echo(data, cmd_numb);
	else if (id == 2)
		ft_cd(data, cmd_numb);
	else if (id == 3)
		ft_pwd(data);
	else if (id == 4)
		ft_unset(data, cmd_numb);
	else if (id == 5)
		print_env(data);
	else if (id == 6)
		ft_exit(data);
	else if (id == 7)
		ft_export(data, cmd_numb);
}
