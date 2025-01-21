



/****************************************************************************/
/*	To_do:	Reduce number of functions in this file.						*/
/*			Optimize line numbers for the functions.						*/
/*			Bug check and ensure this program works.						*/
/*			Put on 42 Header.												*/
/****************************************************************************/
#include "../../include/minishell.h"
#include <limits.h>


///@Brief: Creates and places a KEY=value in the env linked lists.
static int	env_key_create(t_env *env, char *arg)
{
	t_env	new;
	t_env	temp;
	if (env && env->value == NULL)
	{
		env->value = ft_strdup(arg);//------------------------>Malloc Detected
		return (SUCCESS);
	}
	new = malloc(sizeof(t_env));
	if (!new)
		return (FAILURE);
	new->value = ft_strdup(arg);
	while (env && env->next && env->next->next)
		env = env->next;
	tmp = env->next;
	env->next = new;
	new->next = tmp;
	return (SUCCESS);
}

///@Brief:	Finds the key section of the KEY=value in the src and copies it to the dst.
///@To_do:	May need to move to a built-in support functions.
static char *env_key_finder(char *dest, char *src)
{
	int	i;

	i = 0;
	while(src[i] && src[i] != '=' && ft_strlen(src) < 4096)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

///@Brief:	Finds the key in the env linked list and replaces the env->value with arg.
///			Returns 1 when unable to find corresponding key.
///@To_do:	May need to move to a built-in support functions.
static int	env_key_replacer(t_env *env,char *arg)
{
	char	arg_name[4096];
	char	env_name[4096];

	env_key_finder(arg_name, arg);
	while(env && env->next)
	{
		env_key_finder(env_name, env->value);
		if (ft_strncmp(arg_list, env_list, ft_strlen(arg)) == 0)
		{
			free(env->value);
			env->value = ft_strdup(arg);//-------------------------> MALLOC DETECTED
			return (0);
		}
		env = env->next;
	}
	return(1);
}

///@Brief: Finds and updates OLDPWD in the env list, creates new if not found:
///@To_do: Make freeing stuff and avoiding dangling pointers a function?
static int update_old_pwd(t_env *env)
{
	char cwd[PATH_MAX];
	char *old_cwd;

	if (getcwd(cwd, PATH_MAX) == -1)
		return (FAILURE);
	if (!(old_cwd = ft_strjoin("OLDPWD=", cwd))) //---------------> MALLOC DETECTED
		return (FAILURE);
	if (/*Check env for match, if found replace with old_cwd, else return 1*/ env_key_replacer(env, old_cwd) == 1)
		/*Create and add old_cwd to t_env.*/env_key_create(env, old_cwd);
	free(old_cwd);
	old_cwd = NULL;
	return (SUCCESS);
}


///@Brief:	Finds the value in KEY=value for the specific path needed and
///			returns it.
///@To_do: Actually check that it works when hooked up to the main program.
///
char	*get_env_path(char *path_name, t_env *env, int len)
{
	int	i;
	int j;
	char *path;

	i = 0;
	while (env && env->next != NULL)
	{
		if (ft_strncmp(path_name, env->vlaue, len) == 0)
		{
			path = malloc(sizeof(char) * (ft_strlen(env->value) - len + 1));
			while (env->value[i] != '=')
				i++;
			i++;
			while (env->value[i] != '\0')
			{
				path[j] = env->value[i];
				j++;
				i++;
			}
			path[j] = '\0';
			return (path);
		}
		env = env->next;
	}
}

///@Brief:	Handles the 2 options for HOME and Previous DIR.
///@To_do:	Implement error handling akin to BASH.
///@Notes:	Don't think i can use getenv because it takes the envp from outside
///			of the program, ie the unmodified envp list. 
static int	ft_goto(int option, t_env *env)
{
	char	*env_path;
	int		ret_code;
	
	if (option == 0)
	{
		update_old_pwd(env);
		env_path = get_env_path("HOME=", env, 5);
		if (!env_path)
		{
			/*Print error message*/;
			return (FAILURE);
		}
	}
	else if (option == 1)
	{
		env_path = get_env_path("OLDPWD=", env, 7);
		if (!env_path)
		{
			/*Print error message*/
			return (FAILURE);
		}
		update_old_pwd(env);
	}
	ret_code = chdir(env_path);
	return (ret_code);
}


///@Brief:	Handles the 3 possible cd arguments, ie blank, previous dir and relative paths.
int	ft_cd(char **arg, t_env *env)
{
	int ret_code;

	if (!arg[1])
		return (ft_goto(/*Home directory*/0, env));
	else if (ft_strncmp(arg[1], "-", 1) == 0)
		return (ft_goto(/*Previous directory*/1, env));
	else
	{
		update_old_pwd(env);
		ret_code = chdir(arg[1]);
		if (ret_code < 0)
			ret_code *= -1;
		if (ret_code != 0)
			/*Return error message to stdout1 akin to BASH*/;
	}
	return (ret_code);
}
