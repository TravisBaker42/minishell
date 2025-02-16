/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschill <jeschill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 00:19:29 by jeschill          #+#    #+#             */
/*   Updated: 2025/02/16 10:56:13 by jeschill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""


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
		exit(1);
}


///@Brief: Handles the Child processes.
///@To_do: Implement execve.
/// *fd: it's the array containing the pipe ends of our file descripters.
/// *fd_read: is the read_end of the previous pipe.
/// **envp: Contains the array of enviromental variabl pointers.
void	ft_child_process(char ***cmd, int *fd, int fd_read, char **envp)
{
	dup2(fd_read, 0);
	if (*(cmd + 1) != NULL)//not the last || first arg
		dup2(fd[1], 1);
	close(fd[0]);
	ft_execvp(cmd[0], envp);
	exit(1);
}

///@Brief: Handles the Parent Process.
/// *fd: it's the array containing the pipe ends of our file descripters.
/// *fd_read: is the read_end of the previous pipe.
void	ft_parent_process(int *fd, int *fd_read)
{
	wait(NULL);
	close(fd[1]);
	*fd_read = fd[0];
}

///@Brief: Handles multiple pipings.
///@To_do: Shorten code, Implement error_handling.
void	ft_pipe_central(char ***cmd, char **envp)
{
	int		fd[2];
	int		fd_read;
	pid_t	pid;

	fd_read = 0;
	while (*cmd != NULL)
	{
		if (pipe(fd) == -1)
			exit (EXIT_FAILURE);//add to test warning
		pid = fork();
		if (pid == -1)
			exit(1);
		else if (pid == 0)
			ft_child_process(cmd, fd, fd_read, envp);
		else
		{
			ft_parent_process(fd, &fd_read);
			cmd++;
		}
	}
}

int	exec_bin(char **cmd, char **envp)
{
	ft_execvp(cmd, envp);
}

///@Brief:	Executes cmd, either buitltin or bin.
///@To_do:	
///@Notes:	
void	exec_cmd(t_data *data, t_node *node, char **envp)
{
	if (cmd && is_it_builtin(node->cmd[0]))
		data->ret = exec_builtins(node->cmd, data);
	else if (cmd)
		data->ret = exec_bin(node->cmd, data, envp); //Include env;
	ft_close(data->pipe_in);
	ft_close(data->pipe_out);
	data->pipe_in = -1;
	data->pipe_out = -1;
}


