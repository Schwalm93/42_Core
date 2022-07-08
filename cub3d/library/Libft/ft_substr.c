/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:50:37 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:50:39 by tguth            ###   ########.fr       */
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
