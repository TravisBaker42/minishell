/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_central.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:45:25 by jeschill          #+#    #+#             */
/*   Updated: 2025/01/10 13:51:31 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "../libft/libft.h"
#include "minishell.h"

///@Brief:
///@To_do: When gotten the chance, replace strcat with libft ft_strjoin.

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
		exit(1);
	}
}


///@Brief: Handles the Child processes.
///@To_do: Implement execve.
/// *fd: it's the array containing the pipe ends of our file descripters.
/// *fd_read: is the read_end of the previous pipe.
/// **envp: Contains the array of enviromental variabl pointers.
void	ft_child_process(t_cmd_list **cmd_list, int *fd, int fd_read, char **envp)
{
	dup2(fd_read, 0);
	if ((*cmd_list)->next != NULL)//not the last || first arg
		dup2(fd[1], 1);
	close(fd[0]);
	ft_execvp((*cmd_list)->cmds, envp);
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

///	updating to taking the cmd_list 
///@Brief: Handles multiple pipings.
///@To_do: Shorten code, Implement error_handling.
void	ft_pipe_central(t_cmd_list *cmd_list, char **envp)
{
	int		fd[2];
	int		fd_read;
	pid_t	pid;

	fd_read = 0;
	while (cmd_list)
	{
		if (pipe(fd) == -1)
			exit (EXIT_FAILURE);//add to test warning
		pid = fork();
		if (pid == -1)
			exit(1);
		else if (pid == 0)
			ft_child_process(&cmd_list, fd, fd_read, envp);
		else
		{
			ft_parent_process(fd, &fd_read);
			cmd_list = cmd_list->next;
		}
	}
}

/*      taken a ***cmd
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

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
//	char *cat[] = {"cat", "-e",NULL};
	char *wc[] = {"wc", "-c", NULL};
	char *ls[] = {"ls", NULL};
//	char **cmd[] = {ls, wc, cat, NULL};
	char **cmd[] = {ls, wc, NULL};

	ft_pipe_central(cmd, envp);
	return (0);
}*/
