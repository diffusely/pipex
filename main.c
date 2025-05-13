/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 22:15:10 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/13 14:44:03 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pip	*pip;

	if (argc < 5)
	{
		error_handle("Usage: ./pipex file cmd cmd ... file\n", 1);
		return (0);
	}
	pip = ft_calloc(1, sizeof(t_pip));
	if (!pip)
	{
		error_handle("*PIP* Bad alloc!\n", 1);
	}
	if (!ft_strncmp("here_doc", argv[1], 8))
	{
		if (argc < 6)
			error_handle("Usage: ./pipex here_doc LIMITER cmd ... file\n", 1);
		init_here_doc_val(pip, argv, envp, argc);
		here_doc(pip, argv, argc);
		free_all(pip);
		return (0);
	}
	init_pipex_val(pip, argv, envp, argc);
	pipex(pip);
	free_all(pip);
	return (0);
}
