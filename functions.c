/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:21:51 by oaboudan          #+#    #+#             */
/*   Updated: 2023/02/25 19:30:23 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	absd(char *cmd, char **env, int fdin)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		return ;
	pid = fork();
	checkfork((int)pid);
	if (pid)
	{	
		close(pipefd[1]);
		dup2(pipefd[0], STDIN);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT);
		if (fdin == STDIN)
			exit(1);
		else
			exec(cmd, env);
	}
}

void	checkfork(int i)
{
	if (i == -1)
	{
		perror("process creating faill");
		return ;
	}
}

void	exec(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (ft_strchr(args[0], '/') > -1)
		path = args[0];
	else
		path = getpath(args[0], env);
	execve(path, args, env);
	write(STDERR, "pipex: ", 7);
	write(STDERR, cmd, ft_strchr(cmd, 0));
	write(STDERR, ": command not found\n", 20);
	exit(1);
}
