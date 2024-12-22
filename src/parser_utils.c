#include "minishell.h"

int	ft_get_arg_len(t_token_list **head_token)
{
	int				len;
	t_token_list	*temp_token_list;

	temp_token_list = *head_token; 

	if (temp_token_list->token_type == WORD)
	{
		len = 1;
		while (temp_token_list->next)
		{
			if (temp_token_list->token_type == PIPE)
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
