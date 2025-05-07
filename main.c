/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:41:11 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/07 20:21:01 by noavetis         ###   ########.fr       */
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
	
	//ft_printf("wqer\n");
    pip->cmd1 = ft_split(argv[2], ' ');
	pip->cmd2 = ft_split(argv[3], ' ');
	pip->envp = envp;
	pip->cmd_path1 = get_path(argv[2], envp);
	pip->cmd_path2 = get_path(argv[3], envp);

	
	init_files(pip, argc, argv);
	pipex(pip, envp);
    if (!pip->cmd_path1)
	{
		error_print(pip->cmd1[0], "command not found\n", 0);
	}
	
	//char *args[] = {argv[1], argv[2], NULL};
	//ft_printf("%s\n", pip->cmd1);
    //execve(pip->cmd_path1, args, envp);

    return 0;
}

