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

/*void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	i = 0;
	p_dest = dest;
	p_src = src;
	while (i < n)
	{	
		*p_dest = *p_src;
		p_dest++;
		p_src++;
		i++;
	}
	return (dest);
}
*/
int main ()
{
  char str[20] = "Moin User!";
  char str2[] = "Vögel";
  memmove( str, str2, 6 );
//	ft_memmove( str+5, str, 12 );
  puts( str );
  return 0;
}
