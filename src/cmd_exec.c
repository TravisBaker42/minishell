/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschill <jeschill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 00:19:29 by jeschill          #+#    #+#             */
/*   Updated: 2025/02/26 11:48:10 by jeschill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>


char	*ft_get_path(char *cmd)
{
	int		i;
	char	*exec;
	char	**all_path;
	char	*path_part;

	i = -1;
	all_path = ft_split(getenv("PATH"), ':');
	while (all_path[++i])
	{
		path_part = ft_strjoin(all_path[i], "/");
		exec = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
	}
	ft_freetabs(all_path);
	return (cmd);
}


///@Brief: Handles the execution of execve.
void	ft_execvp(char **cmd, char **envp)
{
	char *path;

	path = ft_get_path(cmd[0]);
	if (execve(path, cmd, envp) == -1)
	{
		printf("exiting error execvp function");//testing remove
		//Implement process termination??
		exit(1);
	}
}

int	ft_exec_bin(char **cmd, char **envp)
{
	ft_execvp(cmd, envp);
	return (1);//added for return type of non-void functoin 
}

///@Brief:	Executes cmd, either buitltin or bin.
///@To_do:	
///@Notes:	
void	ft_exec_cmd(t_data *data, t_cmd_list *node, char **envp)
{
	/*if (node->cmds && ft_is_it_builtin(node->cmds[0]))
		data->ret = ft_exec_builtins(node->cmds, data);
	*/
	if (node->cmds)
		data->ret = ft_exec_bin(node->cmds, envp); //Include env;
	ft_close(data->pipe_in);
	ft_close(data->pipe_out);
	data->pipe_in = -1;
	data->pipe_out = -1;
}
