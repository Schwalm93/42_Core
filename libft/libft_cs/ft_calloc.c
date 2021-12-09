/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:10:30 by cschwalm          #+#    #+#             */
/*   Updated: 2021/11/20 11:10:30 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc (num * size);
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < num * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}
