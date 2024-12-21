/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:41:26 by tbaker            #+#    #+#             */
/*   Updated: 2024/12/21 17:57:18 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell"
#include <stdlib.h>

/// @brief parsers tokens into array of array of strings
///
/// @todo everything 
char	***ft_parser(t_token_list **head_token)
{
	char ***cmds;

	cmds = malloc(sizeof());
	if (cmds == NULL)
	{
		printf("some error handling for cmds malloc fail here");
		return (NULL);

	}
	return (cmd):

}
