/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:51:54 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/08 19:28:35 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_print(const char *cmd, const char *msg, int flag)
{
	ft_printf("%s: %s", cmd, msg);
	if (flag)
		perror(msg);
	exit(EXIT_FAILURE);
}

void	error_handle(char *msg, int flag)
{
	if (flag)
		ft_putstr_fd(msg, 2);
	else
		perror(msg);
	exit(EXIT_FAILURE);
}
