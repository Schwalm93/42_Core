/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:20:55 by tguth             #+#    #+#             */
/*   Updated: 2021/05/26 10:20:55 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_strtrim(char const *s1, char const *set)
{
	int	begin;
	int	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	begin = ft_pos(s1, set, 1);
	end = ft_pos(s1, set, -1) + 1;
	if (end <= begin)
		end = ft_strlen(s1);
	return (ft_substr(s1, begin, end - begin));
}
