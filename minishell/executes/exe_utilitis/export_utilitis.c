/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utilitis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 04:13:06 by cschwalm          #+#    #+#             */
/*   Updated: 2022/05/29 13:51:47 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	compare_strings(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

void	sort_exp_strings(t_data *data)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 1;
	temp = data->env_strings[i];
	while (data->env_strings[i])
	{
		while (data->env_strings[j])
		{
			if (compare_strings(data->env_strings[i], data->env_strings[j]) > 0)
			{
				temp = data->env_strings[i];
				data->env_strings[i] = data->env_strings[j];
				data->env_strings[j] = temp;
			}
			j++;
		}
		i++;
		j = (i + 1);
	}
}

int	check_for_variables(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		while (cmd[i] == ' ' || cmd[i] == '"' || cmd[i] == '\'')
		{
			i++;
			if (ft_isalnum(cmd[i]))
				return (1);
		}
		i++;
	}
	return (0);
}
