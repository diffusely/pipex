/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 00:15:03 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/14 17:48:05 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	write_here_doc(t_pip *pip, char **argv)
{
	char	*gnl;

	while (1)
	{
		ft_printf(">");
		gnl = get_next_line(0);
		if (!gnl)
			break ;
		gnl[ft_strlen(gnl) - 1] = '\0';
		if (!ft_strcmp(gnl, argv[2]))
			break ;
		if (write(pip->fd[0][1], gnl, ft_strlen(gnl)) == -1)
		{
			free_all(pip);
			exit(1);
		}
		if (write(pip->fd[0][1], "\n", 1) == -1)
		{
			free_all(pip);
			exit(1);
		}
		free(gnl);
	}
	free(gnl);
	get_next_line(-1);
}

void	here_doc(t_pip *pip, char **argv, int argc)
{
	pip->fout = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (pip->fout == -1)
	{
		free_all(pip);
		error_print(argv[argc - 1], "", 1);
	}
	if (pipe(pip->fd[0]) == -1)
		error_handle("pipe error\n", 1);
	pip->pid[0] = fork();
	if (pip->pid[0] == -1)
		error_handle("fork error\n", 1);
	if (pip->pid[0] == 0)
	{
		close(pip->fd[0][0]);
		write_here_doc(pip, argv);
		close(pip->fd[0][1]);
		free_all(pip);
		exit(0);
	}
	close(pip->fd[0][1]);
	waitpid(pip->pid[0], NULL, 0);
	pip->fin = pip->fd[0][0];
	pipex(pip);
}

void	init_here_doc_val(t_pip *pip, char **argv, char **envp, int argc)
{
	pip->size = argc - 4;
	pip->cmd = NULL;
	pip->path = NULL;
	pip->pid = NULL;
	pip->fd = NULL;
	pip->envp = envp;
	init_cmd_and_pid(pip, argv, 3);
	init_path(pip);
	init_fd(pip);
}
