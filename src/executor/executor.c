/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeschill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:52:52 by jeschill          #+#    #+#             */
/*   Updated: 2025/02/05 12:55:58 by jeschill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//	char *cat[] = {"cat", "-e",NULL};
//	char *wc[] = {"wc", "-c", NULL};
//	char *ls[] = {"ls", NULL};
//	char **cmd[] = {ls, wc, cat, NULL};


typedef struct	s_cmd_list
{
	char				**cmds;
	t_token				token_type;
	struct s_cmd_list	*next;
} t_cmd_list;

/*
example: sort > pls_sort.txt
cmds:	{"sort", NULL}	{">", NULL}	{"pls_sort.txt", NULL}	NULL
token:	word?			LESSER		word?					NULL
ptr:	------------->	---------->	----------------------> NULL

example: env | grep "PATH" | wc -m
cmds:	{}
token:	{}
ptr:




*/
///@Brief:	
///@To_do:	
///@Notes;	
int executor(char ***cmd)
{
	
}

