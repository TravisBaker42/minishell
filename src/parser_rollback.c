/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rollback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:41:26 by tbaker            #+#    #+#             */
/*   Updated: 2025/02/19 16:38:29 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

///		@Breif initlise the cmd list with new nodes assisgns token_type and
///		cmds array
void	ft_init_cmd_list(t_data *data, t_token_list **token_start, t_token_list *token_current, int len)
{
	char			**cmds;
	int				token_type;
	//t_token_list	*temp_current;

	token_type = (*token_start)->token_type;
	cmds = ft_copy_token_value(data, token_start, len);
	if (len > 0) //so it dose not create for when only <= lesser is pasted
		ft_new_cmd_token_node(&data->cmd_list, cmds, token_type);
	//	adds pipe or redirect between words
	if (token_current->token_type <= INPUT)
		// when free the NULL cmds in the cmd_lst if the pipes and redirects can double free maybe 
		ft_new_cmd_token_node(&data->cmd_list, NULL, token_current->token_type);
}	

///		@Breif the cmd array now points the current token_types from token_list
///		the are malloce and stored in the token_list data cant not be free
///		till they have been finished with in the excution 
char	**ft_copy_token_value(t_data *data, t_token_list **token_start, int len)
{
	int i;
	char	**cmds;

	i = 0;
	(void)data;//use for exit clean up
	cmds = (char **)malloc(sizeof(char*) * ( len + 1));
	if (!cmds)
	{
		perror("malloc fail in creating cmds array");
		exit(EXIT_FAILURE);//replace with a clean and exit function that 
						 //tales a string with the error and the t_data
						 //to free all malloced 
	}
	while (i < len)
	{
		cmds[i] = (*token_start)->token_value;//<---cmd_list now has malloc memory from token_list pointing to it
		*token_start = (*token_start)->next;
		i++;
	}
	if ((*token_start)->token_type <= INPUT)
		*token_start = (*token_start)->next;
	cmds[len] = NULL;
	return (cmds);
}

///		@Brief this get i = size of the CMDS array so it can be malloced
///		
///		@token start this for copy over the token_values to cmds
///		@token_current is for looping and iterrating i for sizing cmds
void	ft_create_cmds_arrays(t_data *data, t_token_list *token_start, t_token_list *token_current)
{
	int	i;

	i = 0;
	while(token_current->token_type != TOKEN_EOF)
	{
		if(token_current->token_type == WORD)
			i++;
		if(token_current->token_type <= INPUT || token_current->next->token_type == TOKEN_EOF) //change to <= LESSER for delimetor
		{
			ft_init_cmd_list(data, &token_start, token_current, i);
			i = 0;
		}
		token_current = token_current->next;
	}
	//added end of file node here 
	if (token_current->token_type == TOKEN_EOF)
		ft_new_cmd_token_node(&data->cmd_list, NULL, token_current->token_type);
}

/// @brief parsers tokens into array of array of strings
///
/// @todo everything 
void	ft_parser(t_data *data)
{
	t_token_list	*token_start;
	t_token_list	*token_current;

	data->cmd_list = NULL;
	token_start = data->token;
	token_current = data->token;
	ft_create_cmds_arrays(data, token_start, token_current);
//	printf("Testing ----------------------------------------\nTesting ---cmd_list = %s %s---------\n", data->cmd_list->cmds[0], data->cmd_list->cmds[1]);//<---------------testing remove

}
