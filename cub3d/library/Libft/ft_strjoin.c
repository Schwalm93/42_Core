/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:49:18 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:49:21 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		len_1;
	int		len_2;
	char	*s3;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == 0 || s2 == 0)
		return (0);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	s3 = ft_calloc ((len_1 + len_2 + 1), sizeof(char));
	if (s3 == 0)
		return (0);
	ft_strlcat(s3, s1, len_1 + 1);
	ft_strlcat(s3, s2, len_1 + len_2 + 1);
	free(s1);
	return (s3);
}
