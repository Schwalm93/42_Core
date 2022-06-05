/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utilitis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:36:28 by tguth             #+#    #+#             */
/*   Updated: 2022/06/02 03:19:14 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_trim(char *cmd, int *set_flag)
{
	char	*temp;
	int		first;
	int		i;

	i = 3;
	temp = cmd;
	first = get_next_space(cmd, 0);
	if (*(temp + first) == '\0')
		return (NULL);
	else if (*(temp + first + 1) == '-' && *(temp + first + 2) == 'n')
		ft_trim_helper(&temp, first, &i, set_flag);
	else
		temp += first;
	first = get_first_c(temp);
	if (first == -1)
		return (NULL);
	temp += first;
	return (temp);
}

char	*valided_variable(t_data *data, char *dol, int *index)
{
	char	*var;
	char	*name;

	var = NULL;
	while (dol[*index] != '\0' && is_white_space(dol[*index]) == 0
		&& dol[*index] != '\"' && dol[*index] != '\'')
		(*index)++;
	name = ft_substr(dol, 1, *index - 1);
	if (name[0] == '\0')
	{
		ft_free((void *) &name, NULL, NULL);
		if (*(--dol) == ' ')
			return (ft_strdup(" $"));
		return (ft_strdup("$"));
	}
	var = get_var(data, name);
	ft_free((void *) &name, NULL, NULL);
	return (var);
}

char	*create_substr_before(t_data *data, char *str, char *dol)
{
	char	*temp;

	temp = dol;
	temp--;
	if (temp <= str)
		return (NULL);
	if ((*temp == '\"' || *temp == '\'') && temp != str)
		temp--;
	if (temp == str)
		return (NULL);
	if ((str + get_first_c(str)) != dol)
	{
		while (is_white_space(*temp) == 1)
		{
			temp--;
			if (temp == str)
				return (NULL);
		}
		return (ft_substr_pntr(data, ++temp, str));
	}
	return (NULL);
}

char	*create_substr_after(char *dol, int index)
{
	char	*temp;

	if (*(dol + index) != '\0')
	{
		temp = dol + index;
		return (ft_substr(temp, get_next_c(temp, 0), ft_strlen(temp)));
	}
	return (NULL);
}

void	create_string(char **str, char *before, char *after, char *var)
{
	char	*sol;

	sol = NULL;
	if (before != NULL && var != NULL && after != NULL)
		create_string_1_h(before, after, var, &sol);
	else if (before != NULL && after == NULL && var != NULL)
		create_string_2_h(before, var, &sol);
	else if (before == NULL && after != NULL && var != NULL)
		sol = create_string_3_h(after, var, before, 0);
	else if (before != NULL && after != NULL && var == NULL)
		sol = create_string_3_h(after, var, before, 1);
	else if (before == NULL && after == NULL && var != NULL)
		sol = ft_strjoin(var, " ");
	else if (before != NULL && after == NULL && var == NULL)
		sol = ft_strjoin(before, " ");
	else if (before == NULL && after != NULL && var == NULL)
		sol = ft_strjoin(after, " ");
	create_string_support(str, sol, before);
	ft_free((void *) &after, NULL, NULL);
	return ;
}
