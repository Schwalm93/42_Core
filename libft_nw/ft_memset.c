/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwesche <nwesche@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:31:49 by nwesche           #+#    #+#             */
/*   Updated: 2021/05/17 11:31:49 by nwesche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)

{
	char	*a;

	if (!s)
		return (NULL);
	a = (char *)s;
	while (n > 0)
	{
		*a++ = (char)c;
		n--;
	}
	return (s);
}
