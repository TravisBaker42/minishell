

#include "../../libft/libft.h"

///@Brief:	This function return the key size of envp values. ie the length of
///			KEY in the KEY=value.
static int	ft_env_len(char *key)
{
	int	i;

	i = 0;
	while (key[i] && key[i] != '=')
		i++;
	return (i);
}

/*
------------------------------------------------------------------------------
-------------Subject to change due to reliance on unclear data struct.--------
------------------------------------------------------------------------------

///@Brief:	frees a node.
///@To_do:	Check the exact data struct in case we have to accomodate for
///			potential edge case scenario: 
///@Notes;	
static void	ft_nodus_deletus(t_envp	*envp)
{
	free(envp->env);
	envp->env = NULL;
	free (envp);
	envp = NULL;
}

///@Brief:	This function unsets enviromental variables. Supports multiple args.
///@To_do:	-Need to double check and clarify data struct to figure out how to
///			check and connect the first envp.
///			-Implement proper returns.
///@Notes;	
int	ft_unset(char **str, t_envp *envp)
{
	int		i;
	t_envp	*tmp;

	if (!str[1])
		return (1);
	//Implement condition if 1st encvp needs removing.
	while (envp && envp->next)
	{
		i = 0;
		while (str[++i] != NULL)
		{
			if(ft_strncmp(str[i], envp->next->env, ft_env_len(envp->next->env)) == 0)//Shorten this line
			{
				tmp = envp->next->next;
				ft_nodus_deletus(envp->next);
				envp->next = tmp;
			}
		}
		envp = envp->next;
	}
	return (1);
}

------------------------------------------------------------------------------
-------------Subject to change due to reliance on unclear data struct.--------
------------------------------------------------------------------------------
*/

/*************************************************/
/*				 Proof of concept				 */
/*************************************************/

#include <stdlib.h>
#include <stdio.h>

///@Brief:	Proof of concept done with base envp.
///@To_do:	
///@Notes;	Works for multiple arguments.
int ft_unset(char **str, char **envp)
{
	int i;
	int j;

	j = 0;
	if (!str[1])
		return (1);
	//Here is where we would implement a hypothetical edge case scenario if using data structs.
	while (envp[j])
	{
		i = 0;
		while (str[i])
		{
			if (ft_strncmp(str[i], envp[j], ft_env_len(envp[j])) == 0)
			{
				unsetenv(str[i]);
				printf("%s has been unset \n", str[i]);
				i = 0;
			   	//This one function removes the env var and adjusts the enviromental array.
				//This should emulate what we're trying to do, or more so we're trying to emulate
				//it with a data struct.
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	int i;
	char *arg[] = {"unset","TEST1", "TEST2", NULL};

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("TEST", envp[i], 4) == 0)
		{
			printf("%s\n", envp[i]);
		}
		i++;
	}
	printf("\n 1.number of envp is%i\n", i-1);
	i = 0;
	ft_unset(arg, envp);
	while (envp[i])
	{
		if (ft_strncmp("TEST", envp[i], 4) == 0)
		{
			printf("%s\n", envp[i]);
		}
		i++;
	}
	printf("\n 2.number of envp is%i\n", i-1);
}

