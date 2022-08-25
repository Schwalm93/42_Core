/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 01:53:13 by cschwalm          #+#    #+#             */
/*   Updated: 2022/08/21 10:43:17 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

typedef struct s_commands
{
	char *args[50];
	char *path[100];
	char *params[50];
	int pipes[1000][2];
	int		n_cmds;
	int option;
	int before;

}			t_commands;



#endif