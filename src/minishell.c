/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:48:00 by tbaker            #+#    #+#             */
/*   Updated: 2025/01/10 18:31:31 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

///		for testing need to build real function
void	ft_non_interactive(int argc, char **argv, t_data *data)
{
	int i;

	i = 0;
	printf("non interactive has been selected need to build programme\n");
	while(i < argc)
	{
		printf("number %i = %s\n", i, argv[1]);
		i++;
	}
}

///		@brief To recieve commands through prompt from the terminal
void	ft_interactive(t_data *data)
{
	char *input;

	while (42)
	{
		input = readline("Minishell prompt$ ");
		data->token = ft_lexer(input);
		ft_parser(data);
		ft_execute(data);
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
		ft_interactive(data);
	else
		ft_non_interactive(argc, argv, data);
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
