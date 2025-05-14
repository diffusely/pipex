/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:38:49 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/14 16:40:39 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_files(t_pip *pip, char argc, char **argv)
{
	pip->fin = open(argv[1], O_RDONLY);
	if (pip->fin == -1)
	{
		free(pip);
		error_print(argv[1], "", 1);
	}
	pip->fout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pip->fout == -1)
	{
		close(pip->fin);
		free(pip);
		error_print(argv[argc - 1], "", 1);
	}
}

void	init_path(t_pip *pip)
{
	int		i;

	i = -1;
	pip->path = calloc(pip->size, sizeof(char *));
	while (++i < pip->size)
	{
		pip->path[i] = get_path(pip, pip->cmd[i][0]);
	}
}

void	init_fd(t_pip *pip)
{
	int	i;

	pip->fd = calloc(pip->size - 1, sizeof(int *));
	if (!pip->fd)
	{
		free_all(pip);
		error_handle("*FD* Bad alloc!\n", 1);
	}
	i = 0;
	while (i < pip->size - 1)
	{
		pip->fd[i] = calloc(2, sizeof(int));
		if (!pip->fd[i])
		{
			while (--i >= 0)
				free(pip->fd[i]);
			free(pip->fd);
			pip->fd = NULL;
			free_all(pip);
			error_handle("*FD* Bad alloc!\n", 1);
		}
		++i;
	}
}

void	init_cmd_and_pid(t_pip *pip, char **argv, int add)
{
	int		i;

	pip->pid = calloc(pip->size, sizeof(pid_t));
	if (!pip->pid)
	{
		free_all(pip);
		error_handle("*PID* Bad alloc!\n", 1);
	}
	i = 0;
	pip->cmd = malloc(pip->size * sizeof(char **));
	if (!pip->cmd)
	{
		free_all(pip);
		error_handle("*CMD* Bad alloc!\n", 1);
	}
	while (i < pip->size)
	{
		pip->cmd[i] = ft_split(argv[i + add], ' ');
		if (!pip->cmd[i])
			error_handle("*CMD* Bad alloc\n", 1);
		i++;
	}
}

void	init_pipex_val(t_pip *pip, char **argv, char **envp, int argc)
{
	pip->size = argc - 3;
	pip->cmd = NULL;
	pip->path = NULL;
	pip->pid = NULL;
	pip->fd = NULL;
	pip->envp = envp;
	init_files(pip, argc, argv);
	init_cmd_and_pid(pip, argv, 2);
	init_path(pip);
	init_fd(pip);
}
