/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:00:36 by tguth             #+#    #+#             */
/*   Updated: 2022/06/02 04:10:57 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

int	is_all_white_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (is_white_space(str[i]) == 0)
			return (0);
	}
	return (1);
}

void	command_trim_helper(t_data *data, int len, char **str, char **temp)
{
	int	status_len;
	int	code;
	int	i;
	int	start;

	i = 0;
	start = get_first_c(*str);
	while (i < len && (*str)[start] != '\0')
	{
		if ((*str)[start] == '$' && (*str)[start + 1] == '?')
		{
			code = data->status_code;
			status_len = data->status_len;
			i += (status_len - 1);
			while (status_len-- > 0)
			{
				(*temp)[i--] = (code % 10) + 48;
				code = code / 10;
			}
			start += 2;
			i += (data->status_len + 1);
		}
		else
			(*temp)[i++] = (*str)[start++];
	}
}

void	command_trim(t_data *data, int cmd_numb)
{
	char	*temp;
	int		len;

	temp = NULL;
	if (data->t_commands[cmd_numb]->command != NULL)
	{
		len = trim_strlen(data->t_commands[cmd_numb]->command)
			+ count_status(data, data->t_commands[cmd_numb]->command);
		temp = ft_calloc(len + 1, sizeof(char));
		if (!temp)
			err_handler(data, 1, NULL, "Error can not allocate");
		command_trim_helper(data, len, &(data->t_commands[cmd_numb]->command),
			&temp);
		ft_free((void *) &data->t_commands[cmd_numb]->command, NULL, NULL);
		data->t_commands[cmd_numb]->command = temp;
	}
}
