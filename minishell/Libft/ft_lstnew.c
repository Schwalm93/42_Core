/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:22:10 by tguth             #+#    #+#             */
/*   Updated: 2021/05/26 16:22:10 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list		*head;

	head = NULL;
	head = (t_list *) malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head -> content = content;
	head -> next = NULL;
	return (head);
}
