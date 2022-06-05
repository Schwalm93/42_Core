/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:54:14 by tguth             #+#    #+#             */
/*   Updated: 2021/05/27 11:54:14 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*start;
	t_list	*temp;

	start = *lst;
	if (lst == NULL || del == NULL)
		return ;
	while (start != NULL)
	{
		temp = start -> next;
		del (start ->content);
		free(start);
		start = temp;
	}
	*lst = NULL;
}
