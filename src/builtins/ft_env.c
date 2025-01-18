


#include "../../include/minishell.h"
///@Brief: Displays all enviromental variable pointers in the format of NAME=value.
///@To_do: If need be, can be updated to take info from a struct :D .
int	ft_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_putendl_fd(env[i], 1);
		i++;
	}
	return (SUCCESS);
}


int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	return (ft_env(envp));
}
