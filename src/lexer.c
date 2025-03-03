/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:36:51 by tbaker            #+#    #+#             */
/*   Updated: 2025/02/28 13:57:35 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>//remove for testing 

/// @brief merge test and beginning of lexer
/// 
/// @prama input: is the terminal input from the prompt, 
/// current hard coded test string
///
/// @prama head_token: the gegin of the token_list
///
///	@todo lots of stuff do i show have a return value for errors
void	ft_tokenizer(t_data *data, t_token_list **head_token, const char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == 32 || input[i] == 9)
			i = ft_space(head_token, input, i);
		else if (input[i] == '|')
			i += ft_pipe(head_token, ft_strdup("|"));
		else if (input[i] == '>' || input[i] == '<')
			i += ft_greater_lesser(head_token, input, i);
		else if (input[i] == '$')
			i = ft_var_token(data, head_token, input, i);
		else if (input[i] == '\"' || input[i] == '\'')
			i = ft_quotes(head_token, input, i);
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
