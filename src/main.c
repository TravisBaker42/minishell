/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:48:00 by tbaker            #+#    #+#             */
/*   Updated: 2024/11/23 11:57:42 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "macros.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

/// @breif get the current envronment path and prints it to the terminal
/// if there is no PATH set it prints not set to the terminal
///
/// @todo need to remove before final testing <------------------------
void	test_get_and_print_path(void)
{
	const char *path;

	path = getenv("PATH");
	if (path)
		printf("PATH: %s\n", path);
	else
		printf("PATH not set\n");
}

/// @breif Currently a test for the prompt. Infantly loops printing the prompt and taking the user imput from the terminal then printing it to the terminal,
/// also calls test_path. readline mallocs space for the input and returns a pointer to sting this why is free after use.
/// 
/// @todo do i need a return value, what break conditions are required to terminate the prompt 
void	test_prompt_loop(void)
{
	char *input;

	while (1)
	{
		input = readline("Minishell prompt$ ");
		ft_lexer(input);
		test_get_and_print_path();
		free (input);
	}
}

/// @breif basic main calls prompt loop 
///
/// @todo lots of stuff need to add libft to the make file 
/// are command line vars required does it require env path || just use getenv("PATH")
/// Need to remove printf used for libft testing <------------------------------------------
int	main(void)
{
    printf("libft atoi test =  %d\n", ft_test_libft("42"));//<------------------remove
	test_prompt_loop();
	return (0);
}
