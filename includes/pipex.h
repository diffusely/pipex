/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:42:04 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/07 18:24:11 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

# include "fcntl.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pip
{
	char	*cmd_path1;
	char	*cmd_path2;
	
	char	**cmd1;
	char	**cmd2;
	int		fd[2];
	int		fin;
	int		fout;

	int		pid1;
	int		pid2;
	char	**envp;
	
}	t_pip;

// Path
char	*get_path(char *cmd, char **envp);

// Errors
void	error_print(const char *cmd, const char *msg, int flag);
void	error_handle(char *msg, int flag);

// Init
void	init_files(t_pip *pip, char argc, char **argv);

// Utils
void	free_split(char **str);

// Pipe
void	pipex(t_pip *pip, char **envp);

#endif