/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 00:15:03 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/12 21:19:45 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	open_here_doc_file(t_pip *pip, char **argv, int argc)
{
	char	*gnl;

	pip->fin = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (pip->fin == -1)
	{
		free(pip);
		error_print(argv[1], "", 1);
	}
	while (1)
	{
		ft_printf(">");
		gnl = get_next_line(0);
		if (!gnl)
			break ;
		gnl[ft_strlen(gnl) - 1] = '\0';
		if (!ft_strcmp(gnl, argv[2]))
		{
			free(gnl);
			break ;
		}
		write(pip->fin, gnl, ft_strlen(gnl));
		write(pip->fin, "\n", 1);
		free(gnl);
	}
	get_next_line(-1);
}

void	here_doc(t_pip *pip)
{
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
	open_here_doc_file(pip, argv, argc);
	pip->fout = pip->fin;
	init_cmd_and_pid(pip, argv, 3);
	init_path(pip);
	int i = 0;
	while (i < pip->size)
	{
		ft_printf("%s\n", pip->cmd[i++][0]);
	}
	perror("qq");
	init_fd(pip);
}
