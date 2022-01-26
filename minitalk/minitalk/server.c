/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:19:13 by cschwalm          #+#    #+#             */
/*   Updated: 2022/01/21 03:24:02 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal, siginfo_t *siginfo, void *context)
{
	static unsigned char	c;
	static int				i = 0;

	if (i <= 7 && signal == SIGUSR1)
	{
		c |= (1 << i);
	}
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
		kill(siginfo->si_pid, SIGUSR2);
	}
	else
		kill(siginfo->si_pid, SIGUSR1);
	(void) context;
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
}
