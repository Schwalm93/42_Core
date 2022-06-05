/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:15:09 by tguth             #+#    #+#             */
/*   Updated: 2022/05/29 06:28:37 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	free_helper(void ***arr_pntr)
{
	int	i;

	i = -1;
	if (arr_pntr != NULL && *arr_pntr != NULL)
	{
		while ((*arr_pntr)[++i] != NULL)
		{
			if ((*arr_pntr)[i] != NULL)
				free((*arr_pntr)[i]);
			(*arr_pntr)[i] = NULL;
		}
		free(*arr_pntr);
		*arr_pntr = NULL;
	}
}

void	ft_free(void **single_pntr, void ***arr_pntr, void ***single_arrpntr)
{
	if (single_pntr != NULL && *single_pntr != NULL)
	{
		free(*single_pntr);
		*single_pntr = NULL;
	}
	if (single_arrpntr != NULL && *single_arrpntr != NULL)
	{
		free(*single_arrpntr);
		*single_arrpntr = NULL;
	}
	free_helper(arr_pntr);
}

char	*ft_substr_pntr(t_data *data, char *big, char *small)
{
	int		index;
	char	*start;
	int		i;
	char	*sub;

	i = -1;
	index = 0;
	start = small;
	while (small != big)
	{
		index++;
		small++;
	}
	sub = ft_calloc(index + 1, sizeof(char));
	if (!sub)
		err_handler(data, 1, sub, "Error can not create substring");
	while (++i < index)
		sub[i] = start[i];
	return (sub);
}

static	int	ft_pos(const char *s1, const char *set, int direct)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (direct < 0)
		i = ft_strlen(s1) - 1;
	while (set[n] != '\0' && s1[i] != '\0' && i >= 0)
	{
		if (s1[i] == set[n])
		{
			i = i + direct;
			n = 0;
		}
		else
			n++;
	}
	return (i);
}

char	*ft_strtrim_mini(char *s1, char const *set)
{
	int	begin;

	if (s1 == NULL || set == NULL)
		return (NULL);
	begin = ft_pos(s1, set, 1);
	return (s1 + begin);
}
