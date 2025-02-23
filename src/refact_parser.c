/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refact_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:41:26 by tbaker            #+#    #+#             */
/*   Updated: 2025/02/23 19:17:15 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

int		ft_cmd_size(t_data *data, t_token_list **token_current)
{
	int	len;

	len = 0;
	while ((*token_current)->token_type <= INPUT && (*token_t:)
	{
		if ((*token_current)->token_type
		}
		return (len);
	}

	void	ft_parser(t_data *data)
	{
		t_token_list	*token_start;
		t_token_list	*token_current;

		data->cmd_list = NULL;
	token_start = data->token;
	while (token_start->token_type == SPACE)
		token_start = token_start->next;
	token_current = token_start;//i dont hink this matters
	ft_create_cmds_arrays(data, token_start, token_current);
}
