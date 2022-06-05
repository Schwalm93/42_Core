/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:59:17 by tguth             #+#    #+#             */
/*   Updated: 2022/05/26 06:18:08 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	num_pipes(t_data *data)
{
	int		i;
	int		count;
	int		quotes;
	char	c;

	i = 0;
	count = 1;
	quotes = 0;
	while (data->line[i] != '\0')
	{
		if (i == 0)
			check_i_zero(data->line[i++], &c, &count, &quotes);
		else
			check_i_not_zero(&data->line[i++], &c, &count, &quotes);
	}
	data->count_pipe = count;
}

char	*find_path(char **old_path)
{
	char	*new_path;
	char	*temp;
	int		start;
	int		end;

	start = get_first_c(*old_path);
	end = get_next_space(*old_path, start);
	new_path = ft_substr(*old_path, start, end - start);
	temp = ft_substr(*old_path, end + 1, ft_strlen(*old_path) - (end + 1));
	ft_free((void *) &*old_path, NULL, NULL);
	*old_path = temp;
	return (new_path);
}

char	**ft_init_cmd(t_data *data, char *str, int *j)
{
	*j = 0;
	return (init_cmd(str, data));
}

void	ft_helper(t_data *data, char *str, int j, char ***cmd)
{
	int		quotes;
	int		k;
	char	c;
	int		i;

	k = 0;
	i = -1;
	quotes = 0;
	c = 0;
	while (str[++i] != '\0')
	{
		if (i == 0)
			check_i_z(data->line[i], &c, &quotes);
		else
			check_i_nz(&data->line[i], &c, &quotes);
		if (!quotes && str[i] == '|')
		{
			j++;
			k = 0;
		}
		else
			(*cmd)[j][k++] = str[i];
	}
}
