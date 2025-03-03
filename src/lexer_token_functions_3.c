/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:36:51 by tbaker            #+#    #+#             */
/*   Updated: 2025/02/28 13:57:35 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>//remove for testing 

char	*ft_copy_env_var(char *env_var)
{
	char	*env_var_copy;
	int		start;
	int		end;
	int		i;
	
	i = 0;
	start = 0;
	while (env_var[start] != '=')
		start++;
	start++;
	end = start;
	while (env_var[end])
		end++;
	env_var_copy = (char *)malloc(sizeof(env_var_copy) * start - end + 1);
	while (start < end)
	{
		env_var_copy[i] = env_var[start];
		start++;
		i++;
	}	
	env_var_copy[start - end] = '\0';
	return (env_var_copy);
}

char 	*ft_find_and_return_env(t_data *data, const char *var, int len);
{
	int			i;
	char		*env_var;
	t_env_lst	*env_lst;

	i = 0;
	data->env_lst = data->env_lst;
	while(env_lst)
	{
		if (ft_str_env_cmp(env_lst->env_var, var, len) == 1)
		{
			env_var = ft_copy_env_var(env_lst->env_var);
				return (env_var);
		}
		*env_lst = env_lst->next;
	}
	env_var = ft_strdup(" ");
	return (env_var);
}

//      get size of varable name then iterate through env_lst 
//      string comparing the env_var *char with the current postion in the input up until the end 
//      and make sure env_var len + 1 == '=' 
//      if varable not set in env_list need return string with only one space 
//
char	*ft_return_var(t_data *data, const char *input, int start, int end)
{
	const char	*var;
	char		*env_var;

	var = input[start];
	env_var = ft_find_and_return_env(data, var, start - end);

	return (env_var);
}

int	ft_var_expansion(t_data *data, t_token_list **head_token, const char input, int i)
{
	char	*token_value;
	int		start;

	i++;//moves past $
	start = i;
	while (input[i] != '\0' && input[i] != 32 && input[i] != 9
		&& input[i] != '|' && input[i] != '>' && input[i] != '<' 
		&& input[i] != '\"' && input[i] != '\'' && input[i] != '$')
		i++;
	token_value = ft_return_var(data, input, start, i);
	ft_new_token_node(head_token, WORD, token_value);
	return (i);
}	

/// @brief creat function that iterates till input[i] == space 
//   then i need to get the env and get the size then malloc then
//   copy into malloce dstring and ad to the token_value 
int	ft_var_token(t_data *data, t_token_list **head_token, const char input, int i)
{
	if (input[i + 1] == '?')
	{
		printf("need to build function for $?, program will now exit");
		i += 2;
	}
	else if (input[i + 1] == 32 || input[i + 1] == 9)//9 = tab 32 = space
	{
		ft_new_token_node(head_token, WORD, ft_strdup("$"));
		i++;
	}
	else
		i = ft_var_expansion(data, head_token, input, i);
	return (i);
}
