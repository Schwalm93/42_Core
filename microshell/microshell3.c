/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 02:27:09 by cschwalm          #+#    #+#             */
/*   Updated: 2022/08/14 03:02:17 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define OUT 0
#define IN 1

int main(int argc, char *argv[], char *env[])
{
	int fd[2];
	int fd2[2];
	int pid;
	int pipeopen;


	pipeopen = 0;
	pipe(fd);
	pipe(fd2);

	pid = fork();

	if (pid == 0)
	{
		dup2(fd[IN], STDOUT_FILENO);
		close(fd[OUT]);
		execlp("ls", "ls", "-la", NULL);
	}
	
	sleep(1);
	pid = fork();

	pipe(fd2);
	if (pid == 0)
	{
		dup2(fd[OUT], STDIN_FILENO);
		dup2(fd2[IN], STDOUT_FILENO);
		close(fd[IN]);
		close(fd2[OUT]);
		execlp("grep", "grep", "test", NULL);
	}
	sleep(1);
	pid = fork();

	if (pid == 0)
	{
		dup2(fd2[OUT], STDIN_FILENO);
		close(fd2[IN]);
		close(fd[OUT]);
		close(fd[IN]);
		execlp("wc", "wc", "-l", NULL);
	}

	close(fd2[OUT]);
	close(fd2[IN]);
	close(fd[OUT]);
	close(fd[IN]);





	return (0);
}