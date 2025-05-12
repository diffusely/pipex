/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:19:29 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/12 20:50:00 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_all_fd(t_pip *pip)
{
	int	i;

	i = 0;
	while (i < pip->size - 1)
	{
		close(pip->fd[i][0]);
		close(pip->fd[i][1]);
		i++;
	}
}

static void	close_fd(t_pip *pip, int index)
{
	//if (index == 0)
		//close(pip->fin);
	if (index == pip->size - 1)
		close(pip->fout);
	close_all_fd(pip);
	execve(pip->path[index], pip->cmd[index], pip->envp);
}

static void	call_pipe(t_pip *pip)
{
	int	i;

	i = 0;
	while (i < pip->size - 1)
	{
		if (pipe(pip->fd[i]) == -1)
			error_handle("pipe error\n", 0);
		++i;
	}
}

static void	close_and_wait(t_pip *pip)
{
	int	i;

	close(pip->fin);
	//close(pip->fout);
	close_all_fd(pip);
	i = 0;
	while (i < pip->size)
		waitpid(pip->pid[i++], NULL, 0);
}

void	pipex(t_pip *pip)
{
	int	i;

	i = -1;
	call_pipe(pip);
	while (++i < pip->size)
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
			close_fd(pip, i);
		}
	}
	close_and_wait(pip);
}
