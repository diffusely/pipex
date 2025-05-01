/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:42:04 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/01 14:36:24 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

# include "fcntl.h"

typedef struct s_pip
{
	char	*cmd_path;

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

#endif