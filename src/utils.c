/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:03:24 by jeschill          #+#    #+#             */
/*   Updated: 2025/02/19 16:31:12 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"

///@Brief:	Used to close fds.
///@To_do:	
///@Notes:	We do this because on first run we have the potential of closing STDIN.
void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}

void	ft_freetabs(char **tabs)
{
	int	i;

	i = 0;
	while (tabs[i])
	{
		if (tabs[i])
		{
			free(tabs[i]);
			tabs[i] = NULL;
		}
		i++;
	}
	if (tabs)
	{
		free(tabs);
		tabs = NULL;
	}
}

int	ft_iterates_space(const char *input, int i)
{
	while((input[i] == 32 || input[i] == 9) && input[i] != '\0')
		i++;
	return (i);
}
