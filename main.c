/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:41:11 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/08 23:32:13 by noavetis         ###   ########.fr       */
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
	pip = ft_calloc(1, sizeof(t_pip));
    if (!pip)
        error_handle("Bad alloc!\n", 1);

        //******************************** */
 
    //******************************** */

    
    init_files(pip, argc, argv);
    init_pipex_val(pip, argv, envp, argc);
    pipex(pip, envp);
	//char *args[] = {argv[1], argv[2], NULL};
	//ft_printf("%s\n", pip->cmd1);
    //execve(pip->cmd_path1, args, envp);

    free_all(pip);
    return 0;
}

