/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_functions_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:30:02 by tbaker            #+#    #+#             */
/*   Updated: 2025/02/19 16:32:12 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

/// @breif Tokenizes 
///
/// @todo
/*
char	*ft_return_d_qoutes(const char *input, int start, int end)
{
	char	*string;
	int		i;

	i = 0;
	string = (char *)malloc(sizeof(string) * (end - start) + 1);
	if (!string)
		return (NULL);
	while (start < end)
	{
		if (input[start] == '$')
			printf("need to build function for expandsion of args or before\n");
		string[i] = input[start];
		start++;
		i++;
	}
	string[i] = '\0';
	return (string);
}
*/

/// @breif Tokenizes 
///
/// @todo
/*
int	ft_d_qoutes(t_token_list **head_token, const char *input, int i)
{
	char	*token_value;
	int		start;

	i++;// moves past quote char
	start = i;
	while (input[i] != '\0' && input[i] != '\"')
		i++;
	if (input[i] == '"')
	{
		token_value = ft_return_d_qoutes(input, start, i);
		ft_new_token_node(head_token, D_QUOTE, token_value);
		i++;//moves past qoute char
		return (i);
	}
	else
	{
		printf("need to add function for unclosed double quotes\n");
		return (i);
	}
}*/
