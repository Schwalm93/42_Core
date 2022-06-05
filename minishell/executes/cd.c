/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:42:02 by tguth             #+#    #+#             */
/*   Updated: 2022/05/29 07:26:15 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_sec_last_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	i -= 2;
	if (i < 0)
		return (NULL);
	else
		return (str[i]);
}

void	ft_cd_backward(t_data *data, char **temp, char **cmd)
{
	char	*back;

	back = ft_cd_back(data, temp, 1, cmd);
	if (check_path(data, back, *cmd, 1) == 0)
		ft_create_cd(data, back, cmd);
	else
	{
		data->status_code = 1;
		ft_free((void *) cmd, NULL, NULL);
		err_handler(data, 1, back, "No such file or directory");
	}
	ft_free((void *) &back, NULL, NULL);
}

void	cd_home(t_data *data, char **cmd)
{
	char	*temp;

	temp = get_var(data, "HOME");
	if (temp == NULL)
	{
		ft_free((void *) cmd, NULL, NULL);
		err_handler(data, 1, NULL, "bash: cd: Home not set");
	}
	ft_set_cd(data, ft_strdup(temp), cmd, NULL);
}

void	ft_cd(t_data *data, int cmd_numb)
{
	int		status;
	char	*cmd;

	cmd = ft_check_master(data, data->t_commands[cmd_numb]->command,
			&status);
	ft_free((void *) &data->t_commands[cmd_numb]->command, NULL, NULL);
	if (status == 2)
		data->status_code = 0;
	else if (status == 0)
		cd_home(data, &cmd);
	else if (status == 1)
	{
		ft_cd_back(data, (ft_split(data->path, '/')), 0, &cmd);
		chdir("..");
	}
	else if (status == 3)
		ft_create_cd(data, data->path, &cmd);
	else if (status == 4)
		ft_cd_backward(data, (ft_split(data->path, '/')), &cmd);
	else
		data->status_code = 1;
	data->status_code = 0;
	ft_free((void *) &cmd, NULL, NULL);
}
