/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:26:13 by cschwalm          #+#    #+#             */
/*   Updated: 2021/11/19 13:26:13 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*cdest;
	unsigned char		*csrc;

	i = 0;
	if (!src || !dest)
		return (NULL);
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	if (csrc < cdest)
	{
		while (n--)
		{
			cdest[n] = csrc[n];
		}
		return (dest);
	}
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}

int main ()
{
  char str[20] = "Moin User!";
  char str2[] = "Vögel";
  memmove( str, str2, 6 );
//	ft_memmove( str+5, str, 12 );
  puts( str );
  return 0;
}
