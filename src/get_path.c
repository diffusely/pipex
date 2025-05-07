/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:43:13 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/07 17:49:44 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char **path, char *cmd)
{
	char	*res;
	int		i;

	i = 0;
	while (path[i])
	{
		res = ft_strjoin(path[i], "/");
		res = ft_strjoin_free(res, cmd);
		if (!path)
			return (NULL);
		if (access(res, X_OK) == 0)
			return (free(path), res);
		++i;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	**path;
	int		i;

	i = -1;
	path = NULL;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = ft_split(envp[i] + 5, ':');
			break ;
		}
	}
	if (!path)
		return (NULL);
	return (find_path(path, cmd));
}
