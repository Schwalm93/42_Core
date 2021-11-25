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
	int				*ptr;
	unsigned int	i;

	i = 0;
	ptr = malloc(num * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < num)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
