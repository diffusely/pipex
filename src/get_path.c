/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:43:13 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/09 23:43:50 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(t_pip *pip, char **path, char *cmd)
{
	char	*res;
	int		i;

	i = 0;
	while (path[i])
	{
		res = ft_strjoin(path[i], "/");
		res = ft_strjoin_free(res, cmd);
		if (!res)
		{
			free_split(path);
			free_all(pip);
			error_handle("*JOIN* Bad alloc", 1);
		}
		if (access(res, X_OK) == 0)
			return (free_split(path), res);
		free(res);
		++i;
	}
	return (free_split(path), ft_strdup("Error"));
}

char	*get_path(t_pip *pip, char *cmd)
{
	char	**path;
	int		i;

	i = -1;
	path = NULL;
	if (!cmd)
		return (NULL);
	while (pip->envp[++i])
	{
		if (!ft_strncmp(pip->envp[i], "PATH=", 5))
		{
			path = ft_split(pip->envp[i] + 5, ':');
			break ;
		}
	}
	if (!path)
		return (NULL);
	return (find_path(pip, path, cmd));
}
