/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 04:08:33 by cschwalm          #+#    #+#             */
/*   Updated: 2022/05/01 04:52:06 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	printc(char *string, int color)
{
	if (color == RED)
		printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, string);
	else if (color == GREEN)
		printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET, string);
	else if (color == YELLOW)
		printf(ANSI_COLOR_YELLOW "%s" ANSI_COLOR_RESET, string);
	else if (color == BLUE)
		printf(ANSI_COLOR_BLUE "%s" ANSI_COLOR_RESET, string);
	else if (color == MAGENTA)
		printf(ANSI_COLOR_MAGENTA "%s" ANSI_COLOR_RESET, string);
	else if (color == CYAN)
		printf(ANSI_COLOR_CYAN "%s" ANSI_COLOR_RESET, string);
	else
		printf("%s", string);
}
