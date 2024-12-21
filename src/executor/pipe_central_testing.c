/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_central_testing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:45:25 by jeschill          #+#    #+#             */
/*   Updated: 2024/12/21 12:23:59 by jeschill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
//#include "libft.h"
//Remember to remove.
#include <string.h>

/*
void	ft_freetabs(char **tab)
{
		int i;

		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
}

///@Brief:
///@To_do: When gotten the chance, replace strcat with libft ft_strjoin.

char	*get_path(char *cmd)
{
	int		i;
	char	*exec;
	char	**all_path;
	char	*path_part;

	i = -1;
	all_path = ft_split(getenv("PATH"), ':');
	while (all_path[++i])
	{
		path_part = strcat(all_path[i], "/");
		exec = strcat(path_part, cmd);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
	}
	ft_freetabs(all_path);
	return (cmd);	
}


///@Brief: Handles the execution of execve.
///@To_do: Implemnet execve error handling.
void	ft_execvp(char **cmd, char **envp)
{
	char *path;

	path = get_path(cmd[0]);
	if (execve(path, cmd, envp) == -1)
	{
		exit(1);
	}
}
*/

///@Brief: Handles the Child processes.
///@To_do: Implement execve.
/// *fd: it's the array containing the pipe ends of our file descripters.
/// *fd_read: is the read_end of the previous pipe.
/// **envp: Contains the array of enviromental variabl pointers.
void	child_process(char ***cmd, int *fd, int *fd_read, char **envp)
{
	(void)envp;
	dup2(*fd_read, 0);
	if (*(cmd + 1) != NULL)
		dup2(fd[1], 1);
	close(fd[0]);
	ft_execvp( , envp)
	//execvp((*cmd)[0], *cmd);
	exit(1);
}

///@Brief: Handles the Parent Process.
/// *fd: it's the array containing the pipe ends of our file descripters.
/// *fd_read: is the read_end of the previous pipe.
void	parent_process(int *fd, int *fd_read)
{
	wait(NULL);
	close(fd[1]);
	*fd_read = fd[0];
}

///@Brief: Handles multiple pipings.
///@To_do: Shorten code, Implement error_handling.
void	pipe_central(char ***cmd, char **envp)
{
	int		fd[2];
	int		fd_read;
	pid_t	pid;

	fd_read = 0;
	while (*cmd != NULL)
	{
		pipe(fd);
		pid = fork();
		if (pid == -1)
			exit(1);
		else if (pid == 0)
			child_process(cmd, fd, &fd_read, envp);
		else
		{
			parent_process(fd, &fd_read);
			cmd++;
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	char *cat[] = {"cat", "-e",NULL};
	char *wc[] = {"wc", "-c", NULL};
	char *ls[] = {"ls", NULL};
	char **cmd[] = {ls, wc, cat, NULL};

	pipe_central(cmd, envp);
	return (0);
}