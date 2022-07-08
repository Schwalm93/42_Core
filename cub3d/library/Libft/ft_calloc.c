/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:45:53 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:45:53 by tguth            ###   ########.fr       */
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
