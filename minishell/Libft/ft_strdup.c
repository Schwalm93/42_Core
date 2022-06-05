/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:20:53 by tguth             #+#    #+#             */
/*   Updated: 2021/05/26 10:20:53 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*sol;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	sol = ft_calloc(i + 1, sizeof(char));
	if (sol == NULL)
		return (NULL);
	while (i >= 0)
	{
		sol[i] = s[i];
		i--;
	}
	return (sol);
}
