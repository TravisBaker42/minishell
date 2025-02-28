#include "minishell.h"
#include "../libft/libft.h"
#include <stdio.h>//printf
#include <stdlib.h>//malloc

t_lvl_lst	*ft_new_lvl_lst(int lvl, t_env_lst *env_lst)
{
	t_lvl_lst	*new_lvl_node;

	new_lvl_node = (t_lvl_lst *)malloc(sizeof(t_lvl_lst));
	//some if state for malloc maybe ?
	new_lvl_node->lvl = lvl;
	new_lvl_node->env_lst = env_lst;
	new_lvl_node->next = NULL;
	return (new_lvl_node);
}

/// @breif need to also build a delete node function when exit is called after lvl 1 
void	ft_lvl_lst_add_start(t_lvl_lst **head_lvl, t_lvl_lst *new_node)
{
	if (!head_lvl || !new_node)
		return ;
	if (*head_lvl)
		new_node->next = *head_lvl;
	else
		new_node->next = NULL;
	*head_lvl = new_node;
}

void	ft_new_lvl_node(t_lvl_lst **head_lvl, int lvl, t_env_lst *env_lst)
{
	t_lvl_lst	*new_node;
	int			new_lvl;

	//lvl++;
	new_lvl = lvl + 1;
	new_node = ft_new_lvl_lst(new_lvl, env_lst);
	ft_lvl_lst_add_start(head_lvl, new_node);
}

// need to update shell lvl var  when copy need build it here somewhere
// @breif copys env linked lst and returns it 
t_env_lst	*ft_copy_env_lst(t_env_lst *env_lst)
{
	t_env_lst	*env_copy;
	t_env_lst	*temp_env_lst;

	temp_env_lst = env_lst;
	env_copy = NULL;
	while (temp_env_lst)
	{
		//if (strcmp(temp_env_lst, "what ever the shell level arg =")
		//some function to to reallow memory or could hard code the shell lvl arg here 
		//incrementing it the char lvl by 1 or could build a set argument function that replace 
		//or adds env vars
		ft_new_env_node(&env_copy, ft_strdup(temp_env_lst->env_var));
		temp_env_lst = temp_env_lst->next;
	}
	return (env_copy);
}

//	this function will be called when ./minishell is called as argument in our minishell 
void	ft_init_lvl(t_data *data, t_lvl_lst **head_lvl)
{
	if (!*head_lvl)
		ft_new_lvl_node(head_lvl, 0, ft_env_lst(data->envp));
	else
		ft_new_lvl_node(head_lvl, (*head_lvl)->lvl, ft_copy_env_lst((*head_lvl)->env_lst));
}

// only called at start of minishell
void	ft_init_env(t_data *data)
{
	//printf("test\n");//testing remove
	data->lvl_lst = NULL;
	ft_init_lvl(data, &data->lvl_lst);
}
