/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:14:43 by tguth             #+#    #+#             */
/*   Updated: 2022/04/24 10:45:21 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	void	ft_supp_strjoin_s1(char *s1, int *i, char **sol);
static	void	ft_supp_strjoin_s2(char *s2, int i, int j, char **sol);

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*sol;

	j = 0;
	i = 0;
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	sol = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (sol == NULL)
		return (NULL);
	ft_supp_strjoin_s1(s1, &i, &sol);
	ft_supp_strjoin_s2(s2, i, j, &sol);
	sol[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (sol);
}

static	void	ft_supp_strjoin_s1(char *s1, int *i, char **sol)
{
	if (s1)
	{
		while (s1[(*i)] != '\0')
		{
			sol[0][(*i)] = s1[(*i)];
			(*i)++;
		}
	}
}

static	void	ft_supp_strjoin_s2(char *s2, int i, int j, char **sol)
{
	while (s2[j] != '\0')
	{
		sol[0][i] = s2[j];
		j++;
		i++;
	}
}
