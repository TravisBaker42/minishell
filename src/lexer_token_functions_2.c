/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_functions_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:30:02 by tbaker            #+#    #+#             */
/*   Updated: 2025/02/23 16:06:50 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_return_s_quotes(const char *input, int start, int end)
{
	char	*string;
	int		i;

	i = 0;
	end--;
	string = (char *)malloc(sizeof(string) * (end - start) + 1);
	if (!string)
		return (NULL);
	while (start < end)
	{
		if (input[start] == '$')
			printf("need to build function for expandsion of args or before\n");
		if (input[start] == '\"')
			printf("need to build function for single quotes\n");
		string[i] = input[start];
		start++;
		i++;
	}
	string[i] = '\0';
	return (string);
}
/// @breif Tokenizes 
///
/// @tod
int	ft_s_quotes(t_token_list **head_token, const char *input, int i)
{
	char	*token_value;
	int		start;

	start = i;
	while (input[i] != '\0' && input[i] != '\'')
		i++;
	if (input[i] == '\'')
	{
		i++;
		token_value = ft_return_s_quotes(input, start, i);
		ft_new_token_node(head_token, WORD, token_value);
	}
	else
	{
		//or some other error handling
		printf("Dont need to handle unclose single quotes\n");
	}
	return (i);
}

char	*ft_return_d_quotes(const char *input, int start, int end)
{
	char	*string;
	int		i;

	i = 0;
	end--;
	string = (char *)malloc(sizeof(string) * (end - start) + 1);
	if (!string)
		return (NULL);
	while (start < end)
	{
		if (input[start] == '$')
			printf("need to build function for expandsion of args or before\n");
		if (input[start] == '\'')
			printf("need to build function for single quotes\n");
		string[i] = input[start];
		start++;
		i++;
	}
	string[i] = '\0';
	return (string);
}


/// @breif Tokenizes 
///
/// @todo

int	ft_d_quotes(t_token_list **head_token, const char *input, int i)
{
	char	*token_value;
	int		start;

	start = i;
	while (input[i] != '\0' && input[i] != '\"')
		i++;
	if (input[i] == '\"')
	{
		i++;//sends i back pasted closing qoute
		token_value = ft_return_d_quotes(input, start, i);
		//ft_new_token_node(head_token, D_QUOTE, token_value);
		//will return it as a WORD token
		ft_new_token_node(head_token, WORD, token_value);
	}
	else
	{
		//or some other error handling
		printf("Dont need to handle double quotes\n");
	}
	return (i);
}

// @brief switching functoin if double qoutes else single qoutes
//  returns i as the current positon in prompt input
//  could adde if else incease of error maybe??
int	ft_quotes(t_token_list **head_token, const char *input, int i)
{
	if (input[i] == '\"')
	{
		i++;
		i = ft_d_quotes(head_token, input, i);
	}
	else
	{
		i++;
		i = ft_s_quotes(head_token, input, i);
	}
	return (i);
}
