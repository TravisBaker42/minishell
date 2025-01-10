/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:41:26 by tbaker            #+#    #+#             */
/*   Updated: 2025/01/10 18:48:24 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell"
#include <stdlib.h>

void	ft_new_cmd_list(int len, t_token_list , t_data *data)
{
	data->cmd_list = 
}

void	ft_init_cmd_list(t_data *data)
{
	char			**cmds;
	int				len;
	t_token_list	*token_list;
	t_token_list	*token_list_temp;

	token_list = data->token;
	while (token_list->token_type == WORD)
	{
		token_list = token_list->next;
		len++;
	}



	


}

/// @brief parsers tokens into array of array of strings
///
/// @todo everything 
void	ft_parser(t_data *data)
{
	if (data->token == NULL)
	{
		printf("some error handling for cmds malloc fail here");
		return (NULL);
	}
	else
		ft_init_cmd_list(data);

}
