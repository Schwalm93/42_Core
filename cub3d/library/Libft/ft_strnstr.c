/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:50:15 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:50:15 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	needle_len;

	if (*s2 == 0)
		return ((char *) s1);
	needle_len = ft_strlen(s2);
	while (*s1 != 0 && needle_len <= n)
	{
		if (ft_strncmp(s1, s2, needle_len) == 0)
		{
			return ((char *) s1);
		}
		else
		{
			s1++;
			n--;
		}
	}
	return (NULL);
}
