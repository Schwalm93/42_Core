/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:21:30 by tguth             #+#    #+#             */
/*   Updated: 2021/05/26 10:21:30 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*p_str;
	char			*sol;
	unsigned char	find;

	if (s == NULL)
		return (NULL);
	sol = NULL;
	p_str = (char *) s;
	find = c;
	while (*p_str != '\0')
	{
		if (*p_str == find)
			sol = p_str;
		p_str++;
	}
	if (*p_str == '\0' && find == '\0')
		sol = p_str;
	return (sol);
}
