/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 00:15:03 by noavetis          #+#    #+#             */
/*   Updated: 2025/05/10 01:53:35 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(t_pip *pip, char **argv)
{
	char	*gnl;
	(void)pip;
	ft_printf(">");
	gnl = get_next_line(0);
	while (gnl)
	{
		gnl[ft_strlen(gnl) - 1] = '\0';
		if (!ft_strcmp(gnl, argv[2]))
			break ;
		ft_printf(">");
		free(gnl);
		gnl = get_next_line(0);
	}
	free(gnl);
	get_next_line(-1);
}
