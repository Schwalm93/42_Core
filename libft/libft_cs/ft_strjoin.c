/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:56:34 by cschwalm          #+#    #+#             */
/*   Updated: 2021/12/04 11:42:31 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_1;
	int		len_2;
	char	*s3;

	if (s1 == 0 || s2 == 0)
		return (0);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	s3 = ft_calloc ((len_1 + len_2 + 1), sizeof(char));
	if (s3 == 0)
		return (0);
	ft_strlcat(s3, s1, len_1 + 1);
	ft_strlcat(s3, s2, len_1 + len_2 + 1);
	return (s3);
}
