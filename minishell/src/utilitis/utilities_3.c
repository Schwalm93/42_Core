/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 08:54:24 by tguth             #+#    #+#             */
/*   Updated: 2022/05/26 06:18:43 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	before(char *s1)
{
	int		i;
	int		index;

	i = 0;
	index = -1;
	while (s1[i] != '\0')
	{
		if (s1[0] == '"')
			index++;
		else if (s1[i] == '"' && s1[i - 1] != '\\')
			index++;
		if (s1[i] != '"' && s1[i] != '\\')
			break ;
		i++;
	}
	if (index == -1)
		index = 0;
	return (index);
}

static int	after(char *s1)
{
	int		i;
	int		index;

	i = ft_strlen(s1) - 1;
	index = -1;
	while (i > 0)
	{
		if (s1[i] == '"' && s1[i - 1] != '\\')
			index++;
		if (s1[i] != '"' && s1[i] != '\\')
			break ;
		i--;
	}
	if (s1[i] == '"')
		index++;
	if (index == -1)
		index = 0;
	return (index);
}

char	*ft_strtrim_quotes(char *s1)
{
	char	*temp;
	int		start;
	int		end;

	start = before(s1);
	end = ft_strlen(s1) - after(s1);
	temp = ft_substr(s1, start, end);
	return (temp);
}
