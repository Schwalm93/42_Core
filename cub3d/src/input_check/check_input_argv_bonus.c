/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_argv_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:52:46 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:52:48 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

/* Checks that there are 2 input args and the right file type */
void	check_input_argv(int argc, char **argv)
{
	int	i;
	int	is_valid;

	i = 0;
	is_valid = 0;
	if (argc != 2)
	{
		printe("Error - Wrong Input try this => ./cub3d mapname.cub");
		exit(1);
	}
	while (argv[1][i])
	{
		if (argv[1][i] == '.' && argv[1][i + 1] == 'c' && argv[1][i + 2] == 'u'
			&& argv[1][i + 3] == 'b' && argv[1][i + 4] == '\0')
		{
			is_valid = 1;
			break ;
		}
		i++;
	}
	if (is_valid != 1)
	{
		printe("Error - Wrong Input try this => ./cub3d mapname.cub");
		exit(1);
	}
}
