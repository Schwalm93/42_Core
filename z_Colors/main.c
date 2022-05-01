/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 04:08:33 by cschwalm          #+#    #+#             */
/*   Updated: 2022/05/01 04:11:36 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(void)
{
    printf(ANSI_COLOR_RED   "ANSI_COLOR_RED\n"  ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN   "ANSI_COLOR_GREEN\n"  ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW   "ANSI_COLOR_YELLOW\n"  ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE   "ANSI_COLOR_BLUE\n"  ANSI_COLOR_RESET);
    printf(ANSI_COLOR_MAGENTA   "ANSI_COLOR_MAGENTA\n"  ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN   "ANSI_COLOR_CYAN\n"  ANSI_COLOR_RESET);

    return (0);
}