/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:19:29 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/08 23:35:02 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// static void	close_fd(t_pip *pipe, int index)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < pipe->size - 1)
// 	{
// 		j = 0;
// 		while (j < 2)
// 		{
// 			if (!(i == index && j == 0)
// 				|| !(i + 1 == index && j == 1))
// 				close(pipe->fd[i][j]);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	pipex(t_pip *pip, char **envp)
{
	int	i;

	i = 0;
	while (i < pip->size - 1)
	{
		if (pipe(pip->fd[i]) == -1)
		{	
			free_all(pip);
			error_handle("pipe error\n", 0);
		}
		++i;
	}
	i = 0;
	while (i < pip->size)
	{
		pip->pid[i] = fork();
		if (pip->pid[i] == -1)
			error_handle("fork error\n", 0);
		if (pip->pid[i] == 0)
		{
			if (i == 0)
				dup2(pip->fin, STDIN_FILENO);
			else
				dup2(pip->fd[i - 1][0], STDIN_FILENO);
			if (i == pip->size - 1)
				dup2(pip->fout, STDOUT_FILENO);
			else
				dup2(pip->fd[i][1], STDOUT_FILENO);
			execve(pip->path[i], pip->cmd[i], envp);
		}
	}
	
	close(pip->fin);
	close(pip->fout);

	i = 0;
	while (i < pip->size)
		waitpid(pip->pid[i], NULL, 0);
}
