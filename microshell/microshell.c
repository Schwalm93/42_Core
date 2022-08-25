/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 02:27:09 by cschwalm          #+#    #+#             */
/*   Updated: 2022/08/25 03:42:17 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define OUT 0
#define IN 1

int	count_cmds(int argc, char **argv)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (i < argc)
	{
		if (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0)
			count++;
		i++;
	}
	return (count);
}

int	execute_cd(t_commands *cmds, char **env)
{
	int i;

	i = 0;
	if (cmds->args[1] == NULL)
	{
		write(STDERR_FILENO, "error: cd: bad arguments\n", 25);
		return (1);
	}
	else if (chdir(cmds->args[1]) != 0)
	{
		write(STDERR_FILENO, "error: cd: cannot change directory to ", 38);
		while (cmds->args[1][i])
		{
			write(1, &cmds->args[1][i], 1);
			i++;
		}
		write(STDERR_FILENO, "\n", 1);
		return (1);
	}
	i = 0;
	return (0);
}

int	getpath(t_commands *cmds, char **argv, int index)
{
	int	i;
	int	j;

	cmds->path[0] = argv[index];
	cmds->args[0] = argv[index];
	cmds->args[1] = NULL;
	i = index + 1;
	j = 1;
	cmds->option = 0;
	if (argv[i] != NULL)
	{
		if (cmds->before == 0)
			cmds->option = 0;
		while (argv[i] != NULL )
		{	
			if (strcmp(argv[i], "|") == 0)
			{
				if (cmds->before == 0)
					cmds->option = 1; // Erster Befehl in Verkettung
				else if (cmds->before == 1)
					cmds->option = 2; // Weiterer Befehl in Verkettung
				cmds->before = 1;
				i++;
				break ;
			}
			if (strcmp(argv[i], ";") == 0)
			{
				if (cmds->before == 1)
					cmds->option = 3; // Letzter Befehl in Verkettung
				else
					cmds->option = 0;
				cmds->before = 0;
				i++;
				break ;
			}
			cmds->args[j] = argv[i];
			i++;
			j++;
		}
		if (argv[i] == NULL && cmds->before == 1)
			cmds->option = 3;
		cmds->args[j] = NULL;
	}
	return (i);
}

int main(int argc, char **argv, char **env)
{
	t_commands	cmds;
	pid_t		pid;
	int			status;
	int			index;
	int			i;
	int			n;

	i = 0;
	cmds.before = 0;
	if (argc < 2)
		return (0);
	cmds.n_cmds = count_cmds(argc, argv);
	while (i < cmds.n_cmds)
	{
		pipe(cmds.pipes[i]);
		i++;
	}
	i = 0;
	index = 1;
/************************** ALGO ******************/
	while (i < cmds.n_cmds)
	{
		index = getpath(&cmds, argv, index);
		if (strcmp(cmds.args[0], "cd") == 0)
			execute_cd(&cmds, env);
		else
		{
			pid = fork();
			if (pid == -1)
				return (1);
			if (pid == 0)
			{
				if (cmds.option == 1)
				{
					dup2(cmds.pipes[i][IN], STDOUT_FILENO);
				}
				else if (cmds.option == 2)
				{
					dup2(cmds.pipes[i - 1][OUT], STDIN_FILENO);
					dup2(cmds.pipes[i][IN], STDOUT_FILENO);
				}
				else if (cmds.option == 3)
				{
					dup2(cmds.pipes[i - 1][OUT], STDIN_FILENO);
				}
				/******** CLOSE CHILD PROCESS******/
				n = 0;
				while (n < (i + 1))   
				{
					close(cmds.pipes[n][IN]);
					close(cmds.pipes[n][OUT]);
					n++;
				}
				/******** EXECUTE ********/
				execve(cmds.path[0], cmds.args, env);
			}
		}
		i++;
	}
/*********************** CLOSE MAIN PROCESS*******************/
	i = 0;
	while (i < cmds.n_cmds)
	{
		close(cmds.pipes[i][OUT]);
		close(cmds.pipes[i][IN]);
		i++;
	}
/*********************** WAITPID ****************/
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));

	return (0);
}
