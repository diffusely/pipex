/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:38:49 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/01 13:58:25 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_files(t_pip *pip, char argc, char **argv)
{
	pip->fin = open(argv[1], O_RDONLY);

	if (pip->fin == -1)
	{
		free(pip->cmd_path);
		free(pip);
		error_handle("file error\n", 0);
		exit(0);
	}

	pip->fout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (pip->fout == -1)
	{
		free(pip->cmd_path);
		free(pip);
		error_handle("file error\n", 0);
		exit(0);
	}
}
