/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:28:51 by jeschill          #+#    #+#             */
/*   Updated: 2024/12/07 15:12:15 by jeschill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


///To_do: Shorten function, implement comprenhensive error handling,
//Implement execve with Pathfinder.
void	pipe_central(char ***cmd)
{
	int		fd[2];
	pid_t	pid;
	int		fdd;

	fdd = 0;
	while (*cmd != NULL)
	{
		pipe(fd);
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			dup2(fdd, 0);
			if (*(cmd + 1) != NULL)
				dup2(fd[1], 1);
			close(fd[0]);
			execvp((*cmd)[0], *cmd);
			exit(1);
		}
		else
		{
			wait(NULL);
			close(fd[1]);
			fdd = fd[0];
			cmd++;
		}
	}
}

int	main(void)
{
	//char *cat[] = {"cat", "-e", NULL};
	////char *wc[] = {"wc", "-c", NULL};
	char	*ls[] = {"ls", NULL};
	char	**cmd[] = {ls, NULL};

	pipe_central(cmd);
	return (0);
}
