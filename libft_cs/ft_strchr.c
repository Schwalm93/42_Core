/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:08:30 by cschwalm          #+#    #+#             */
/*   Updated: 2021/11/17 17:08:30 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	unsigned char	mark;
	char			*p_str;
	char			*p_result;

	mark = c;
	p_str = (char *) str;
	p_result = NULL;
	while (*p_str != 0)
	{
		if (*p_str == mark)
		{
			p_result = p_str;
			return (p_result);
		}
		p_str++;
	}
	return (p_result);
}
