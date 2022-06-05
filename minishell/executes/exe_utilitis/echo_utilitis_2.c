/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utilitis_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:07:02 by tguth             #+#    #+#             */
/*   Updated: 2022/06/02 03:51:54 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	create_string_support(char **str, char *sol, char *before)
{
	char	*tmp;

	tmp = ft_strjoin(*str, sol);
	ft_free((void *) str, NULL, NULL);
	ft_free((void *) &sol, NULL, NULL);
	*str = tmp;
	ft_free((void *) &before, NULL, NULL);
}

void	ft_trim_helper(char **temp, int first, int *i, int *set_flag)
{
	while (*(*temp + first + *i) == 'n')
		(*i)++;
	if (*(*temp + first + *i) == ' ' || *(*temp + first + *i) == '\t'
		|| *(*temp + first + *i) == '\0')
	{
		*set_flag = 1;
		*temp += first + *i;
	}
	else
		*temp += first;
}

void	create_string_1_h(char *before, char *after, char *var, char **sol)
{
	char	*temp;
	char	*temp_2;

	temp = ft_strjoin(before, " ");
	temp_2 = ft_strjoin(temp, var);
	ft_free((void *) &temp, NULL, NULL);
	temp = ft_strjoin(temp_2, " ");
	*sol = ft_strjoin(temp, after);
	ft_free((void *) &temp_2, NULL, NULL);
	ft_free((void *) &temp, NULL, NULL);
}

void	create_string_2_h(char *before, char *var, char **sol)
{
	char	*temp;

	if (var[0] == '$' && var[1] == '\0')
		temp = ft_strdup(before);
	else if (var[0] == ' ' && var[1] == '$' && var[2] == '\0')
		temp = ft_strdup(before);
	else
		temp = ft_strjoin(before, " ");
	*sol = ft_strjoin(temp, var);
	ft_free((void *) &temp, NULL, NULL);
}

char	*create_string_3_h(char *after, char *var, char *before, int i)
{
	char	*temp;
	char	*sol;

	if (i == 0)
	{
		temp = ft_strjoin(var, " ");
		sol = ft_strjoin(temp, after);
	}
	else
	{
		temp = ft_strjoin(before, " ");
		sol = ft_strjoin(temp, after);
	}
	ft_free((void *) &temp, NULL, NULL);
	return (sol);
}
