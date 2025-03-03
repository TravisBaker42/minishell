/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:03:24 by jeschill          #+#    #+#             */
/*   Updated: 2025/02/28 13:30:04 by tbaker           ###   ########.fr       */
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

void	ft_free_malloc(t_data *data)
{
	if (data->cmd_list)
		ft_free_cmd_list(&data->cmd_list);
	if (data->token)
		ft_free_token_list(&data->token);
}

//change to macros
int	ft_str_env_cmp(char *lst_var, const char *input_var, int len);
{
	int	i;

	i = 0;
	if (lst_var[len] == '=')//check to see if lst_env->env_var is termnated with = sign before comparing)
	{
		//maybe added not equal to NULL condition
		while (i < len && lst_var[i] == input_var[i])
			i++;
		return (1);
	}
	else
		return (0);
}
