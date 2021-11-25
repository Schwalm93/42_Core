/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwesche <nwesche@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:19:18 by nwesche           #+#    #+#             */
/*   Updated: 2021/06/03 16:19:18 by nwesche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		s_len;
	char	*dest;

	if (!src)
		return (NULL);
	i = 0;
	s_len = ft_strlen(src);
	dest = malloc(sizeof(char) * (s_len + 1));
	if (!dest)
		return (NULL);
	while (i < s_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
