/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschill <jeschill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:28:54 by jeschill          #+#    #+#             */
/*   Updated: 2025/02/04 22:11:35 by jeschill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
typedef	struct	s_fd_tracker
{
	int	in;
	int	out;
	int	fd_in;
	int fd_out;
	int	pipe_in;
	int pipe_out;
	int	pid;
	int	is_parent;
}	t_fd_tracker;
///@Brief:	Handles redirection of Truncate and Append. ie ">" and ">>".
///@To_do:	*Set up a struct(May have it's own or simply add all to the main
///			struct) that contains file descriptors that require tracking.
///			Define the system default fd, opened file fd, pipe fd and ...
///			*Fix fd_out pathway relative to struct, 
///@Notes:	
void	redir(t_data *data, char *file_str, int token)
{
	close(fd_out);//Include struct pathing in future. //This is done to ensure previously
				  //opened fd for outputs is properly closed before using.
	if (token == GREATER) //Adjust in future for better readability
		fd_out = open(file_str, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU); //Include Pathing for file_str in future;
	else if (token == GREATER_GREATER) //Also gotta adjust this for future.
		fd_out = open(file_str, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU); //Include Pathing for file_str in Future;
	if (fd_out == -1)
	{
		//error handling.
		//Should mimic bash error and output to std_err.
		ft_putstr_fd(file_str, STDERR);
		ft_putstr_fd(": No such file or directory", STDERR);
		//Might need to add stuff(Flag?) to prevent execution?
		return();
	}
	dup2(fd_out, STDOUT); //Makes sure future outputs go to specified file after fd_out replaces STDOUT.
}


///@Brief:	Handles input redirection. ie "<".
///@To_do:	Pretty much everything above.
///@Notes:	Example usage: sort < input.txt  //Equivalent to: cat input.txt | sort
void	input(t_data *data, char *file_str, int token)
{
	close(fd_in);
	fd_in = open(file_str, O_RDONLY, S_IRWXU);
	if (fd_in == -1)
	{
		//error handling.
		//Should mimic bash error and output to std_err.
		ft_putstr_fd(file_str, STDERR);
		ft_putstr_fd(": No such file or directory", STDERR);
		//Might need to add stuff(Flag?) to prevent execution?
		return();
	}
	dup2(fd_in, STDIN);
}


