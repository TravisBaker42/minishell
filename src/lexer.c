/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:36:51 by tbaker            #+#    #+#             */
/*   Updated: 2024/11/23 11:44:44 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>

/// @brief merge test and beginning of lexer
/// 
/// @prama input: is the terminal input from the prompt, current hard coded test string
///
/// @prama head_token: the gegin of the token_list
///
///	@todo lots of stuff do i show have a return value for errors
void	ft_tokenizer(t_token_list **head_token, const char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		i = ft_iterates_space(input, i);
		if (input[i] == '|')
			i += ft_pipe(head_token, ft_strdup("|"));
		else if (input[i] == '(' || input[i] == ')')
			i += ft_brackets(head_token, input, i);
		else if (input[i] == '>' || input[i] == '<')
			i += ft_greater_lesser(head_token, input, i);
		else if (input[i] == '\"')
			i = ft_d_qoutes(head_token, input, i);
		else
			i = ft_word(head_token, input, i);
	}
	ft_new_token_node(head_token, TOKEN_EOF, NULL);
}

/// @brief merge test and beginning of lexer
/// 
/// @prama input: is the prompt from the terminal
///
/// @todo everything
t_token_list	*ft_lexer(const char *input)
{
	t_token_list	*head_token;

	head_token = NULL;
	ft_tokenizer(&head_token, input);
	return (head_token);
}


