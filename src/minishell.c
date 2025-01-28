/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:48:00 by tbaker            #+#    #+#             */
/*   Updated: 2025/01/15 14:17:49 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

/*void	ft_test_print_cmd_list(t_data *data)
{
	int			i;
	t_cmd_list	*print_cmds;

	print_cmds = data->cmd_list;
	while (print_cmds)
	{
		i = 0;
		while(print_cmds->cmds[i])
		{
			printf("%s ", print_cmds->cmds[i]);
			i++;
		}
		print_cmds = print_cmds->next;
		printf("\n");
	}
}*/

// remove only for testing
void	ft_test_env(t_lvl_lst *current_shell)
{
	t_env_lst	*env_lst;

	env_lst = current_shell->env_lst;
	printf("current shell lvl = %d\n", current_shell->lvl);
	while (env_lst)
	{
		printf("%s\n", env_lst->env_var);
		env_lst = env_lst->next;
	}
	printf("test complete\n");
}

void	ft_free_malloc(t_data *data)
{
	if (data->cmd_list)
		ft_free_cmd_list(&data->cmd_list);
	if (data->token)
		ft_free_token_list(&data->token);
}

///		for testing need to build real function
void	ft_non_interactive(int argc, char **argv, t_data *data)
{
	int i;

	i = 0;
	(void)data;
	printf("non interactive has been selected need to build programme\n");
	while(i < argc)
	{
		printf("number %i = %s\n", i, argv[i]);
		i++;
	}
}

///		@brief To recieve commands through prompt from the terminal
void	ft_interactive(t_data *data)
{
	char *prompt;
	char *input;

	prompt = "\033[1;36mMinishell prompt$ \033[0m";
	while (42)
	{
		input = readline(prompt);
		data->token = ft_lexer(input);
		ft_parser(data);	
		ft_init_env(data); //initalise intial shell lvl varaibles
		ft_test_env(data->lvl_lst); // this test that it works needs to be removed 
									// need to test for mulitipule shells 
									// need to build control statement to catch 
									// "./minishell" then call ft_init_lvl
									// and dup current env_lst to a new lvl_lst node
		ft_executor(data);//need to free data for cmd_list and token_list 
		ft_free_malloc(data);
		free (input);
	}
}

/// @breif basic main calls prompt loop 
///
/// @todo lots of stuff need to add libft to the make file 
/// are command line vars required does it require env path || just use getenv("PATH")
/// Need to remove printf used for libft testing <------------------------------------------

int	main(int argc, char **argv, char **envp)
{
	t_data data;

	data.envp = envp;
	if (argc == 1)
	{
		ft_interactive(&data);
	}
	else
		ft_non_interactive(argc, argv, &data);
	return (EXIT_SUCCESS);
}	
/*
int	main(void)
{
	t_token_list		*tokens;
//	char				***cmds;
	const char			*test_ptr;//<--------------------testing only remove and replace with prompt
	
	test_ptr = "ls | wc -c | cat -e";
		//	test_ptr = "      ls                               -la       |    grep -e s |      cat | ls -la >> file.txt"; //<-----remove testing only
//	test_ptr = "() | djaslkdj \"hello  world\" > >> < <<       &&&"; //<-----remove testing only
	// next test case
	//test_ptr = "\"l\"s | cat       | echo "hello '\' world " ;
	//test_ptr = "echo \"$(date '+%Y-%m-%d') $(date)\"";
	tokens = ft_lexer(test_ptr);
//	cmds = ft_parser(&tokens);
	ft_test_print_list(&tokens);//<-----------------------testing only remove
//	ft_execute(cmds);
	ft_free(&tokens);
	return (0);
}*/
