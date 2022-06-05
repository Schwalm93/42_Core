/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:24:42 by tguth             #+#    #+#             */
/*   Updated: 2021/06/04 13:24:42 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init(unsigned int *pos1, int *i, int *count_sol)
{
	*pos1 = 0;
	*i = 0;
	*count_sol = 0;
}

static	int	ft_counter(char const *s, char c)
{
	int	counter;
	int	i;

	counter = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0' && i != 0)
			counter++;
		i++;
	}
	return (counter + 1);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	pos1;
	int				i;
	int				count_sol;
	char			**sol;

	ft_init(&pos1, &i, &count_sol);
	if (s == NULL)
		return (NULL);
	sol = ft_calloc(ft_counter(s, c), sizeof(char *));
	if (sol == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		pos1 = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i - 1] != c)
			sol[count_sol] = ft_substr(s, pos1, i - pos1);
		count_sol ++;
	}
	sol[count_sol] = NULL;
	return (sol);
}
