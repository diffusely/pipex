/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:45:09 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/08 23:36:01 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_pip *pip)
{
	close(pip->fin);
	close(pip->fout);
	if (pip->pid)
		free(pip->pid);
	free_fd(pip);
	free_path(pip);
	free(pip);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		free(str[i++]);
	free(str);
	str = NULL;
}

void	free_path(t_pip *pip)
{
	int	i;

	if (!pip->path)
		return ;
	i = 0;
	while(i < pip->size)
		free(pip->path[i++]);
	free(pip->path);
	pip->path = NULL;
}


void	free_fd(t_pip *pip)
{
	int	i;

	if (!pip)
		return ;
	i = 0;
	while (i < pip->size - 1)
		free(pip->fd[i++]);
	free(pip->fd);
	pip->fd = NULL;
}