/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:21:35 by oaboudan          #+#    #+#             */
/*   Updated: 2023/02/25 19:55:20 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

int	ft_strncmp(char *str1, char *str2, int n)
{
	while (--n > 0 && *str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str2 - *str1);
}

char	**ft_split(char *str, char sep)
{
	char	**tab;
	int		count;
	int		t[2];

	count = 0;
	t[0] = 0;
	while (str[t[0]])
		if (str[t[0]++] == sep)
			count++;
	tab = malloc(sizeof(char *) * (count + 2));
	if (!tab)
		return (NULL);
	tab[count + 1] = NULL;
	t[1] = 0;
	while (t[1] < count + 1)
	{
		t[0] = 0;
		while (str[t[0]] && str[t[0]] != sep)
			t[0]++;
		tab[t[1]++] = ft_strndup(str, t[0]);
		str = str + t[0] + 1;
	}
	return (tab);
}

char	*ft_strndup(char *str, unsigned int n)
{
	char				*duped;
	unsigned int		i;

	i = 0;
	duped = malloc(sizeof(char) * (n + 1));
	if (!duped)
		return (NULL);
	while (i < n)
		duped[i++] = *str++;
	duped[n] = 0;
	return (duped);
}

char	*join_path(char *path, char *bin)
{
	char	*joined;
	int		i;
	int		j;

	joined = malloc(sizeof(char)
			*(ft_strchr(path, 0) + ft_strchr(bin, 0) + 2));
	if (!joined)
		return (joined);
	i = 0;
	j = 0;
	while (path[j])
		joined[i++] = path[j++];
	joined[i++] = '/';
	j = 0;
	while (bin[j])
		joined[i++] = bin[j++];
	joined[i] = 0;
	return (joined);
}
