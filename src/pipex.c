/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:19:29 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/01 14:33:36 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_pip *pip)
{
	if (pipe(pip->fd) == -1)
		error_handle("pipe error\n", 0);
	
	pip->pid1 = fork();
	if (pip->pid1 == -1)
		error_handle("fork error\n", 0);
	
	if (pip->pid1 == 0)
	{

        dup2(pip->fin, STDIN_FILENO);
        dup2(pip->fd[1], STDOUT_FILENO);
        close(pip->fd[0]);
        close(pip->fin);

        execve(pip->cmd1_path, pip->cmd1_args, pip->envp);
        error_handle("execve cmd1 error\n", 1);
	}

	pip->pid2 = fork();
	if (pip->pid2 == -1)
		error_handle("fork error\n", 0);

	if (pip->pid2 == 0)
	{
		
	}
}
