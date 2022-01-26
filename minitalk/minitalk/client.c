/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:19:07 by cschwalm          #+#    #+#             */
/*   Updated: 2022/01/26 05:06:15 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_sig_server;

void	server_answer(int signal, siginfo_t *siginfo, void *context)
{
	g_sig_server = 1;
	(void) siginfo;
	(void) context;
	(void) signal;
}

void	send_char(int pid, char c)
{
	int	b;

	b = 0;
	while (b < 8)
	{
		g_sig_server = 0;
		if (c & (1 << b))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		while (g_sig_server == 0)
			pause();
		b++;
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	int					i;
	struct sigaction	sa;

	i = 0;
	g_sig_server = 1;
	sa.sa_sigaction = server_answer;
	sa.sa_flags = SA_SIGINFO;
	if (argc != 3)
	{
		ft_putstr_fd("Error. Right Format = ./client [PID] [String]", 1);
		return (0);
	}
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	return (0);
}
