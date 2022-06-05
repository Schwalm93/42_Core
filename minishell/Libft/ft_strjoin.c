/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:20:58 by tguth             #+#    #+#             */
/*   Updated: 2021/05/26 10:20:58 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sol;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	sol = NULL;
	i = ft_strlen(s1);
	j = 0;
	sol = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (sol == NULL)
		return (NULL);
	while (j < i)
	{
		sol[j] = s1[j];
		j++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		sol[j] = s2[i];
		j++;
		i++;
	}
	return (sol);
}
