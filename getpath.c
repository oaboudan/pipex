/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:27:08 by oaboudan          #+#    #+#             */
/*   Updated: 2023/03/02 21:29:42 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*getpath(char *cmd, char **env)
{
	char	*path;
	char	*fpath;
	char	*lpath;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	exitfuntion(path);
	while (path && ft_strchr(path, ':') > -1)
	{
		fpath = ft_strndup(path, ft_strchr(path, ':'));
		lpath = join_path(fpath, cmd);
		free(fpath);
		if (access(lpath, F_OK) == 0)
			return (lpath);
		free (lpath);
		path += ft_strchr(path, ':') + 1;
	}
	return (cmd);
}

void	exitfuntion(char *path)
{
	if (path == NULL)
	{
		perror("no path");
		exit(1);
	}
}
