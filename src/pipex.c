/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:19:29 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/07 20:22:04 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
	   
void	pipex(t_pip *pip, char **envp)
{
	if (pipe(pip->fd) == -1)
		error_handle("pipe error\n", 0);
	
	pip->pid1 = fork();
	if (pip->pid1 == -1)
		error_handle("fork error\n", 0);
	
	//ft_printf("test\n");
	if (pip->pid1 == 0)
	{
		dup2(pip->fin, STDIN_FILENO);
        dup2(pip->fd[1], STDOUT_FILENO);
		
		close(pip->fd[0]);
		close(pip->fd[1]);
		close(pip->fin);

        execve(pip->cmd_path1, pip->cmd1, envp);
        error_handle("execve cmd1 error\n", 1);
	}

	pip->pid2 = fork();
	if (pip->pid2 == -1)
		error_handle("fork error\n", 0);

	if (pip->pid2 == 0)
	{
        dup2(pip->fd[0], STDIN_FILENO);
		dup2(pip->fout, STDOUT_FILENO);
		
        close(pip->fd[0]);
		close(pip->fd[1]);
		close(pip->fout);

        execve(pip->cmd_path2, pip->cmd2, envp);
        error_handle("execve cmd2 error\n", 1);	
	}
	

	close(pip->fd[0]);
	close(pip->fd[1]);
	close(pip->fin);
	close(pip->fout);

	waitpid(pip->pid1, NULL, 0);
	waitpid(pip->pid2, NULL, 0);
}
