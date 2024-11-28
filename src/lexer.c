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
#include <unistd.h>
#include <stdio.h>

/// @brief merge test and beginning of lexer
/// 
/// @prama input: is the terminal input from the prompt
///
///	@todo lots of stuff do i show have a return value for errors
void	ft_check_for_token(t_token_list **head_token, char *input)
{
	while (input)
	{
		if (*input == '|')

		*input++;
	}
}

/// @brief merge test and beginning of lexer
/// 
/// @prama input: is the prompt from the terminal
///
/// @todo everything
t_token_list	**ft_lexer(char *input)
{
	t_token_list	*head_token;

	head_token = NULL;
	ft_check_for_token(&head_token, input)
	return (&head_token);
}


