/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:52:52 by jeschill          #+#    #+#             */
/*   Updated: 2025/02/19 13:27:29 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/// Brief@ : Handles all command executions: Including piping, redirections, file creation, builtins;
/// Todo@  : Implement cmd format bundling speciafically for piping. Builtins
//			 may be implemented in pipe_central or here?
///	     File creation implementation. ...
void	ft_executor(t_data *data)
{
	ft_pipe_central(data->cmd_list, data->envp);
}

