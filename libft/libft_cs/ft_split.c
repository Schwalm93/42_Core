/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:58:33 by cschwalm          #+#    #+#             */
/*   Updated: 2021/12/04 12:55:35 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_counter(const char *s, char c)
{
	int	counter;
	int	i;

	counter = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			counter++;
		i++;
	}
	return (counter + 1);
}

char	**ft_split(const char *s, char c)
{
	char			**str;
	int				i;
	unsigned int	pos_1;
	int				count_str;

	count_str = 0;
	pos_1 = 0;
	i = 0;
	if (!s)
		return (NULL);
	str = ft_calloc(sizeof(char *), ft_counter(s, c));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		pos_1 = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i - 1] != c)
			str[count_str] = ft_substr(s, pos_1, i - pos_1);
		count_str++;
	}
	return (str);
}
int	main(void)
{
	char str[] = "Das:Ist:der:String";
	char **p;
	unsigned int i;

	i = 0;
	p = ft_split(str, ':');

	while (p[i] != 0)
	{
	printf("p[%d]: %s \n", i,p[i]);
	i++;
	}

	free(p);

	return 0;
}