#include "minishell.h"
#include "../libft/libft.h"
#include <stdlib.h>

/// @breif Tokenizes ( ) and return the iterator to the next char input 
///
/// @todo
int	ft_brackets(t_token_list **head_token, const char *input, int i)
{
	if (input[i] == '(')
		ft_new_token_node(head_token, O_BRACKET, ft_strdup(")"));
	else
		ft_new_token_node(head_token, C_BRACKET, ft_strdup("("));
	return (1);
}

/// @breif Tokenizes >> > << < and return the iterator to the next char input 
///
/// @todo 
int	ft_greater_lesser(t_token_list **head_token, const char *input, int i)
{
	if (input[i] == '>')
	{
		if (input[i + 1] == '>')
		{
			ft_new_token_node(head_token, GREATER_GREATER, ft_strdup(">>"));
			return (2);
		}
		else
			ft_new_token_node(head_token, GREATER, ft_strdup(">"));
	}
	else
	{
		if (input[i + 1] == '<')
		{
			ft_new_token_node(head_token, LESSER_LESSER, ft_strdup("<<"));
			return (2);
		}
		else
			ft_new_token_node(head_token, LESSER, ft_strdup("<"));
	}
	return (1);
}
/// @Breif creates a new token node in the list and adds it to the back of
/// the list with PIPE token and token value of '|'
///
/// @parma head_token: begin of the token_list
///
/// @parma token_value: token value '|'
int	ft_pipe(t_token_list **head_token, char *token_value)
{
	ft_new_token_node(head_token, PIPE, token_value);
	return (1);
}

///	@Breif like substring
char	*ft_return_word(const char *input, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(word) * (end - start) + 1);
	//build better error handeling
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = input[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

/// @brief creates new word token adds to back of token_list
///
int	ft_word(t_token_list **head_token, const char *input, int i)
{
	char	*token_value;
	int		start;

	start = i;
	while (input[i] != '\0' && input[i] != 32 && input[i] != 9 && input[i] != '|')
		i++;
	token_value = ft_return_word(input, start, i);
	ft_new_token_node(head_token, WORD, token_value);
	return (i);
}
