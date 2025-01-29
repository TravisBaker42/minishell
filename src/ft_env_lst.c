#include "../include/minishell.h"
#include "../libft/libft.h"
//#include <stdio.h>
#include <stdlib.h>
//#include <string.h>//remove and add ft_strdup

// all working needs to be add to header and make file 
// no memory leaks needs be called in the env lvl list when addind new nodes
// ft_strdup needs to added and libft linked for intergration 
// malloc memory of env needs to be freed at exit
// main needs to be removed
// envp_list 
// modify minishell header struct and remove after testing and intergration

void	ft_free_env_lst(t_env_lst **env_token)
{
	t_env_lst	*current;
	t_env_lst	*next_node;

	current = *env_token;
	while (current)
	{
		next_node = current->next;
		if (current->env_var)
		{
			free(current->env_var);
			current->env_var = NULL;
		}
		if (current)
		{
			free(current);
			current = NULL;
		}
		current = next_node;
	}
	*env_token = NULL;
}

t_env_lst	*ft_new_env_lst(char *env_var)
{
	t_env_lst	*new_env_node;

	new_env_node = (t_env_lst *)malloc(sizeof(t_env_lst));
	//if (!new_token_node)
	//	return (NULL);
	new_env_node->env_var =  env_var;
	new_env_node->next = NULL;
	return (new_env_node);
}

void	ft_env_lst_add_back(t_env_lst **head_env, t_env_lst *new_node)
{
	t_env_lst	*temp_env_lst;

	if (!new_node || !head_env)
		return ;
	if (!(*head_env))
		*head_env = new_node;
	else
	{
		temp_env_lst = *head_env;
		while (temp_env_lst->next)
			temp_env_lst = temp_env_lst->next;
		temp_env_lst->next = new_node;
	}
}

//		creates and adds nodes to back of list
void	ft_new_env_node(t_env_lst **mini_env_lst, char *env_var)
{
	t_env_lst	*new_node;
	new_node = ft_new_env_lst(env_var);
	ft_env_lst_add_back(mini_env_lst, new_node);
}

// This well need to modified to take the t_data struct as argument
// t_data will have or ill use this funcction for the env_lvl_lst and just call this with 
// in my ft_new_lvl_node function 
 t_env_lst	*ft_env_lst(char **envp)
{
	t_env_lst	*mini_env_lst;
	int			i;

	i = 0;
	mini_env_lst = NULL;
	while (envp[i])
	{
		//ft_new_env_node(&mini_env_list, ft_strdup(envp[i]);
		ft_new_env_node(&mini_env_lst, ft_strdup(envp[i]));//remove 
	//	printf("test\n %s\n", envp[i]);//remove testing<<---------------------------------------------------------
		i++;
	}
	return (mini_env_lst);
}
//	remove only for testing 
//	tested and leaked check all working as expected 
/*
int	main(int argc, char **argv, char **envp)
{
	t_env_lst	*minishell_env_lst;

	(void) argv;
	(void) argc;
	minishell_env_lst = ft_env_lst(envp);
	printf("test for minishell envorinment varable list \n");
	if (minishell_env_lst)
	{
		while (minishell_env_lst)
		{
			printf("%s\n", minishell_env_lst->env_var);
			minishell_env_lst = minishell_env_lst->next;
		}
		ft_free_env_lst(&minishell_env_lst);
		return (EXIT_SUCCESS);
	}
	else
	{
		printf("minishell_env init failure\n");
		return (EXIT_FAILURE);
	}
}*/
