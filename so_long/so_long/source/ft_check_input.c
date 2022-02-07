/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:44:22 by tguth             #+#    #+#             */
/*   Updated: 2022/02/07 07:22:59 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char *ft_bug(int fp, char **overflow)
{
	return (get_next_line(fp, 10, overflow));
}

void	ft_check_line(char **line, t_pointer *t_pntr, char **overflow, int fp)
{
	printf("2. %d\n", (*t_pntr).t_map_p->map_x);
	printf("%s\n", ft_bug(fp, overflow));
	/*if (*line == NULL)
	{
		printf("Error! get next line!\n");
		ft_free(*line);
		exit(0);
	}*/
	printf("3. %d\n", (*t_pntr).t_map_p->map_x);
	if ((*t_pntr).t_map_p->map_x == 0)
		(*t_pntr).t_map_p->map_x = 10;//ft_strlen(*line) - 1;
	printf("4. %d\n", (*t_pntr).t_map_p->map_x);
	if ((*t_pntr).t_map_p->map_x != ft_strlen(*line) - 1 && line[0][ft_strlen(*line)] == '\0' && line[0][ft_strlen(*line) - 1] == '\n')
	{
		printf("Error! Map must be rectangular!\n");
		ft_free(*line);
		ft_free(overflow);
		exit(0);
	}
}

void	ft_check_wall(char *line, int i, char **overflow)
{
	if (line[0] != '1' || (line[i] != '1' && line[i + 1] == '\n'))
	{
		printf("Error! Map must be surrounded by walls\n");
		ft_free(overflow);
		ft_free(line);
		exit(0);
	}
	return ;
}

int	ft_set_walls(char *line, int i, t_pointer *t_pntr, int *walls)
{
	if (line[i] == '1')
	{
		ft_lstadd_back_xy(&(*t_pntr).t_map_p->head_wall,
			ft_lstnew_xy((*t_pntr).t_map_p->map_y, i));
		(*walls)++;
		return (1);
	}
	if (line[i] == '0')
	{
		ft_lstadd_back_xy(&(*t_pntr).t_map_p->head_empty,
			ft_lstnew_xy((*t_pntr).t_map_p->map_y, i));
		return (1);
	}
	return (0);
}

int	ft_set_player_coin(char *line, int i, t_pointer *t_pntr, char **overflow)
{
	if (line [i] == 'c' || line[i] == 'C')
	{
		ft_lstadd_back_xy(&(*t_pntr).t_map_p->head_coin,
			ft_lstnew_xy((*t_pntr).t_map_p->map_y, i));
		(*t_pntr).t_map_p->numb_coin ++;
		return (1);
	}
	if (line[i] == 'p' || line[i] == 'P')
	{
		if ((*t_pntr).t_map_p->player_x != 0
			&& (*t_pntr).t_map_p->player_y != 0)
		{
			printf("Error! Only one Player!\n");
			ft_free(overflow);
			ft_free(line);
			exit(0);
		}
		(*t_pntr).t_map_p->player_x = i;
		(*t_pntr).t_map_p->player_y = (*t_pntr).t_map_p->map_y;
		return (1);
	}
	return (0);
}

int	ft_set_exit(char *line, int i, t_pointer *t_pntr, char **overflow)
{
	if (line[i] == 'e' || line[i] == 'E')
	{
		if ((*t_pntr).t_map_p->exit_x != 0
			&& (*t_pntr).t_map_p->exit_y != 0)
		{
			printf("Error! Only one Exit!\n");
			ft_free(overflow);
			ft_free(line);
			exit(0);
		}
		(*t_pntr).t_map_p->exit_x = i;
		(*t_pntr).t_map_p->exit_y = (*t_pntr).t_map_p->map_y;
		return (1);
	}
	return (0);
}
