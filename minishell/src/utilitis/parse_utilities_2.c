/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utilities_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:41:52 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/02 06:48:52 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	check_i_zero(char line_char, char *c, int *count, int *quotes)
{
	if (!*quotes && (line_char == '"' || line_char == '\''))
	{
		*quotes = 1;
		*c = line_char;
	}
	else if (*quotes && line_char == *c)
		*quotes = 0;
	if (line_char == '|' && !*quotes)
	{
		(*count)++;
	}
}

void	check_i_not_zero(char *line_char, char *c, int *count, int *quotes)
{
	char	temp;

	temp = *(line_char - 1);
	if (!*quotes && (*line_char == '"' || *line_char == '\'') && temp != '\\')
	{
		*quotes = 1;
		*c = *line_char;
	}
	else if (*quotes && *line_char == *c && temp != '\\')
		*quotes = 0;
	if (*line_char == '|' && !*quotes)
	{
		(*count)++;
	}
}

void	check_i_z(char line_char, char *c, int *quotes)
{
	if (!*quotes && (line_char == '"' || line_char == '\''))
	{
		*quotes = 1;
		*c = line_char;
	}
	else if (*quotes && line_char == *c)
		*quotes = 0;
}

void	check_i_nz(char *line_char, char *c, int *quotes)
{
	char	temp;

	temp = *(line_char - 1);
	if (!*quotes && (*line_char == '"' || *line_char == '\'') && temp != '\\')
	{
		*quotes = 1;
		*c = *line_char;
	}
	else if (quotes && *line_char == *c)
		*quotes = 0;
}
