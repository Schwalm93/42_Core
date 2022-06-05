/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:25:28 by cschwalm          #+#    #+#             */
/*   Updated: 2022/06/02 06:48:52 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handler(int signum)
{
	if (signum == SIGINT && g_pid == 0)
	{
		ft_putstr_fd("\b\b\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signum == SIGINT && g_pid != 0)
		ft_putstr_fd("\n", 1);
	else if (signum == SIGQUIT)
		ft_putstr_fd("\b\b\n", 1);
	g_pid = 0;
}

void	signal_check(t_data *data)
{
	struct sigaction	sa;

	memset(&sa, '\0', sizeof(sa));
	sa.sa_handler = &handler;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		err_handler(data, 0, NULL, "Can not handle Ctrl + C");
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
		err_handler(data, 1, NULL, "Can not handle Ctrl + D");
}
