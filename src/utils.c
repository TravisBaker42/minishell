/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:03:24 by jeschill          #+#    #+#             */
/*   Updated: 2025/02/25 20:30:14 by jeschill         ###   ########.fr       */
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

void	ft_reset_std(t_data *data)
{
	data->in = dup(STDIN_FILENO);
	data->out = dup(STDOUT_FILENO);
}

void	ft_close_fds(t_data *data)
{
	ft_close(data->fd_in);
	ft_close(data->fd_out);
	ft_close(data->pipe_in);
	ft_close(data->pipe_out);
}

void	ft_reset_fds(t_data *data)
{
	data->fd_in = -1;
	data->fd_out = -1;
	data->pipe_in = -1;
	data->pipe_out = -1;
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
