/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:07:30 by tbaker            #+#    #+#             */
/*   Updated: 2025/02/19 13:19:06 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>// removew for testing

void	ft_cmd_list_add_back(t_cmd_list **head_cmd, t_cmd_list *new_node)
{
	t_cmd_list	*temp_cmd_list;

	if (!new_node || !head_cmd)
		return ;
	if (!(*head_cmd))
		*head_cmd = new_node;
	else
	{
		temp_cmd_list = *head_cmd;
		while(temp_cmd_list->next)
			temp_cmd_list = temp_cmd_list->next;
		temp_cmd_list->next = new_node;
		new_node->prev = temp_cmd_list;
	}
}

t_cmd_list	*ft_new_cmd_list(char **cmds, t_token token_type)
{
	t_cmd_list	*new_cmd_node;

	new_cmd_node = (t_cmd_list *)malloc(sizeof(t_cmd_list));
	new_cmd_node->token_type = token_type;
	new_cmd_node->cmds = cmds;
	new_cmd_node->next = NULL;
	new_cmd_node->prev = NULL;
	return (new_cmd_node);
}

void	ft_new_cmd_token_node(t_cmd_list **cmd_list, char **cmds, t_token token_type)
{
	t_cmd_list	*new_node;

	new_node = ft_new_cmd_list(cmds, token_type);
	ft_cmd_list_add_back(cmd_list, new_node);
}

void	ft_free_cmd_list(t_cmd_list **head_cmd)
{
	t_cmd_list	*current;
	t_cmd_list	*next_node;

	current = *head_cmd;
	while (current)
	{
		next_node = current->next;
		if (current->cmds)
		{
			ft_freetabs(current->cmds);
			current->cmds = NULL;
		}
		if (current)
		{
			free(current);
			current = NULL;
		}
		current = next_node;
	}
}
/*

int	ft_amount_pipes(t_token_list **head_token)
{
	int				len;
	t_token_list	*temp_token_list;

	temp_token_list = *head_token; 
	len = 0;
	if (temp_token_list->token_type == WORD)
	{
		while (temp_token_list->next)
		{
			if (temp_token_list->token_type <= LESSER)
				len++;
			temp_token_list = temp_token_list->next;
		}
		return (len);
	}
	// the first argument is not a program such as ls and
	// the command is incorrected
	else
	{
		printf("error has occurred no program name as first arg\n");
		return (-1);
	}
}
*/
