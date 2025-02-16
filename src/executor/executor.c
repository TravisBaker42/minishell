/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:52:52 by jeschill          #+#    #+#             */
/*   Updated: 2025/02/16 15:06:41 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "testing.h"
#include "lib/libft/libft.h"

//	char *cat[] = {"cat", "-e",NULL};
//	char *wc[] = {"wc", "-c", NULL};
//	char *ls[] = {"ls", NULL};
//	char **cmd[] = {ls, wc, cat, NULL};

/*
example: sort > pls_sort.txt
cmds:	{"sort", NULL}	{">", NULL}	{"pls_sort.txt", NULL}	NULL
token:	word?			LESSER		word?					NULL
ptr:	------------->	---------->	----------------------> NULL

example: ls | wc -c | cat -e
cmds:	{"cat", "-e", NULL}	{"|", NULL}	{"wc", "-c", NULL}	{"|", NULL}	{"cat", "-e", NULL}	NULL
token:	word				pipe		word				pipe		word				NULL
ptr:	------------------>	---------->	----------------->	---------->	------------------>	NULL

example: env | grep "PATH" | wc -m
cmds:	{"env", NULL}	{"|", NULL}	{"grep", "PATH", NULL}	{"|", NULL}	{"wc", "-m"}	NULL
token:	word			pipe		word					pipe		word			NULL
ptr:	------------>	---------->	--------------------->	---------->	----------->	NULL
*/

/*
# define CMD 0
# define TRUNC 1
# define APPEND 2
# define INPUT 3
# define PIPE 4
# define END 5


typedef struct	s_data
{
	t_node	*start;
	int		in;
	int		out;
	int		fd_in;
	int		fd_out;
	int		pipe_in;
	int		pipe_out;
	int		pid;
	int		is_parent;
	int		ret;
	int		no_exec;
} t_data;

typedef struct s_node
{
	char	**cmd;
	int		token_type;
	struct	t_node	next;
	struct	t_node	prev;
}	t_node;

*/
//********************Testing node creation****************//
char	**dup_cmd(char **cmd)
{	
	char	**new_cmd;
	int		count;
	int		i;

	i = 0;	
	if (!cmd)
		return (NULL);
	count = 0;
	while (cmd[count] != NULL)
		count++;
	new_cmd = malloc((count + 1) * sizeof(char *));
	if (!new_cmd)
		return (NULL);
	while (i < count)
	{
		new_cmd[i] = ft_strdup(cmd[i]);
		if (!new_cmd[i])
		{
			while (i >= 0)
			{
				free(new_cmd[i]);
				i--;
			}
			free(new_cmd);
			return (NULL);
		}
		i++;
	}
	new_cmd[i] = NULL;
	return (new_cmd);
}

t_node	*create_node(int tk_type, char **cmd)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		printf("malloc falied");
		return (NULL);
	}
	new->cmd = dup_cmd(cmd);
	new->token_type = tk_type;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
//********************Testing node creation****************//

///@Brief: 	Execution flow chart: 
///			Recieve ptr containing cmd string and ...;
///			Checks for prev token type;
///			If else for redirections;
///			Identify cmds and then execute;
///			Always skips over redir;
///			Loop it until CMD is finished;
///
///
///@To_do:	Shorten some list names.
///			Include FD and STDIN/OUT sanitization after CMD is finished in function that calls executor
///@Notes;	What if we make token type an int and define in header?
void	executor(t_data *data, t_node *cmd, char **envp)
{
	t_node	*next;
	t_node	*prev;
	int		pip_child;
	
	pip_child = 0;
	next = next_sep(cmd); //Finds next seperator.
	prev = prev_sep(cmd); //Finds prev seperator.
	if (type_id(prev, TRUNC))
		redir(data, cmd, TRUNC);
	else if (type_id(prev, APPEND))
		redir(data, cmd, APPEND);
	else if (type_id(prev, INPUT))
		input(data, cmd, INPUT);
	else if (type_id(prev, PIPE))
		pip_child = quick_pipe(data);
	if (next && type_id(next, END) == 0 && pip_child != 1)
		executor(data, next->next, envp);
	if ((type_id(prev, PIPE) || !prev) && pip_child != 1 && data->no_exec == 0)
		exec_cmd(data, cmd, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char *ls[] = {"ls", NULL};
	char *wc[] = {"wc", "-c", NULL};
	char *cat[] = {"cat", "-e",NULL};
	char *pipe[] = {"|", NULL};
//	char **cmd[] = {ls, pipe, wc, pipe, cat, NULL};

	(void)argc;
	(void)argv;
	data.in = dup(STDIN_FILENO);
	data.out = dup(STDOUT_FILENO);
	t_node	*start = create_node(0, ls);
	t_node	*pipe1 = create_node(4, pipe);
	t_node	*cmd2 = create_node(0, wc);
	t_node	*pipe2 = create_node(4, pipe);
	t_node	*cmd3 = create_node(0, cat);

	start->prev = NULL;
	start->next = pipe1;
	pipe1->prev = start;
	pipe1->next = cmd2;
	cmd2->prev = pipe1;
	cmd2->next = pipe2;
	pipe2->prev = cmd2;
	pipe2->next = cmd3;
	cmd3->prev = pipe2;
	cmd3->next = NULL;

	data.start = start;
	data.no_exec = 0;
	data.fd_in = -1;
	data.fd_out = -1;
	data.pipe_in = -1;
	data.pipe_out = -1;
	executor(&data, data.start, envp);
	return (0);
}
