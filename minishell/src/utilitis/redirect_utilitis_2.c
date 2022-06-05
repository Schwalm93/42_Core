/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utilitis_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 06:13:57 by tguth             #+#    #+#             */
/*   Updated: 2022/06/01 11:20:29 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	before_arrow(char *begin, char *arrow, int *quotes, int echo)
{
	char	*second;

	second = begin;
	while (arrow != second)
	{
		if ((*arrow == '"' || *arrow == '\'')
			&& *(arrow - 1) != '\\' && echo == 0)
			(*quotes)++;
		else if (*arrow == '\'' && *(arrow - 1) != '\\' && echo == 1)
			(*quotes)++;
		arrow--;
	}
	if (*begin != '\\' && (*arrow == '"' || *arrow == '\'') && echo == 0)
		(*quotes)++;
	else if (*begin != '\\' && *arrow == '\'' && echo == 1)
		(*quotes)++;
	*quotes %= 2;
}

void	after_arrow(char *end, char *arrow, int *quotes, int echo)
{
	while (arrow != end)
	{
		if ((*arrow == '"' || *arrow == '\'')
			&& *(arrow - 1) != '\\' && echo == 0)
			(*quotes)++;
		else if (*arrow == '\'' && *(arrow - 1) != '\\' && echo == 1)
			(*quotes)++;
		arrow++;
	}
	if ((*arrow == '"' || *arrow == '\'')
		&& *(arrow - 1) != '\\' && echo == 0)
		(*quotes)++;
	else if (*arrow == '\'' && *(arrow - 1) != '\\' && echo == 1)
		(*quotes)++;
	if (*quotes % 2 == 0)
		*quotes = 1;
	else
		*quotes %= 2;
}

int	re_check_quotes(char *begin, char *arrow, int echo)
{
	char	*last;
	int		quotes;

	last = begin;
	quotes = 0;
	while (*last != '\0')
		last++;
	before_arrow(begin, arrow, &quotes, echo);
	if (quotes == 0)
		return (0);
	after_arrow(last, arrow, &quotes, echo);
	if (quotes != 0)
		return (quotes);
	return (0);
}

char	*ft_redirect_helper(char *before, char *after, char *cmd)
{
	char	*temp;

	if (after == NULL)
	{
		ft_free((void *) &cmd, NULL, NULL);
		return (before);
	}
	temp = ft_strjoin(before, after);
	ft_free((void *) &before, NULL, NULL);
	ft_free((void *) &after, NULL, NULL);
	ft_free((void *) &cmd, NULL, NULL);
	return (temp);
}
