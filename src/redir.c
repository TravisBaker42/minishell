/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschill <jeschill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:28:54 by jeschill          #+#    #+#             */
/*   Updated: 2025/02/26 00:25:26 by jeschill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"
#include <stdio.h> //Testing
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

///@Brief:	Handles redirection of Truncate and Append. ie ">" and ">>".
///@To_do:	*Set up a struct(May have it's own or simply add all to the main
///			struct) that contains file descriptors that require tracking.
///			Define the system default fd, opened file fd, pipe fd and ...
///			*Fix fd_out pathway relative to struct, 
///@Notes:	
void	ft_redir(t_data *data, t_cmd_list *node, int token)
{
	char	*str;

	str = node->cmds[0];
	ft_close(data->fd_out);//Include struct pathing in future. //This is done to ensure previously
				  //opened fd for outputs is properly closed before using.
	if (token == TRUNC) //Adjust in future for better readability
		data->fd_out = open(str, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	else if (token == APPEND) //Also gotta adjust this for future.
		data->fd_out = open(str, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	if (data->fd_out == -1)
	{
		//error handling.
		//Should mimic bash error and output to std_err.
		ft_putstr_fd("Minishell: ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		data->no_exec = 1;
		return ;
	}
	dup2(data->fd_out, STDOUT_FILENO); //Makes sure future outputs go to specified file after fd_out replaces STDOUT.
}

///@Brief:	Handles input redirection. ie "<".
///@To_do:	Pretty much everything above.
///@Notes:	Example usage: sort < input.txt  //Equivalent to: cat input.txt | sort
void	ft_input(t_data *data, t_cmd_list *node)
{
	char *str;

	str = node->cmds[0];
	ft_close(data->fd_in);
	data->fd_in = open(str, O_RDONLY, S_IRWXU);
	if (data->fd_in == -1)
	{
		//error handling.
		//Should mimic bash error and output to std_err.
		ft_putstr_fd("Minishell: ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		data->no_exec = 1;
		return ;
	}
	dup2(data->fd_in, STDIN_FILENO);
}

///@Brief:	Sets up a pipe process between CMD.
///@To_do:	
///@Notes:	
int	ft_quick_pipe(t_data *data)
{
	pid_t	pid;
	int		p_fd[2];

	pipe(p_fd);
	pid = fork();
	if (pid == 0)	//Child process.
	{
		ft_close(p_fd[1]);
		dup2(p_fd[0], STDIN_FILENO);
		data->pipe_in = p_fd[0];
		data->no_exec = 0;
		return (2);
	}
	else			//Parent process.
	{
		ft_close(p_fd[0]);
		dup2(p_fd[1], STDOUT_FILENO);
		data->pipe_out = p_fd[1];
		return (1);
	}
}

