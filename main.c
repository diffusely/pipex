/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:41:11 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/01 14:06:53 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{

	(void)argc;
    // if (argc != 2) {
    //     ft_putstr_fd("Usage: ./program <command>\n", 2);
    //     return 1;
    // }

	t_pip *pip;
	pip = malloc(sizeof(t_pip));
	init_files(pip, argc, argv);
    char *cmd = argv[1];
    pip->cmd_path = get_path(cmd, envp);

    if (!pip->cmd_path)
	{
		error_print(cmd, "command not found\n", 0);
	}
	
	char *args[] = {cmd, argv[2], NULL};
    execve(pip->cmd_path, args, envp);

    return 0;
}

