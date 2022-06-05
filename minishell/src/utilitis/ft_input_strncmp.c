/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:21:10 by tguth             #+#    #+#             */
/*   Updated: 2021/05/26 10:21:10 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_input_strncmp(const char *s1, const char *s2, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (len - i > 0 && (s1[j] != '\0' || s2[i] != '\0'))
	{
		while (s1[j] == '"' || s1[j] == '\'' || s1[j] == '\\')
			j++;
		if (s1[j] != s2[i])
			return ((unsigned char) s1[j] - (unsigned char) s2[i]);
		else if ((s1[j + 1] == ' ' || s1[j + 1] == '"'
				|| s1[j + 1] == '\'' || s1[j + 1] == '\\')
			&& s2[i + 1] == '\0')
			return (0);
		else if (s1[j + 1] != '\0' && s2[i + 1] == '\0')
			return (1);
		i++;
		j++;
	}
	return (0);
}
