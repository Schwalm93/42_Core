/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:21:32 by tguth             #+#    #+#             */
/*   Updated: 2021/05/26 10:21:32 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sol;

	sol = NULL;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	if (start >= i)
		return (ft_calloc(1, 1));
	sol = ft_calloc(len + 1, sizeof(char));
	if (sol == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sol[i] = s[start];
		start++;
		i++;
	}
	sol[i] = '\0';
	return (sol);
}
