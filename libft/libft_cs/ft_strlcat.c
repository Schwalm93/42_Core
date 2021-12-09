/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:52:46 by cschwalm          #+#    #+#             */
/*   Updated: 2021/11/19 14:52:46 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	n;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	n = dest_len;
	if (size <= dest_len)
		return (src_len + size);
	while (src[i] != '\0' && n < size - 1)
	{
		dest[n] = src[i];
		i++;
		n++;
	}
	dest[n] = '\0';
	return (dest_len + src_len);
}
