/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:56:40 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:56:43 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_free_str(void **pntr)
{
	if (pntr == NULL || *pntr == NULL)
		return ;
	free(*pntr);
	*pntr = NULL;
}

void	ft_free_arry(void ***pntr)
{
	int	i;

	i = -1;
	if (pntr == NULL || **pntr == NULL)
		return ;
	while ((*pntr)[++i] != NULL)
	{
		free((*pntr)[i]);
		(*pntr)[i] = NULL;
	}
	free(*pntr);
	*pntr = NULL;
}
