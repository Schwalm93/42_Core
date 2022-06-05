/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:13:37 by tguth             #+#    #+#             */
/*   Updated: 2022/06/02 04:29:15 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_create_dollar(t_data *data, char **temp, char **sol)
{
	char	*dol;
	char	*var;
	char	*before;
	char	*after;

	dol = ft_strchr(*temp, '$');
	var = NULL;
	if (dol != NULL)
	{
		before = create_substr_before(data, *temp, dol);
		if (re_check_quotes(*temp, dol, 1) == 0)
			var = valided_variable(data, dol, &data->index);
		after = create_substr_after(dol, data->index);
		create_string(sol, before, after, var);
		ft_free((void *) temp, NULL, NULL);
	}
	else
		create_string(sol, NULL, *temp, NULL);
}

static void	ft_check_dollar(t_data *data, char **str)
{
	char	*sol;
	int		i;
	char	**tmp;
	char	*sub;

	if (strchr(*str, '$') == NULL)
		return ;
	sol = ft_calloc(1, sizeof(char));
	if (!sol)
		err_handler(data, 1, *str, "Error can not allocate");
	data->index = 0;
	i = -1;
	tmp = ft_split(*str, ' ');
	while (tmp[++i] != NULL)
		ft_create_dollar(data, &tmp[i], &sol);
	ft_free((void *) str, NULL, (void *) &tmp);
	if (sol[ft_strlen(sol) - 1] == ' ')
	{
		sub = ft_substr(sol, 0, ft_strlen(sol) - 1);
		free(sol);
		*str = sub;
	}
	else
		*str = sol;
	return ;
}

static void	echo_to_screen(char *str, int set_flag)
{
	int	i;

	i = -1;
	if (set_flag == 0)
	{
		ft_putstr_fd_c(str, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	else
	{
		while (str[++i] != '\0')
		{
			if (str[i + 1] == '\0' && str[i] == '\n')
				break ;
			else if (str[i] != '\'' && str[i] != '"')
				ft_putchar_fd(str[i], STDOUT_FILENO);
		}
	}
	ft_free((void *) &str, NULL, NULL);
}

void	ft_echo(t_data *data, int cmd_numb)
{
	char	*str;
	int		set_flag;
	char	*temp;

	set_flag = 0;
	temp = ft_trim(data->t_commands[cmd_numb]->command, &set_flag);
	if (temp != NULL)
	{
		str = ft_strdup(temp);
		ft_check_dollar(data, &str);
		echo_to_screen(str, set_flag);
	}
	ft_free((void *) &data->t_commands[cmd_numb]->command, NULL, NULL);
	data->status_code = 0;
}
