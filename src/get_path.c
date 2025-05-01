/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:43:13 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/01 13:41:41 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char *path, char *cmd)
{
	char	*res;

	res = ft_strdup(path);
	res = ft_strjoin_free(res, "/");
	res = ft_strjoin_free(res, cmd);
	path = res;
	while (path)
	{
		path = ft_strchr(path, '/');
		if (!path)
			return (NULL);
		if (access(path, X_OK) == 0)
			return (free(res), ft_strdup(path));
		++path;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	*path;
	int		i;

	i = -1;
	path = NULL;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = envp[i];
			break ;
		}
	}
	if (!path)
		return (NULL);
	return (find_path(path, cmd));
}
