/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:54:37 by tguth             #+#    #+#             */
/*   Updated: 2022/07/06 10:54:40 by tguth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	left_vision(t_data *data)
{
	double		olddirx;
	double		oldplanex;
	t_player	*play;

	play = data->player;
	olddirx = play->dirx;
	play->dirx
		= play->dirx * cos(STEP_SIZE) - play->diry * sin(STEP_SIZE);
	play->diry = olddirx * sin(STEP_SIZE) + play->diry * cos(STEP_SIZE);
	oldplanex = play->planex;
	play->planex
		= play->planex * cos(STEP_SIZE) - play->planey * sin(STEP_SIZE);
	play->planey = oldplanex * sin(STEP_SIZE)
		+ play->planey * cos(STEP_SIZE);
}

void	right_vision(t_data *data)
{
	double		olddirx;
	double		oldplanex;
	t_player	*play;

	play = data->player;
	olddirx = play->dirx;
	play->dirx
		= play->dirx * cos(-STEP_SIZE) - play->diry * sin(-STEP_SIZE);
	play->diry = olddirx * sin(-STEP_SIZE) + play->diry * cos(-STEP_SIZE);
	oldplanex = play->planex;
	play->planex
		= play->planex * cos(-STEP_SIZE) - play->planey * sin(-STEP_SIZE);
	play->planey = oldplanex * sin(-STEP_SIZE)
		+ play->planey * cos(-STEP_SIZE);
}
