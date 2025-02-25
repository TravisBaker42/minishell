/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:41:26 by tbaker            #+#    #+#             */
/*   Updated: 2025/02/24 16:09:35 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>


///		@Breif the cmd array now points the current token_types from token_list
///		the are malloce and stored in the token_list data cant not be free
///		till they have been finished with in the excution 
char	**ft_copy_token_value(t_data *data, t_token_list **token_start, int cmd_len)
{
	char	*arg;
	char	**cmds;
	int		i;

	i = 0;
	(void)data;//use for exit clean up
	cmds = (char **)malloc(sizeof(char*) * ( cmd_len + 1));
	if (!cmds)
	{
		perror("malloc fail in creating cmds array");
		exit(EXIT_FAILURE);//replace with a clean and exit function that 
						 //tales a string with the error and the t_data
						 //to free all malloced 
	}
	while (i < cmd_len)
	{
		arg = ft_strdup("");
		if ((*token_start)->token_type == SPACE)
			*token_start = (*token_start)->next;
		while ((*token_start)->token_type == WORD && (*token_start)->next->token_type == WORD)
		{
			arg = ft_strjoin(arg, (*token_start)->token_value);
			*token_start = (*token_start)->next;
		}
		if((*token_start)->token_type == WORD && ((*token_start)->next->token_type == SPACE || (*token_start)->next->token_type <= INPUT
		 || (*token_start)->next->token_type == TOKEN_EOF))
		{
			arg = ft_strjoin(arg, (*token_start)->token_value);
			cmds[i] = arg;
		//	if ((*token_start)->next == SPACE);
		//	*token_start = (*token_start)->next;
		}
		*token_start = (*token_start)->next;
		i++;
	}
	//if ((*token_start)->token_type <= INPUT)
	while ((*token_start)->token_type != WORD && (*token_start)->token_type != TOKEN_EOF)
		*token_start = (*token_start)->next;
	cmds[cmd_len] = NULL;
	return (cmds);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//NEED TO FIX AND MOVE AND ADDED TO HEADER FILE 
//NEED TO CHECK ALL OTHER CMD_LST CMDS make sure they have been strdup
//from token list and then free the token list 
//could refactor tokeniser to create token value for TOKEN_EOF 
char	**ft_copy_token_delimiter_value(char *token_value)
{
	char	**cmds;

//	(void)data;//use for exit clean up
	cmds = (char **)malloc(sizeof(char*) * 2);
	cmds[0] = ft_strdup(token_value);
	cmds[1] = NULL;
	return (cmds);
}

///		@Breif initlise the cmd list with new nodes assisgns token_type and
///		cmds array
void	ft_init_cmd_list(t_data *data, t_token_list **token_start, t_token_list *token_current, int cmd_len)
{
	char			**cmds;

//	printf("%d\n", cmd_len);//remove for testing
	if (cmd_len > 0) //so it dose not create for when only <= lesser is pasted
	{
		cmds = ft_copy_token_value(data, token_start, cmd_len);
		//ft_new_cmd_token_node(&data->cmd_list, cmds, token_type);
		ft_new_cmd_token_node(&data->cmd_list, cmds, WORD);
	}
	if (token_current->token_type <= INPUT)
		// when free the NULL cmds in the cmd_lst if the pipes and redirects can double free maybe 
		ft_new_cmd_token_node(&data->cmd_list, ft_copy_token_delimiter_value(token_current->token_value), token_current->token_type);
}	

///		@Brief this get i = size of the CMDS array so it can be malloced
///		
///		@token start this for copy over the token_values to cmds
///		@token_current is for looping and iterrating i for sizing cmds
void	ft_create_cmds_arrays(t_data *data, t_token_list *token_start, t_token_list *token_current)
{
	int	cmd_len;

	cmd_len = 0;
	while(token_current->token_type != TOKEN_EOF)
	{
		if(token_current->token_type == WORD)
		{
			while(token_current->token_type == WORD && token_current->next->token_type == WORD)
				token_current = token_current->next;
			if (token_current->token_type == WORD && (token_current->next->token_type == SPACE || token_current->next->token_type == TOKEN_EOF || 
					token_current->next->token_type <= INPUT))
				cmd_len++;
/*			if (token_current->token_type <= INPUT || token_current->next->token_type == TOKEN_EOF)
			{
				ft_init_cmd_list(data, &token_start, token_current, cmd_len);
				cmd_len = 0;
			}
			*/
		}
		if (token_current->token_type <= INPUT || token_current->next->token_type == TOKEN_EOF)
		{
			ft_init_cmd_list(data, &token_start, token_current, cmd_len);
			cmd_len = 0;
		}
		token_current = token_current->next;
	}
	ft_new_cmd_token_node(&data->cmd_list, ft_copy_token_delimiter_value("eof"), token_current->token_type);
}

void	ft_parser(t_data *data)
{
	t_token_list	*token_start;
	t_token_list	*token_current;

	data->cmd_list = NULL;
	token_start = data->token;
//	while (token_start->token_type == SPACE)
//		token_start = token_start->next;
	//my need to test print token start and current postions
//	token_current = token_start;//i dont hink this matters
	token_current = data->token;
	ft_create_cmds_arrays(data, token_start, token_current);
}
/*
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
}*/

/// @brief parsers tokens into array of array of strings
///
/// @todo everything 
