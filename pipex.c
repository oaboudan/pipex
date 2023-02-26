/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:21:23 by oaboudan          #+#    #+#             */
/*   Updated: 2023/02/25 21:51:11 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	child2;

	fd[0] = open(av[1], O_RDWR);
	fd[1] = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd[0] == -1 || fd[1] == -1)
		return (write(STDERR, "something is wrong.\n", 20), (-1));
	if (ac == 5)
	{
		dup2(fd[0], STDIN);
		absd(av[2], env, fd[0]);
		dup2(fd[1], STDOUT);
		child2 = fork();
		checkfork(child2);
		if (child2 == 0)
			exec(av[3], env);
		wait(NULL);
		wait(NULL);
	}
	else
		write(STDERR, "Invalid number of argument.\n", 29);
	return (0);
}
