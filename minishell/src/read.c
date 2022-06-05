/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:16:01 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/02 06:48:52 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_for_quotas(char *line)
{
	int		i;
	int		quotes;
	int		count;
	char	c;

	i = 0;
	quotes = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (i == 0)
			check_i_zero(line[i++], &c, &count, &quotes);
		else
			check_i_not_zero(&line[i++], &c, &count, &quotes);
	}
	return (quotes);
}

void	read_input(t_data *data)
{
	char	*temp1;
	char	*temp2;

	temp1 = ft_strjoin(data->path, ": ");
	data->line = readline(temp1);
	ft_free((void *) &temp1, NULL, NULL);
	if (data->line == NULL)
		ft_exit(data);
	if (data->line[0] != '\0' && get_next_c(data->line, 0) != -1)
	{
		while (check_for_quotas(data->line))
		{
			temp1 = ft_strjoin(data->line, "\n");
			ft_free((void *) &data->line, NULL, NULL);
			temp2 = readline(">");
			data->line = ft_strjoin(temp1, temp2);
			ft_free((void *) &temp1, NULL, NULL);
			ft_free((void *) &temp2, NULL, NULL);
		}
	}
	else
	{
		free(data->line);
		read_input(data);
	}
}
