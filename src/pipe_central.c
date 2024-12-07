/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_central.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:45:25 by jeschill          #+#    #+#             */
/*   Updated: 2024/12/04 17:30:27 by jeschill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/// @BRIEF: Counts the amount of arguments in cmd. An argument is defined as
/// an executable binary + respective flags.
int	pipe_counter(char ***cmd)
{
	int i;

	i = 0;
	while (cmd[i])
		i++;
	return(i);
}



/// @Brief: Connects the pipes
/// @ToDo: 
void	pipe_fitting(char **cmd)
{
	pid_t	pid;
	int	p_fd[2];

	if (pipe(p_fd) == -1)
		exit(0);
	pid = fork;
	if (pid == -1)
		exit(0);
	if (pid == 0)
	{
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		exec(cmd);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
	}
}


/// @Brief: ...
void	pipe_central(char ***cmd)
{
	int	i;
	int	count;

	i = 0;
	count = pipe_counter(cmd);
	while (i < count - 1)
	{
		pipe_fitting(av[i]);
		i++;
	}
	exec(cmd[]);
}

/// @Brief: Input needed for pipe central should follow the below format.
int	main()
{
	char *cat[] = {"cat", NULL};
	char *wc[] = {"wc", "-c", NULL};
	char *ls[] = {"ls", NULL};
	char **cmd[] = {cat, wc, ls, NULL};

	pipe_central(cmd);
	return (0);
}
