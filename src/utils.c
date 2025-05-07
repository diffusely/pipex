/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <noavetis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:45:09 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/07 17:53:44 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_pip *pip)
{
	free(pip->cmd_path);
}

void	free_split(char **str)
{
	int i;

	if (!str)
		return ;
	i = 0;
	for (str[i])
		free(str[i++]);
	free(str);
	str = NULL;
}
