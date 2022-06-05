/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_supp_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 07:41:20 by tguth             #+#    #+#             */
/*   Updated: 2022/06/02 06:48:52 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_check_cd_1(t_data *data, char *str, char **sol)
{
	char	*tmp;
	int		i;
	int		stat;

	stat = -1;
	tmp = ft_strtrim_mini(str, "cd");
	i = get_first_c(tmp);
	if (i == -1 || ft_strlen(tmp) == 0)
		stat = 0;
	else if (*(tmp + i) == '.' && *(tmp + i + 1) == '.'
		&& *(tmp + i + 2) == '\0')
		stat = 1;
	else if (*(tmp + i) == '.' && *(tmp + i + 1) == '.'
		&& *(tmp + i + 2) != '\0' && *(tmp + i + 2) != '/')
		err_handler(data, 1, tmp, "too many arguments");
	else if (*(tmp + i) == '.' && *(tmp + i + 1) == '.'
		&& *(tmp + i + 2) == '/')
	{
		free(*sol);
		*sol = ft_strdup(tmp + i + 3);
		return (4);
	}
	else if (*(tmp + i) == '.' && *(tmp + i + 1) == '\0')
		stat = 2;
	return (stat);
}

static int	ft_check_cd_2(t_data *data, char *str, char **sol)
{
	char	*temp;
	int		index;

	temp = ft_strtrim_mini(str, "cd");
	index = get_first_c(temp);
	if (*(temp + index) == '.' && *(temp + index + 1) != '\0'
		&& *(temp + index + 1) != '/')
		err_handler(data, 1, *sol, "too many arguments");
	else if (*(temp + index) == '.' && *(temp + index + 1) == '/')
		return (ft_check_cd_helper(sol, &temp, 2, index));
	else if (*(temp + index) == '/')
		return (ft_check_cd_helper(sol, &temp, 1, index));
	else
		return (ft_check_cd_helper(sol, &temp, 0, index));
	return (-1);
}

char	*ft_check_master(t_data *data, char *str, int *status)
{
	char	*sol;

	sol = NULL;
	*status = -1;
	*status = ft_check_cd_1(data, str, &sol);
	if (*status != -1)
		return (sol);
	*status = ft_check_cd_2(data, str, &sol);
	if (*status != -1)
		return (sol);
	else
		err_handler(data, 1, sol, "Error cd");
	return (NULL);
}

static void	ft_back_supp(char **str, char *arr)
{
	char	*tmp;

	tmp = ft_strjoin(*str, "/");
	ft_free((void *) str, NULL, NULL);
	*str = ft_strjoin(tmp, arr);
	ft_free((void *) &tmp, NULL, NULL);
}

char	*ft_cd_back(t_data *data, char **temp, int turn, char **cmd)
{
	char	*str;
	char	*name;
	int		i;

	i = -1;
	name = check_cd_name(data, &temp);
	if (name == NULL)
		return (NULL);
	str = ft_calloc(1, sizeof(char));
	if (!str)
	{
		ft_free((void *) cmd, NULL, NULL);
		err_handler(data, 1, str, "Error Malloc");
	}
	while (temp[++i] != NULL)
	{
		ft_back_supp(&str, temp[i]);
		if (ft_strncmp(temp[i], name, ft_strlen(temp[i]) - 1) == 0)
		{
			cd_supp_1_helper(data, turn, &str);
			break ;
		}
	}
	ft_free(NULL, (void *) &temp, NULL);
	return (str);
}
