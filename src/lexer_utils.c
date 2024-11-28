#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

/// @brief create new token node in list and assigns the token and the string the token represents
///
/// @prama t_token:
/// @prama token_real_value:
/// 
/// @todo may need build better or just return NULL and handle NULL return as error and free and print msg from there
t_token_list	*ft_new_token_list(t_token token_type, char *token_value)
{
	t_token_list	*new_token_node;
	
	new_token_node = (t_token_list *)malloc(sizeof(t_token_list));
	if (!new_token_node)
		return (NULL);
	new_token_list->token_type = token_type;
	new_token_list->token_value = token_value;
	new_token_list->next = NULL;
	return	(new_token_node);
}

/// @brief Adds newly create token node to end of the token list
///
/// @prama head_token: start of the token_list
///
/// @prama new_token: newly created intialised token
void	*ft_token_list_add_back(t_token_list **head_token, t_token_list *new_node)
{
	t_token_list	*temp_token_list;
	
	if (!new_node || !head_token)
		return (NULL);
	if (*head_token = NULL)
		*head_token = new_node;
	else
	{
		temp_token_list = *head_token;
		while (temp_token_list->next)
			temp_token_list = temp_token_list->next;
		temp_token_list->next = new_node;
	}
}

/// @brief for testing <---------------------remove
///
/// @parma head of the token_list
///
/// @todo reomve before finial testing
void	ft_test_print_token(t_token_list **head_token)
{
	t_token_list	*temp_token_list;
	int				i;

	i = 0;
	temp_token_list = head_token;
	while (temp_token_list)
	{
		printf("Token value = %s Token type = %d node postion = %d\n", temp_token_list->token_value, temp_token_list->token_type, i);
		i++;
		temp_token_list = temp_token_list->next;
	}
	printf("list finished");
}