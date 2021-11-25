/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwesche <nwesche@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:42:18 by nwesche           #+#    #+#             */
/*   Updated: 2021/05/20 10:42:18 by nwesche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_sub_find(const char *s1, const char *s2, size_t len)
{
	size_t	count;

	count = 0;
	while (*s1 != '\0' && count <= len)
	{
		if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
			return ((char *)s1);
		s1++;
		count++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	s1_length;
	size_t	s2_length;

	if (!s1 || !s2)
		return (NULL);
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	if (s2_length == 0)
		return ((char *)s1);
	if (s2_length > s1_length || s2_length > len)
		return (NULL);
	len = len - s2_length;
	return (ft_sub_find(s1, s2, len));
}
