/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_supp_1_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 07:52:04 by tguth             #+#    #+#             */
/*   Updated: 2022/05/29 08:28:41 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	cd_supp_1_helper(t_data *data, int turn, char **str)
{
	int	index;

	if (turn == 0)
	{
		index = find_var_index(data, "PWD");
		if (index != -1)
			set_env_var(data, *str, "PWD");
		else
			free(*str);
		*str = NULL;
	}
}
