/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:07:23 by oaboudan          #+#    #+#             */
/*   Updated: 2023/02/25 21:50:55 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "stdio.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define INFILE 0
# define OUTFILE 1

char	*join_path(char *path, char *bin);
int		ft_strncmp(char *str1, char *str2, int n);
int		ft_strchr(char *str, char c);
char	*ft_strndup(char *str, unsigned int n);
char	**ft_split(char *str, char sep);
void	absd(char *cmd, char **env, int fdin);
void	checkfork(int i);
void	exec(char *cmd, char **env);
char	*getpath(char *cmd, char **env);
void	exitfuntion(char *path);

#endif