/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:57:14 by cschwalm          #+#    #+#             */
/*   Updated: 2021/12/04 12:01:00 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if ((int)start > ft_strlen(s))
	{
		str = malloc (sizeof(char));
		str[0] = '\0';
		return (str);
	}
	str = (char *) malloc(sizeof(char [len + 1]));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0 && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
