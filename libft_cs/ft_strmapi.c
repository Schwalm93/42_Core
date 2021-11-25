/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 06:53:33 by cschwalm          #+#    #+#             */
/*   Updated: 2021/11/25 08:03:43 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	if (s == NULL)
		return (NULL);
	result = malloc(strlen(s));
	if (result == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		result[i] = s[i];
		i++;
	}
	i = 0;
	while (result[i])
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	return (result);
}
