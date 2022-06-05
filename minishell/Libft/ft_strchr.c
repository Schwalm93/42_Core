/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:20:42 by tguth             #+#    #+#             */
/*   Updated: 2021/05/26 10:20:42 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p_str;
	char	*sol;
	char	find;

	if (s == NULL)
		return (NULL);
	find = c;
	sol = NULL;
	p_str = (char *) s;
	while (*p_str != '\0')
	{
		if (*p_str != find)
			p_str++;
		else
		{
			sol = p_str;
			return (sol);
		}
	}
	if (*p_str == '\0' && find == '\0')
	{
		sol = p_str;
		return (sol);
	}
	return (NULL);
}
